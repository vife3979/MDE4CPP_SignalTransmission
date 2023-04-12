
#include "fUML/Semantics/CommonBehavior/impl/EventOccurrenceImpl.hpp"
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
#include <stdexcept>
#include "abstractDataTypes/Bag.hpp"


#include "abstractDataTypes/AnyEObject.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"
#include "uml/Trigger.hpp"
//Factories and Package includes
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::CommonBehavior;

//*********************************
// Constructor / Destructor
//*********************************
EventOccurrenceImpl::EventOccurrenceImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

EventOccurrenceImpl::~EventOccurrenceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EventOccurrence "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


EventOccurrenceImpl::EventOccurrenceImpl(const EventOccurrenceImpl & obj): EventOccurrenceImpl()
{
	*this = obj;
}

EventOccurrenceImpl& EventOccurrenceImpl::operator=(const EventOccurrenceImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::EModelElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of EventOccurrence 
	 * which is generated by the compiler (as EventOccurrence is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//EventOccurrence::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EventOccurrence "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_target  = obj.getTarget();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> EventOccurrenceImpl::copy() const
{
	std::shared_ptr<EventOccurrenceImpl> element(new EventOccurrenceImpl());
	*element =(*this);
	element->setThisEventOccurrencePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void EventOccurrenceImpl::doSend()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> > EventOccurrenceImpl::getParameterValues()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool EventOccurrenceImpl::match(std::shared_ptr<uml::Trigger> trigger)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool EventOccurrenceImpl::matchAny(std::shared_ptr<Bag<uml::Trigger>> triggers)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

void EventOccurrenceImpl::sendTo(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> target)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference target */
std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> EventOccurrenceImpl::getTarget() const
{
    return m_target;
}
void EventOccurrenceImpl::setTarget(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> _target)
{
    m_target = _target;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> EventOccurrenceImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void EventOccurrenceImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void EventOccurrenceImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("target");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("target")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void EventOccurrenceImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
}

void EventOccurrenceImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EVENTOCCURRENCE_ATTRIBUTE_TARGET:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> _target = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>( references.front() );
				setTarget(_target);
			}
			
			return;
		}
	}
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void EventOccurrenceImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ecore::EObjectImpl::saveContent(saveHandler);
}

void EventOccurrenceImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::CommonBehavior::CommonBehaviorPackage> package = fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getTarget(), "target", getTarget()->eClass() != fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getReference_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> EventOccurrenceImpl::eStaticClass() const
{
	return fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any EventOccurrenceImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EVENTOCCURRENCE_ATTRIBUTE_TARGET:
			return eAny(getTarget(),fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::REFERENCE_CLASS,false); //450
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}

bool EventOccurrenceImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EVENTOCCURRENCE_ATTRIBUTE_TARGET:
			return getTarget() != nullptr; //450
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}

bool EventOccurrenceImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EVENTOCCURRENCE_ATTRIBUTE_TARGET:
		{
			// CAST Any to fUML::Semantics::StructuredClassifiers::Reference
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> _target = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(_temp);
			setTarget(_target); //450
			return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any EventOccurrenceImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// fUML::Semantics::CommonBehavior::EventOccurrence::doSend(): 905542773
		case CommonBehaviorPackage::EVENTOCCURRENCE_OPERATION_DOSEND:
		{
			this->doSend();
			break;
		}
		// fUML::Semantics::CommonBehavior::EventOccurrence::getParameterValues() : fUML::Semantics::CommonBehavior::ParameterValue[*]: 2905522987
		case CommonBehaviorPackage::EVENTOCCURRENCE_OPERATION_GETPARAMETERVALUES:
		{
			std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> > resultList = this->getParameterValues();
			return eAnyBag(resultList,fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_CLASS);
			break;
		}
		// fUML::Semantics::CommonBehavior::EventOccurrence::match(uml::Trigger) : bool: 3505679709
		case CommonBehaviorPackage::EVENTOCCURRENCE_OPERATION_MATCH_TRIGGER:
		{
			//Retrieve input parameter 'trigger'
			//parameter 0
			std::shared_ptr<uml::Trigger> incoming_param_trigger;
			std::list<Any>::const_iterator incoming_param_trigger_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_trigger = (*incoming_param_trigger_arguments_citer)->get<std::shared_ptr<uml::Trigger> >();
			result = eAny(this->match(incoming_param_trigger),0,false);
			break;
		}
		// fUML::Semantics::CommonBehavior::EventOccurrence::matchAny(uml::Trigger[*]) : bool: 2005940351
		case CommonBehaviorPackage::EVENTOCCURRENCE_OPERATION_MATCHANY_TRIGGER:
		{
			//Retrieve input parameter 'triggers'
			//parameter 0
			std::shared_ptr<Bag<uml::Trigger>> incoming_param_triggers;
			std::list<Any>::const_iterator incoming_param_triggers_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_triggers = (*incoming_param_triggers_arguments_citer)->get<std::shared_ptr<Bag<uml::Trigger>> >();
			result = eAny(this->matchAny(incoming_param_triggers),0,false);
			break;
		}
		// fUML::Semantics::CommonBehavior::EventOccurrence::sendTo(fUML::Semantics::StructuredClassifiers::Reference): 1965482620
		case CommonBehaviorPackage::EVENTOCCURRENCE_OPERATION_SENDTO_REFERENCE:
		{
			//Retrieve input parameter 'target'
			//parameter 0
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> incoming_param_target;
			std::list<Any>::const_iterator incoming_param_target_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_target = (*incoming_param_target_arguments_citer)->get<std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> >();
			this->sendTo(incoming_param_target);
			break;
		}

		default:
		{
			// call superTypes
			result = ecore::EModelElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> EventOccurrenceImpl::getThisEventOccurrencePtr() const
{
	return m_thisEventOccurrencePtr.lock();
}
void EventOccurrenceImpl::setThisEventOccurrencePtr(std::weak_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> thisEventOccurrencePtr)
{
	m_thisEventOccurrencePtr = thisEventOccurrencePtr;
}


