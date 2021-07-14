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

#include "abstractDataTypes/Bag.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"


#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"
#include "uml/Trigger.hpp"

//Factories an Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

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
	EventOccurrence::operator=(obj);

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

std::shared_ptr<ecore::EClass> EventOccurrenceImpl::eStaticClass() const
{
	return fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void EventOccurrenceImpl::doSend()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> > EventOccurrenceImpl::getParameterValues()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool EventOccurrenceImpl::match(std::shared_ptr<uml::Trigger> trigger)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool EventOccurrenceImpl::matchAny(std::shared_ptr<Bag<uml::Trigger>> triggers)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void EventOccurrenceImpl::sendTo(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> target)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference target
*/
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



std::shared_ptr<EventOccurrence> EventOccurrenceImpl::getThisEventOccurrencePtr() const
{
	return m_thisEventOccurrencePtr.lock();
}
void EventOccurrenceImpl::setThisEventOccurrencePtr(std::weak_ptr<EventOccurrence> thisEventOccurrencePtr)
{
	m_thisEventOccurrencePtr = thisEventOccurrencePtr;
}
std::shared_ptr<ecore::EObject> EventOccurrenceImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any EventOccurrenceImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EVENTOCCURRENCE_ATTRIBUTE_TARGET:
			return eAny(getTarget()); //450
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
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> _target = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(_temp);
			setTarget(_target); //450
			return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any EventOccurrenceImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 4501
		case CommonBehaviorPackage::EVENTOCCURRENCE_OPERATION_DOSEND:
		{
			this->doSend();
			break;
		}
		
		// 4502
		case CommonBehaviorPackage::EVENTOCCURRENCE_OPERATION_GETPARAMETERVALUES:
		{
			result = eAny(this->getParameterValues());
			break;
		}
		
		// 4503
		case CommonBehaviorPackage::EVENTOCCURRENCE_OPERATION_MATCH_TRIGGER:
		{
			//Retrieve input parameter 'trigger'
			//parameter 0
			std::shared_ptr<uml::Trigger> incoming_param_trigger;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_trigger_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_trigger = (*incoming_param_trigger_arguments_citer)->get()->get<std::shared_ptr<uml::Trigger> >();
			result = eAny(this->match(incoming_param_trigger));
			break;
		}
		
		// 4504
		case CommonBehaviorPackage::EVENTOCCURRENCE_OPERATION_MATCHANY_TRIGGER:
		{
			//Retrieve input parameter 'triggers'
			//parameter 0
			std::shared_ptr<Bag<uml::Trigger>> incoming_param_triggers;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_triggers_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_triggers = (*incoming_param_triggers_arguments_citer)->get()->get<std::shared_ptr<Bag<uml::Trigger>> >();
			result = eAny(this->matchAny(incoming_param_triggers));
			break;
		}
		
		// 4505
		case CommonBehaviorPackage::EVENTOCCURRENCE_OPERATION_SENDTO_REFERENCE:
		{
			//Retrieve input parameter 'target'
			//parameter 0
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> incoming_param_target;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_target_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_target = (*incoming_param_target_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> >();
			this->sendTo(incoming_param_target);
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

