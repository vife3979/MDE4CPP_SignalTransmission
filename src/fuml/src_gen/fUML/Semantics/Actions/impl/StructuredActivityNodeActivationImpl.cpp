
#include "fUML/Semantics/Actions/impl/StructuredActivityNodeActivationImpl.hpp"
#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
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

#include "abstractDataTypes/Subset.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Includes from codegen annotation
#include "fUML/fUMLFactory.hpp"
#include "fUML/Semantics/Activities/ObjectToken.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "uml/StructuredActivityNode.hpp"
#include "uml/Action.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/InputPin.hpp"
#include "uml/OutputPin.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "fUML/Semantics/Actions/ActionsFactory.hpp"
#include "uml/umlFactory.hpp"
#include "uml/Action.hpp"
#include "fUML/Semantics/Actions/ActionActivation.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivation.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "uml/ExecutableNode.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "uml/OutputPin.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
//Factories and Package includes
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
StructuredActivityNodeActivationImpl::StructuredActivityNodeActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

StructuredActivityNodeActivationImpl::~StructuredActivityNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete StructuredActivityNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
StructuredActivityNodeActivationImpl::StructuredActivityNodeActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:StructuredActivityNodeActivationImpl()
{
	m_group = par_group;
}

StructuredActivityNodeActivationImpl::StructuredActivityNodeActivationImpl(const StructuredActivityNodeActivationImpl & obj): StructuredActivityNodeActivationImpl()
{
	*this = obj;
}

StructuredActivityNodeActivationImpl& StructuredActivityNodeActivationImpl::operator=(const StructuredActivityNodeActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	ActionActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of StructuredActivityNodeActivation 
	 * which is generated by the compiler (as StructuredActivityNodeActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//StructuredActivityNodeActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy StructuredActivityNodeActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'activationGroup'
	if(obj.getActivationGroup()!=nullptr)
	{
		m_activationGroup = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(obj.getActivationGroup()->copy());
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> StructuredActivityNodeActivationImpl::copy() const
{
	std::shared_ptr<StructuredActivityNodeActivationImpl> element(new StructuredActivityNodeActivationImpl());
	*element =(*this);
	element->setThisStructuredActivityNodeActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> StructuredActivityNodeActivationImpl::completeAction()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > incomingTokens(new Bag<fUML::Semantics::Activities::Token>());
    if (!this->isSuspended()) 
    {
        incomingTokens = fUML::Semantics::Actions::ActionActivationImpl::completeAction();
    }
    return incomingTokens;
	//end of body
}

void StructuredActivityNodeActivationImpl::createEdgeInstances()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<uml::ActivityEdge> > edges = (std::dynamic_pointer_cast<uml::StructuredActivityNode> (this->getNode()))->getEdge();
	this->getActivationGroup()->createEdgeInstance(edges);
	//end of body
}

void StructuredActivityNodeActivationImpl::createNodeActivations()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	fUML::Semantics::Actions::ActionActivationImpl::createNodeActivations();

	this->setActivationGroup(std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup>(fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createActivityNodeActivationGroup()));
	this->getActivationGroup()->setContainingNodeActivation(getThisStructuredActivityNodeActivationPtr());

	std::shared_ptr<uml::StructuredActivityNode> structuredActivityNode = std::dynamic_pointer_cast<uml::StructuredActivityNode> (this->getNode());
	std::shared_ptr<Bag<uml::ActivityNode> > nodes = structuredActivityNode->getNode();
	this->getActivationGroup()->createNodeActivations(nodes);
	//end of body
}

void StructuredActivityNodeActivationImpl::doAction()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	if ((std::dynamic_pointer_cast<uml::StructuredActivityNode>(this->getNode()))->getMustIsolate()) 
	{
        _beginIsolation();
        this->doStructuredActivity();
        _endIsolation();
    }
	else 
	{
        this->doStructuredActivity();
    }
	//end of body
}

void StructuredActivityNodeActivationImpl::doStructuredActivity()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	//Remark: action is not used in the specification.
	std::shared_ptr<uml::Action> action = std::dynamic_pointer_cast<uml::Action>(this->getNode());
    assert(action != nullptr);

    // *** Concurrently send offers from all input pins. ***
    std::shared_ptr<Bag<uml::InputPin> > inputPins = nullptr;//action->input;
    std::vector<std::shared_ptr<uml::InputPin>>::iterator i;

    for (i = inputPins->begin(); i!= inputPins->end();++i)
    {
    	std::shared_ptr<uml::InputPin> inputPin = std::dynamic_pointer_cast<uml::InputPin> (*i);
    	std::shared_ptr<fUML::Semantics::Actions::PinActivation> pinActivation = this->retrievePinActivation(inputPin);
        pinActivation->sendUnofferedTokens();
    }

    std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation> > nodes = this->getActivationGroup()->getNodeActivations();
    this->getActivationGroup()->run(nodes);
	//end of body
}

std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> StructuredActivityNodeActivationImpl::getNodeActivation(std::shared_ptr<uml::ActivityNode> node)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> thisActivation = fUML::Semantics::Actions::ActionActivationImpl::getNodeActivation(node);

	std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> activation = nullptr;
    if (thisActivation != nullptr) 
    {
        activation = thisActivation;
    }
    else if (this->getActivationGroup() != nullptr)
    {
        activation = this->getActivationGroup()->getNodeActivation(node);
    }

    return activation;
	//end of body
}

std::shared_ptr<Bag<Any>> StructuredActivityNodeActivationImpl::getPinValues(std::shared_ptr<uml::OutputPin> pin)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<fUML::Semantics::Actions::PinActivation> pinActivation = std::dynamic_pointer_cast<fUML::Semantics::Actions::PinActivation>(this->getActivationGroup()->getNodeActivation(pin));
	std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> tokens = pinActivation->getTokens();

	std::shared_ptr<Bag<Any>> values(new Bag<Any>());
    for (unsigned int i = 0; i < tokens->size(); i++) 
    {
    	std::shared_ptr<fUML::Semantics::Activities::Token> token = tokens->at(i);
    	std::shared_ptr<Any> value = token->getValue();
        if (value != nullptr) 
        {
            values->push_back(value);
        }
    }

    return values;
	//end of body
}

bool StructuredActivityNodeActivationImpl::isSourceFor(std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> edgeInstance)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    bool isSource = fUML::Semantics::Actions::ActionActivationImpl::isSourceFor(edgeInstance);
    if (!isSource) {
        isSource = this->getActivationGroup()->hasSourceFor(edgeInstance);
    }
    return isSource;
	//end of body
}

bool StructuredActivityNodeActivationImpl::isSuspended()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    return this->getActivationGroup()->isSuspended();
	//end of body
}

std::shared_ptr<Bag<uml::ActivityNode>> StructuredActivityNodeActivationImpl::makeActivityNodeList(std::shared_ptr<Bag<uml::ExecutableNode>> nodes)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<uml::ActivityNode> > activityNodes(new Bag<uml::ActivityNode>());

    for (unsigned int i = 0; i < nodes->size(); i++) 
    {
    	std::shared_ptr<uml::ActivityNode> node = nodes->at(i);
        activityNodes->push_back(node);
        std::shared_ptr<uml::Action> action = std::dynamic_pointer_cast<uml::Action>(node);
        if (action != nullptr) 
        {
        	std::shared_ptr<Bag<uml::InputPin> > inputPins = action->getInput();//was: nullptr;
            for (unsigned int j = 0; j < inputPins->size(); j++) 
            {
            	std::shared_ptr<uml::InputPin> inputPin = inputPins->at(j);
                activityNodes->push_back(inputPin);
            }

            std::shared_ptr<Bag<uml::OutputPin> > outputPins = action->getOutput();//was: nullptr;
            for (unsigned int j = 0; j < outputPins->size(); j++) 
            {
            	std::shared_ptr<uml::OutputPin> outputPin = outputPins->at(j);
                activityNodes->push_back(std::dynamic_pointer_cast<uml::ActivityNode>(outputPin));
            }
        }
    }

    return activityNodes;
	//end of body
}

void StructuredActivityNodeActivationImpl::putPinValues(std::shared_ptr<uml::OutputPin> pin, std::shared_ptr<Bag<Any>> values)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<fUML::Semantics::Actions::PinActivation> pinActivation = std::dynamic_pointer_cast<fUML::Semantics::Actions::PinActivation>(this->getActivationGroup()->getNodeActivation(std::dynamic_pointer_cast<uml::ActivityNode>(pin)));

    for (unsigned int i = 0; i < values->size(); i++) 
    {
    	std::shared_ptr<Any> value = values->at(i);
    	std::shared_ptr<fUML::Semantics::Activities::ObjectToken> token = fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createObjectToken();
        token->setValue(value);
        pinActivation->addToken(token);
    }
	//end of body
}

void StructuredActivityNodeActivationImpl::resume()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > incomingTokens = fUML::Semantics::Actions::ActionActivationImpl::completeAction();
    if (incomingTokens->size() > 0) 
    {
        this->fire(incomingTokens);
    }
    if (!this->isSuspended()) 
    {
        fUML::Semantics::Actions::ActionActivationImpl::resume();
    }
	//end of body
}

void StructuredActivityNodeActivationImpl::terminate()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    this->terminateAll();
    fUML::Semantics::Actions::ActionActivationImpl::terminate();
	//end of body
}

void StructuredActivityNodeActivationImpl::terminateAll()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    this->getActivationGroup()->terminateAll();
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference activationGroup */
std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> StructuredActivityNodeActivationImpl::getActivationGroup() const
{
    return m_activationGroup;
}
void StructuredActivityNodeActivationImpl::setActivationGroup(std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> _activationGroup)
{
    m_activationGroup = _activationGroup;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> StructuredActivityNodeActivationImpl::eContainer() const
{
	if(auto wp = m_group.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void StructuredActivityNodeActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void StructuredActivityNodeActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void StructuredActivityNodeActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("activationGroup") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ActivityNodeActivationGroup";
			}
			loadHandler->handleChild(this->getActivationGroup()); 

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
	ActionActivationImpl::loadNode(nodeName, loadHandler);
}

void StructuredActivityNodeActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ActionActivationImpl::resolveReferences(featureID, references);
}

void StructuredActivityNodeActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void StructuredActivityNodeActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'activationGroup'

		saveHandler->addReference(this->getActivationGroup(), "activationGroup", getActivationGroup()->eClass() != fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityNodeActivationGroup_Class());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> StructuredActivityNodeActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getStructuredActivityNodeActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> StructuredActivityNodeActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::STRUCTUREDACTIVITYNODEACTIVATION_ATTRIBUTE_ACTIVATIONGROUP:
			return eAny(getActivationGroup(),fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_CLASS,false); //11111
	}
	return ActionActivationImpl::eGet(featureID, resolve, coreType);
}

bool StructuredActivityNodeActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::STRUCTUREDACTIVITYNODEACTIVATION_ATTRIBUTE_ACTIVATIONGROUP:
			return getActivationGroup() != nullptr; //11111
	}
	return ActionActivationImpl::internalEIsSet(featureID);
}

bool StructuredActivityNodeActivationImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::STRUCTUREDACTIVITYNODEACTIVATION_ATTRIBUTE_ACTIVATIONGROUP:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> _activationGroup = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(eObject);
					if(_activationGroup)
					{
						setActivationGroup(_activationGroup); //11111
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'activationGroup'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'activationGroup'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return ActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> StructuredActivityNodeActivationImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Actions::StructuredActivityNodeActivation::completeAction() : fUML::Semantics::Activities::Token[*]: 3878860807
		case ActionsPackage::STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_COMPLETEACTION:
		{
			std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> resultList = this->completeAction();
			return eEcoreContainerAny(resultList,fUML::Semantics::Activities::ActivitiesPackage::TOKEN_CLASS);
			break;
		}
		// fUML::Semantics::Actions::StructuredActivityNodeActivation::createEdgeInstances(): 4189320520
		case ActionsPackage::STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_CREATEEDGEINSTANCES:
		{
			this->createEdgeInstances();
			break;
		}
		// fUML::Semantics::Actions::StructuredActivityNodeActivation::createNodeActivations(): 3493676622
		case ActionsPackage::STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_CREATENODEACTIVATIONS:
		{
			this->createNodeActivations();
			break;
		}
		// fUML::Semantics::Actions::StructuredActivityNodeActivation::doAction(): 3506173856
		case ActionsPackage::STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_DOACTION:
		{
			this->doAction();
			break;
		}
		// fUML::Semantics::Actions::StructuredActivityNodeActivation::doStructuredActivity(): 1244905776
		case ActionsPackage::STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_DOSTRUCTUREDACTIVITY:
		{
			this->doStructuredActivity();
			break;
		}
		// fUML::Semantics::Actions::StructuredActivityNodeActivation::getNodeActivation(uml::ActivityNode) : fUML::Semantics::Activities::ActivityNodeActivation: 935616927
		case ActionsPackage::STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_GETNODEACTIVATION_ACTIVITYNODE:
		{
			//Retrieve input parameter 'node'
			//parameter 0
			std::shared_ptr<uml::ActivityNode> incoming_param_node;
			Bag<Any>::const_iterator incoming_param_node_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_node_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_node = std::dynamic_pointer_cast<uml::ActivityNode>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'node'. Failed to invoke operation 'getNodeActivation'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'node'. Failed to invoke operation 'getNodeActivation'!")
					return nullptr;
				}
			}
		
			result = eEcoreAny(this->getNodeActivation(incoming_param_node), fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATION_CLASS);
			break;
		}
		// fUML::Semantics::Actions::StructuredActivityNodeActivation::getPinValues(uml::OutputPin) : Any[*]: 418079140
		case ActionsPackage::STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_GETPINVALUES_OUTPUTPIN:
		{
			//Retrieve input parameter 'pin'
			//parameter 0
			std::shared_ptr<uml::OutputPin> incoming_param_pin;
			Bag<Any>::const_iterator incoming_param_pin_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_pin_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_pin = std::dynamic_pointer_cast<uml::OutputPin>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'pin'. Failed to invoke operation 'getPinValues'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'pin'. Failed to invoke operation 'getPinValues'!")
					return nullptr;
				}
			}
		
			result = eAny(this->getPinValues(incoming_param_pin), 0, true);
			break;
		}
		// fUML::Semantics::Actions::StructuredActivityNodeActivation::isSourceFor(fUML::Semantics::Activities::ActivityEdgeInstance) : bool: 3281612984
		case ActionsPackage::STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_ISSOURCEFOR_ACTIVITYEDGEINSTANCE:
		{
			//Retrieve input parameter 'edgeInstance'
			//parameter 0
			std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> incoming_param_edgeInstance;
			Bag<Any>::const_iterator incoming_param_edgeInstance_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_edgeInstance_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_edgeInstance = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityEdgeInstance>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'edgeInstance'. Failed to invoke operation 'isSourceFor'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'edgeInstance'. Failed to invoke operation 'isSourceFor'!")
					return nullptr;
				}
			}
		
			result = eAny(this->isSourceFor(incoming_param_edgeInstance), 0, false);
			break;
		}
		// fUML::Semantics::Actions::StructuredActivityNodeActivation::isSuspended() : bool: 3925255716
		case ActionsPackage::STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_ISSUSPENDED:
		{
			result = eAny(this->isSuspended(), 0, false);
			break;
		}
		// fUML::Semantics::Actions::StructuredActivityNodeActivation::makeActivityNodeList(uml::ExecutableNode[*]) : uml::ActivityNode[*]: 854326129
		case ActionsPackage::STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_MAKEACTIVITYNODELIST_EXECUTABLENODE:
		{
			//Retrieve input parameter 'nodes'
			//parameter 0
			std::shared_ptr<Bag<uml::ExecutableNode>> incoming_param_nodes;
			Bag<Any>::const_iterator incoming_param_nodes_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>((*incoming_param_nodes_arguments_citer));
				if(ecoreContainerAny)
				{
					try
					{
						std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
				
						if(eObjectList)
						{
							incoming_param_nodes.reset();
							for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
							{
								std::shared_ptr<uml::ExecutableNode> _temp = std::dynamic_pointer_cast<uml::ExecutableNode>(anEObject);
								incoming_param_nodes->add(_temp);
							}
						}
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreContainerAny' for parameter 'nodes'. Failed to invoke operation 'makeActivityNodeList'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreContainerAny' for parameter 'nodes'. Failed to invoke operation 'makeActivityNodeList'!")
					return nullptr;
				}
			}
		
			std::shared_ptr<Bag<uml::ActivityNode>> resultList = this->makeActivityNodeList(incoming_param_nodes);
			return eEcoreContainerAny(resultList,uml::umlPackage::ACTIVITYNODE_CLASS);
			break;
		}
		// fUML::Semantics::Actions::StructuredActivityNodeActivation::putPinValues(uml::OutputPin, Any[*]): 362386455
		case ActionsPackage::STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_PUTPINVALUES_OUTPUTPIN_EJAVAOBJECT:
		{
			//Retrieve input parameter 'pin'
			//parameter 0
			std::shared_ptr<uml::OutputPin> incoming_param_pin;
			Bag<Any>::const_iterator incoming_param_pin_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_pin_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_pin = std::dynamic_pointer_cast<uml::OutputPin>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'pin'. Failed to invoke operation 'putPinValues'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'pin'. Failed to invoke operation 'putPinValues'!")
					return nullptr;
				}
			}
		
			//Retrieve input parameter 'values'
			//parameter 1
			std::shared_ptr<Bag<Any>> incoming_param_values;
			Bag<Any>::const_iterator incoming_param_values_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_values = (*incoming_param_values_arguments_citer)->get<std::shared_ptr<Bag<Any>>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'values'. Failed to invoke operation 'putPinValues'!")
				return nullptr;
			}
		
			this->putPinValues(incoming_param_pin,incoming_param_values);
			break;
		}
		// fUML::Semantics::Actions::StructuredActivityNodeActivation::resume(): 568722472
		case ActionsPackage::STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_RESUME:
		{
			this->resume();
			break;
		}
		// fUML::Semantics::Actions::StructuredActivityNodeActivation::terminate(): 2956351072
		case ActionsPackage::STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_TERMINATE:
		{
			this->terminate();
			break;
		}
		// fUML::Semantics::Actions::StructuredActivityNodeActivation::terminateAll(): 188036217
		case ActionsPackage::STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_TERMINATEALL:
		{
			this->terminateAll();
			break;
		}

		default:
		{
			// call superTypes
			result = ActionActivationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> StructuredActivityNodeActivationImpl::getThisStructuredActivityNodeActivationPtr() const
{
	return m_thisStructuredActivityNodeActivationPtr.lock();
}
void StructuredActivityNodeActivationImpl::setThisStructuredActivityNodeActivationPtr(std::weak_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> thisStructuredActivityNodeActivationPtr)
{
	m_thisStructuredActivityNodeActivationPtr = thisStructuredActivityNodeActivationPtr;
	setThisActionActivationPtr(thisStructuredActivityNodeActivationPtr);
}


