
#include "fUML/Semantics/Activities/impl/DecisionNodeActivationImpl.hpp"
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


#include "abstractDataTypes/AnyEObject.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Includes from codegen annotation
#include "abstractDataTypes/Subset.hpp"
#include "fUML/Semantics/Loci/Executor.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/Activities/ObjectToken.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "uml/ActivityEdge.hpp"
#include "uml/Behavior.hpp"
#include "uml/DecisionNode.hpp"
#include "uml/ObjectFlow.hpp"
#include "uml/Parameter.hpp"
#include "uml/ParameterDirectionKind.hpp"
#include "uml/umlFactory.hpp"
#include "uml/ValueSpecification.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Activities/ControlNodeActivation.hpp"
#include "uml/DecisionNode.hpp"
#include "fUML/Semantics/CommonBehavior/Execution.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "uml/ValueSpecification.hpp"
//Factories and Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::Activities;

//*********************************
// Constructor / Destructor
//*********************************
DecisionNodeActivationImpl::DecisionNodeActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

DecisionNodeActivationImpl::~DecisionNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DecisionNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
DecisionNodeActivationImpl::DecisionNodeActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:DecisionNodeActivationImpl()
{
	m_group = par_group;
}

DecisionNodeActivationImpl::DecisionNodeActivationImpl(const DecisionNodeActivationImpl & obj): DecisionNodeActivationImpl()
{
	*this = obj;
}

DecisionNodeActivationImpl& DecisionNodeActivationImpl::operator=(const DecisionNodeActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	ControlNodeActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of DecisionNodeActivation 
	 * which is generated by the compiler (as DecisionNodeActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//DecisionNodeActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DecisionNodeActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_decisionNode  = obj.getDecisionNode();
	//Clone references with containment (deep copy)
	//clone reference 'decisionInputExecution'
	if(obj.getDecisionInputExecution()!=nullptr)
	{
		m_decisionInputExecution = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::Execution>(obj.getDecisionInputExecution()->copy());
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> DecisionNodeActivationImpl::copy() const
{
	std::shared_ptr<DecisionNodeActivationImpl> element(new DecisionNodeActivationImpl());
	*element =(*this);
	element->setThisDecisionNodeActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Values::Value> DecisionNodeActivationImpl::executeDecisionInputBehavior(std::shared_ptr<fUML::Semantics::Values::Value> inputValue,std::shared_ptr<fUML::Semantics::Values::Value> decisionInputValue)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<uml::DecisionNode> decisionNode = this->getDecisionNode();
	std::shared_ptr<uml::Behavior> decisionInputBehavior = nullptr;

    if(decisionNode != nullptr)
    {
        decisionInputBehavior = decisionNode->getDecisionInput();
    }

    std::shared_ptr<fUML::Semantics::Values::Value> decisionInputResult = nullptr;

    if (decisionInputBehavior == nullptr)
    {
        if (decisionInputValue != nullptr)
        {
            decisionInputResult = decisionInputValue;
        }
        else
        {
            decisionInputResult = inputValue;
        }
    }
    else
    {
        this->setDecisionInputExecution(this->getExecutionLocus()->getFactory()->createExecution(decisionInputBehavior,this->getExecutionContext()));

        unsigned int i = 0;
        unsigned int j = 0;
        while (((j == 0) || ((j == 1) && (decisionInputValue != nullptr)))
               && (i < decisionInputBehavior->getOwnedParameter()->size()))
        {
        	std::shared_ptr<uml::Parameter> parameter = decisionInputBehavior->getOwnedParameter()->at(i);
            if (parameter->getDirection() == uml::ParameterDirectionKind::IN
                    || parameter->getDirection() == uml::ParameterDirectionKind::INOUT)
            {
            	std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> inputParameterValue(fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createParameterValue());
                inputParameterValue->setParameter(parameter);

                j = j + 1;
                if (j == 1 && inputValue != nullptr)
                {
                    inputParameterValue->getValues()->push_back(inputValue);
                }
                else
                {
                    inputParameterValue->getValues()->push_back(decisionInputValue);
                }

                this->getDecisionInputExecution()->setParameterValue(inputParameterValue);
            }
            i = i + 1;
        }
        this->getDecisionInputExecution()->execute();

        std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> > outputParameterValues = this->getDecisionInputExecution()->getOutputParameterValues();
        this->getDecisionInputExecution()->destroy();

        decisionInputResult = outputParameterValues->at(0)->getValues()->at(0);
    }

    return decisionInputResult;
	//end of body
}

void DecisionNodeActivationImpl::fire(std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incomingTokens)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	DEBUG_MESSAGE(std::cout<<"[fire] Decision node " << this->getNode()->getName() << "..."<<std::endl;)

	std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > removedControlTokens = this->removeJoinedControlTokens(incomingTokens);
	std::shared_ptr<Bag<fUML::Semantics::Values::Value> > decisionValues = this->getDecisionValues(incomingTokens);
	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance> > outgoingEdges = this->getOutgoingEdges();

    for (unsigned int i = 0; i < outgoingEdges->size(); i++) 
    {
    	std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> edgeInstance = outgoingEdges->at(i);
    	std::shared_ptr<uml::ValueSpecification> guard = edgeInstance->getEdge()->getGuard();

    	std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > offeredTokens(new Bag<fUML::Semantics::Activities::Token>());
        for (unsigned int j = 0; j < incomingTokens->size(); j++) 
        {
        	std::shared_ptr<fUML::Semantics::Activities::Token> incomingToken = incomingTokens->at(j);
        	std::shared_ptr<fUML::Semantics::Values::Value> decisionValue = decisionValues->at(j);
            if (this->test(guard, decisionValue)) 
            {
                offeredTokens->push_back(incomingToken);
            }
        }

        if (offeredTokens->size() > 0) 
        {
            for (unsigned int j = 0; j < removedControlTokens->size(); j++) 
            {
            	std::shared_ptr<fUML::Semantics::Activities::Token> removedControlToken = removedControlTokens->at(j);
                offeredTokens->push_back(removedControlToken);
            }
            edgeInstance->sendOffer(offeredTokens);
        }
    }
	//end of body
}

std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> DecisionNodeActivationImpl::getDecisionInputFlowInstance()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<uml::ActivityEdge>  decisionInputFlow = this->getDecisionNode()->getDecisionInputFlow();

	std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> edgeInstance = nullptr;
    if (decisionInputFlow != nullptr) 
    {
        unsigned int i = 0;
        while ((edgeInstance == nullptr) && (i < this->getIncomingEdges()->size())) 
        {
        	std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> incomingEdge = this->getIncomingEdges()->at(i);
            if (incomingEdge->getEdge() == decisionInputFlow) 
            {
                edgeInstance = incomingEdge;
            }
            i = i + 1;
        }
    }

    return edgeInstance;
	//end of body
}

std::shared_ptr<fUML::Semantics::Values::Value> DecisionNodeActivationImpl::getDecisionInputFlowValue()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> decisionInputFlowInstance = this->getDecisionInputFlowInstance();

	std::shared_ptr<fUML::Semantics::Values::Value> value = nullptr;
    if (decisionInputFlowInstance != nullptr) 
    {
    	std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > tokens = decisionInputFlowInstance->takeOfferedTokens();
        if (tokens->size() > 0) 
        {
            value = tokens->at(0)->getValue();
        }
    }

    return value;
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::Values::Value> > DecisionNodeActivationImpl::getDecisionValues(std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incomingTokens)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<fUML::Semantics::Values::Value> decisionInputValue = this->getDecisionInputFlowValue();

	std::shared_ptr<Bag<fUML::Semantics::Values::Value> > decisionValues(new Bag<fUML::Semantics::Values::Value>());

    for (unsigned int i = 0; i < incomingTokens->size(); i++) 
    {
    	std::shared_ptr<fUML::Semantics::Activities::Token> incomingToken = incomingTokens->at(i);
    	std::shared_ptr<fUML::Semantics::Values::Value> value = this->executeDecisionInputBehavior(incomingToken->getValue(), decisionInputValue);
        decisionValues->push_back(value);
    }

    DEBUG_MESSAGE(
		for (unsigned int i = 0; i < decisionValues->size(); i++)
		{
			std::shared_ptr<fUML::Semantics::Values::Value> decisionValue = decisionValues->at(i);
			if (decisionValue)
			{
				std::cout<<"[getDecisionValues] decisionValues[" << i << "] = "
				   << decisionValue->toString()<<std::endl;
			}
			else
			{
				std::cout<<"[getDecisionValues] decisionValues[" << i << "] = nullptr" << std::endl;
			}
		}
    )

    return decisionValues;
	//end of body
}

bool DecisionNodeActivationImpl::hasObjectFlowInput()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<uml::ActivityEdge> decisionInputFlow = this->getDecisionNode()->getDecisionInputFlow();

    bool isObjectFlow = false;
    unsigned int i = 0;
    while (!isObjectFlow && i < this->getIncomingEdges()->size()) 
    {
    	std::shared_ptr<uml::ActivityEdge> edge = this->getIncomingEdges()->at(i)->getEdge();
        isObjectFlow = (edge != decisionInputFlow) && (std::dynamic_pointer_cast<uml::ObjectFlow>(edge) != nullptr);
        i = i + 1;
    }
    return isObjectFlow;
	//end of body
}

bool DecisionNodeActivationImpl::isReady()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	unsigned int i = 0;
    bool ready = true;
    DEBUG_MESSAGE(std::cout<< "INCOMING EDGE SIZE:"<< this->getIncomingEdges()->size()<<std::endl;)
    while (ready && (i < this->getIncomingEdges()->size())) {
        ready = this->getIncomingEdges()->at(i)->hasOffer();
        i = i + 1;
    }
    DEBUG_MESSAGE(std::cout<< "READY:"<< ready<<std::endl;)
    return ready;
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > DecisionNodeActivationImpl::removeJoinedControlTokens(std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incomingTokens)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > removedControlTokens(new Bag<fUML::Semantics::Activities::Token>());

    if (this->hasObjectFlowInput()) 
    {
        unsigned int i = 0;
        while (i < incomingTokens->size()) 
        {
        	std::shared_ptr<fUML::Semantics::Activities::Token> token = incomingTokens->at(i);
            if (token->isControl()) 
            {
                removedControlTokens->push_back(token);
                incomingTokens->erase(incomingTokens->begin()+i);
                i = i - 1;
            }
            i = i + 1;
        }
    }

    return removedControlTokens;
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > DecisionNodeActivationImpl::takeOfferedTokens()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::ObjectFlow> decisionInputFlow = this->getDecisionNode()->getDecisionInputFlow();

	std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > allTokens(new Bag<fUML::Semantics::Activities::Token>());
	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance> > incomingEdges = this->getIncomingEdges();
    for (unsigned int i = 0; i < incomingEdges->size(); i++) 
    {
    	std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> edgeInstance = incomingEdges->at(i);
        if (edgeInstance->getEdge() != decisionInputFlow) 
        {
        	std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > tokens = edgeInstance->takeOfferedTokens();
            for (unsigned int j = 0; j < tokens->size(); j++)
            {
                allTokens->push_back(tokens->at(j));
            }
        }
    }

    return allTokens;
	//end of body
}

void DecisionNodeActivationImpl::terminate()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    if (this->getDecisionInputExecution() != nullptr) {
        this->getDecisionInputExecution()->terminate();
    }

    fUML::Semantics::Activities::ControlNodeActivationImpl::terminate();
	//end of body
}

bool DecisionNodeActivationImpl::test(std::shared_ptr<uml::ValueSpecification> gaurd,std::shared_ptr<fUML::Semantics::Values::Value> value)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	bool guardResult = true;
    if (gaurd != nullptr) 
    {
    	std::shared_ptr<fUML::Semantics::Values::Value> guardValue = this->getExecutionLocus()->getExecutor()->evaluate(gaurd);
        guardResult = guardValue->equals(value);
    }
    return guardResult;
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference decisionInputExecution */
std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> DecisionNodeActivationImpl::getDecisionInputExecution() const
{
    return m_decisionInputExecution;
}
void DecisionNodeActivationImpl::setDecisionInputExecution(std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> _decisionInputExecution)
{
    m_decisionInputExecution = _decisionInputExecution;
	
}

/* Getter & Setter for reference decisionNode */
std::shared_ptr<uml::DecisionNode> DecisionNodeActivationImpl::getDecisionNode() const
{
    return m_decisionNode;
}
void DecisionNodeActivationImpl::setDecisionNode(std::shared_ptr<uml::DecisionNode> _decisionNode)
{
    m_decisionNode = _decisionNode;
	//additional setter call for redefined reference ActivityNodeActivation::node
	fUML::Semantics::Activities::ActivityNodeActivationImpl::setNode(_decisionNode);
}
/*Additional Setter for redefined reference 'ActivityNodeActivation::node'*/
void DecisionNodeActivationImpl::setNode(std::shared_ptr<uml::ActivityNode> _node)
{
	std::shared_ptr<uml::DecisionNode> _decisionNode = std::dynamic_pointer_cast<uml::DecisionNode>(_node);
	if(_decisionNode)
	{
		m_decisionNode = _decisionNode;

		//additional setter call for redefined reference ActivityNodeActivation::node
		fUML::Semantics::Activities::ActivityNodeActivationImpl::setNode(_decisionNode);
	}
	else
	{
		std::cerr<<"[DecisionNodeActivation::setNode] : Could not set node because provided node was not of type 'std::shared_ptr<uml::DecisionNode>'"<<std::endl;
	}
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> DecisionNodeActivationImpl::eContainer() const
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
void DecisionNodeActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void DecisionNodeActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("decisionNode");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("decisionNode")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ControlNodeActivationImpl::loadAttributes(loadHandler, attr_list);
}

void DecisionNodeActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("decisionInputExecution") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChild(this->getDecisionInputExecution()); 

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
	ControlNodeActivationImpl::loadNode(nodeName, loadHandler);
}

void DecisionNodeActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::DECISIONNODEACTIVATION_ATTRIBUTE_DECISIONNODE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::DecisionNode> _decisionNode = std::dynamic_pointer_cast<uml::DecisionNode>( references.front() );
				setDecisionNode(_decisionNode);
			}
			
			return;
		}
	}
	ControlNodeActivationImpl::resolveReferences(featureID, references);
}

void DecisionNodeActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ControlNodeActivationImpl::saveContent(saveHandler);
	
	ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void DecisionNodeActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Activities::ActivitiesPackage> package = fUML::Semantics::Activities::ActivitiesPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getDecisionNode(), "decisionNode", getDecisionNode()->eClass() != uml::umlPackage::eInstance()->getDecisionNode_Class()); 
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'decisionInputExecution'

		saveHandler->addReference(this->getDecisionInputExecution(), "decisionInputExecution", getDecisionInputExecution()->eClass() != fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> DecisionNodeActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getDecisionNodeActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any DecisionNodeActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::DECISIONNODEACTIVATION_ATTRIBUTE_DECISIONINPUTEXECUTION:
			return eAny(getDecisionInputExecution(),fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_CLASS,false); //376
		case fUML::Semantics::Activities::ActivitiesPackage::DECISIONNODEACTIVATION_ATTRIBUTE_DECISIONNODE:
			return eAny(getDecisionNode(),uml::umlPackage::DECISIONNODE_CLASS,false); //377
	}
	return ControlNodeActivationImpl::eGet(featureID, resolve, coreType);
}

bool DecisionNodeActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::DECISIONNODEACTIVATION_ATTRIBUTE_DECISIONINPUTEXECUTION:
			return getDecisionInputExecution() != nullptr; //376
		case fUML::Semantics::Activities::ActivitiesPackage::DECISIONNODEACTIVATION_ATTRIBUTE_DECISIONNODE:
			return getDecisionNode() != nullptr; //377
	}
	return ControlNodeActivationImpl::internalEIsSet(featureID);
}

bool DecisionNodeActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::DECISIONNODEACTIVATION_ATTRIBUTE_DECISIONINPUTEXECUTION:
		{
			// CAST Any to fUML::Semantics::CommonBehavior::Execution
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> _decisionInputExecution = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::Execution>(_temp);
			setDecisionInputExecution(_decisionInputExecution); //376
			return true;
		}
		case fUML::Semantics::Activities::ActivitiesPackage::DECISIONNODEACTIVATION_ATTRIBUTE_DECISIONNODE:
		{
			// CAST Any to uml::DecisionNode
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::DecisionNode> _decisionNode = std::dynamic_pointer_cast<uml::DecisionNode>(_temp);
			setDecisionNode(_decisionNode); //377
			return true;
		}
	}

	return ControlNodeActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any DecisionNodeActivationImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Activities::DecisionNodeActivation::executeDecisionInputBehavior(fUML::Semantics::Values::Value, fUML::Semantics::Values::Value) : fUML::Semantics::Values::Value: 1497497786
		case ActivitiesPackage::DECISIONNODEACTIVATION_OPERATION_EXECUTEDECISIONINPUTBEHAVIOR_VALUE_VALUE:
		{
			//Retrieve input parameter 'inputValue'
			//parameter 0
			std::shared_ptr<fUML::Semantics::Values::Value> incoming_param_inputValue;
			std::list<Any>::const_iterator incoming_param_inputValue_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_inputValue = (*incoming_param_inputValue_arguments_citer)->get<std::shared_ptr<fUML::Semantics::Values::Value> >();
			//Retrieve input parameter 'decisionInputValue'
			//parameter 1
			std::shared_ptr<fUML::Semantics::Values::Value> incoming_param_decisionInputValue;
			std::list<Any>::const_iterator incoming_param_decisionInputValue_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_decisionInputValue = (*incoming_param_decisionInputValue_arguments_citer)->get<std::shared_ptr<fUML::Semantics::Values::Value> >();
			result = eAnyObject(this->executeDecisionInputBehavior(incoming_param_inputValue,incoming_param_decisionInputValue), fUML::Semantics::Values::ValuesPackage::VALUE_CLASS);
			break;
		}
		// fUML::Semantics::Activities::DecisionNodeActivation::fire(fUML::Semantics::Activities::Token[*]): 4127070096
		case ActivitiesPackage::DECISIONNODEACTIVATION_OPERATION_FIRE_TOKEN:
		{
			//Retrieve input parameter 'incomingTokens'
			//parameter 0
			std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incoming_param_incomingTokens;
			std::list<Any>::const_iterator incoming_param_incomingTokens_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_incomingTokens = (*incoming_param_incomingTokens_arguments_citer)->get<std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> >();
			this->fire(incoming_param_incomingTokens);
			break;
		}
		// fUML::Semantics::Activities::DecisionNodeActivation::getDecisionInputFlowInstance() : fUML::Semantics::Activities::ActivityEdgeInstance: 589400247
		case ActivitiesPackage::DECISIONNODEACTIVATION_OPERATION_GETDECISIONINPUTFLOWINSTANCE:
		{
			result = eAnyObject(this->getDecisionInputFlowInstance(), fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEDGEINSTANCE_CLASS);
			break;
		}
		// fUML::Semantics::Activities::DecisionNodeActivation::getDecisionInputFlowValue() : fUML::Semantics::Values::Value: 15068892
		case ActivitiesPackage::DECISIONNODEACTIVATION_OPERATION_GETDECISIONINPUTFLOWVALUE:
		{
			result = eAnyObject(this->getDecisionInputFlowValue(), fUML::Semantics::Values::ValuesPackage::VALUE_CLASS);
			break;
		}
		// fUML::Semantics::Activities::DecisionNodeActivation::getDecisionValues(fUML::Semantics::Activities::Token[*]) : fUML::Semantics::Values::Value[*]: 1834254220
		case ActivitiesPackage::DECISIONNODEACTIVATION_OPERATION_GETDECISIONVALUES_TOKEN:
		{
			//Retrieve input parameter 'incomingTokens'
			//parameter 0
			std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incoming_param_incomingTokens;
			std::list<Any>::const_iterator incoming_param_incomingTokens_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_incomingTokens = (*incoming_param_incomingTokens_arguments_citer)->get<std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> >();
			std::shared_ptr<Bag<fUML::Semantics::Values::Value> > resultList = this->getDecisionValues(incoming_param_incomingTokens);
			return eAnyBag(resultList,fUML::Semantics::Values::ValuesPackage::VALUE_CLASS);
			break;
		}
		// fUML::Semantics::Activities::DecisionNodeActivation::hasObjectFlowInput() : bool: 336094904
		case ActivitiesPackage::DECISIONNODEACTIVATION_OPERATION_HASOBJECTFLOWINPUT:
		{
			result = eAny(this->hasObjectFlowInput(),0,false);
			break;
		}
		// fUML::Semantics::Activities::DecisionNodeActivation::isReady() : bool: 2829031806
		case ActivitiesPackage::DECISIONNODEACTIVATION_OPERATION_ISREADY:
		{
			result = eAny(this->isReady(),0,false);
			break;
		}
		// fUML::Semantics::Activities::DecisionNodeActivation::removeJoinedControlTokens(fUML::Semantics::Activities::Token[*]) : fUML::Semantics::Activities::Token[*]: 1559509247
		case ActivitiesPackage::DECISIONNODEACTIVATION_OPERATION_REMOVEJOINEDCONTROLTOKENS_TOKEN:
		{
			//Retrieve input parameter 'incomingTokens'
			//parameter 0
			std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incoming_param_incomingTokens;
			std::list<Any>::const_iterator incoming_param_incomingTokens_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_incomingTokens = (*incoming_param_incomingTokens_arguments_citer)->get<std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> >();
			std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > resultList = this->removeJoinedControlTokens(incoming_param_incomingTokens);
			return eAnyBag(resultList,fUML::Semantics::Activities::ActivitiesPackage::TOKEN_CLASS);
			break;
		}
		// fUML::Semantics::Activities::DecisionNodeActivation::takeOfferedTokens() : fUML::Semantics::Activities::Token[*]: 121080352
		case ActivitiesPackage::DECISIONNODEACTIVATION_OPERATION_TAKEOFFEREDTOKENS:
		{
			std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > resultList = this->takeOfferedTokens();
			return eAnyBag(resultList,fUML::Semantics::Activities::ActivitiesPackage::TOKEN_CLASS);
			break;
		}
		// fUML::Semantics::Activities::DecisionNodeActivation::terminate(): 1771187084
		case ActivitiesPackage::DECISIONNODEACTIVATION_OPERATION_TERMINATE:
		{
			this->terminate();
			break;
		}
		// fUML::Semantics::Activities::DecisionNodeActivation::test(uml::ValueSpecification, fUML::Semantics::Values::Value) : bool: 753683065
		case ActivitiesPackage::DECISIONNODEACTIVATION_OPERATION_TEST_VALUESPECIFICATION_VALUE:
		{
			//Retrieve input parameter 'gaurd'
			//parameter 0
			std::shared_ptr<uml::ValueSpecification> incoming_param_gaurd;
			std::list<Any>::const_iterator incoming_param_gaurd_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_gaurd = (*incoming_param_gaurd_arguments_citer)->get<std::shared_ptr<uml::ValueSpecification> >();
			//Retrieve input parameter 'value'
			//parameter 1
			std::shared_ptr<fUML::Semantics::Values::Value> incoming_param_value;
			std::list<Any>::const_iterator incoming_param_value_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_value = (*incoming_param_value_arguments_citer)->get<std::shared_ptr<fUML::Semantics::Values::Value> >();
			result = eAny(this->test(incoming_param_gaurd,incoming_param_value),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = ControlNodeActivationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Activities::DecisionNodeActivation> DecisionNodeActivationImpl::getThisDecisionNodeActivationPtr() const
{
	return m_thisDecisionNodeActivationPtr.lock();
}
void DecisionNodeActivationImpl::setThisDecisionNodeActivationPtr(std::weak_ptr<fUML::Semantics::Activities::DecisionNodeActivation> thisDecisionNodeActivationPtr)
{
	m_thisDecisionNodeActivationPtr = thisDecisionNodeActivationPtr;
	setThisControlNodeActivationPtr(thisDecisionNodeActivationPtr);
}


