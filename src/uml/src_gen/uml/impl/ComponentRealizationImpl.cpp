#include "uml/impl/ComponentRealizationImpl.hpp"

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


#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Component.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/OpaqueExpression.hpp"
#include "uml/Package.hpp"
#include "uml/Realization.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateParameter.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ComponentRealizationImpl::ComponentRealizationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ComponentRealizationImpl::~ComponentRealizationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ComponentRealization "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ComponentRealizationImpl::ComponentRealizationImpl(std::weak_ptr<uml::Component> par_abstraction)
:ComponentRealizationImpl()
{
	m_abstraction = par_abstraction;
	m_owner = par_abstraction;
}

//Additional constructor for the containments back reference
ComponentRealizationImpl::ComponentRealizationImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ComponentRealizationImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ComponentRealizationImpl::ComponentRealizationImpl(std::weak_ptr<uml::Element> par_owner)
:ComponentRealizationImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ComponentRealizationImpl::ComponentRealizationImpl(std::weak_ptr<uml::Package> par_owningPackage)
:ComponentRealizationImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
ComponentRealizationImpl::ComponentRealizationImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:ComponentRealizationImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

ComponentRealizationImpl::ComponentRealizationImpl(const ComponentRealizationImpl & obj): ComponentRealizationImpl()
{
	*this = obj;
}

ComponentRealizationImpl& ComponentRealizationImpl::operator=(const ComponentRealizationImpl & obj)
{
	//call overloaded =Operator for each base class
	RealizationImpl::operator=(obj);
	ComponentRealization::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ComponentRealization "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_abstraction  = obj.getAbstraction();
	//Clone references with containment (deep copy)
	std::shared_ptr<Subset<uml::Classifier, uml::NamedElement /*Subset does not reference a union*/>> realizingClassifierContainer = getRealizingClassifier();
	if(nullptr != realizingClassifierContainer )
	{
		int size = realizingClassifierContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _realizingClassifier=(*realizingClassifierContainer)[i];
			if(nullptr != _realizingClassifier)
			{
				realizingClassifierContainer->push_back(std::dynamic_pointer_cast<uml::Classifier>(_realizingClassifier->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container realizingClassifier."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr realizingClassifier."<< std::endl;)
	}
	return *this;
}

std::shared_ptr<ecore::EObject> ComponentRealizationImpl::copy() const
{
	std::shared_ptr<ComponentRealizationImpl> element(new ComponentRealizationImpl());
	*element =(*this);
	element->setThisComponentRealizationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ComponentRealizationImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getComponentRealization_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
/*
Getter & Setter for reference abstraction
*/
std::weak_ptr<uml::Component> ComponentRealizationImpl::getAbstraction() const
{

    return m_abstraction;
}
void ComponentRealizationImpl::setAbstraction(std::weak_ptr<uml::Component> _abstraction)
{
    m_abstraction = _abstraction;
}


/*
Getter & Setter for reference realizingClassifier
*/
std::shared_ptr<Subset<uml::Classifier, uml::NamedElement /*Subset does not reference a union*/>> ComponentRealizationImpl::getRealizingClassifier() const
{
	if(m_realizingClassifier == nullptr)
	{
		/*Subset*/
		m_realizingClassifier.reset(new Subset<uml::Classifier, uml::NamedElement /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_realizingClassifier - Subset<uml::Classifier, uml::NamedElement /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		m_realizingClassifier->initSubset(getClient());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_realizingClassifier - Subset<uml::Classifier, uml::NamedElement /*Subset does not reference a union*/ >(getClient())" << std::endl;
		#endif
		
	}
//assert(m_realizingClassifier);
    return m_realizingClassifier;
}



//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> ComponentRealizationImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> ComponentRealizationImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> ComponentRealizationImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::Element>> ComponentRealizationImpl::getRelatedElement() const
{
	if(m_relatedElement == nullptr)
	{
		/*Union*/
		m_relatedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_relatedElement - Union<uml::Element>()" << std::endl;
		#endif
		
		
	}
	return m_relatedElement;
}

std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> ComponentRealizationImpl::getSource() const
{
	if(m_source == nullptr)
	{
		/*SubsetUnion*/
		m_source.reset(new SubsetUnion<uml::Element, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_source - SubsetUnion<uml::Element, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_source->initSubsetUnion(getRelatedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_source - SubsetUnion<uml::Element, uml::Element >(getRelatedElement())" << std::endl;
		#endif
		
	}
	return m_source;
}

std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> ComponentRealizationImpl::getTarget() const
{
	if(m_target == nullptr)
	{
		/*SubsetUnion*/
		m_target.reset(new SubsetUnion<uml::Element, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_target - SubsetUnion<uml::Element, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_target->initSubsetUnion(getRelatedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_target - SubsetUnion<uml::Element, uml::Element >(getRelatedElement())" << std::endl;
		#endif
		
	}
	return m_target;
}




std::shared_ptr<ComponentRealization> ComponentRealizationImpl::getThisComponentRealizationPtr() const
{
	return m_thisComponentRealizationPtr.lock();
}
void ComponentRealizationImpl::setThisComponentRealizationPtr(std::weak_ptr<ComponentRealization> thisComponentRealizationPtr)
{
	m_thisComponentRealizationPtr = thisComponentRealizationPtr;
	setThisRealizationPtr(thisComponentRealizationPtr);
}
std::shared_ptr<ecore::EObject> ComponentRealizationImpl::eContainer() const
{
	if(auto wp = m_abstraction.lock())
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

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ComponentRealizationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::COMPONENTREALIZATION_ATTRIBUTE_ABSTRACTION:
			return eAny(getAbstraction().lock()); //4819
		case uml::umlPackage::COMPONENTREALIZATION_ATTRIBUTE_REALIZINGCLASSIFIER:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Classifier>::iterator iter = getRealizingClassifier()->begin();
			Bag<uml::Classifier>::iterator end = getRealizingClassifier()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //4818			
		}
	}
	return RealizationImpl::eGet(featureID, resolve, coreType);
}
bool ComponentRealizationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::COMPONENTREALIZATION_ATTRIBUTE_ABSTRACTION:
			return getAbstraction().lock() != nullptr; //4819
		case uml::umlPackage::COMPONENTREALIZATION_ATTRIBUTE_REALIZINGCLASSIFIER:
			return getRealizingClassifier() != nullptr; //4818
	}
	return RealizationImpl::internalEIsSet(featureID);
}
bool ComponentRealizationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::COMPONENTREALIZATION_ATTRIBUTE_ABSTRACTION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Component> _abstraction = std::dynamic_pointer_cast<uml::Component>(_temp);
			setAbstraction(_abstraction); //4819
			return true;
		}
		case uml::umlPackage::COMPONENTREALIZATION_ATTRIBUTE_REALIZINGCLASSIFIER:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Classifier>> realizingClassifierList(new Bag<uml::Classifier>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				realizingClassifierList->add(std::dynamic_pointer_cast<uml::Classifier>(*iter));
				iter++;
			}
			
			Bag<uml::Classifier>::iterator iterRealizingClassifier = getRealizingClassifier()->begin();
			Bag<uml::Classifier>::iterator endRealizingClassifier = getRealizingClassifier()->end();
			while (iterRealizingClassifier != endRealizingClassifier)
			{
				if (realizingClassifierList->find(*iterRealizingClassifier) == -1)
				{
					getRealizingClassifier()->erase(*iterRealizingClassifier);
				}
				iterRealizingClassifier++;
			}
 
			iterRealizingClassifier = realizingClassifierList->begin();
			endRealizingClassifier = realizingClassifierList->end();
			while (iterRealizingClassifier != endRealizingClassifier)
			{
				if (getRealizingClassifier()->find(*iterRealizingClassifier) == -1)
				{
					getRealizingClassifier()->add(*iterRealizingClassifier);
				}
				iterRealizingClassifier++;			
			}
			return true;
		}
	}

	return RealizationImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any ComponentRealizationImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = RealizationImpl::eInvoke(operationID, arguments);
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
void ComponentRealizationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ComponentRealizationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("realizingClassifier");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("realizingClassifier")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	RealizationImpl::loadAttributes(loadHandler, attr_list);
}

void ComponentRealizationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	RealizationImpl::loadNode(nodeName, loadHandler);
}

void ComponentRealizationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::COMPONENTREALIZATION_ATTRIBUTE_ABSTRACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Component> _abstraction = std::dynamic_pointer_cast<uml::Component>( references.front() );
				setAbstraction(_abstraction);
			}
			
			return;
		}

		case uml::umlPackage::COMPONENTREALIZATION_ATTRIBUTE_REALIZINGCLASSIFIER:
		{
			std::shared_ptr<Subset<uml::Classifier, uml::NamedElement /*Subset does not reference a union*/>> _realizingClassifier = getRealizingClassifier();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Classifier>  _r = std::dynamic_pointer_cast<uml::Classifier>(ref);
				if (_r != nullptr)
				{
					_realizingClassifier->push_back(_r);
				}
			}
			return;
		}
	}
	RealizationImpl::resolveReferences(featureID, references);
}

void ComponentRealizationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	RealizationImpl::saveContent(saveHandler);
	
	AbstractionImpl::saveContent(saveHandler);
	
	DependencyImpl::saveContent(saveHandler);
	
	DirectedRelationshipImpl::saveContent(saveHandler);
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	RelationshipImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
	
}

void ComponentRealizationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReferences<uml::Classifier>("realizingClassifier", this->getRealizingClassifier());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

