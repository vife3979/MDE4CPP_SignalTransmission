
#include "uml/impl/ConnectionPointReferenceImpl.hpp"
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
#include <stdexcept>
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
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/Namespace.hpp"
#include "uml/Pseudostate.hpp"
#include "uml/Region.hpp"
#include "uml/State.hpp"
#include "uml/StringExpression.hpp"
#include "uml/Transition.hpp"
#include "uml/Vertex.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ConnectionPointReferenceImpl::ConnectionPointReferenceImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ConnectionPointReferenceImpl::~ConnectionPointReferenceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ConnectionPointReference "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ConnectionPointReferenceImpl::ConnectionPointReferenceImpl(std::weak_ptr<uml::Region> par_container)
:ConnectionPointReferenceImpl()
{
	m_container = par_container;
	m_namespace = par_container;
}

//Additional constructor for the containments back reference
ConnectionPointReferenceImpl::ConnectionPointReferenceImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ConnectionPointReferenceImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ConnectionPointReferenceImpl::ConnectionPointReferenceImpl(std::weak_ptr<uml::Element> par_owner)
:ConnectionPointReferenceImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ConnectionPointReferenceImpl::ConnectionPointReferenceImpl(std::weak_ptr<uml::State> par_state)
:ConnectionPointReferenceImpl()
{
	m_state = par_state;
	m_namespace = par_state;
}

ConnectionPointReferenceImpl::ConnectionPointReferenceImpl(const ConnectionPointReferenceImpl & obj): ConnectionPointReferenceImpl()
{
	*this = obj;
}

ConnectionPointReferenceImpl& ConnectionPointReferenceImpl::operator=(const ConnectionPointReferenceImpl & obj)
{
	//call overloaded =Operator for each base class
	VertexImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ConnectionPointReference 
	 * which is generated by the compiler (as ConnectionPointReference is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ConnectionPointReference::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ConnectionPointReference "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_entry  = obj.getEntry();
	m_exit  = obj.getExit();
	m_state  = obj.getState();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ConnectionPointReferenceImpl::copy() const
{
	std::shared_ptr<ConnectionPointReferenceImpl> element(new ConnectionPointReferenceImpl());
	*element =(*this);
	element->setThisConnectionPointReferencePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool ConnectionPointReferenceImpl::entry_pseudostates(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool ConnectionPointReferenceImpl::exit_pseudostates(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference entry */
std::shared_ptr<Bag<uml::Pseudostate>> ConnectionPointReferenceImpl::getEntry() const
{
	if(m_entry == nullptr)
	{
		m_entry.reset(new Bag<uml::Pseudostate>());
		
		
	}
    return m_entry;
}

/* Getter & Setter for reference exit */
std::shared_ptr<Bag<uml::Pseudostate>> ConnectionPointReferenceImpl::getExit() const
{
	if(m_exit == nullptr)
	{
		m_exit.reset(new Bag<uml::Pseudostate>());
		
		
	}
    return m_exit;
}

/* Getter & Setter for reference state */
std::weak_ptr<uml::State> ConnectionPointReferenceImpl::getState() const
{
    return m_state;
}
void ConnectionPointReferenceImpl::setState(std::weak_ptr<uml::State> _state)
{
    m_state = _state;
	
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> ConnectionPointReferenceImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> ConnectionPointReferenceImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> ConnectionPointReferenceImpl::getOwner() const
{
	return m_owner;
}

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ConnectionPointReferenceImpl::eContainer() const
{
	if(auto wp = m_container.lock())
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

	if(auto wp = m_state.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void ConnectionPointReferenceImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ConnectionPointReferenceImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("entry");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("entry")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("exit");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("exit")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	VertexImpl::loadAttributes(loadHandler, attr_list);
}

void ConnectionPointReferenceImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	VertexImpl::loadNode(nodeName, loadHandler);
}

void ConnectionPointReferenceImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_ENTRY:
		{
			std::shared_ptr<Bag<uml::Pseudostate>> _entry = getEntry();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Pseudostate>  _r = std::dynamic_pointer_cast<uml::Pseudostate>(ref);
				if (_r != nullptr)
				{
					_entry->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_EXIT:
		{
			std::shared_ptr<Bag<uml::Pseudostate>> _exit = getExit();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Pseudostate>  _r = std::dynamic_pointer_cast<uml::Pseudostate>(ref);
				if (_r != nullptr)
				{
					_exit->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_STATE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::State> _state = std::dynamic_pointer_cast<uml::State>( references.front() );
				setState(_state);
			}
			
			return;
		}
	}
	VertexImpl::resolveReferences(featureID, references);
}

void ConnectionPointReferenceImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	VertexImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ConnectionPointReferenceImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReferences<uml::Pseudostate>("entry", this->getEntry());
		saveHandler->addReferences<uml::Pseudostate>("exit", this->getExit());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ConnectionPointReferenceImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getConnectionPointReference_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ConnectionPointReferenceImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_ENTRY:
			return eEcoreContainerAny(getEntry(),uml::umlPackage::PSEUDOSTATE_CLASS); //5212
		case uml::umlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_EXIT:
			return eEcoreContainerAny(getExit(),uml::umlPackage::PSEUDOSTATE_CLASS); //5213
		case uml::umlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_STATE:
		{
			std::shared_ptr<ecore::EObject> returnValue=getState().lock();
			return eEcoreAny(returnValue,uml::umlPackage::STATE_CLASS); //5214
		}
	}
	return VertexImpl::eGet(featureID, resolve, coreType);
}

bool ConnectionPointReferenceImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_ENTRY:
			return getEntry() != nullptr; //5212
		case uml::umlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_EXIT:
			return getExit() != nullptr; //5213
		case uml::umlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_STATE:
			return getState().lock() != nullptr; //5214
	}
	return VertexImpl::internalEIsSet(featureID);
}

bool ConnectionPointReferenceImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_ENTRY:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::Pseudostate>> _entry = getEntry();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Pseudostate> valueToAdd = std::dynamic_pointer_cast<uml::Pseudostate>(anEObject);
	
							if (valueToAdd)
							{
								if(_entry->find(valueToAdd) == -1)
								{
									_entry->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'entry'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'entry'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_EXIT:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::Pseudostate>> _exit = getExit();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Pseudostate> valueToAdd = std::dynamic_pointer_cast<uml::Pseudostate>(anEObject);
	
							if (valueToAdd)
							{
								if(_exit->find(valueToAdd) == -1)
								{
									_exit->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'exit'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'exit'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_STATE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::State> _state = std::dynamic_pointer_cast<uml::State>(eObject);
					if(_state)
					{
						setState(_state); //5214
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'state'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'state'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return VertexImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ConnectionPointReferenceImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::ConnectionPointReference::entry_pseudostates(Any, std::map) : bool: 3367242240
		case umlPackage::CONNECTIONPOINTREFERENCE_OPERATION_ENTRY_PSEUDOSTATES_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			std::shared_ptr<Any> incoming_param_diagnostics;
			Bag<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'diagnostics'. Failed to invoke operation 'entry_pseudostates'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			Bag<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'context'. Failed to invoke operation 'entry_pseudostates'!")
				return nullptr;
			}
		
			result = eAny(this->entry_pseudostates(incoming_param_diagnostics,incoming_param_context), 0, false);
			break;
		}
		// uml::ConnectionPointReference::exit_pseudostates(Any, std::map) : bool: 3610740388
		case umlPackage::CONNECTIONPOINTREFERENCE_OPERATION_EXIT_PSEUDOSTATES_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			std::shared_ptr<Any> incoming_param_diagnostics;
			Bag<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'diagnostics'. Failed to invoke operation 'exit_pseudostates'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			Bag<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'context'. Failed to invoke operation 'exit_pseudostates'!")
				return nullptr;
			}
		
			result = eAny(this->exit_pseudostates(incoming_param_diagnostics,incoming_param_context), 0, false);
			break;
		}

		default:
		{
			// call superTypes
			result = VertexImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::ConnectionPointReference> ConnectionPointReferenceImpl::getThisConnectionPointReferencePtr() const
{
	return m_thisConnectionPointReferencePtr.lock();
}
void ConnectionPointReferenceImpl::setThisConnectionPointReferencePtr(std::weak_ptr<uml::ConnectionPointReference> thisConnectionPointReferencePtr)
{
	m_thisConnectionPointReferencePtr = thisConnectionPointReferencePtr;
	setThisVertexPtr(thisConnectionPointReferencePtr);
}


