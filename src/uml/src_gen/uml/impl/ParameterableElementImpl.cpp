#include "uml/impl/ParameterableElementImpl.hpp"

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
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"


#include "uml/Comment.hpp"
#include "uml/Element.hpp"
#include "uml/ParameterableElement.hpp"
#include "uml/TemplateParameter.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ParameterableElementImpl::ParameterableElementImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ParameterableElementImpl::~ParameterableElementImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ParameterableElement "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ParameterableElementImpl::ParameterableElementImpl(std::weak_ptr<uml::Element> par_owner)
:ParameterableElementImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ParameterableElementImpl::ParameterableElementImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:ParameterableElementImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

ParameterableElementImpl::ParameterableElementImpl(const ParameterableElementImpl & obj): ParameterableElementImpl()
{
	*this = obj;
}

ParameterableElementImpl& ParameterableElementImpl::operator=(const ParameterableElementImpl & obj)
{
	//call overloaded =Operator for each base class
	ElementImpl::operator=(obj);
	ParameterableElement::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ParameterableElement "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_owningTemplateParameter  = obj.getOwningTemplateParameter();
	m_templateParameter  = obj.getTemplateParameter();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ParameterableElementImpl::copy() const
{
	std::shared_ptr<ParameterableElementImpl> element(new ParameterableElementImpl());
	*element =(*this);
	element->setThisParameterableElementPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ParameterableElementImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getParameterableElement_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ParameterableElementImpl::isCompatibleWith(std::shared_ptr<uml::ParameterableElement> p)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ParameterableElementImpl::isTemplateParameter()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference owningTemplateParameter
*/
std::weak_ptr<uml::TemplateParameter> ParameterableElementImpl::getOwningTemplateParameter() const
{

    return m_owningTemplateParameter;
}
void ParameterableElementImpl::setOwningTemplateParameter(std::weak_ptr<uml::TemplateParameter> _owningTemplateParameter)
{
    m_owningTemplateParameter = _owningTemplateParameter;
}


/*
Getter & Setter for reference templateParameter
*/
std::shared_ptr<uml::TemplateParameter> ParameterableElementImpl::getTemplateParameter() const
{

    return m_templateParameter;
}
void ParameterableElementImpl::setTemplateParameter(std::shared_ptr<uml::TemplateParameter> _templateParameter)
{
    m_templateParameter = _templateParameter;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> ParameterableElementImpl::getOwnedElement() const
{
	if(m_ownedElement == nullptr)
	{
		/*Union*/
		m_ownedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_ownedElement - Union<uml::Element>()" << std::endl;
		#endif
		
		
	}
	return m_ownedElement;
}

std::weak_ptr<uml::Element> ParameterableElementImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<ParameterableElement> ParameterableElementImpl::getThisParameterableElementPtr() const
{
	return m_thisParameterableElementPtr.lock();
}
void ParameterableElementImpl::setThisParameterableElementPtr(std::weak_ptr<ParameterableElement> thisParameterableElementPtr)
{
	m_thisParameterableElementPtr = thisParameterableElementPtr;
	setThisElementPtr(thisParameterableElementPtr);
}
std::shared_ptr<ecore::EObject> ParameterableElementImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ParameterableElementImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
			return eAny(getOwningTemplateParameter().lock()); //1783
		case uml::umlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_TEMPLATEPARAMETER:
			return eAny(getTemplateParameter()); //1784
	}
	return ElementImpl::eGet(featureID, resolve, coreType);
}
bool ParameterableElementImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter().lock() != nullptr; //1783
		case uml::umlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_TEMPLATEPARAMETER:
			return getTemplateParameter() != nullptr; //1784
	}
	return ElementImpl::internalEIsSet(featureID);
}
bool ParameterableElementImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::TemplateParameter> _owningTemplateParameter = std::dynamic_pointer_cast<uml::TemplateParameter>(_temp);
			setOwningTemplateParameter(_owningTemplateParameter); //1783
			return true;
		}
		case uml::umlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_TEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::TemplateParameter> _templateParameter = std::dynamic_pointer_cast<uml::TemplateParameter>(_temp);
			setTemplateParameter(_templateParameter); //1784
			return true;
		}
	}

	return ElementImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any ParameterableElementImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 17847
		case umlPackage::PARAMETERABLEELEMENT_OPERATION_ISCOMPATIBLEWITH_PARAMETERABLEELEMENT:
		{
			//Retrieve input parameter 'p'
			//parameter 0
			std::shared_ptr<uml::ParameterableElement> incoming_param_p;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_p_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_p = (*incoming_param_p_arguments_citer)->get()->get<std::shared_ptr<uml::ParameterableElement> >();
			result = eAny(this->isCompatibleWith(incoming_param_p));
			break;
		}
		
		// 17848
		case umlPackage::PARAMETERABLEELEMENT_OPERATION_ISTEMPLATEPARAMETER:
		{
			result = eAny(this->isTemplateParameter());
			break;
		}

		default:
		{
			// call superTypes
			result = ElementImpl::eInvoke(operationID, arguments);
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
void ParameterableElementImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get umlFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void ParameterableElementImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("templateParameter");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("templateParameter")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ElementImpl::loadAttributes(loadHandler, attr_list);
}

void ParameterableElementImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ElementImpl::loadNode(nodeName, loadHandler);
}

void ParameterableElementImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::TemplateParameter> _owningTemplateParameter = std::dynamic_pointer_cast<uml::TemplateParameter>( references.front() );
				setOwningTemplateParameter(_owningTemplateParameter);
			}
			
			return;
		}

		case uml::umlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_TEMPLATEPARAMETER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::TemplateParameter> _templateParameter = std::dynamic_pointer_cast<uml::TemplateParameter>( references.front() );
				setTemplateParameter(_templateParameter);
			}
			
			return;
		}
	}
	ElementImpl::resolveReferences(featureID, references);
}

void ParameterableElementImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void ParameterableElementImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getTemplateParameter(), "templateParameter", getTemplateParameter()->eClass() != uml::umlPackage::eInstance()->getTemplateParameter_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

