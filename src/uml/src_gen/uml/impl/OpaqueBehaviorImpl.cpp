#include "uml/impl/OpaqueBehaviorImpl.hpp"

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
#include "abstractDataTypes/SubsetUnion.hpp"
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


#include "uml/Behavior.hpp"
#include "uml/BehavioralFeature.hpp"
#include "uml/BehavioredClassifier.hpp"
#include "uml/Class.hpp"
#include "uml/Classifier.hpp"
#include "uml/CollaborationUse.hpp"
#include "uml/Comment.hpp"
#include "uml/ConnectableElement.hpp"
#include "uml/Connector.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/Extension.hpp"
#include "uml/Feature.hpp"
#include "uml/Generalization.hpp"
#include "uml/GeneralizationSet.hpp"
#include "uml/InterfaceRealization.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Operation.hpp"
#include "uml/Package.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/Parameter.hpp"
#include "uml/ParameterSet.hpp"
#include "uml/Port.hpp"
#include "uml/Property.hpp"
#include "uml/Reception.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/Substitution.hpp"
#include "uml/TemplateBinding.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/TemplateSignature.hpp"
#include "uml/UseCase.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
OpaqueBehaviorImpl::OpaqueBehaviorImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

OpaqueBehaviorImpl::~OpaqueBehaviorImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete OpaqueBehavior "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
OpaqueBehaviorImpl::OpaqueBehaviorImpl(std::weak_ptr<uml::BehavioredClassifier> par_behavioredClassifier)
:OpaqueBehaviorImpl()
{
	m_behavioredClassifier = par_behavioredClassifier;
	m_namespace = par_behavioredClassifier;
}

//Additional constructor for the containments back reference
OpaqueBehaviorImpl::OpaqueBehaviorImpl(std::weak_ptr<uml::Namespace> par_namespace)
:OpaqueBehaviorImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
OpaqueBehaviorImpl::OpaqueBehaviorImpl(std::weak_ptr<uml::Element> par_owner)
:OpaqueBehaviorImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
OpaqueBehaviorImpl::OpaqueBehaviorImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:OpaqueBehaviorImpl()
{
	switch(reference_id)
	{	
	case uml::umlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
		m_owningPackage = par_Package;
		m_namespace = par_Package;
		 return;
	case uml::umlPackage::TYPE_ATTRIBUTE_PACKAGE:
		m_package = par_Package;
		m_namespace = par_Package;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}

//Additional constructor for the containments back reference
OpaqueBehaviorImpl::OpaqueBehaviorImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:OpaqueBehaviorImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


OpaqueBehaviorImpl::OpaqueBehaviorImpl(const OpaqueBehaviorImpl & obj): OpaqueBehaviorImpl()
{
	*this = obj;
}

OpaqueBehaviorImpl& OpaqueBehaviorImpl::operator=(const OpaqueBehaviorImpl & obj)
{
	//call overloaded =Operator for each base class
	BehaviorImpl::operator=(obj);
	OpaqueBehavior::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy OpaqueBehavior "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	std::shared_ptr<Bag<std::string>> bodyContainer = getBody();
	if(nullptr != bodyContainer )
	{
		int size = bodyContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _body=(*bodyContainer)[i];	
			if(nullptr != _body)
			{
				bodyContainer->push_back(_body);
			} 
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container body."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr body."<< std::endl;)
	}
	std::shared_ptr<Bag<std::string>> languageContainer = getLanguage();
	if(nullptr != languageContainer )
	{
		int size = languageContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _language=(*languageContainer)[i];	
			if(nullptr != _language)
			{
				languageContainer->push_back(_language);
			} 
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container language."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr language."<< std::endl;)
	}

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> OpaqueBehaviorImpl::copy() const
{
	std::shared_ptr<OpaqueBehaviorImpl> element(new OpaqueBehaviorImpl());
	*element =(*this);
	element->setThisOpaqueBehaviorPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> OpaqueBehaviorImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getOpaqueBehavior_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute body
*/
std::shared_ptr<Bag<std::string>> OpaqueBehaviorImpl::getBody() const 
{
	if(m_body == nullptr)
	{
		m_body.reset(new Bag<std::string>());
	}
	return m_body;
}



/*
Getter & Setter for attribute language
*/
std::shared_ptr<Bag<std::string>> OpaqueBehaviorImpl::getLanguage() const 
{
	if(m_language == nullptr)
	{
		m_language.reset(new Bag<std::string>());
	}
	return m_language;
}



//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> OpaqueBehaviorImpl::getAttribute() const
{
	if(m_attribute == nullptr)
	{
		/*SubsetUnion*/
		m_attribute.reset(new SubsetUnion<uml::Property, uml::Feature >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_attribute - SubsetUnion<uml::Property, uml::Feature >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_attribute->initSubsetUnion(getFeature());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_attribute - SubsetUnion<uml::Property, uml::Feature >(getFeature())" << std::endl;
		#endif
		
	}
	return m_attribute;
}

std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> OpaqueBehaviorImpl::getFeature() const
{
	if(m_feature == nullptr)
	{
		/*SubsetUnion*/
		m_feature.reset(new SubsetUnion<uml::Feature, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_feature - SubsetUnion<uml::Feature, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_feature->initSubsetUnion(getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_feature - SubsetUnion<uml::Feature, uml::NamedElement >(getMember())" << std::endl;
		#endif
		
	}
	return m_feature;
}

std::shared_ptr<Union<uml::NamedElement>> OpaqueBehaviorImpl::getMember() const
{
	if(m_member == nullptr)
	{
		/*Union*/
		m_member.reset(new Union<uml::NamedElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_member - Union<uml::NamedElement>()" << std::endl;
		#endif
		
		
	}
	return m_member;
}

std::weak_ptr<uml::Namespace> OpaqueBehaviorImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> OpaqueBehaviorImpl::getOwnedElement() const
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> OpaqueBehaviorImpl::getOwnedMember() const
{
	if(m_ownedMember == nullptr)
	{
		/*SubsetUnion*/
		m_ownedMember.reset(new SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_ownedMember->initSubsetUnion(getOwnedElement(),getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >(getOwnedElement(),getMember())" << std::endl;
		#endif
		
	}
	return m_ownedMember;
}

std::weak_ptr<uml::Element> OpaqueBehaviorImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> OpaqueBehaviorImpl::getRedefinedElement() const
{
	if(m_redefinedElement == nullptr)
	{
		/*Union*/
		m_redefinedElement.reset(new Union<uml::RedefinableElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinedElement - Union<uml::RedefinableElement>()" << std::endl;
		#endif
		
		
	}
	return m_redefinedElement;
}

std::shared_ptr<Union<uml::Classifier>> OpaqueBehaviorImpl::getRedefinitionContext() const
{
	if(m_redefinitionContext == nullptr)
	{
		/*Union*/
		m_redefinitionContext.reset(new Union<uml::Classifier>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinitionContext - Union<uml::Classifier>()" << std::endl;
		#endif
		
		
	}
	return m_redefinitionContext;
}

std::shared_ptr<SubsetUnion<uml::ConnectableElement, uml::NamedElement>> OpaqueBehaviorImpl::getRole() const
{
	if(m_role == nullptr)
	{
		/*SubsetUnion*/
		m_role.reset(new SubsetUnion<uml::ConnectableElement, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_role - SubsetUnion<uml::ConnectableElement, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_role->initSubsetUnion(getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_role - SubsetUnion<uml::ConnectableElement, uml::NamedElement >(getMember())" << std::endl;
		#endif
		
	}
	return m_role;
}




std::shared_ptr<OpaqueBehavior> OpaqueBehaviorImpl::getThisOpaqueBehaviorPtr() const
{
	return m_thisOpaqueBehaviorPtr.lock();
}
void OpaqueBehaviorImpl::setThisOpaqueBehaviorPtr(std::weak_ptr<OpaqueBehavior> thisOpaqueBehaviorPtr)
{
	m_thisOpaqueBehaviorPtr = thisOpaqueBehaviorPtr;
	setThisBehaviorPtr(thisOpaqueBehaviorPtr);
}
std::shared_ptr<ecore::EObject> OpaqueBehaviorImpl::eContainer() const
{
	if(auto wp = m_behavioredClassifier.lock())
	{
		return wp;
	}

	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_owningPackage.lock())
	{
		return wp;
	}
	if(auto wp = m_package.lock())
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
Any OpaqueBehaviorImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::OPAQUEBEHAVIOR_ATTRIBUTE_BODY:
			return eAny(getBody()); //16561
		case uml::umlPackage::OPAQUEBEHAVIOR_ATTRIBUTE_LANGUAGE:
			return eAny(getLanguage()); //16562
	}
	return BehaviorImpl::eGet(featureID, resolve, coreType);
}
bool OpaqueBehaviorImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::OPAQUEBEHAVIOR_ATTRIBUTE_BODY:
			return !getBody()->empty(); //16561
		case uml::umlPackage::OPAQUEBEHAVIOR_ATTRIBUTE_LANGUAGE:
			return !getLanguage()->empty(); //16562
	}
	return BehaviorImpl::internalEIsSet(featureID);
}
bool OpaqueBehaviorImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::OPAQUEBEHAVIOR_ATTRIBUTE_BODY:
		{
			// BOOST CAST
			// nothing to do
			return true;
		}
		case uml::umlPackage::OPAQUEBEHAVIOR_ATTRIBUTE_LANGUAGE:
		{
			// BOOST CAST
			// nothing to do
			return true;
		}
	}

	return BehaviorImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any OpaqueBehaviorImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = BehaviorImpl::eInvoke(operationID, arguments);
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
void OpaqueBehaviorImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void OpaqueBehaviorImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	BehaviorImpl::loadAttributes(loadHandler, attr_list);
}

void OpaqueBehaviorImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	try
	{
		if (nodeName.compare("body") == 0)
		{
			std::shared_ptr<std::string> value = loadHandler->getChildText();
			std::shared_ptr<Bag<std::string>> list_body = this->getBody();
			list_body->push_back(value);
			return;
		}

		if (nodeName.compare("language") == 0)
		{
			std::shared_ptr<std::string> value = loadHandler->getChildText();
			std::shared_ptr<Bag<std::string>> list_language = this->getLanguage();
			list_language->push_back(value);
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
	BehaviorImpl::loadNode(nodeName, loadHandler);
}

void OpaqueBehaviorImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	BehaviorImpl::resolveReferences(featureID, references);
}

void OpaqueBehaviorImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	BehaviorImpl::saveContent(saveHandler);
	
	ClassImpl::saveContent(saveHandler);
	
	BehavioredClassifierImpl::saveContent(saveHandler);
	EncapsulatedClassifierImpl::saveContent(saveHandler);
	
	StructuredClassifierImpl::saveContent(saveHandler);
	
	ClassifierImpl::saveContent(saveHandler);
	
	NamespaceImpl::saveContent(saveHandler);
	RedefinableElementImpl::saveContent(saveHandler);
	TemplateableElementImpl::saveContent(saveHandler);
	TypeImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
	
	
	
	
}

void OpaqueBehaviorImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getOpaqueBehavior_Attribute_body()) )
		{
			for (std::shared_ptr<std::string> value : *m_body)
			{
				saveHandler->addAttributeAsNode("body", *value);
			}
		}

		if ( this->eIsSet(package->getOpaqueBehavior_Attribute_language()) )
		{
			for (std::shared_ptr<std::string> value : *m_language)
			{
				saveHandler->addAttributeAsNode("language", *value);
			}
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

