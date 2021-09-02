
#include "uml/impl/TimeConstraintImpl.hpp"

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

#include "abstractDataTypes/SubsetUnion.hpp"


#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"


//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"

#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/IntervalConstraint.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/ValueSpecification.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TimeConstraintImpl::TimeConstraintImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

TimeConstraintImpl::~TimeConstraintImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TimeConstraint "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
TimeConstraintImpl::TimeConstraintImpl(std::weak_ptr<uml::Namespace> par_Namespace, const int reference_id)
:TimeConstraintImpl()
{
	switch(reference_id)
	{	
	case uml::umlPackage::CONSTRAINT_ATTRIBUTE_CONTEXT:
		m_context = par_Namespace;
		m_namespace = par_Namespace;
		 return;
	case uml::umlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
		m_namespace = par_Namespace;
		m_owner = par_Namespace;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}


//Additional constructor for the containments back reference
TimeConstraintImpl::TimeConstraintImpl(std::weak_ptr<uml::Element> par_owner)
:TimeConstraintImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
TimeConstraintImpl::TimeConstraintImpl(std::weak_ptr<uml::Package> par_owningPackage)
:TimeConstraintImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
TimeConstraintImpl::TimeConstraintImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:TimeConstraintImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

TimeConstraintImpl::TimeConstraintImpl(const TimeConstraintImpl & obj): TimeConstraintImpl()
{
	*this = obj;
}

TimeConstraintImpl& TimeConstraintImpl::operator=(const TimeConstraintImpl & obj)
{
	//call overloaded =Operator for each base class
	IntervalConstraintImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of TimeConstraint 
	 * which is generated by the compiler (as TimeConstraint is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//TimeConstraint::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TimeConstraint "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_firstEvent = obj.getFirstEvent();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> TimeConstraintImpl::copy() const
{
	std::shared_ptr<TimeConstraintImpl> element(new TimeConstraintImpl());
	*element =(*this);
	element->setThisTimeConstraintPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool TimeConstraintImpl::has_one_constrainedElement(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute firstEvent */
bool TimeConstraintImpl::getFirstEvent() const 
{
	return m_firstEvent;
}
void TimeConstraintImpl::setFirstEvent(bool _firstEvent)
{
	m_firstEvent = _firstEvent;
	
}

//*********************************
// Reference Getters & Setters
//*********************************

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> TimeConstraintImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> TimeConstraintImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> TimeConstraintImpl::getOwner() const
{
	return m_owner;
}



//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> TimeConstraintImpl::eContainer() const
{
	if(auto wp = m_context.lock())
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
// Persistence Functions
//*********************************
void TimeConstraintImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void TimeConstraintImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("firstEvent");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setFirstEvent(value);
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

	IntervalConstraintImpl::loadAttributes(loadHandler, attr_list);
}

void TimeConstraintImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	IntervalConstraintImpl::loadNode(nodeName, loadHandler);
}

void TimeConstraintImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	IntervalConstraintImpl::resolveReferences(featureID, references);
}

void TimeConstraintImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	IntervalConstraintImpl::saveContent(saveHandler);
	
	ConstraintImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void TimeConstraintImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getTimeConstraint_Attribute_firstEvent()) )
		{
			saveHandler->addAttribute("firstEvent", this->getFirstEvent());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


std::shared_ptr<ecore::EClass> TimeConstraintImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getTimeConstraint_Class();
}


//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any TimeConstraintImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::TIMECONSTRAINT_ATTRIBUTE_FIRSTEVENT:
			return eAny(getFirstEvent()); //23615
	}
	return IntervalConstraintImpl::eGet(featureID, resolve, coreType);
}

bool TimeConstraintImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::TIMECONSTRAINT_ATTRIBUTE_FIRSTEVENT:
			return getFirstEvent() != true; //23615
	}
	return IntervalConstraintImpl::internalEIsSet(featureID);
}

bool TimeConstraintImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::TIMECONSTRAINT_ATTRIBUTE_FIRSTEVENT:
		{
			// BOOST CAST
			bool _firstEvent = newValue->get<bool>();
			setFirstEvent(_firstEvent); //23615
			return true;
		}
	}

	return IntervalConstraintImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any TimeConstraintImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 161108299
		case umlPackage::TIMECONSTRAINT_OPERATION_HAS_ONE_CONSTRAINEDELEMENT_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->has_one_constrainedElement(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = IntervalConstraintImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}


std::shared_ptr<TimeConstraint> TimeConstraintImpl::getThisTimeConstraintPtr() const
{
	return m_thisTimeConstraintPtr.lock();
}
void TimeConstraintImpl::setThisTimeConstraintPtr(std::weak_ptr<TimeConstraint> thisTimeConstraintPtr)
{
	m_thisTimeConstraintPtr = thisTimeConstraintPtr;
	setThisIntervalConstraintPtr(thisTimeConstraintPtr);
}
