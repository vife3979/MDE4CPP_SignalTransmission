#include "uml/impl/DeploymentImpl.hpp"

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


#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/DeployedArtifact.hpp"
#include "uml/DeploymentSpecification.hpp"
#include "uml/DeploymentTarget.hpp"
#include "uml/Element.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
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
DeploymentImpl::DeploymentImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

DeploymentImpl::~DeploymentImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Deployment "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
DeploymentImpl::DeploymentImpl(std::weak_ptr<uml::DeploymentTarget> par_location)
:DeploymentImpl()
{
	m_location = par_location;
	m_owner = par_location;
}

//Additional constructor for the containments back reference
DeploymentImpl::DeploymentImpl(std::weak_ptr<uml::Namespace> par_namespace)
:DeploymentImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
DeploymentImpl::DeploymentImpl(std::weak_ptr<uml::Element> par_owner)
:DeploymentImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
DeploymentImpl::DeploymentImpl(std::weak_ptr<uml::Package> par_owningPackage)
:DeploymentImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
DeploymentImpl::DeploymentImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:DeploymentImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

DeploymentImpl::DeploymentImpl(const DeploymentImpl & obj): DeploymentImpl()
{
	*this = obj;
}

DeploymentImpl& DeploymentImpl::operator=(const DeploymentImpl & obj)
{
	//call overloaded =Operator for each base class
	DependencyImpl::operator=(obj);
	Deployment::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Deployment "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_location  = obj.getLocation();
	//Clone references with containment (deep copy)
	std::shared_ptr<Subset<uml::DeploymentSpecification, uml::Element>> configurationContainer = getConfiguration();
	if(nullptr != configurationContainer )
	{
		int size = configurationContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _configuration=(*configurationContainer)[i];
			if(nullptr != _configuration)
			{
				configurationContainer->push_back(std::dynamic_pointer_cast<uml::DeploymentSpecification>(_configuration->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container configuration."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr configuration."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::DeployedArtifact, uml::NamedElement /*Subset does not reference a union*/>> deployedArtifactContainer = getDeployedArtifact();
	if(nullptr != deployedArtifactContainer )
	{
		int size = deployedArtifactContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _deployedArtifact=(*deployedArtifactContainer)[i];
			if(nullptr != _deployedArtifact)
			{
				deployedArtifactContainer->push_back(std::dynamic_pointer_cast<uml::DeployedArtifact>(_deployedArtifact->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container deployedArtifact."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr deployedArtifact."<< std::endl;)
	}
	/*Subset*/
	m_configuration->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_configuration - Subset<uml::DeploymentSpecification, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> DeploymentImpl::copy() const
{
	std::shared_ptr<DeploymentImpl> element(new DeploymentImpl());
	*element =(*this);
	element->setThisDeploymentPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> DeploymentImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getDeployment_Class();
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
Getter & Setter for reference configuration
*/
std::shared_ptr<Subset<uml::DeploymentSpecification, uml::Element>> DeploymentImpl::getConfiguration() const
{
	if(m_configuration == nullptr)
	{
		/*Subset*/
		m_configuration.reset(new Subset<uml::DeploymentSpecification, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_configuration - Subset<uml::DeploymentSpecification, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_configuration->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_configuration - Subset<uml::DeploymentSpecification, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_configuration;
}



/*
Getter & Setter for reference deployedArtifact
*/
std::shared_ptr<Subset<uml::DeployedArtifact, uml::NamedElement /*Subset does not reference a union*/>> DeploymentImpl::getDeployedArtifact() const
{
	if(m_deployedArtifact == nullptr)
	{
		/*Subset*/
		m_deployedArtifact.reset(new Subset<uml::DeployedArtifact, uml::NamedElement /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_deployedArtifact - Subset<uml::DeployedArtifact, uml::NamedElement /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		m_deployedArtifact->initSubset(getSupplier());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_deployedArtifact - Subset<uml::DeployedArtifact, uml::NamedElement /*Subset does not reference a union*/ >(getSupplier())" << std::endl;
		#endif
		
	}

    return m_deployedArtifact;
}



/*
Getter & Setter for reference location
*/
std::weak_ptr<uml::DeploymentTarget> DeploymentImpl::getLocation() const
{
//assert(m_location);
    return m_location;
}
void DeploymentImpl::setLocation(std::weak_ptr<uml::DeploymentTarget> _location)
{
    m_location = _location;
}


//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> DeploymentImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> DeploymentImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> DeploymentImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::Element>> DeploymentImpl::getRelatedElement() const
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

std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> DeploymentImpl::getSource() const
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

std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> DeploymentImpl::getTarget() const
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




std::shared_ptr<Deployment> DeploymentImpl::getThisDeploymentPtr() const
{
	return m_thisDeploymentPtr.lock();
}
void DeploymentImpl::setThisDeploymentPtr(std::weak_ptr<Deployment> thisDeploymentPtr)
{
	m_thisDeploymentPtr = thisDeploymentPtr;
	setThisDependencyPtr(thisDeploymentPtr);
}
std::shared_ptr<ecore::EObject> DeploymentImpl::eContainer() const
{
	if(auto wp = m_location.lock())
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
Any DeploymentImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::DEPLOYMENT_ATTRIBUTE_CONFIGURATION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::DeploymentSpecification>::iterator iter = m_configuration->begin();
			Bag<uml::DeploymentSpecification>::iterator end = m_configuration->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //6917			
		}
		case uml::umlPackage::DEPLOYMENT_ATTRIBUTE_DEPLOYEDARTIFACT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::DeployedArtifact>::iterator iter = m_deployedArtifact->begin();
			Bag<uml::DeployedArtifact>::iterator end = m_deployedArtifact->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //6918			
		}
		case uml::umlPackage::DEPLOYMENT_ATTRIBUTE_LOCATION:
			return eAny(getLocation().lock()); //6919
	}
	return DependencyImpl::eGet(featureID, resolve, coreType);
}
bool DeploymentImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::DEPLOYMENT_ATTRIBUTE_CONFIGURATION:
			return getConfiguration() != nullptr; //6917
		case uml::umlPackage::DEPLOYMENT_ATTRIBUTE_DEPLOYEDARTIFACT:
			return getDeployedArtifact() != nullptr; //6918
		case uml::umlPackage::DEPLOYMENT_ATTRIBUTE_LOCATION:
			return getLocation().lock() != nullptr; //6919
	}
	return DependencyImpl::internalEIsSet(featureID);
}
bool DeploymentImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::DEPLOYMENT_ATTRIBUTE_CONFIGURATION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::DeploymentSpecification>> configurationList(new Bag<uml::DeploymentSpecification>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				configurationList->add(std::dynamic_pointer_cast<uml::DeploymentSpecification>(*iter));
				iter++;
			}
			
			Bag<uml::DeploymentSpecification>::iterator iterConfiguration = m_configuration->begin();
			Bag<uml::DeploymentSpecification>::iterator endConfiguration = m_configuration->end();
			while (iterConfiguration != endConfiguration)
			{
				if (configurationList->find(*iterConfiguration) == -1)
				{
					m_configuration->erase(*iterConfiguration);
				}
				iterConfiguration++;
			}
 
			iterConfiguration = configurationList->begin();
			endConfiguration = configurationList->end();
			while (iterConfiguration != endConfiguration)
			{
				if (m_configuration->find(*iterConfiguration) == -1)
				{
					m_configuration->add(*iterConfiguration);
				}
				iterConfiguration++;			
			}
			return true;
		}
		case uml::umlPackage::DEPLOYMENT_ATTRIBUTE_DEPLOYEDARTIFACT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::DeployedArtifact>> deployedArtifactList(new Bag<uml::DeployedArtifact>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				deployedArtifactList->add(std::dynamic_pointer_cast<uml::DeployedArtifact>(*iter));
				iter++;
			}
			
			Bag<uml::DeployedArtifact>::iterator iterDeployedArtifact = m_deployedArtifact->begin();
			Bag<uml::DeployedArtifact>::iterator endDeployedArtifact = m_deployedArtifact->end();
			while (iterDeployedArtifact != endDeployedArtifact)
			{
				if (deployedArtifactList->find(*iterDeployedArtifact) == -1)
				{
					m_deployedArtifact->erase(*iterDeployedArtifact);
				}
				iterDeployedArtifact++;
			}
 
			iterDeployedArtifact = deployedArtifactList->begin();
			endDeployedArtifact = deployedArtifactList->end();
			while (iterDeployedArtifact != endDeployedArtifact)
			{
				if (m_deployedArtifact->find(*iterDeployedArtifact) == -1)
				{
					m_deployedArtifact->add(*iterDeployedArtifact);
				}
				iterDeployedArtifact++;			
			}
			return true;
		}
		case uml::umlPackage::DEPLOYMENT_ATTRIBUTE_LOCATION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::DeploymentTarget> _location = std::dynamic_pointer_cast<uml::DeploymentTarget>(_temp);
			setLocation(_location); //6919
			return true;
		}
	}

	return DependencyImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any DeploymentImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = DependencyImpl::eInvoke(operationID, arguments);
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
void DeploymentImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void DeploymentImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("deployedArtifact");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("deployedArtifact")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	DependencyImpl::loadAttributes(loadHandler, attr_list);
}

void DeploymentImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("configuration") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "DeploymentSpecification";
			}
			loadHandler->handleChildContainer<uml::DeploymentSpecification>(this->getConfiguration());  

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
	DependencyImpl::loadNode(nodeName, loadHandler);
}

void DeploymentImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::DEPLOYMENT_ATTRIBUTE_DEPLOYEDARTIFACT:
		{
			std::shared_ptr<Subset<uml::DeployedArtifact, uml::NamedElement /*Subset does not reference a union*/>> _deployedArtifact = getDeployedArtifact();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::DeployedArtifact>  _r = std::dynamic_pointer_cast<uml::DeployedArtifact>(ref);
				if (_r != nullptr)
				{
					_deployedArtifact->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::DEPLOYMENT_ATTRIBUTE_LOCATION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::DeploymentTarget> _location = std::dynamic_pointer_cast<uml::DeploymentTarget>( references.front() );
				setLocation(_location);
			}
			
			return;
		}
	}
	DependencyImpl::resolveReferences(featureID, references);
}

void DeploymentImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

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

void DeploymentImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'configuration'
		for (std::shared_ptr<uml::DeploymentSpecification> configuration : *this->getConfiguration()) 
		{
			saveHandler->addReference(configuration, "configuration", configuration->eClass() != package->getDeploymentSpecification_Class());
		}
	// Add references
		saveHandler->addReferences<uml::DeployedArtifact>("deployedArtifact", this->getDeployedArtifact());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

