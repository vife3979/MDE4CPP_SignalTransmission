
#include "fUML/Semantics/Actions/impl/CallActionActivationImpl.hpp"
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
#include <stdexcept>
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
#include "fUML/Semantics/CommonBehavior/Execution.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
//#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"
#include "uml/UMLAny.hpp"
#include "uml/Behavior.hpp"
#include "uml/CallAction.hpp"
#include "uml/InputPin.hpp"
#include "uml/OutputPin.hpp"
#include "uml/Parameter.hpp"
#include "uml/Property.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "fUML/Semantics/Actions/ActionsFactory.hpp"
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "uml/Action.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "uml/Behavior.hpp"
#include "uml/CallAction.hpp"
#include "fUML/Semantics/CommonBehavior/Execution.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/Actions/InvocationActionActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
//Factories and Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
CallActionActivationImpl::CallActionActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CallActionActivationImpl::~CallActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CallActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
CallActionActivationImpl::CallActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:CallActionActivationImpl()
{
	m_group = par_group;
}

CallActionActivationImpl::CallActionActivationImpl(const CallActionActivationImpl & obj): CallActionActivationImpl()
{
	*this = obj;
}

CallActionActivationImpl& CallActionActivationImpl::operator=(const CallActionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	InvocationActionActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of CallActionActivation 
	 * which is generated by the compiler (as CallActionActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//CallActionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CallActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_callAction  = obj.getCallAction();
	//Clone references with containment (deep copy)
	return *this;
}

//*********************************
// Operations
//*********************************
void CallActionActivationImpl::doAction()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::CallAction> callAction = this->getCallAction();
	std::shared_ptr<Bag<uml::InputPin>> argumentPins = callAction->getArgument();
	std::shared_ptr<Subset<fUML::Semantics::Actions::InputPinActivation, fUML::Semantics::Actions::PinActivation>> inputActivationList = this->getInputPinActivation();

	unsigned int inputPinNumber = 0;
	std::shared_ptr<uml::Behavior> behavior = this->retrieveBehavior();
	
	if(!behavior)
	{
		DEBUG_ERROR("Behavior is nullptr! Failed to perform call!")
		return;
	}
	
	std::shared_ptr<Bag<uml::Parameter>> parameterList = behavior->getOwnedParameter();
	unsigned int size = parameterList->size();
	std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> inputParameterValues(new Bag<fUML::Semantics::CommonBehavior::ParameterValue>());
	
	for (unsigned int i=0; i<size; i++)
	{
		std::shared_ptr<uml::Parameter> parameter = parameterList->at(i);
		uml::ParameterDirectionKind direction = parameter->getDirection();
		
		if (direction == uml::ParameterDirectionKind::IN || direction == uml::ParameterDirectionKind::INOUT)
		{
			std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> parameterValue = fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createParameterValue();
			parameterValue->setParameter(parameter);

			// get corresponding pin (pin and parameter list should be synchronized)
			std::shared_ptr<uml::InputPin> correspondingInputpin = argumentPins->at(i);
			std::string pinName = correspondingInputpin->getName();

			// if pin name starts with 'self', get values from context attribute
			if (pinName.find("self.") == 0)
			{
				std::string attributeName = pinName.substr (5, std::string::npos);
				DEBUG_INFO("Changing execution context to self." << attributeName << ".")

				std::shared_ptr<uml::Element> context = this->getExecutionContext();

				std::shared_ptr<uml::Property> attribute = nullptr;
				std::shared_ptr<Bag<uml::Classifier>> contextTypes; /* Currently not supported. TODO: implement something like getTypes */ // = context->getTypes();
				Bag<uml::Classifier>::iterator contextTypesIter = contextTypes->begin();
				Bag<uml::Classifier>::iterator contextTypesEnd = contextTypes->end();

				while (attribute == nullptr || contextTypesIter < contextTypesEnd)
				{
					std::shared_ptr<uml::Classifier> classifier = *contextTypesIter;
					contextTypesIter++;

					std::shared_ptr<Bag<uml::Property>> attributes = classifier->getAllAttributes();
					Bag<uml::Property>::iterator attributeIter = attributes->begin();
					Bag<uml::Property>::iterator attributeEnd = attributes->end();
					while (attribute == nullptr || attributeIter < attributeEnd)
					{
						if ((*attributeIter)->getName() == attributeName)
						{
							attribute = *attributeIter;
						}
						attributeIter++;
					}
				}

				if(attribute == nullptr)
				{
					std::cerr << "Could not find the attribute in the current context for input pin '" << pinName << "'." << std::endl;
					exit(EXIT_FAILURE);
				}

				DEBUG_INFO("Found context attribute self."<< attributeName << " for target pin.")

				if (context != nullptr)
				{
					std::shared_ptr<Any> attributeValue = context->get(attribute);
					parameterValue->getValues()->add(attributeValue);
				}
			}
			// if pin name starts with 'self', use context as value
			else if (pinName.find("self") == 0)
			{
				std::shared_ptr<uml::Element> context = getExecutionContext();
				std::shared_ptr<Any> contextValue = eUMLAny(context, context->getMetaElementID());
				
				parameterValue->getValues()->add(contextValue);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> activation =inputActivationList->at(inputPinNumber);
				std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > tokenList = activation->takeUnofferedTokens();
				for(std::shared_ptr<fUML::Semantics::Activities::Token> token : *tokenList)
				{
					std::shared_ptr<Any> value = token->getValue();
					if(value != nullptr)
					{
						DEBUG_INFO("Target: "<<value->toString() << ".")
						parameterValue->getValues()->add(value);
					}
				}
			}

			inputParameterValues->add(parameterValue);
			inputPinNumber++;
		}
	}

	std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> outputParameterValues = this->doCall(inputParameterValues);
	
	if(outputParameterValues)
	{
		std::shared_ptr<Bag<uml::OutputPin>> resultPins = callAction->getResult();
		std::shared_ptr<Subset<fUML::Semantics::Actions::OutputPinActivation, fUML::Semantics::Actions::PinActivation>> outputActivationList=this->getOutputPinActivation();
		unsigned int outputPinNumber = 0;
		for (std::shared_ptr<uml::Parameter> parameter : *parameterList)
		{
			if (!(parameter->getDirection() == uml::ParameterDirectionKind::IN))
			{
				for (std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> outputParameterValue : *outputParameterValues)
				{
					if (outputParameterValue->getParameter() == parameter)
					{
						std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> resultPinActivation = outputActivationList->at(outputPinNumber);
						std::shared_ptr<Bag<Any>> values = outputParameterValue->getValues();

						for (std::shared_ptr<Any> value : *values)
						{
							DEBUG_INFO("Creating outgoing ObjectToken for CallAction '" << callAction ->getName() << "'.")

							std::shared_ptr<fUML::Semantics::Activities::ObjectToken> token = fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createObjectToken();
							token->setValue(value);

							resultPinActivation->addToken(token);
							ACT_DEBUG(std::cout<<"SET_TOKEN;NODE:"<< resultPinActivation->getNode()->getQualifiedName() <<";TOKEN:"<<token->getValue() << ";CURRENT_TOKENS:"<< (this->getHeldTokens()->size()+1) <<";DIRECTION:add"<<std::endl;)
						}
						outputPinNumber++;
						break;
					}
				}
			}
		}
	}
	else
	{
		DEBUG_ERROR("Output parameter values were NULL for CallAction '" << callAction ->getName() << "'.")
	}
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> CallActionActivationImpl::doCall(std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> inputParameterValues)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}





std::shared_ptr<uml::Behavior> CallActionActivationImpl::retrieveBehavior() const
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

void CallActionActivationImpl::terminate()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	/* Property CallActionActivation::callExecutions do not exist anymore
	std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::Execution> > executionList = this->getCallExecutions();
	for (std::shared_ptr<fUML::Semantics::CommonBehavior::Execution>  execution: *executionList)
	{
		execution->terminate();
	}
	*/

	fUML::Semantics::Actions::InvocationActionActivationImpl::terminate();
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference callAction */
std::shared_ptr<uml::CallAction> CallActionActivationImpl::getCallAction() const
{
    return m_callAction;
}
void CallActionActivationImpl::setCallAction(std::shared_ptr<uml::CallAction> _callAction)
{
    m_callAction = _callAction;
	//additional setter call for redefined reference ActionActivation::action
	fUML::Semantics::Actions::ActionActivationImpl::setAction(_callAction);
}
/*Additional Setter for redefined reference 'ActionActivation::action'*/
void CallActionActivationImpl::setAction(std::shared_ptr<uml::Action> _action)
{
	std::shared_ptr<uml::CallAction> _callAction = std::dynamic_pointer_cast<uml::CallAction>(_action);
	if(_callAction)
	{
		m_callAction = _callAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setAction(_callAction);
	}
	else
	{
		std::cerr<<"[CallActionActivation::setAction] : Could not set action because provided action was not of type 'std::shared_ptr<uml::CallAction>'"<<std::endl;
	}
}
/*Additional Setter for redefined reference 'ActivityNodeActivation::node'*/
void CallActionActivationImpl::setNode(std::shared_ptr<uml::ActivityNode> _node)
{
	std::shared_ptr<uml::CallAction> _callAction = std::dynamic_pointer_cast<uml::CallAction>(_node);
	if(_callAction)
	{
		m_callAction = _callAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setNode(_node);
	}
	else
	{
		std::cerr<<"[CallActionActivation::setNode] : Could not set node because provided node was not of type 'std::shared_ptr<uml::CallAction>'"<<std::endl;
	}
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> CallActionActivationImpl::getPinActivation() const
{
	if(m_pinActivation == nullptr)
	{
		/*Union*/
		m_pinActivation.reset(new Union<fUML::Semantics::Actions::PinActivation>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_pinActivation - Union<fUML::Semantics::Actions::PinActivation>()" << std::endl;
		#endif
		
		
	}
	return m_pinActivation;
}

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> CallActionActivationImpl::eContainer() const
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
void CallActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CallActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("callAction");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("callAction")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	InvocationActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void CallActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	InvocationActionActivationImpl::loadNode(nodeName, loadHandler);
}

void CallActionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CALLACTIONACTIVATION_ATTRIBUTE_CALLACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::CallAction> _callAction = std::dynamic_pointer_cast<uml::CallAction>( references.front() );
				setCallAction(_callAction);
			}
			
			return;
		}
	}
	InvocationActionActivationImpl::resolveReferences(featureID, references);
}

void CallActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	InvocationActionActivationImpl::saveContent(saveHandler);
	
	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void CallActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getCallAction(), "callAction", getCallAction()->eClass() != uml::umlPackage::eInstance()->getCallAction_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> CallActionActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getCallActionActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> CallActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CALLACTIONACTIVATION_ATTRIBUTE_CALLACTION:
			return eAny(getCallAction(),uml::umlPackage::CALLACTION_CLASS,false); //1412
	}
	return InvocationActionActivationImpl::eGet(featureID, resolve, coreType);
}

bool CallActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CALLACTIONACTIVATION_ATTRIBUTE_CALLACTION:
			return getCallAction() != nullptr; //1412
	}
	return InvocationActionActivationImpl::internalEIsSet(featureID);
}

bool CallActionActivationImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CALLACTIONACTIVATION_ATTRIBUTE_CALLACTION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::CallAction> _callAction = std::dynamic_pointer_cast<uml::CallAction>(eObject);
					if(_callAction)
					{
						setCallAction(_callAction); //1412
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'callAction'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'callAction'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return InvocationActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> CallActionActivationImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Actions::CallActionActivation::doAction(): 3531200850
		case ActionsPackage::CALLACTIONACTIVATION_OPERATION_DOACTION:
		{
			this->doAction();
			break;
		}
		// fUML::Semantics::Actions::CallActionActivation::doCall(fUML::Semantics::CommonBehavior::ParameterValue[*]) : fUML::Semantics::CommonBehavior::ParameterValue[*]: 27461358
		case ActionsPackage::CALLACTIONACTIVATION_OPERATION_DOCALL_PARAMETERVALUE:
		{
			//Retrieve input parameter 'inputParameterValues'
			//parameter 0
			std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> incoming_param_inputParameterValues;
			Bag<Any>::const_iterator incoming_param_inputParameterValues_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>((*incoming_param_inputParameterValues_arguments_citer));
				if(ecoreContainerAny)
				{
					try
					{
						std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
				
						if(eObjectList)
						{
							incoming_param_inputParameterValues.reset();
							for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
							{
								std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> _temp = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue>(anEObject);
								incoming_param_inputParameterValues->add(_temp);
							}
						}
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreContainerAny' for parameter 'inputParameterValues'. Failed to invoke operation 'doCall'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreContainerAny' for parameter 'inputParameterValues'. Failed to invoke operation 'doCall'!")
					return nullptr;
				}
			}
		
			std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> resultList = this->doCall(incoming_param_inputParameterValues);
			return eEcoreContainerAny(resultList,fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_CLASS);
			break;
		}
		// fUML::Semantics::Actions::CallActionActivation::retrieveBehavior() : uml::Behavior {const}: 3994859198
		case ActionsPackage::CALLACTIONACTIVATION_OPERATION_RETRIEVEBEHAVIOR:
		{
			result = eEcoreAny(this->retrieveBehavior(), uml::umlPackage::BEHAVIOR_CLASS);
			break;
		}
		// fUML::Semantics::Actions::CallActionActivation::terminate(): 2819746834
		case ActionsPackage::CALLACTIONACTIVATION_OPERATION_TERMINATE:
		{
			this->terminate();
			break;
		}

		default:
		{
			// call superTypes
			result = InvocationActionActivationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Actions::CallActionActivation> CallActionActivationImpl::getThisCallActionActivationPtr() const
{
	return m_thisCallActionActivationPtr.lock();
}
void CallActionActivationImpl::setThisCallActionActivationPtr(std::weak_ptr<fUML::Semantics::Actions::CallActionActivation> thisCallActionActivationPtr)
{
	m_thisCallActionActivationPtr = thisCallActionActivationPtr;
	setThisInvocationActionActivationPtr(thisCallActionActivationPtr);
}


