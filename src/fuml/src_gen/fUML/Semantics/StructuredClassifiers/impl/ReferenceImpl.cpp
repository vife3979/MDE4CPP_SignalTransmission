
#include "fUML/Semantics/StructuredClassifiers/impl/ReferenceImpl.hpp"

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
#include <uml/Classifier.hpp>
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "uml/Class.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"

#include "uml/Class.hpp"
#include "uml/Classifier.hpp"
#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"
#include "fUML/Semantics/CommonBehavior/Execution.hpp"
#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"
#include "fUML/Semantics/StructuredClassifiers/Object.hpp"
#include "uml/Operation.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/SignalInstance.hpp"
#include "uml/StructuralFeature.hpp"
#include "fUML/Semantics/SimpleClassifiers/StructuredValue.hpp"
#include "fUML/Semantics/Values/Value.hpp"

//Factories an Package includes
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::StructuredClassifiers;

//*********************************
// Constructor / Destructor
//*********************************
ReferenceImpl::ReferenceImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ReferenceImpl::~ReferenceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Reference "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


ReferenceImpl::ReferenceImpl(const ReferenceImpl & obj): ReferenceImpl()
{
	*this = obj;
}

ReferenceImpl& ReferenceImpl::operator=(const ReferenceImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::SimpleClassifiers::StructuredValueImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Reference 
	 * which is generated by the compiler (as Reference is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Reference::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Reference "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_referent  = obj.getReferent();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ReferenceImpl::copy() const
{
	std::shared_ptr<ReferenceImpl> element(new ReferenceImpl());
	*element =(*this);
	element->setThisReferencePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Values::Value> ReferenceImpl::_copy()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// // Create a new reference with the same referent as this reference.

std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> newValue = fUML::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createReference();

newValue->setReferent(this->getReferent());

return newValue;
	//end of body
}

void ReferenceImpl::assignFeatureValue(std::shared_ptr<uml::StructuralFeature> feature,std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values,int position)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->getReferent()->assignFeatureValue(feature,values,position);
	//end of body
}

void ReferenceImpl::destroy()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	this->getReferent()->destroy();
	//end of body
}

std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> ReferenceImpl::dispatch(std::shared_ptr<uml::Operation> operation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->getReferent()->dispatch(operation);
	//end of body
}

bool ReferenceImpl::equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		bool isEqual = false;
	auto other = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(otherValue);
	if (other != nullptr) {
		if (this->getReferent() == nullptr) {
			isEqual = other->getReferent() == nullptr;
		} else {
			isEqual = this->getReferent()->equals(other->getReferent());
		}
	}
	return isEqual;
	//end of body
}

std::shared_ptr<Bag<uml::Classifier> > ReferenceImpl::getTypes()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		return  this->getReferent()->getTypes();
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::Values::Value> > ReferenceImpl::getValues(std::shared_ptr<uml::StructuralFeature> feature,std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->getReferent()->getValues(feature,featureValues);
	//end of body
}

std::shared_ptr<fUML::Semantics::Values::Value> ReferenceImpl::new_()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return fUML::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createReference();
	//end of body
}

void ReferenceImpl::removeValue(std::shared_ptr<uml::StructuralFeature> feature,std::shared_ptr<fUML::Semantics::Values::Value> value)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	this->getReferent()->removeValue(feature, value);
	//end of body
}

std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> ReferenceImpl::retrieveFeatureValue(std::shared_ptr<uml::StructuralFeature> feature)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->getReferent()->retrieveFeatureValue(feature);
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue> > ReferenceImpl::retrieveFeatureValues()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->getReferent()->retrieveFeatureValues();
	//end of body
}

void ReferenceImpl::send(std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> signalInstance)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	this->getReferent()->send(signalInstance);
	//end of body
}

void ReferenceImpl::send(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> eventOccurrence)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	
	//end of body
}

void ReferenceImpl::setFeatureValue(std::shared_ptr<uml::StructuralFeature> feature,std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values,int position)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	this->getReferent()->setFeatureValue(feature,values,position);
	//end of body
}

void ReferenceImpl::startBehavior(std::shared_ptr<uml::Class> classifier,std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> inputs)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	this->getReferent()->startBehavior(classifier,inputs);
	//end of body
}

std::string ReferenceImpl::toString()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return "Reference to " + this->getReferent()->toString();
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference referent */
std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> ReferenceImpl::getReferent() const
{
    return m_referent;
}
void ReferenceImpl::setReferent(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> _referent)
{
    m_referent = _referent;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ReferenceImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void ReferenceImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ReferenceImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("referent");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("referent")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	fUML::Semantics::SimpleClassifiers::StructuredValueImpl::loadAttributes(loadHandler, attr_list);
}

void ReferenceImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::SimpleClassifiers::StructuredValueImpl::loadNode(nodeName, loadHandler);
}

void ReferenceImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::REFERENCE_ATTRIBUTE_REFERENT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> _referent = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Object>( references.front() );
				setReferent(_referent);
			}
			
			return;
		}
	}
	fUML::Semantics::SimpleClassifiers::StructuredValueImpl::resolveReferences(featureID, references);
}

void ReferenceImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::SimpleClassifiers::StructuredValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ReferenceImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage> package = fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getReferent(), "referent", getReferent()->eClass() != fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getObject_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


std::shared_ptr<ecore::EClass> ReferenceImpl::eStaticClass() const
{
	return fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getReference_Class();
}


//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any ReferenceImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::REFERENCE_ATTRIBUTE_REFERENT:
			{
				std::shared_ptr<ecore::EObject> returnValue=getReferent();
				return eAny(returnValue); //990
			}
	}
	return fUML::Semantics::SimpleClassifiers::StructuredValueImpl::eGet(featureID, resolve, coreType);
}

bool ReferenceImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::REFERENCE_ATTRIBUTE_REFERENT:
			return getReferent() != nullptr; //990
	}
	return fUML::Semantics::SimpleClassifiers::StructuredValueImpl::internalEIsSet(featureID);
}

bool ReferenceImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::REFERENCE_ATTRIBUTE_REFERENT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> _referent = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Object>(_temp);
			setReferent(_referent); //990
			return true;
		}
	}

	return fUML::Semantics::SimpleClassifiers::StructuredValueImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any ReferenceImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 379318105
		case StructuredClassifiersPackage::REFERENCE_OPERATION__COPY:
		{
			result = eAny(this->_copy());
			break;
		}
		
		// 895585040
		case StructuredClassifiersPackage::REFERENCE_OPERATION_ASSIGNFEATUREVALUE_STRUCTURALFEATURE_EINT:
		{
			//Retrieve input parameter 'feature'
			//parameter 0
			std::shared_ptr<uml::StructuralFeature> incoming_param_feature;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_feature_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_feature = (*incoming_param_feature_arguments_citer)->get()->get<std::shared_ptr<uml::StructuralFeature> >();
			//Retrieve input parameter 'values'
			//parameter 1
			std::shared_ptr<Bag<fUML::Semantics::Values::Value>> incoming_param_values;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_values_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_values = (*incoming_param_values_arguments_citer)->get()->get<std::shared_ptr<Bag<fUML::Semantics::Values::Value>> >();
			//Retrieve input parameter 'position'
			//parameter 2
			int incoming_param_position;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_position_arguments_citer = std::next(arguments->begin(), 2);
			incoming_param_position = (*incoming_param_position_arguments_citer)->get()->get<int >();
			this->assignFeatureValue(incoming_param_feature,incoming_param_values,incoming_param_position);
			break;
		}
		
		// 2091249574
		case StructuredClassifiersPackage::REFERENCE_OPERATION_DESTROY:
		{
			this->destroy();
			break;
		}
		
		// 391208876
		case StructuredClassifiersPackage::REFERENCE_OPERATION_DISPATCH_OPERATION:
		{
			//Retrieve input parameter 'operation'
			//parameter 0
			std::shared_ptr<uml::Operation> incoming_param_operation;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_operation_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_operation = (*incoming_param_operation_arguments_citer)->get()->get<std::shared_ptr<uml::Operation> >();
			result = eAny(this->dispatch(incoming_param_operation));
			break;
		}
		
		// 2043258442
		case StructuredClassifiersPackage::REFERENCE_OPERATION_EQUALS_VALUE:
		{
			//Retrieve input parameter 'otherValue'
			//parameter 0
			std::shared_ptr<fUML::Semantics::Values::Value> incoming_param_otherValue;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_otherValue_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_otherValue = (*incoming_param_otherValue_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::Values::Value> >();
			result = eAny(this->equals(incoming_param_otherValue));
			break;
		}
		
		// 341056213
		case StructuredClassifiersPackage::REFERENCE_OPERATION_GETTYPES:
		{
			result = eAny(this->getTypes());
			break;
		}
		
		// 409855785
		case StructuredClassifiersPackage::REFERENCE_OPERATION_GETVALUES_STRUCTURALFEATURE_FEATUREVALUE:
		{
			//Retrieve input parameter 'feature'
			//parameter 0
			std::shared_ptr<uml::StructuralFeature> incoming_param_feature;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_feature_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_feature = (*incoming_param_feature_arguments_citer)->get()->get<std::shared_ptr<uml::StructuralFeature> >();
			//Retrieve input parameter 'featureValues'
			//parameter 1
			std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> incoming_param_featureValues;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_featureValues_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_featureValues = (*incoming_param_featureValues_arguments_citer)->get()->get<std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> >();
			result = eAny(this->getValues(incoming_param_feature,incoming_param_featureValues));
			break;
		}
		
		// 1807744549
		case StructuredClassifiersPackage::REFERENCE_OPERATION_NEW_:
		{
			result = eAny(this->new_());
			break;
		}
		
		// 359785992
		case StructuredClassifiersPackage::REFERENCE_OPERATION_REMOVEVALUE_STRUCTURALFEATURE_VALUE:
		{
			//Retrieve input parameter 'feature'
			//parameter 0
			std::shared_ptr<uml::StructuralFeature> incoming_param_feature;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_feature_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_feature = (*incoming_param_feature_arguments_citer)->get()->get<std::shared_ptr<uml::StructuralFeature> >();
			//Retrieve input parameter 'value'
			//parameter 1
			std::shared_ptr<fUML::Semantics::Values::Value> incoming_param_value;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_value_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_value = (*incoming_param_value_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::Values::Value> >();
			this->removeValue(incoming_param_feature,incoming_param_value);
			break;
		}
		
		// 252923786
		case StructuredClassifiersPackage::REFERENCE_OPERATION_RETRIEVEFEATUREVALUE_STRUCTURALFEATURE:
		{
			//Retrieve input parameter 'feature'
			//parameter 0
			std::shared_ptr<uml::StructuralFeature> incoming_param_feature;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_feature_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_feature = (*incoming_param_feature_arguments_citer)->get()->get<std::shared_ptr<uml::StructuralFeature> >();
			result = eAny(this->retrieveFeatureValue(incoming_param_feature));
			break;
		}
		
		// 1383269448
		case StructuredClassifiersPackage::REFERENCE_OPERATION_RETRIEVEFEATUREVALUES:
		{
			result = eAny(this->retrieveFeatureValues());
			break;
		}
		
		// 736452414
		case StructuredClassifiersPackage::REFERENCE_OPERATION_SEND_SIGNALINSTANCE:
		{
			//Retrieve input parameter 'signalInstance'
			//parameter 0
			std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> incoming_param_signalInstance;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_signalInstance_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_signalInstance = (*incoming_param_signalInstance_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> >();
			this->send(incoming_param_signalInstance);
			break;
		}
		
		// 2041193923
		case StructuredClassifiersPackage::REFERENCE_OPERATION_SEND_EVENTOCCURRENCE:
		{
			//Retrieve input parameter 'eventOccurrence'
			//parameter 0
			std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> incoming_param_eventOccurrence;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_eventOccurrence_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_eventOccurrence = (*incoming_param_eventOccurrence_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> >();
			this->send(incoming_param_eventOccurrence);
			break;
		}
		
		// 1476170621
		case StructuredClassifiersPackage::REFERENCE_OPERATION_SETFEATUREVALUE_STRUCTURALFEATURE_EINT:
		{
			//Retrieve input parameter 'feature'
			//parameter 0
			std::shared_ptr<uml::StructuralFeature> incoming_param_feature;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_feature_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_feature = (*incoming_param_feature_arguments_citer)->get()->get<std::shared_ptr<uml::StructuralFeature> >();
			//Retrieve input parameter 'values'
			//parameter 1
			std::shared_ptr<Bag<fUML::Semantics::Values::Value>> incoming_param_values;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_values_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_values = (*incoming_param_values_arguments_citer)->get()->get<std::shared_ptr<Bag<fUML::Semantics::Values::Value>> >();
			//Retrieve input parameter 'position'
			//parameter 2
			int incoming_param_position;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_position_arguments_citer = std::next(arguments->begin(), 2);
			incoming_param_position = (*incoming_param_position_arguments_citer)->get()->get<int >();
			this->setFeatureValue(incoming_param_feature,incoming_param_values,incoming_param_position);
			break;
		}
		
		// 1959081471
		case StructuredClassifiersPackage::REFERENCE_OPERATION_STARTBEHAVIOR_CLASS_PARAMETERVALUE:
		{
			//Retrieve input parameter 'classifier'
			//parameter 0
			std::shared_ptr<uml::Class> incoming_param_classifier;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_classifier_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_classifier = (*incoming_param_classifier_arguments_citer)->get()->get<std::shared_ptr<uml::Class> >();
			//Retrieve input parameter 'inputs'
			//parameter 1
			std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> incoming_param_inputs;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_inputs_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_inputs = (*incoming_param_inputs_arguments_citer)->get()->get<std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> >();
			this->startBehavior(incoming_param_classifier,incoming_param_inputs);
			break;
		}
		
		// 1690791699
		case StructuredClassifiersPackage::REFERENCE_OPERATION_TOSTRING:
		{
			result = eAny(this->toString());
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::Semantics::SimpleClassifiers::StructuredValueImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}


std::shared_ptr<Reference> ReferenceImpl::getThisReferencePtr() const
{
	return m_thisReferencePtr.lock();
}
void ReferenceImpl::setThisReferencePtr(std::weak_ptr<Reference> thisReferencePtr)
{
	m_thisReferencePtr = thisReferencePtr;
	setThisStructuredValuePtr(thisReferencePtr);
}
