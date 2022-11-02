
#include "fUML/Semantics/Activities/impl/DecisionNodeActivationImpl.hpp"
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

#include "abstractDataTypes/Bag.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
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
//#include "fUML/Semantics/Values/Value.hpp"
#include "uml/ActivityEdge.hpp"
#include "uml/Behavior.hpp"
#include "uml/DecisionNode.hpp"
#include "uml/ObjectFlow.hpp"
#include "uml/Parameter.hpp"
#include "uml/ParameterDirectionKind.hpp"
#include "uml/umlFactory.hpp"
#include "uml/ValueSpecification.hpp"
//Forward declaration includes
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Activities/ControlNodeActivation.hpp"
#include "uml/DecisionNode.hpp"
#include "fUML/Semantics/CommonBehavior/Execution.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
#include "uml/ValueSpecification.hpp"
//Factories and Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
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
std::shared_ptr<Any> DecisionNodeActivationImpl::executeDecisionInputBehavior(std::shared_ptr<Any> inputValue, std::shared_ptr<Any> decisionInputValue)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::DecisionNode> decisionNode = this->getDecisionNode();
	std::shared_ptr<uml::Behavior> decisionInputBehavior = nullptr;

    if(decisionNode != nullptr)
    {
        decisionInputBehavior = decisionNode->getDecisionInput();
    }

    std::shared_ptr<Any> decisionInputResult = nullptr;

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
		std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> inputParameterValues(new Bag<fUML::Semantics::CommonBehavior::ParameterValue>());

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

                inputParameterValues->add(inputParameterValue);
            }
            i = i + 1;
        }

        std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> > outputParameterValues = this->getExecutionLocus()->getExecutor()->execute(decisionInputBehavior, this->getExecutionContext(), inputParameterValues);

        decisionInputResult = outputParameterValues->at(0)->getValues()->at(0);
    }

    return decisionInputResult;
	//end of body
}

void DecisionNodeActivationImpl::fire(std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incomingTokens)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	DEBUG_INFO("Firing DecisionNode '" << this->getNode()->getName() << "'.")

	std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> removedControlTokens = this->removeJoinedControlTokens(incomingTokens);
	std::shared_ptr<Bag<Any>> decisionValues = this->getDecisionValues(incomingTokens);
	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> outgoingEdges = this->getOutgoingEdges();

    for (unsigned int i = 0; i < outgoingEdges->size(); i++) 
    {
    	std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> edgeInstance = outgoingEdges->at(i);
    	std::shared_ptr<uml::ValueSpecification> guard = edgeInstance->getEdge()->getGuard();

    	std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > offeredTokens(new Bag<fUML::Semantics::Activities::Token>());
        for (unsigned int j = 0; j < incomingTokens->size(); j++) 
        {
        	std::shared_ptr<fUML::Semantics::Activities::Token> incomingToken = incomingTokens->at(j);
        	std::shared_ptr<Any> decisionValue = decisionValues->at(j);
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

std::shared_ptr<Any> DecisionNodeActivationImpl::getDecisionInputFlowValue()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> decisionInputFlowInstance = this->getDecisionInputFlowInstance();

	std::shared_ptr<Any> value = nullptr;
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

std::shared_ptr<Bag<Any>> DecisionNodeActivationImpl::getDecisionValues(std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incomingTokens)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Any> decisionInputValue = this->getDecisionInputFlowValue();

	std::shared_ptr<Bag<Any>> decisionValues(new Bag<Any>());

    for (unsigned int i = 0; i < incomingTokens->size(); i++) 
    {
    	std::shared_ptr<fUML::Semantics::Activities::Token> incomingToken = incomingTokens->at(i);
    	std::shared_ptr<Any> value = this->executeDecisionInputBehavior(incomingToken->getValue(), decisionInputValue);
        decisionValues->push_back(value);
    }

#ifndef NDEBUG
	std::string decisionValuesDebugInfoMessage;
	for (unsigned int i = 0; i < decisionValues->size(); i++)
	{
		std::shared_ptr<Any> decisionValue = decisionValues->at(i);
		if (decisionValue)
		{
			decisionValuesDebugInfoMessage += "decisionValues[" + std::to_string(i) + "] = " + decisionValue->toString() + " ; ";
		}
		else
		{
			decisionValuesDebugInfoMessage += "decisionValues[" + std::to_string(i) + "] = nullptr ; ";
		}
	}
#endif

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
    DEBUG_INFO("DecisionNode '" << this->getNode()->getName() << "' has " << this->getIncomingEdges()->size() << "incoming edges.")
    while (ready && (i < this->getIncomingEdges()->size())) {
        ready = this->getIncomingEdges()->at(i)->hasOffer();
        i = i + 1;
    }
    DEBUG_INFO("DecisionNode '" << this->getNode()->getName() << "' " << ((ready) ? "is ready to execute." : "is not ready to execute yet."))
    return ready;
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> DecisionNodeActivationImpl::removeJoinedControlTokens(std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incomingTokens)
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

std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> DecisionNodeActivationImpl::takeOfferedTokens()
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



bool DecisionNodeActivationImpl::test(std::shared_ptr<uml::ValueSpecification> guard, std::shared_ptr<Any> value)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	bool guardResult = true;
    if (guard != nullptr) 
    {
		// Determine what kind of ValueSpecification is present
		switch(guard->getMetaElementID())
		{
			case uml::umlPackage::LITERALBOOLEAN_CLASS:
			{
				bool guardValue = guard->booleanValue();
				try
				{
					bool booleanValue = value->get<bool>();
					
					guardResult = (guardValue == booleanValue);
				}
				catch(...)
				{
					guardResult = false;
				}
				break;
			}
			case uml::umlPackage::LITERALINTEGER_CLASS:
			{
				int guardValue = guard->integerValue();
				try
				{
					int integerValue = value->get<int>();
					
					guardResult = (guardValue == integerValue);
				}
				catch(...)
				{
					guardResult = false;
				}
				break;
			}
			case uml::umlPackage::LITERALREAL_CLASS:
			{
				double guardValue = guard->realValue();
				try
				{
					double realValue = value->get<double>();
					
					guardResult = (guardValue == realValue);
				}
				catch(...)
				{
					guardResult = false;
				}
				break;
			}
			case uml::umlPackage::LITERALSTRING_CLASS:
			{
				std::string guardValue = guard->stringValue();
				try
				{
					std::string stringValue = value->get<std::string>();
					
					guardResult = (guardValue == stringValue);
				}
				catch(...)
				{
					guardResult = false;
				}
				break;
			}
			case uml::umlPackage::LITERALUNLIMITEDNATURAL_CLASS:
			{
				int guardValue = guard->integerValue();
				try
				{
					int integerValue = value->get<int>();
					
					guardResult = (guardValue == integerValue);
				}
				catch(...)
				{
					guardResult = false;
				}
				break;
			}
			case uml::umlPackage::INSTANCEVALUE_CLASS:
			{
				/*
					Currently not supported
				*/
				DEBUG_WARNING("Evaluation of InstanceValues used for ActivityEdge guards is currently not supported!")
				break;
			}
			default:
			{
				DEBUG_ERROR("Unknown kind of ValuesSpecification used for ActivityEdge guard!")
			}
		}
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

std::shared_ptr<ecore::EClass> DecisionNodeActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getDecisionNodeActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> DecisionNodeActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::DECISIONNODEACTIVATION_ATTRIBUTE_DECISIONNODE:
			return eAny(getDecisionNode(),uml::umlPackage::DECISIONNODE_CLASS,false); //377
	}
	return ControlNodeActivationImpl::eGet(featureID, resolve, coreType);
}

bool DecisionNodeActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::DECISIONNODEACTIVATION_ATTRIBUTE_DECISIONNODE:
			return getDecisionNode() != nullptr; //377
	}
	return ControlNodeActivationImpl::internalEIsSet(featureID);
}

bool DecisionNodeActivationImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::DECISIONNODEACTIVATION_ATTRIBUTE_DECISIONNODE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::DecisionNode> _decisionNode = std::dynamic_pointer_cast<uml::DecisionNode>(eObject);
					if(_decisionNode)
					{
						setDecisionNode(_decisionNode); //377
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'decisionNode'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'decisionNode'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return ControlNodeActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> DecisionNodeActivationImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Activities::DecisionNodeActivation::executeDecisionInputBehavior(Any, Any) : Any: 3052258302
		case ActivitiesPackage::DECISIONNODEACTIVATION_OPERATION_EXECUTEDECISIONINPUTBEHAVIOR_EJAVAOBJECT_EJAVAOBJECT:
		{
			//Retrieve input parameter 'inputValue'
			//parameter 0
			std::shared_ptr<Any> incoming_param_inputValue;
			Bag<Any>::const_iterator incoming_param_inputValue_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_inputValue = (*incoming_param_inputValue_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'inputValue'. Failed to invoke operation 'executeDecisionInputBehavior'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'decisionInputValue'
			//parameter 1
			std::shared_ptr<Any> incoming_param_decisionInputValue;
			Bag<Any>::const_iterator incoming_param_decisionInputValue_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_decisionInputValue = (*incoming_param_decisionInputValue_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'decisionInputValue'. Failed to invoke operation 'executeDecisionInputBehavior'!")
				return nullptr;
			}
		
			result = eAny(this->executeDecisionInputBehavior(incoming_param_inputValue,incoming_param_decisionInputValue), 0, false);
			break;
		}
		// fUML::Semantics::Activities::DecisionNodeActivation::fire(fUML::Semantics::Activities::Token[*]): 4127070096
		case ActivitiesPackage::DECISIONNODEACTIVATION_OPERATION_FIRE_TOKEN:
		{
			//Retrieve input parameter 'incomingTokens'
			//parameter 0
			std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incoming_param_incomingTokens;
			Bag<Any>::const_iterator incoming_param_incomingTokens_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>((*incoming_param_incomingTokens_arguments_citer));
				if(ecoreContainerAny)
				{
					try
					{
						std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
				
						if(eObjectList)
						{
							incoming_param_incomingTokens.reset();
							for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
							{
								std::shared_ptr<fUML::Semantics::Activities::Token> _temp = std::dynamic_pointer_cast<fUML::Semantics::Activities::Token>(anEObject);
								incoming_param_incomingTokens->add(_temp);
							}
						}
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreContainerAny' for parameter 'incomingTokens'. Failed to invoke operation 'fire'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreContainerAny' for parameter 'incomingTokens'. Failed to invoke operation 'fire'!")
					return nullptr;
				}
			}
		
			this->fire(incoming_param_incomingTokens);
			break;
		}
		// fUML::Semantics::Activities::DecisionNodeActivation::getDecisionInputFlowInstance() : fUML::Semantics::Activities::ActivityEdgeInstance: 589400247
		case ActivitiesPackage::DECISIONNODEACTIVATION_OPERATION_GETDECISIONINPUTFLOWINSTANCE:
		{
			result = eEcoreAny(this->getDecisionInputFlowInstance(), fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEDGEINSTANCE_CLASS);
			break;
		}
		// fUML::Semantics::Activities::DecisionNodeActivation::getDecisionInputFlowValue() : Any: 1399588784
		case ActivitiesPackage::DECISIONNODEACTIVATION_OPERATION_GETDECISIONINPUTFLOWVALUE:
		{
			result = eAny(this->getDecisionInputFlowValue(), 0, false);
			break;
		}
		// fUML::Semantics::Activities::DecisionNodeActivation::getDecisionValues(fUML::Semantics::Activities::Token[*]) : Any[*]: 2333144120
		case ActivitiesPackage::DECISIONNODEACTIVATION_OPERATION_GETDECISIONVALUES_TOKEN:
		{
			//Retrieve input parameter 'incomingTokens'
			//parameter 0
			std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incoming_param_incomingTokens;
			Bag<Any>::const_iterator incoming_param_incomingTokens_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>((*incoming_param_incomingTokens_arguments_citer));
				if(ecoreContainerAny)
				{
					try
					{
						std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
				
						if(eObjectList)
						{
							incoming_param_incomingTokens.reset();
							for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
							{
								std::shared_ptr<fUML::Semantics::Activities::Token> _temp = std::dynamic_pointer_cast<fUML::Semantics::Activities::Token>(anEObject);
								incoming_param_incomingTokens->add(_temp);
							}
						}
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreContainerAny' for parameter 'incomingTokens'. Failed to invoke operation 'getDecisionValues'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreContainerAny' for parameter 'incomingTokens'. Failed to invoke operation 'getDecisionValues'!")
					return nullptr;
				}
			}
		
			result = eAny(this->getDecisionValues(incoming_param_incomingTokens), 0, true);
			break;
		}
		// fUML::Semantics::Activities::DecisionNodeActivation::hasObjectFlowInput() : bool: 336094904
		case ActivitiesPackage::DECISIONNODEACTIVATION_OPERATION_HASOBJECTFLOWINPUT:
		{
			result = eAny(this->hasObjectFlowInput(), 0, false);
			break;
		}
		// fUML::Semantics::Activities::DecisionNodeActivation::isReady() : bool: 2829031806
		case ActivitiesPackage::DECISIONNODEACTIVATION_OPERATION_ISREADY:
		{
			result = eAny(this->isReady(), 0, false);
			break;
		}
		// fUML::Semantics::Activities::DecisionNodeActivation::removeJoinedControlTokens(fUML::Semantics::Activities::Token[*]) : fUML::Semantics::Activities::Token[*]: 1559509247
		case ActivitiesPackage::DECISIONNODEACTIVATION_OPERATION_REMOVEJOINEDCONTROLTOKENS_TOKEN:
		{
			//Retrieve input parameter 'incomingTokens'
			//parameter 0
			std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incoming_param_incomingTokens;
			Bag<Any>::const_iterator incoming_param_incomingTokens_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>((*incoming_param_incomingTokens_arguments_citer));
				if(ecoreContainerAny)
				{
					try
					{
						std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
				
						if(eObjectList)
						{
							incoming_param_incomingTokens.reset();
							for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
							{
								std::shared_ptr<fUML::Semantics::Activities::Token> _temp = std::dynamic_pointer_cast<fUML::Semantics::Activities::Token>(anEObject);
								incoming_param_incomingTokens->add(_temp);
							}
						}
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreContainerAny' for parameter 'incomingTokens'. Failed to invoke operation 'removeJoinedControlTokens'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreContainerAny' for parameter 'incomingTokens'. Failed to invoke operation 'removeJoinedControlTokens'!")
					return nullptr;
				}
			}
		
			std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> resultList = this->removeJoinedControlTokens(incoming_param_incomingTokens);
			return eEcoreContainerAny(resultList,fUML::Semantics::Activities::ActivitiesPackage::TOKEN_CLASS);
			break;
		}
		// fUML::Semantics::Activities::DecisionNodeActivation::takeOfferedTokens() : fUML::Semantics::Activities::Token[*]: 121080352
		case ActivitiesPackage::DECISIONNODEACTIVATION_OPERATION_TAKEOFFEREDTOKENS:
		{
			std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> resultList = this->takeOfferedTokens();
			return eEcoreContainerAny(resultList,fUML::Semantics::Activities::ActivitiesPackage::TOKEN_CLASS);
			break;
		}
		// fUML::Semantics::Activities::DecisionNodeActivation::test(uml::ValueSpecification, Any) : bool: 2379610281
		case ActivitiesPackage::DECISIONNODEACTIVATION_OPERATION_TEST_VALUESPECIFICATION_EJAVAOBJECT:
		{
			//Retrieve input parameter 'guard'
			//parameter 0
			std::shared_ptr<uml::ValueSpecification> incoming_param_guard;
			Bag<Any>::const_iterator incoming_param_guard_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_guard_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_guard = std::dynamic_pointer_cast<uml::ValueSpecification>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'guard'. Failed to invoke operation 'test'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'guard'. Failed to invoke operation 'test'!")
					return nullptr;
				}
			}
		
			//Retrieve input parameter 'value'
			//parameter 1
			std::shared_ptr<Any> incoming_param_value;
			Bag<Any>::const_iterator incoming_param_value_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_value = (*incoming_param_value_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'value'. Failed to invoke operation 'test'!")
				return nullptr;
			}
		
			result = eAny(this->test(incoming_param_guard,incoming_param_value), 0, false);
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


