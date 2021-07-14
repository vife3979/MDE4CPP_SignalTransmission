#include "uml/impl/TemplateParameterSubstitutionImpl.hpp"

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
#include "abstractDataTypes/Any.hpp"
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
#include "uml/TemplateBinding.hpp"
#include "uml/TemplateParameter.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TemplateParameterSubstitutionImpl::TemplateParameterSubstitutionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

TemplateParameterSubstitutionImpl::~TemplateParameterSubstitutionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TemplateParameterSubstitution "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
TemplateParameterSubstitutionImpl::TemplateParameterSubstitutionImpl(std::weak_ptr<uml::Element> par_owner)
:TemplateParameterSubstitutionImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
TemplateParameterSubstitutionImpl::TemplateParameterSubstitutionImpl(std::weak_ptr<uml::TemplateBinding> par_templateBinding)
:TemplateParameterSubstitutionImpl()
{
	m_templateBinding = par_templateBinding;
	m_owner = par_templateBinding;
}

TemplateParameterSubstitutionImpl::TemplateParameterSubstitutionImpl(const TemplateParameterSubstitutionImpl & obj): TemplateParameterSubstitutionImpl()
{
	*this = obj;
}

TemplateParameterSubstitutionImpl& TemplateParameterSubstitutionImpl::operator=(const TemplateParameterSubstitutionImpl & obj)
{
	//call overloaded =Operator for each base class
	ElementImpl::operator=(obj);
	TemplateParameterSubstitution::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TemplateParameterSubstitution "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_actual  = obj.getActual();
	m_formal  = obj.getFormal();
	m_templateBinding  = obj.getTemplateBinding();
	//Clone references with containment (deep copy)
	if(obj.getOwnedActual()!=nullptr)
	{
		m_ownedActual = std::dynamic_pointer_cast<uml::ParameterableElement>(obj.getOwnedActual()->copy());
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> TemplateParameterSubstitutionImpl::copy() const
{
	std::shared_ptr<TemplateParameterSubstitutionImpl> element(new TemplateParameterSubstitutionImpl());
	*element =(*this);
	element->setThisTemplateParameterSubstitutionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> TemplateParameterSubstitutionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getTemplateParameterSubstitution_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool TemplateParameterSubstitutionImpl::must_be_compatible(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference actual
*/
std::shared_ptr<uml::ParameterableElement> TemplateParameterSubstitutionImpl::getActual() const
{
//assert(m_actual);
    return m_actual;
}
void TemplateParameterSubstitutionImpl::setActual(std::shared_ptr<uml::ParameterableElement> _actual)
{
    m_actual = _actual;
	
}


/*
Getter & Setter for reference formal
*/
std::shared_ptr<uml::TemplateParameter> TemplateParameterSubstitutionImpl::getFormal() const
{
//assert(m_formal);
    return m_formal;
}
void TemplateParameterSubstitutionImpl::setFormal(std::shared_ptr<uml::TemplateParameter> _formal)
{
    m_formal = _formal;
	
}


/*
Getter & Setter for reference ownedActual
*/
std::shared_ptr<uml::ParameterableElement> TemplateParameterSubstitutionImpl::getOwnedActual() const
{

    return m_ownedActual;
}
void TemplateParameterSubstitutionImpl::setOwnedActual(std::shared_ptr<uml::ParameterableElement> _ownedActual)
{
    m_ownedActual = _ownedActual;
	
	//additional setter call for redefined reference TemplateParameterSubstitution::actual
	this->setActual(_ownedActual);
	
}


/*
Getter & Setter for reference templateBinding
*/
std::weak_ptr<uml::TemplateBinding> TemplateParameterSubstitutionImpl::getTemplateBinding() const
{
//assert(m_templateBinding);
    return m_templateBinding;
}
void TemplateParameterSubstitutionImpl::setTemplateBinding(std::weak_ptr<uml::TemplateBinding> _templateBinding)
{
    m_templateBinding = _templateBinding;
	m_owner = this->getTemplateBinding().lock();
	
	
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> TemplateParameterSubstitutionImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> TemplateParameterSubstitutionImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<TemplateParameterSubstitution> TemplateParameterSubstitutionImpl::getThisTemplateParameterSubstitutionPtr() const
{
	return m_thisTemplateParameterSubstitutionPtr.lock();
}
void TemplateParameterSubstitutionImpl::setThisTemplateParameterSubstitutionPtr(std::weak_ptr<TemplateParameterSubstitution> thisTemplateParameterSubstitutionPtr)
{
	m_thisTemplateParameterSubstitutionPtr = thisTemplateParameterSubstitutionPtr;
	setThisElementPtr(thisTemplateParameterSubstitutionPtr);
}
std::shared_ptr<ecore::EObject> TemplateParameterSubstitutionImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_templateBinding.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any TemplateParameterSubstitutionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::TEMPLATEPARAMETERSUBSTITUTION_ATTRIBUTE_ACTUAL:
			return eAny(getActual()); //2323
		case uml::umlPackage::TEMPLATEPARAMETERSUBSTITUTION_ATTRIBUTE_FORMAL:
			return eAny(getFormal()); //2324
		case uml::umlPackage::TEMPLATEPARAMETERSUBSTITUTION_ATTRIBUTE_OWNEDACTUAL:
			return eAny(getOwnedActual()); //2325
		case uml::umlPackage::TEMPLATEPARAMETERSUBSTITUTION_ATTRIBUTE_TEMPLATEBINDING:
			return eAny(getTemplateBinding().lock()); //2326
	}
	return ElementImpl::eGet(featureID, resolve, coreType);
}
bool TemplateParameterSubstitutionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::TEMPLATEPARAMETERSUBSTITUTION_ATTRIBUTE_ACTUAL:
			return getActual() != nullptr; //2323
		case uml::umlPackage::TEMPLATEPARAMETERSUBSTITUTION_ATTRIBUTE_FORMAL:
			return getFormal() != nullptr; //2324
		case uml::umlPackage::TEMPLATEPARAMETERSUBSTITUTION_ATTRIBUTE_OWNEDACTUAL:
			return getOwnedActual() != nullptr; //2325
		case uml::umlPackage::TEMPLATEPARAMETERSUBSTITUTION_ATTRIBUTE_TEMPLATEBINDING:
			return getTemplateBinding().lock() != nullptr; //2326
	}
	return ElementImpl::internalEIsSet(featureID);
}
bool TemplateParameterSubstitutionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::TEMPLATEPARAMETERSUBSTITUTION_ATTRIBUTE_ACTUAL:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ParameterableElement> _actual = std::dynamic_pointer_cast<uml::ParameterableElement>(_temp);
			setActual(_actual); //2323
			return true;
		}
		case uml::umlPackage::TEMPLATEPARAMETERSUBSTITUTION_ATTRIBUTE_FORMAL:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::TemplateParameter> _formal = std::dynamic_pointer_cast<uml::TemplateParameter>(_temp);
			setFormal(_formal); //2324
			return true;
		}
		case uml::umlPackage::TEMPLATEPARAMETERSUBSTITUTION_ATTRIBUTE_OWNEDACTUAL:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ParameterableElement> _ownedActual = std::dynamic_pointer_cast<uml::ParameterableElement>(_temp);
			setOwnedActual(_ownedActual); //2325
			return true;
		}
		case uml::umlPackage::TEMPLATEPARAMETERSUBSTITUTION_ATTRIBUTE_TEMPLATEBINDING:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::TemplateBinding> _templateBinding = std::dynamic_pointer_cast<uml::TemplateBinding>(_temp);
			setTemplateBinding(_templateBinding); //2326
			return true;
		}
	}

	return ElementImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any TemplateParameterSubstitutionImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 23249
		case umlPackage::TEMPLATEPARAMETERSUBSTITUTION_OPERATION_MUST_BE_COMPATIBLE_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->must_be_compatible(incoming_param_diagnostics,incoming_param_context));
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
void TemplateParameterSubstitutionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void TemplateParameterSubstitutionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("actual");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("actual")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("formal");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("formal")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void TemplateParameterSubstitutionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("ownedActual") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChild(this->getOwnedActual()); 

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
	ElementImpl::loadNode(nodeName, loadHandler);
}

void TemplateParameterSubstitutionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::TEMPLATEPARAMETERSUBSTITUTION_ATTRIBUTE_ACTUAL:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ParameterableElement> _actual = std::dynamic_pointer_cast<uml::ParameterableElement>( references.front() );
				setActual(_actual);
			}
			
			return;
		}

		case uml::umlPackage::TEMPLATEPARAMETERSUBSTITUTION_ATTRIBUTE_FORMAL:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::TemplateParameter> _formal = std::dynamic_pointer_cast<uml::TemplateParameter>( references.front() );
				setFormal(_formal);
			}
			
			return;
		}

		case uml::umlPackage::TEMPLATEPARAMETERSUBSTITUTION_ATTRIBUTE_TEMPLATEBINDING:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::TemplateBinding> _templateBinding = std::dynamic_pointer_cast<uml::TemplateBinding>( references.front() );
				setTemplateBinding(_templateBinding);
			}
			
			return;
		}
	}
	ElementImpl::resolveReferences(featureID, references);
}

void TemplateParameterSubstitutionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void TemplateParameterSubstitutionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'ownedActual'
		std::shared_ptr<uml::ParameterableElement> ownedActual = this->getOwnedActual();
		if (ownedActual != nullptr)
		{
			saveHandler->addReference(ownedActual, "ownedActual", ownedActual->eClass() != package->getParameterableElement_Class());
		}
	// Add references
		saveHandler->addReference(this->getActual(), "actual", getActual()->eClass() != uml::umlPackage::eInstance()->getParameterableElement_Class()); 
		saveHandler->addReference(this->getFormal(), "formal", getFormal()->eClass() != uml::umlPackage::eInstance()->getTemplateParameter_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

