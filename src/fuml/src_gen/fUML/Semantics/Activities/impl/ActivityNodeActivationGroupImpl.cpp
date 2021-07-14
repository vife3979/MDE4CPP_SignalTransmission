#include "fUML/Semantics/Activities/impl/ActivityNodeActivationGroupImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_MESSAGE(a) /**/
#else
	#define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//#include "util/ProfileCallCount.hpp"

#include <cassert>
#include <iostream>
#include <sstream>

#include "abstractDataTypes/Bag.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation
#include "abstractDataTypes/SubsetUnion.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivation.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Activities/ActivityParameterNodeActivation.hpp"
#include "fUML/Semantics/Activities/ControlNodeActivation.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "uml/umlPackage.hpp"
#include "uml/Action.hpp"
#include "uml/ActivityEdge.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/Class.hpp"
#include "uml/InputPin.hpp"


//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "fUML/Semantics/Actions/ActionsFactory.hpp"


#include "uml/ActivityEdge.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "fUML/Semantics/Activities/ActivityExecution.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivation.hpp"
#include "fUML/Semantics/Activities/ActivityParameterNodeActivation.hpp"
#include "fUML/Semantics/Actions/StructuredActivityNodeActivation.hpp"

//Factories an Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Activities;

//*********************************
// Constructor / Destructor
//*********************************
ActivityNodeActivationGroupImpl::ActivityNodeActivationGroupImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ActivityNodeActivationGroupImpl::~ActivityNodeActivationGroupImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ActivityNodeActivationGroup "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ActivityNodeActivationGroupImpl::ActivityNodeActivationGroupImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityExecution> par_activityExecution)
:ActivityNodeActivationGroupImpl()
{
	m_activityExecution = par_activityExecution;
}

//Additional constructor for the containments back reference
ActivityNodeActivationGroupImpl::ActivityNodeActivationGroupImpl(std::weak_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> par_containingNodeActivation)
:ActivityNodeActivationGroupImpl()
{
	m_containingNodeActivation = par_containingNodeActivation;
}

ActivityNodeActivationGroupImpl::ActivityNodeActivationGroupImpl(const ActivityNodeActivationGroupImpl & obj): ActivityNodeActivationGroupImpl()
{
	*this = obj;
}

ActivityNodeActivationGroupImpl& ActivityNodeActivationGroupImpl::operator=(const ActivityNodeActivationGroupImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::EModelElementImpl::operator=(obj);
	ActivityNodeActivationGroup::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ActivityNodeActivationGroup "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_activityExecution  = obj.getActivityExecution();
	m_containingNodeActivation  = obj.getContainingNodeActivation();
	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation>> _suspendedActivations = obj.getSuspendedActivations();
	m_suspendedActivations.reset(new Bag<fUML::Semantics::Activities::ActivityNodeActivation>(*(obj.getSuspendedActivations().get())));
	//Clone references with containment (deep copy)
	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> edgeInstancesContainer = getEdgeInstances();
	if(nullptr != edgeInstancesContainer )
	{
		int size = edgeInstancesContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _edgeInstances=(*edgeInstancesContainer)[i];
			if(nullptr != _edgeInstances)
			{
				edgeInstancesContainer->push_back(std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityEdgeInstance>(_edgeInstances->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container edgeInstances."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr edgeInstances."<< std::endl;)
	}
	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation>> nodeActivationsContainer = getNodeActivations();
	if(nullptr != nodeActivationsContainer )
	{
		int size = nodeActivationsContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _nodeActivations=(*nodeActivationsContainer)[i];
			if(nullptr != _nodeActivations)
			{
				nodeActivationsContainer->push_back(std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivation>(_nodeActivations->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container nodeActivations."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr nodeActivations."<< std::endl;)
	}
	
	
	return *this;
}

std::shared_ptr<ecore::EObject> ActivityNodeActivationGroupImpl::copy() const
{
	std::shared_ptr<ActivityNodeActivationGroupImpl> element(new ActivityNodeActivationGroupImpl());
	*element =(*this);
	element->setThisActivityNodeActivationGroupPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ActivityNodeActivationGroupImpl::eStaticClass() const
{
	return fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityNodeActivationGroup_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void ActivityNodeActivationGroupImpl::activate(std::shared_ptr<Bag<uml::ActivityNode>> nodes,std::shared_ptr<Bag<uml::ActivityEdge>> edges)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	this->createNodeActivations(nodes);
    this->createEdgeInstance(edges);    
    std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation> > nodeActiviations = this->getNodeActivations();
    this->run(nodeActiviations);
	//end of body
}

void ActivityNodeActivationGroupImpl::addEdgeInstance(std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> instance)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	instance->setGroup(getThisActivityNodeActivationGroupPtr());
    this->getEdgeInstances()->push_back(instance);
	//end of body
}

void ActivityNodeActivationGroupImpl::addNodeActivation(std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> activation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	activation->setGroup(getThisActivityNodeActivationGroupPtr());
    this->getNodeActivations()->push_back(activation);
	//end of body
}

bool ActivityNodeActivationGroupImpl::checkIncomingEdges(std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> incomingEdges,std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation>> activations)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    unsigned int j = 0;
    bool notFound = true;

    while (j < incomingEdges->size() && notFound) {
        unsigned int k = 0;
        while (k < activations->size() && notFound) {
            if (activations->at(k)->isSourceFor(
                        incomingEdges->at(j))) {
                notFound = false;
            }
            k = k + 1;
        }
        j = j + 1;
    }

    return notFound;
	//end of body
}

void ActivityNodeActivationGroupImpl::createEdgeInstance(std::shared_ptr<Bag<uml::ActivityEdge>> edges)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	for (unsigned int i = 0; i < edges->size(); i++) 
	{
        std::shared_ptr<uml::ActivityEdge> edge = edges->at(i);
        //DEBUG_MESSAGE(std::cout<<"EDGE:" << edge << edge->getName()<<std::endl;)
        DEBUG_MESSAGE(std::cout<<"[createEdgeInstances] Creating an edge instance from "
                   << edge->getSource()->getName()
                   << " to "
                   << edge->getTarget()->getName()
                   << "."<<std::endl;)

        std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> edgeInstance=fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createActivityEdgeInstance();
        edgeInstance->setEdge(edge);

        this->addEdgeInstance(edgeInstance);
        //DEBUG_MESSAGE(std::cout<<"SOURCE:"<<edge->getSource()<<std::endl;)
        //DEBUG_MESSAGE(std::cout<<"TARGET:"<<edge->getTarget()<<std::endl;)
        this->getNodeActivation(edge->getSource())->addOutgoingEdge(edgeInstance);
        this->getNodeActivation(edge->getTarget())->addIncomingEdge(edgeInstance);
    }

	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation> > nodeActivations = this->getNodeActivations();
    for (unsigned int i = 0; i < nodeActivations->size(); i++) {
    	std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> nodeActivation = nodeActivations->at(i);
        nodeActivation->createEdgeInstances();
    }
	//end of body
}

std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> ActivityNodeActivationGroupImpl::createNodeActivation(std::shared_ptr<uml::ActivityNode> node)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation>  activation = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivation> (this->retrieveActivityExecution()->getLocus()->getFactory()->instantiateVisitor(node));
    if(activation!=nullptr)
    {
    	activation->setNode(node);
    	activation->setRunning(false);
    	this->addNodeActivation(activation);
    	activation->createNodeActivations();
    }
    else
    {
        DEBUG_MESSAGE(std::cout<<"Null activation"<<std::endl;)
    }
    return activation;
	//end of body
}

void ActivityNodeActivationGroupImpl::createNodeActivations(std::shared_ptr<Bag<uml::ActivityNode>> nodes)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	for (unsigned int i = 0; i < nodes->size(); i++) 
	{
		std::shared_ptr<uml::ActivityNode> node = nodes->at(i);
        if(node != nullptr)
        {
        	DEBUG_MESSAGE(std::cout<<"[createNodeActivations] Creating a node activation for "
                   << node->getName() << "..."<<std::endl;)
        	this->createNodeActivation(node);
        }
        else
        {
            DEBUG_MESSAGE(std::cout<<"Warning! A node was null!"<<std::endl;)
        }
    }
	//end of body
}

std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> ActivityNodeActivationGroupImpl::getNodeActivation(std::shared_ptr<uml::ActivityNode> node)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> activation = nullptr;

    int nodeMetaElementID = node->getMetaElementID();
    if ((nodeMetaElementID == uml::umlPackage::PIN_CLASS) || 
		(nodeMetaElementID == uml::umlPackage::INPUTPIN_CLASS) ||
		(nodeMetaElementID == uml::umlPackage::OUTPUTPIN_CLASS) ||
		(nodeMetaElementID == uml::umlPackage::ACTIONINPUTPIN_CLASS) ||
		(nodeMetaElementID == uml::umlPackage::VALUEPIN_CLASS))
	{
			auto containingNodeActivation=this->getContainingNodeActivation().lock();
			if(containingNodeActivation)
			{
				activation = containingNodeActivation->retrievePinActivation(std::dynamic_pointer_cast<uml::Pin>(node));
			}
  	  }

    if (activation == nullptr) 
    {
        unsigned int i = 0;
        std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation>> nodeActivations=this->getNodeActivations();
        unsigned int nodeActivationsSize= nodeActivations->size();
        while ((!activation) && (i < nodeActivationsSize))
        {
        	activation = nodeActivations->at(i)->getNodeActivation(node);
            i = i + 1;
        }
    }

    return activation;
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityParameterNodeActivation> > ActivityNodeActivationGroupImpl::getOutputParameterNodeActivations()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityParameterNodeActivation> > parameterNodeActivations(new Bag<fUML::Semantics::Activities::ActivityParameterNodeActivation>());
	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation> > nodeActivations = this->getNodeActivations();
	for (std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> activation : *nodeActivations)
	{
		if (activation->eClass() == fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityParameterNodeActivation_Class())
		{
			if (activation->getIncomingEdges()->size() > 0)
			{
				parameterNodeActivations->push_back(std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityParameterNodeActivation>(activation));
			}
		}
	}
	return parameterNodeActivations;
	//end of body
}

bool ActivityNodeActivationGroupImpl::hasSourceFor(std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> edgeInstance)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		bool hasSource = false;
	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation> > activations = this->getNodeActivations();
    unsigned int i = 0;
    while (!hasSource && i < activations->size()) 
    {
        hasSource = activations->at(i)->isSourceFor(edgeInstance);
        i = i + 1;
    }
    return hasSource;
	//end of body
}

bool ActivityNodeActivationGroupImpl::isSuspended()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    return this->getSuspendedActivations()->size() > 0;
	//end of body
}

void ActivityNodeActivationGroupImpl::resume(std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> activation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		DEBUG_MESSAGE(std::cout<<"[resume] node=" << (activation->getNode() == nullptr ? "null" : activation->getNode()->getName())<<std::endl;)

    bool found = false;
    unsigned int i = 0;
    while (!found && i < this->getSuspendedActivations()->size()) {
        if (this->getSuspendedActivations()->at(i) == activation) {
            this->getSuspendedActivations()->erase(this->getSuspendedActivations()->begin() + i);
            found = true;
        }
        i = i + 1;
    }
    if (!this->isSuspended()) 
    {
    	std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> containingNodeActivation = this->getContainingNodeActivation().lock();
        if (containingNodeActivation != nullptr) 
        {
            containingNodeActivation->resume();
        }
    }
	//end of body
}

std::shared_ptr<fUML::Semantics::Activities::ActivityExecution> ActivityNodeActivationGroupImpl::retrieveActivityExecution()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<fUML::Semantics::Activities::ActivityExecution> activityExecution = this->getActivityExecution().lock();
    if (!activityExecution)
    {
    	auto activation=this->getContainingNodeActivation().lock();
    	if(activation)
    	{
    		auto group=activation->getGroup().lock();
    		if(group)
    		{
    			activityExecution = group->retrieveActivityExecution();
    		}
    		else
    		{
                DEBUG_MESSAGE(std::cout<<__PRETTY_FUNCTION__<<std::endl;)
                throw "invalid group";
    		}
    	}
		else
		{
            DEBUG_MESSAGE(std::cout<<__PRETTY_FUNCTION__<<std::endl;)
            throw "invalid activation";
		}
    }
    return activityExecution;
	//end of body
}

void ActivityNodeActivationGroupImpl::run(std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation>> activations)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		{
		auto endIter=activations->end();
		for (auto it = activations->begin(); it != endIter; it++)
		{
			std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> activation = (*it);
			activation->run();
		}
	}

    DEBUG_MESSAGE(std::cout<<"[run] Checking for enabled nodes..."<<std::endl;)

    std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation> > enabledActivations(new Bag<fUML::Semantics::Activities::ActivityNodeActivation>());
    {
        auto endIter=activations->end();
		for (auto it = activations->begin(); it != endIter; ++it)
		{
			std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> activation = (*it);

			if(activation->getNode())
			{
				DEBUG_MESSAGE(std::cout<<"[run] Checking node " << activation->getNode()->getName()<< "..."<<std::endl;)
			}
			else
			{
				DEBUG_MESSAGE(std::cout<<"[run] Checking node anonymous Node (e.g. anonymous Fork) ..."<<std::endl;)
			}
			const int class_id = activation->eClass()->getClassifierID();
			if(!(class_id == fUML::Semantics::Actions::ActionsPackage::INPUTPINACTIVATION_CLASS ||  class_id == fUML::Semantics::Actions::ActionsPackage::OUTPUTPINACTIVATION_CLASS || class_id ==fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONNODEACTIVATION_CLASS))
			{
				std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance> > edges = activation->getIncomingEdges();
				bool isEnabled = this->checkIncomingEdges(edges, activations);

				// For an action activation, also consider incoming edges to
				// input pins
				if (isEnabled)
				{
					std::shared_ptr<uml::Action> action = std::dynamic_pointer_cast<uml::Action>(activation->getNode());
					if(action != nullptr) // if there is no action (e.g anonymous Fork), then there is also no pins
					{
						std::shared_ptr<Bag<uml::InputPin> > inputPins = action->getInput();
				        auto pinEndIter=inputPins->end();
						for (auto pinIt = inputPins->begin(); pinIt != pinEndIter; ++pinIt)
						{
							std::shared_ptr<uml::InputPin> inputPin = (*pinIt);
							std::shared_ptr<fUML::Semantics::Actions::ActionActivation> actionActivation = std::dynamic_pointer_cast<fUML::Semantics::Actions::ActionActivation>(activation);
							std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance> > inputEdges = actionActivation->retrievePinActivation(inputPin)->getIncomingEdges();
							isEnabled = isEnabled && this->checkIncomingEdges(inputEdges, activations);
						}
					}
				}

				if (isEnabled)
				{

					if(activation->getNode())
					{
						DEBUG_MESSAGE(std::cout<<"[run] Node " << activation->getNode()->getName()<< " is enabled."<<std::endl;)
					}
					else
					{
						DEBUG_MESSAGE(std::cout<<"[run] Node anonymous Node (eg. anonymous Fork) is enabled."<<std::endl;)
					}
					enabledActivations->push_back(activation);
				}
			}
		}
    }
    DEBUG_MESSAGE(std::cout<<"[run] " << enabledActivations->size() << " node(s) is/are enabled."<<std::endl;)

    // *** Send offers to all enabled nodes concurrently. ***
    {
		auto endIter=enabledActivations->end();
		for (auto it = enabledActivations->begin(); it != endIter; it++)
		{
			std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> activation = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivation> (*it);
			if(activation->getNode())
			{
				DEBUG_MESSAGE(std::cout<<"[run] Sending offer to node " << activation->getNode()->getName()<<std::endl;)
			}
			else
			{
				DEBUG_MESSAGE(std::cout<<"[run] Sending offer to anonymous Node (e.g anonymous Fork)"<<std::endl;)
			}
			activation->receiveOffer();
		}
    }
	//end of body
}

void ActivityNodeActivationGroupImpl::runNodes(std::shared_ptr<Bag<uml::ActivityNode>> nodes)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation> > nodeActivations(new Bag<fUML::Semantics::Activities::ActivityNodeActivation>());

    for (unsigned int i = 0; i < nodes->size(); i++) 
    {
    	std::shared_ptr<uml::ActivityNode> node = nodes->at(i);
    	std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> nodeActivation = this->getNodeActivation(node);
        if (nodeActivation != nullptr) 
        {
            nodeActivations->push_back(nodeActivation);
        }
    }

    this->run(nodeActivations);
	//end of body
}

void ActivityNodeActivationGroupImpl::suspend(std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> activation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	DEBUG_MESSAGE(std::cout<<"[suspend] node=" << (activation->getNode() == nullptr ? "null" : activation->getNode()->getName())<<std::endl;)

    if (!this->isSuspended()) 
    {
    	std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> containingNodeActivation = this->getContainingNodeActivation().lock();
        if (containingNodeActivation != nullptr)
        {
            containingNodeActivation->suspend();
        }
    }
    this->getSuspendedActivations()->push_back(activation);
	//end of body
}

void ActivityNodeActivationGroupImpl::terminateAll()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	//DEBUG_MESSAGE(//TODO fix std::cout<<"[terminateAll] Terminating activation group for "<< (this->getActivityExecution() != nullptr ? "activity " + this->getActivityExecution()->getTypes()->at(0)->getName() : this->getContainingNodeActivation() != nullptr ? "node " << this->getContainingNodeActivation()->getNode()->getName() : "expansion region") << ".");)

	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation> > nodeActivations = this->getNodeActivations();
    for (unsigned int i = 0; i < nodeActivations->size(); i++) 
    {
    	std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> nodeActivation = nodeActivations->at(i);
        nodeActivation->terminate();
    }

    this->getSuspendedActivations()->clear();
	//end of body
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference activityExecution
*/
std::weak_ptr<fUML::Semantics::Activities::ActivityExecution> ActivityNodeActivationGroupImpl::getActivityExecution() const
{

    return m_activityExecution;
}
void ActivityNodeActivationGroupImpl::setActivityExecution(std::weak_ptr<fUML::Semantics::Activities::ActivityExecution> _activityExecution)
{
    m_activityExecution = _activityExecution;
	
}


/*
Getter & Setter for reference containingNodeActivation
*/
std::weak_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> ActivityNodeActivationGroupImpl::getContainingNodeActivation() const
{

    return m_containingNodeActivation;
}
void ActivityNodeActivationGroupImpl::setContainingNodeActivation(std::weak_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> _containingNodeActivation)
{
    m_containingNodeActivation = _containingNodeActivation;
	
}


/*
Getter & Setter for reference edgeInstances
*/
std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> ActivityNodeActivationGroupImpl::getEdgeInstances() const
{
	if(m_edgeInstances == nullptr)
	{
		m_edgeInstances.reset(new Bag<fUML::Semantics::Activities::ActivityEdgeInstance>());
		
		
	}

    return m_edgeInstances;
}



/*
Getter & Setter for reference nodeActivations
*/
std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation>> ActivityNodeActivationGroupImpl::getNodeActivations() const
{
	if(m_nodeActivations == nullptr)
	{
		m_nodeActivations.reset(new Bag<fUML::Semantics::Activities::ActivityNodeActivation>());
		
		
	}

    return m_nodeActivations;
}



/*
Getter & Setter for reference suspendedActivations
*/
std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation>> ActivityNodeActivationGroupImpl::getSuspendedActivations() const
{
	if(m_suspendedActivations == nullptr)
	{
		m_suspendedActivations.reset(new Bag<fUML::Semantics::Activities::ActivityNodeActivation>());
		
		
	}

    return m_suspendedActivations;
}



//*********************************
// Union Getter
//*********************************



std::shared_ptr<ActivityNodeActivationGroup> ActivityNodeActivationGroupImpl::getThisActivityNodeActivationGroupPtr() const
{
	return m_thisActivityNodeActivationGroupPtr.lock();
}
void ActivityNodeActivationGroupImpl::setThisActivityNodeActivationGroupPtr(std::weak_ptr<ActivityNodeActivationGroup> thisActivityNodeActivationGroupPtr)
{
	m_thisActivityNodeActivationGroupPtr = thisActivityNodeActivationGroupPtr;
}
std::shared_ptr<ecore::EObject> ActivityNodeActivationGroupImpl::eContainer() const
{
	if(auto wp = m_activityExecution.lock())
	{
		return wp;
	}

	if(auto wp = m_containingNodeActivation.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ActivityNodeActivationGroupImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_ACTIVITYEXECUTION:
			return eAny(getActivityExecution().lock()); //102
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_CONTAININGNODEACTIVATION:
			return eAny(getContainingNodeActivation().lock()); //103
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_EDGEINSTANCES:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<fUML::Semantics::Activities::ActivityEdgeInstance>::iterator iter = getEdgeInstances()->begin();
			Bag<fUML::Semantics::Activities::ActivityEdgeInstance>::iterator end = getEdgeInstances()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //100			
		}
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_NODEACTIVATIONS:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<fUML::Semantics::Activities::ActivityNodeActivation>::iterator iter = getNodeActivations()->begin();
			Bag<fUML::Semantics::Activities::ActivityNodeActivation>::iterator end = getNodeActivations()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //101			
		}
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_SUSPENDEDACTIVATIONS:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<fUML::Semantics::Activities::ActivityNodeActivation>::iterator iter = getSuspendedActivations()->begin();
			Bag<fUML::Semantics::Activities::ActivityNodeActivation>::iterator end = getSuspendedActivations()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //104			
		}
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}
bool ActivityNodeActivationGroupImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_ACTIVITYEXECUTION:
			return getActivityExecution().lock() != nullptr; //102
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_CONTAININGNODEACTIVATION:
			return getContainingNodeActivation().lock() != nullptr; //103
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_EDGEINSTANCES:
			return getEdgeInstances() != nullptr; //100
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_NODEACTIVATIONS:
			return getNodeActivations() != nullptr; //101
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_SUSPENDEDACTIVATIONS:
			return getSuspendedActivations() != nullptr; //104
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool ActivityNodeActivationGroupImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_ACTIVITYEXECUTION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::Activities::ActivityExecution> _activityExecution = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityExecution>(_temp);
			setActivityExecution(_activityExecution); //102
			return true;
		}
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_CONTAININGNODEACTIVATION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> _containingNodeActivation = std::dynamic_pointer_cast<fUML::Semantics::Actions::StructuredActivityNodeActivation>(_temp);
			setContainingNodeActivation(_containingNodeActivation); //103
			return true;
		}
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_EDGEINSTANCES:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> edgeInstancesList(new Bag<fUML::Semantics::Activities::ActivityEdgeInstance>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				edgeInstancesList->add(std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityEdgeInstance>(*iter));
				iter++;
			}
			
			Bag<fUML::Semantics::Activities::ActivityEdgeInstance>::iterator iterEdgeInstances = getEdgeInstances()->begin();
			Bag<fUML::Semantics::Activities::ActivityEdgeInstance>::iterator endEdgeInstances = getEdgeInstances()->end();
			while (iterEdgeInstances != endEdgeInstances)
			{
				if (edgeInstancesList->find(*iterEdgeInstances) == -1)
				{
					getEdgeInstances()->erase(*iterEdgeInstances);
				}
				iterEdgeInstances++;
			}
 
			iterEdgeInstances = edgeInstancesList->begin();
			endEdgeInstances = edgeInstancesList->end();
			while (iterEdgeInstances != endEdgeInstances)
			{
				if (getEdgeInstances()->find(*iterEdgeInstances) == -1)
				{
					getEdgeInstances()->add(*iterEdgeInstances);
				}
				iterEdgeInstances++;			
			}
			return true;
		}
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_NODEACTIVATIONS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation>> nodeActivationsList(new Bag<fUML::Semantics::Activities::ActivityNodeActivation>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				nodeActivationsList->add(std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivation>(*iter));
				iter++;
			}
			
			Bag<fUML::Semantics::Activities::ActivityNodeActivation>::iterator iterNodeActivations = getNodeActivations()->begin();
			Bag<fUML::Semantics::Activities::ActivityNodeActivation>::iterator endNodeActivations = getNodeActivations()->end();
			while (iterNodeActivations != endNodeActivations)
			{
				if (nodeActivationsList->find(*iterNodeActivations) == -1)
				{
					getNodeActivations()->erase(*iterNodeActivations);
				}
				iterNodeActivations++;
			}
 
			iterNodeActivations = nodeActivationsList->begin();
			endNodeActivations = nodeActivationsList->end();
			while (iterNodeActivations != endNodeActivations)
			{
				if (getNodeActivations()->find(*iterNodeActivations) == -1)
				{
					getNodeActivations()->add(*iterNodeActivations);
				}
				iterNodeActivations++;			
			}
			return true;
		}
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_SUSPENDEDACTIVATIONS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation>> suspendedActivationsList(new Bag<fUML::Semantics::Activities::ActivityNodeActivation>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				suspendedActivationsList->add(std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivation>(*iter));
				iter++;
			}
			
			Bag<fUML::Semantics::Activities::ActivityNodeActivation>::iterator iterSuspendedActivations = getSuspendedActivations()->begin();
			Bag<fUML::Semantics::Activities::ActivityNodeActivation>::iterator endSuspendedActivations = getSuspendedActivations()->end();
			while (iterSuspendedActivations != endSuspendedActivations)
			{
				if (suspendedActivationsList->find(*iterSuspendedActivations) == -1)
				{
					getSuspendedActivations()->erase(*iterSuspendedActivations);
				}
				iterSuspendedActivations++;
			}
 
			iterSuspendedActivations = suspendedActivationsList->begin();
			endSuspendedActivations = suspendedActivationsList->end();
			while (iterSuspendedActivations != endSuspendedActivations)
			{
				if (getSuspendedActivations()->find(*iterSuspendedActivations) == -1)
				{
					getSuspendedActivations()->add(*iterSuspendedActivations);
				}
				iterSuspendedActivations++;			
			}
			return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any ActivityNodeActivationGroupImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 1007
		case ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_OPERATION_ACTIVATE_ACTIVITYNODE_ACTIVITYEDGE:
		{
			//Retrieve input parameter 'nodes'
			//parameter 0
			std::shared_ptr<Bag<uml::ActivityNode>> incoming_param_nodes;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_nodes_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_nodes = (*incoming_param_nodes_arguments_citer)->get()->get<std::shared_ptr<Bag<uml::ActivityNode>> >();
			//Retrieve input parameter 'edges'
			//parameter 1
			std::shared_ptr<Bag<uml::ActivityEdge>> incoming_param_edges;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_edges_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_edges = (*incoming_param_edges_arguments_citer)->get()->get<std::shared_ptr<Bag<uml::ActivityEdge>> >();
			this->activate(incoming_param_nodes,incoming_param_edges);
			break;
		}
		
		// 1015
		case ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_OPERATION_ADDEDGEINSTANCE_ACTIVITYEDGEINSTANCE:
		{
			//Retrieve input parameter 'instance'
			//parameter 0
			std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> incoming_param_instance;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_instance_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_instance = (*incoming_param_instance_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> >();
			this->addEdgeInstance(incoming_param_instance);
			break;
		}
		
		// 1012
		case ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_OPERATION_ADDNODEACTIVATION_ACTIVITYNODEACTIVATION:
		{
			//Retrieve input parameter 'activation'
			//parameter 0
			std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> incoming_param_activation;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_activation_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_activation = (*incoming_param_activation_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> >();
			this->addNodeActivation(incoming_param_activation);
			break;
		}
		
		// 1006
		case ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_OPERATION_CHECKINCOMINGEDGES_ACTIVITYEDGEINSTANCE_ACTIVITYNODEACTIVATION:
		{
			//Retrieve input parameter 'incomingEdges'
			//parameter 0
			std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> incoming_param_incomingEdges;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_incomingEdges_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_incomingEdges = (*incoming_param_incomingEdges_arguments_citer)->get()->get<std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> >();
			//Retrieve input parameter 'activations'
			//parameter 1
			std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation>> incoming_param_activations;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_activations_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_activations = (*incoming_param_activations_arguments_citer)->get()->get<std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation>> >();
			result = eAny(this->checkIncomingEdges(incoming_param_incomingEdges,incoming_param_activations));
			break;
		}
		
		// 1014
		case ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_OPERATION_CREATEEDGEINSTANCE_ACTIVITYEDGE:
		{
			//Retrieve input parameter 'edges'
			//parameter 0
			std::shared_ptr<Bag<uml::ActivityEdge>> incoming_param_edges;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_edges_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_edges = (*incoming_param_edges_arguments_citer)->get()->get<std::shared_ptr<Bag<uml::ActivityEdge>> >();
			this->createEdgeInstance(incoming_param_edges);
			break;
		}
		
		// 1011
		case ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_OPERATION_CREATENODEACTIVATION_ACTIVITYNODE:
		{
			//Retrieve input parameter 'node'
			//parameter 0
			std::shared_ptr<uml::ActivityNode> incoming_param_node;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_node_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_node = (*incoming_param_node_arguments_citer)->get()->get<std::shared_ptr<uml::ActivityNode> >();
			result = eAny(this->createNodeActivation(incoming_param_node));
			break;
		}
		
		// 1010
		case ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_OPERATION_CREATENODEACTIVATIONS_ACTIVITYNODE:
		{
			//Retrieve input parameter 'nodes'
			//parameter 0
			std::shared_ptr<Bag<uml::ActivityNode>> incoming_param_nodes;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_nodes_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_nodes = (*incoming_param_nodes_arguments_citer)->get()->get<std::shared_ptr<Bag<uml::ActivityNode>> >();
			this->createNodeActivations(incoming_param_nodes);
			break;
		}
		
		// 1013
		case ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_OPERATION_GETNODEACTIVATION_ACTIVITYNODE:
		{
			//Retrieve input parameter 'node'
			//parameter 0
			std::shared_ptr<uml::ActivityNode> incoming_param_node;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_node_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_node = (*incoming_param_node_arguments_citer)->get()->get<std::shared_ptr<uml::ActivityNode> >();
			result = eAny(this->getNodeActivation(incoming_param_node));
			break;
		}
		
		// 1017
		case ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_OPERATION_GETOUTPUTPARAMETERNODEACTIVATIONS:
		{
			result = eAny(this->getOutputParameterNodeActivations());
			break;
		}
		
		// 1021
		case ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_OPERATION_HASSOURCEFOR_ACTIVITYEDGEINSTANCE:
		{
			//Retrieve input parameter 'edgeInstance'
			//parameter 0
			std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> incoming_param_edgeInstance;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_edgeInstance_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_edgeInstance = (*incoming_param_edgeInstance_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> >();
			result = eAny(this->hasSourceFor(incoming_param_edgeInstance));
			break;
		}
		
		// 1020
		case ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_OPERATION_ISSUSPENDED:
		{
			result = eAny(this->isSuspended());
			break;
		}
		
		// 1018
		case ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_OPERATION_RESUME_ACTIVITYNODEACTIVATION:
		{
			//Retrieve input parameter 'activation'
			//parameter 0
			std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> incoming_param_activation;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_activation_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_activation = (*incoming_param_activation_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> >();
			this->resume(incoming_param_activation);
			break;
		}
		
		// 1016
		case ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_OPERATION_RETRIEVEACTIVITYEXECUTION:
		{
			result = eAny(this->retrieveActivityExecution());
			break;
		}
		
		// 1005
		case ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_OPERATION_RUN_ACTIVITYNODEACTIVATION:
		{
			//Retrieve input parameter 'activations'
			//parameter 0
			std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation>> incoming_param_activations;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_activations_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_activations = (*incoming_param_activations_arguments_citer)->get()->get<std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation>> >();
			this->run(incoming_param_activations);
			break;
		}
		
		// 1008
		case ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_OPERATION_RUNNODES_ACTIVITYNODE:
		{
			//Retrieve input parameter 'nodes'
			//parameter 0
			std::shared_ptr<Bag<uml::ActivityNode>> incoming_param_nodes;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_nodes_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_nodes = (*incoming_param_nodes_arguments_citer)->get()->get<std::shared_ptr<Bag<uml::ActivityNode>> >();
			this->runNodes(incoming_param_nodes);
			break;
		}
		
		// 1019
		case ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_OPERATION_SUSPEND_ACTIVITYNODEACTIVATION:
		{
			//Retrieve input parameter 'activation'
			//parameter 0
			std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> incoming_param_activation;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_activation_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_activation = (*incoming_param_activation_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> >();
			this->suspend(incoming_param_activation);
			break;
		}
		
		// 1009
		case ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_OPERATION_TERMINATEALL:
		{
			this->terminateAll();
			break;
		}

		default:
		{
			// call superTypes
			result = ecore::EModelElementImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

//*********************************
// Persistence Functions
//*********************************
void ActivityNodeActivationGroupImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get fUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void ActivityNodeActivationGroupImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("suspendedActivations");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("suspendedActivations")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}

	ecore::EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void ActivityNodeActivationGroupImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("edgeInstances") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ActivityEdgeInstance";
			}
			loadHandler->handleChildContainer<fUML::Semantics::Activities::ActivityEdgeInstance>(this->getEdgeInstances());  

			return; 
		}

		if ( nodeName.compare("nodeActivations") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChildContainer<fUML::Semantics::Activities::ActivityNodeActivation>(this->getNodeActivations());  

			return; 
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}
	//load BasePackage Nodes
}

void ActivityNodeActivationGroupImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_ACTIVITYEXECUTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::Activities::ActivityExecution> _activityExecution = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityExecution>( references.front() );
				setActivityExecution(_activityExecution);
			}
			
			return;
		}

		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_CONTAININGNODEACTIVATION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> _containingNodeActivation = std::dynamic_pointer_cast<fUML::Semantics::Actions::StructuredActivityNodeActivation>( references.front() );
				setContainingNodeActivation(_containingNodeActivation);
			}
			
			return;
		}

		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_SUSPENDEDACTIVATIONS:
		{
			std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation>> _suspendedActivations = getSuspendedActivations();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation>  _r = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivation>(ref);
				if (_r != nullptr)
				{
					_suspendedActivations->push_back(_r);
				}
			}
			return;
		}
	}
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void ActivityNodeActivationGroupImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void ActivityNodeActivationGroupImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Activities::ActivitiesPackage> package = fUML::Semantics::Activities::ActivitiesPackage::eInstance();
	// Add references
		saveHandler->addReferences<fUML::Semantics::Activities::ActivityNodeActivation>("suspendedActivations", this->getSuspendedActivations());
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'edgeInstances'

		saveHandler->addReferences<fUML::Semantics::Activities::ActivityEdgeInstance>("edgeInstances", this->getEdgeInstances());

		// Save 'nodeActivations'

		saveHandler->addReferences<fUML::Semantics::Activities::ActivityNodeActivation>("nodeActivations", this->getNodeActivations());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

