
#include "fUML/Semantics/Activities/impl/ObjectTokenImpl.hpp"
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



#include "abstractDataTypes/AnyEObject.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Includes from codegen annotation
 #include "fUML/Semantics/Values/ValuesPackage.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "fUML/Semantics/Values/ValuesFactory.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
#include "fUML/Semantics/Values/Value.hpp"
//Factories and Package includes
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"

using namespace fUML::Semantics::Activities;

//*********************************
// Constructor / Destructor
//*********************************
ObjectTokenImpl::ObjectTokenImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ObjectTokenImpl::~ObjectTokenImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ObjectToken "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ObjectTokenImpl::ObjectTokenImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivation> par_holder)
:ObjectTokenImpl()
{
	m_holder = par_holder;
}

ObjectTokenImpl::ObjectTokenImpl(const ObjectTokenImpl & obj): ObjectTokenImpl()
{
	*this = obj;
}

ObjectTokenImpl& ObjectTokenImpl::operator=(const ObjectTokenImpl & obj)
{
	//call overloaded =Operator for each base class
	TokenImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ObjectToken 
	 * which is generated by the compiler (as ObjectToken is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ObjectToken::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ObjectToken "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'value'
	if(obj.getValue()!=nullptr)
	{
		m_value = std::dynamic_pointer_cast<fUML::Semantics::Values::Value>(obj.getValue()->copy());
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> ObjectTokenImpl::copy() const
{
	std::shared_ptr<ObjectTokenImpl> element(new ObjectTokenImpl());
	*element =(*this);
	element->setThisObjectTokenPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Activities::Token> ObjectTokenImpl::_copy()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Return a new object token with the same value as this token.
// [Note: the holder of the copy is not set.]

std::shared_ptr<fUML::Semantics::Activities::ObjectToken> copy = fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createObjectToken();
copy->setValue(this->getValue());

return copy;
	//end of body
}

bool ObjectTokenImpl::equals(std::shared_ptr<fUML::Semantics::Activities::Token> other)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return (this == other.get());
	//end of body
}

bool ObjectTokenImpl::isControl()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return false;
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference value */
std::shared_ptr<fUML::Semantics::Values::Value> ObjectTokenImpl::getValue() const
{
    return m_value;
}
void ObjectTokenImpl::setValue(std::shared_ptr<fUML::Semantics::Values::Value> _value)
{
    m_value = _value;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ObjectTokenImpl::eContainer() const
{
	if(auto wp = m_holder.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void ObjectTokenImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ObjectTokenImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	TokenImpl::loadAttributes(loadHandler, attr_list);
}

void ObjectTokenImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("value") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChild(this->getValue()); 

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
	TokenImpl::loadNode(nodeName, loadHandler);
}

void ObjectTokenImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	TokenImpl::resolveReferences(featureID, references);
}

void ObjectTokenImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	TokenImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ObjectTokenImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Activities::ActivitiesPackage> package = fUML::Semantics::Activities::ActivitiesPackage::eInstance();
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'value'

		saveHandler->addReference(this->getValue(), "value", getValue()->eClass() != fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ObjectTokenImpl::eStaticClass() const
{
	return fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getObjectToken_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any ObjectTokenImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::OBJECTTOKEN_ATTRIBUTE_VALUE:
			return eAny(getValue(),fUML::Semantics::Values::ValuesPackage::VALUE_CLASS,false); //832
	}
	return TokenImpl::eGet(featureID, resolve, coreType);
}

bool ObjectTokenImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::OBJECTTOKEN_ATTRIBUTE_VALUE:
			return getValue() != nullptr; //832
	}
	return TokenImpl::internalEIsSet(featureID);
}

bool ObjectTokenImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::OBJECTTOKEN_ATTRIBUTE_VALUE:
		{
			// CAST Any to fUML::Semantics::Values::Value
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::Values::Value> _value = std::dynamic_pointer_cast<fUML::Semantics::Values::Value>(_temp);
			setValue(_value); //832
			return true;
		}
	}

	return TokenImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any ObjectTokenImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Activities::ObjectToken::_copy() : fUML::Semantics::Activities::Token: 2325156054
		case ActivitiesPackage::OBJECTTOKEN_OPERATION__COPY:
		{
			result = eAnyObject(this->_copy(), fUML::Semantics::Activities::ActivitiesPackage::TOKEN_CLASS);
			break;
		}
		// fUML::Semantics::Activities::ObjectToken::equals(fUML::Semantics::Activities::Token) : bool: 1120332551
		case ActivitiesPackage::OBJECTTOKEN_OPERATION_EQUALS_TOKEN:
		{
			//Retrieve input parameter 'other'
			//parameter 0
			std::shared_ptr<fUML::Semantics::Activities::Token> incoming_param_other;
			std::list<Any>::const_iterator incoming_param_other_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_other = (*incoming_param_other_arguments_citer)->get<std::shared_ptr<fUML::Semantics::Activities::Token> >();
			result = eAny(this->equals(incoming_param_other),0,false);
			break;
		}
		// fUML::Semantics::Activities::ObjectToken::isControl() : bool: 3725482608
		case ActivitiesPackage::OBJECTTOKEN_OPERATION_ISCONTROL:
		{
			result = eAny(this->isControl(),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = TokenImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Activities::ObjectToken> ObjectTokenImpl::getThisObjectTokenPtr() const
{
	return m_thisObjectTokenPtr.lock();
}
void ObjectTokenImpl::setThisObjectTokenPtr(std::weak_ptr<fUML::Semantics::Activities::ObjectToken> thisObjectTokenPtr)
{
	m_thisObjectTokenPtr = thisObjectTokenPtr;
	setThisTokenPtr(thisObjectTokenPtr);
}


