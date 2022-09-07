
#include "uml/impl/BehaviorExecutionSpecificationImpl.hpp"
#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
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

#include "abstractDataTypes/SubsetUnion.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "uml/Behavior.hpp"
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ExecutionSpecification.hpp"
#include "uml/GeneralOrdering.hpp"
#include "uml/Interaction.hpp"
#include "uml/InteractionOperand.hpp"
#include "uml/Lifeline.hpp"
#include "uml/Namespace.hpp"
#include "uml/OccurrenceSpecification.hpp"
#include "uml/StringExpression.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
BehaviorExecutionSpecificationImpl::BehaviorExecutionSpecificationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

BehaviorExecutionSpecificationImpl::~BehaviorExecutionSpecificationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete BehaviorExecutionSpecification "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
BehaviorExecutionSpecificationImpl::BehaviorExecutionSpecificationImpl(std::weak_ptr<uml::Interaction> par_enclosingInteraction)
:BehaviorExecutionSpecificationImpl()
{
	m_enclosingInteraction = par_enclosingInteraction;
	m_namespace = par_enclosingInteraction;
}

//Additional constructor for the containments back reference
BehaviorExecutionSpecificationImpl::BehaviorExecutionSpecificationImpl(std::weak_ptr<uml::InteractionOperand> par_enclosingOperand)
:BehaviorExecutionSpecificationImpl()
{
	m_enclosingOperand = par_enclosingOperand;
	m_namespace = par_enclosingOperand;
}

//Additional constructor for the containments back reference
BehaviorExecutionSpecificationImpl::BehaviorExecutionSpecificationImpl(std::weak_ptr<uml::Namespace> par_namespace)
:BehaviorExecutionSpecificationImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
BehaviorExecutionSpecificationImpl::BehaviorExecutionSpecificationImpl(std::weak_ptr<uml::Element> par_owner)
:BehaviorExecutionSpecificationImpl()
{
	m_owner = par_owner;
}

BehaviorExecutionSpecificationImpl::BehaviorExecutionSpecificationImpl(const BehaviorExecutionSpecificationImpl & obj): BehaviorExecutionSpecificationImpl()
{
	*this = obj;
}

BehaviorExecutionSpecificationImpl& BehaviorExecutionSpecificationImpl::operator=(const BehaviorExecutionSpecificationImpl & obj)
{
	//call overloaded =Operator for each base class
	ExecutionSpecificationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of BehaviorExecutionSpecification 
	 * which is generated by the compiler (as BehaviorExecutionSpecification is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//BehaviorExecutionSpecification::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy BehaviorExecutionSpecification "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_behavior  = obj.getBehavior();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> BehaviorExecutionSpecificationImpl::copy() const
{
	std::shared_ptr<BehaviorExecutionSpecificationImpl> element(new BehaviorExecutionSpecificationImpl());
	*element =(*this);
	element->setThisBehaviorExecutionSpecificationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference behavior */
std::shared_ptr<uml::Behavior> BehaviorExecutionSpecificationImpl::getBehavior() const
{
    return m_behavior;
}
void BehaviorExecutionSpecificationImpl::setBehavior(std::shared_ptr<uml::Behavior> _behavior)
{
    m_behavior = _behavior;
	
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> BehaviorExecutionSpecificationImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> BehaviorExecutionSpecificationImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> BehaviorExecutionSpecificationImpl::getOwner() const
{
	return m_owner;
}

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> BehaviorExecutionSpecificationImpl::eContainer() const
{
	if(auto wp = m_enclosingInteraction.lock())
	{
		return wp;
	}

	if(auto wp = m_enclosingOperand.lock())
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
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void BehaviorExecutionSpecificationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void BehaviorExecutionSpecificationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("behavior");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("behavior")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ExecutionSpecificationImpl::loadAttributes(loadHandler, attr_list);
}

void BehaviorExecutionSpecificationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ExecutionSpecificationImpl::loadNode(nodeName, loadHandler);
}

void BehaviorExecutionSpecificationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::BEHAVIOREXECUTIONSPECIFICATION_ATTRIBUTE_BEHAVIOR:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Behavior> _behavior = std::dynamic_pointer_cast<uml::Behavior>( references.front() );
				setBehavior(_behavior);
			}
			
			return;
		}
	}
	ExecutionSpecificationImpl::resolveReferences(featureID, references);
}

void BehaviorExecutionSpecificationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ExecutionSpecificationImpl::saveContent(saveHandler);
	
	InteractionFragmentImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void BehaviorExecutionSpecificationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getBehavior(), "behavior", getBehavior()->eClass() != uml::umlPackage::eInstance()->getBehavior_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> BehaviorExecutionSpecificationImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getBehaviorExecutionSpecification_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> BehaviorExecutionSpecificationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::BEHAVIOREXECUTIONSPECIFICATION_ATTRIBUTE_BEHAVIOR:
			return eAny(getBehavior(),uml::umlPackage::BEHAVIOR_CLASS,false); //2415
	}
	return ExecutionSpecificationImpl::eGet(featureID, resolve, coreType);
}

bool BehaviorExecutionSpecificationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::BEHAVIOREXECUTIONSPECIFICATION_ATTRIBUTE_BEHAVIOR:
			return getBehavior() != nullptr; //2415
	}
	return ExecutionSpecificationImpl::internalEIsSet(featureID);
}

bool BehaviorExecutionSpecificationImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::BEHAVIOREXECUTIONSPECIFICATION_ATTRIBUTE_BEHAVIOR:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Behavior> _behavior = std::dynamic_pointer_cast<uml::Behavior>(eObject);
					if(_behavior)
					{
						setBehavior(_behavior); //2415
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'behavior'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'behavior'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return ExecutionSpecificationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> BehaviorExecutionSpecificationImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ExecutionSpecificationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::BehaviorExecutionSpecification> BehaviorExecutionSpecificationImpl::getThisBehaviorExecutionSpecificationPtr() const
{
	return m_thisBehaviorExecutionSpecificationPtr.lock();
}
void BehaviorExecutionSpecificationImpl::setThisBehaviorExecutionSpecificationPtr(std::weak_ptr<uml::BehaviorExecutionSpecification> thisBehaviorExecutionSpecificationPtr)
{
	m_thisBehaviorExecutionSpecificationPtr = thisBehaviorExecutionSpecificationPtr;
	setThisExecutionSpecificationPtr(thisBehaviorExecutionSpecificationPtr);
}


