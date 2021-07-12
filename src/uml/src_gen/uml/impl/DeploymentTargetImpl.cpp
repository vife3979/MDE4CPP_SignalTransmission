#include "uml/impl/DeploymentTargetImpl.hpp"

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
#include "uml/Deployment.hpp"
#include "uml/Element.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/StringExpression.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
DeploymentTargetImpl::DeploymentTargetImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

DeploymentTargetImpl::~DeploymentTargetImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DeploymentTarget "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
DeploymentTargetImpl::DeploymentTargetImpl(std::weak_ptr<uml::Namespace> par_namespace)
:DeploymentTargetImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
DeploymentTargetImpl::DeploymentTargetImpl(std::weak_ptr<uml::Element> par_owner)
:DeploymentTargetImpl()
{
	m_owner = par_owner;
}

DeploymentTargetImpl::DeploymentTargetImpl(const DeploymentTargetImpl & obj): DeploymentTargetImpl()
{
	*this = obj;
}

DeploymentTargetImpl& DeploymentTargetImpl::operator=(const DeploymentTargetImpl & obj)
{
	//call overloaded =Operator for each base class
	NamedElementImpl::operator=(obj);
	DeploymentTarget::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DeploymentTarget "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	std::shared_ptr<Bag<uml::PackageableElement>> _deployedElement = obj.getDeployedElement();
	m_deployedElement.reset(new Bag<uml::PackageableElement>(*(obj.getDeployedElement().get())));
	//Clone references with containment (deep copy)
	std::shared_ptr<Subset<uml::Deployment, uml::Element>> deploymentContainer = getDeployment();
	if(nullptr != deploymentContainer )
	{
		int size = deploymentContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _deployment=(*deploymentContainer)[i];
			if(nullptr != _deployment)
			{
				deploymentContainer->push_back(std::dynamic_pointer_cast<uml::Deployment>(_deployment->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container deployment."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr deployment."<< std::endl;)
	}
	/*Subset*/
	m_deployment->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_deployment - Subset<uml::Deployment, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> DeploymentTargetImpl::copy() const
{
	std::shared_ptr<DeploymentTargetImpl> element(new DeploymentTargetImpl());
	*element =(*this);
	element->setThisDeploymentTargetPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> DeploymentTargetImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getDeploymentTarget_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::PackageableElement> > DeploymentTargetImpl::getDeployedElements()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference deployedElement
*/
std::shared_ptr<Bag<uml::PackageableElement>> DeploymentTargetImpl::getDeployedElement() const
{
	if(m_deployedElement == nullptr)
	{
		m_deployedElement.reset(new Bag<uml::PackageableElement>());
		
		
	}

    return m_deployedElement;
}



/*
Getter & Setter for reference deployment
*/
std::shared_ptr<Subset<uml::Deployment, uml::Element>> DeploymentTargetImpl::getDeployment() const
{
	if(m_deployment == nullptr)
	{
		/*Subset*/
		m_deployment.reset(new Subset<uml::Deployment, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_deployment - Subset<uml::Deployment, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_deployment->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_deployment - Subset<uml::Deployment, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_deployment;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> DeploymentTargetImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> DeploymentTargetImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<DeploymentTarget> DeploymentTargetImpl::getThisDeploymentTargetPtr() const
{
	return m_thisDeploymentTargetPtr.lock();
}
void DeploymentTargetImpl::setThisDeploymentTargetPtr(std::weak_ptr<DeploymentTarget> thisDeploymentTargetPtr)
{
	m_thisDeploymentTargetPtr = thisDeploymentTargetPtr;
	setThisNamedElementPtr(thisDeploymentTargetPtr);
}
std::shared_ptr<ecore::EObject> DeploymentTargetImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any DeploymentTargetImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::DEPLOYMENTTARGET_ATTRIBUTE_DEPLOYEDELEMENT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::PackageableElement>::iterator iter = getDeployedElement()->begin();
			Bag<uml::PackageableElement>::iterator end = getDeployedElement()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //719			
		}
		case uml::umlPackage::DEPLOYMENTTARGET_ATTRIBUTE_DEPLOYMENT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Deployment>::iterator iter = getDeployment()->begin();
			Bag<uml::Deployment>::iterator end = getDeployment()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //7110			
		}
	}
	return NamedElementImpl::eGet(featureID, resolve, coreType);
}
bool DeploymentTargetImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::DEPLOYMENTTARGET_ATTRIBUTE_DEPLOYEDELEMENT:
			return getDeployedElement() != nullptr; //719
		case uml::umlPackage::DEPLOYMENTTARGET_ATTRIBUTE_DEPLOYMENT:
			return getDeployment() != nullptr; //7110
	}
	return NamedElementImpl::internalEIsSet(featureID);
}
bool DeploymentTargetImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::DEPLOYMENTTARGET_ATTRIBUTE_DEPLOYMENT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Deployment>> deploymentList(new Bag<uml::Deployment>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				deploymentList->add(std::dynamic_pointer_cast<uml::Deployment>(*iter));
				iter++;
			}
			
			Bag<uml::Deployment>::iterator iterDeployment = getDeployment()->begin();
			Bag<uml::Deployment>::iterator endDeployment = getDeployment()->end();
			while (iterDeployment != endDeployment)
			{
				if (deploymentList->find(*iterDeployment) == -1)
				{
					getDeployment()->erase(*iterDeployment);
				}
				iterDeployment++;
			}
 
			iterDeployment = deploymentList->begin();
			endDeployment = deploymentList->end();
			while (iterDeployment != endDeployment)
			{
				if (getDeployment()->find(*iterDeployment) == -1)
				{
					getDeployment()->add(*iterDeployment);
				}
				iterDeployment++;			
			}
			return true;
		}
	}

	return NamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any DeploymentTargetImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 7167
		case umlPackage::DEPLOYMENTTARGET_OPERATION_GETDEPLOYEDELEMENTS:
		{
			result = eAny(this->getDeployedElements());
			break;
		}

		default:
		{
			// call superTypes
			result = NamedElementImpl::eInvoke(operationID, arguments);
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
void DeploymentTargetImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void DeploymentTargetImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	NamedElementImpl::loadAttributes(loadHandler, attr_list);
}

void DeploymentTargetImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("deployment") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Deployment";
			}
			loadHandler->handleChildContainer<uml::Deployment>(this->getDeployment());  

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
	NamedElementImpl::loadNode(nodeName, loadHandler);
}

void DeploymentTargetImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	NamedElementImpl::resolveReferences(featureID, references);
}

void DeploymentTargetImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void DeploymentTargetImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'deployment'
		for (std::shared_ptr<uml::Deployment> deployment : *this->getDeployment()) 
		{
			saveHandler->addReference(deployment, "deployment", deployment->eClass() != package->getDeployment_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

