#include "fUML/Semantics/CommonBehavior/impl/ParameterValueImpl.hpp"

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
#include "fUML/Semantics/Values/ValuesPackage.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Values/ValuesFactory.hpp"


#include "uml/Parameter.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "fUML/Semantics/Values/Value.hpp"

//Factories an Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::CommonBehavior;

//*********************************
// Constructor / Destructor
//*********************************
ParameterValueImpl::ParameterValueImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ParameterValueImpl::~ParameterValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ParameterValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


ParameterValueImpl::ParameterValueImpl(const ParameterValueImpl & obj): ParameterValueImpl()
{
	*this = obj;
}

ParameterValueImpl& ParameterValueImpl::operator=(const ParameterValueImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::EModelElementImpl::operator=(obj);
	ParameterValue::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ParameterValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_parameter  = obj.getParameter();
	//Clone references with containment (deep copy)
	std::shared_ptr<Bag<fUML::Semantics::Values::Value>> valuesContainer = getValues();
	if(nullptr != valuesContainer )
	{
		int size = valuesContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _values=(*valuesContainer)[i];
			if(nullptr != _values)
			{
				valuesContainer->push_back(std::dynamic_pointer_cast<fUML::Semantics::Values::Value>(_values->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container values."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr values."<< std::endl;)
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> ParameterValueImpl::copy() const
{
	std::shared_ptr<ParameterValueImpl> element(new ParameterValueImpl());
	*element =(*this);
	element->setThisParameterValuePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ParameterValueImpl::eStaticClass() const
{
	return fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getParameterValue_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> ParameterValueImpl::_copy()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Create a new parameter value for the same parameter as this parameter value, but with
// copies of the values of this parameter value.

std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> newValue = fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createParameterValue();
newValue->setParameter(this->getParameter());

std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values = this->getValues();
unsigned int valuesSize = values->size();

for(unsigned int i = 0; i < valuesSize; i++)
{
	std::shared_ptr<fUML::Semantics::Values::Value> value = values->at(i);
	newValue->getValues()->add(value->_copy());
}

return newValue;
	//end of body
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference parameter
*/
std::shared_ptr<uml::Parameter> ParameterValueImpl::getParameter() const
{
//assert(m_parameter);
    return m_parameter;
}
void ParameterValueImpl::setParameter(std::shared_ptr<uml::Parameter> _parameter)
{
    m_parameter = _parameter;
}


/*
Getter & Setter for reference values
*/
std::shared_ptr<Bag<fUML::Semantics::Values::Value>> ParameterValueImpl::getValues() const
{
	if(m_values == nullptr)
	{
		m_values.reset(new Bag<fUML::Semantics::Values::Value>());
		
		
	}

    return m_values;
}



//*********************************
// Union Getter
//*********************************



std::shared_ptr<ParameterValue> ParameterValueImpl::getThisParameterValuePtr() const
{
	return m_thisParameterValuePtr.lock();
}
void ParameterValueImpl::setThisParameterValuePtr(std::weak_ptr<ParameterValue> thisParameterValuePtr)
{
	m_thisParameterValuePtr = thisParameterValuePtr;
}
std::shared_ptr<ecore::EObject> ParameterValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ParameterValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_ATTRIBUTE_PARAMETER:
			return eAny(getParameter()); //870
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_ATTRIBUTE_VALUES:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<fUML::Semantics::Values::Value>::iterator iter = getValues()->begin();
			Bag<fUML::Semantics::Values::Value>::iterator end = getValues()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //871			
		}
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}
bool ParameterValueImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_ATTRIBUTE_PARAMETER:
			return getParameter() != nullptr; //870
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_ATTRIBUTE_VALUES:
			return getValues() != nullptr; //871
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool ParameterValueImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_ATTRIBUTE_PARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Parameter> _parameter = std::dynamic_pointer_cast<uml::Parameter>(_temp);
			setParameter(_parameter); //870
			return true;
		}
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_ATTRIBUTE_VALUES:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::Semantics::Values::Value>> valuesList(new Bag<fUML::Semantics::Values::Value>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				valuesList->add(std::dynamic_pointer_cast<fUML::Semantics::Values::Value>(*iter));
				iter++;
			}
			
			Bag<fUML::Semantics::Values::Value>::iterator iterValues = getValues()->begin();
			Bag<fUML::Semantics::Values::Value>::iterator endValues = getValues()->end();
			while (iterValues != endValues)
			{
				if (valuesList->find(*iterValues) == -1)
				{
					getValues()->erase(*iterValues);
				}
				iterValues++;
			}
 
			iterValues = valuesList->begin();
			endValues = valuesList->end();
			while (iterValues != endValues)
			{
				if (getValues()->find(*iterValues) == -1)
				{
					getValues()->add(*iterValues);
				}
				iterValues++;			
			}
			return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any ParameterValueImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 8702
		case CommonBehaviorPackage::PARAMETERVALUE_OPERATION__COPY:
		{
			result = eAny(this->_copy());
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
void ParameterValueImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ParameterValueImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("parameter");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("parameter")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void ParameterValueImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("values") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChildContainer<fUML::Semantics::Values::Value>(this->getValues());  

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

void ParameterValueImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_ATTRIBUTE_PARAMETER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Parameter> _parameter = std::dynamic_pointer_cast<uml::Parameter>( references.front() );
				setParameter(_parameter);
			}
			
			return;
		}
	}
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void ParameterValueImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void ParameterValueImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::CommonBehavior::CommonBehaviorPackage> package = fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getParameter(), "parameter", getParameter()->eClass() != uml::umlPackage::eInstance()->getParameter_Class()); 
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'values'

		saveHandler->addReferences<fUML::Semantics::Values::Value>("values", this->getValues());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

