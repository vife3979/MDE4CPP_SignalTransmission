#include "TimeObservationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "UmlPackageImpl.hpp"

//Forward declaration includes
#include "Comment.hpp"

#include "Dependency.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "NamedElement.hpp"

#include "Namespace.hpp"

#include "Observation.hpp"

#include "Package.hpp"

#include "StringExpression.hpp"

#include "TemplateParameter.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TimeObservationImpl::TimeObservationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References
	

	//Init references
	
}

TimeObservationImpl::~TimeObservationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TimeObservation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			TimeObservationImpl::TimeObservationImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:TimeObservationImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			TimeObservationImpl::TimeObservationImpl(std::weak_ptr<uml::Element > par_owner)
			:TimeObservationImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			TimeObservationImpl::TimeObservationImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:TimeObservationImpl()
			{
			    m_owningPackage = par_owningPackage;
			}





//Additional constructor for the containments back reference
			TimeObservationImpl::TimeObservationImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:TimeObservationImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
			}






TimeObservationImpl::TimeObservationImpl(const TimeObservationImpl & obj):TimeObservationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TimeObservation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_firstEvent = obj.getFirstEvent();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_event  = obj.getEvent();

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_owningPackage  = obj.getOwningPackage();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_templateParameter  = obj.getTemplateParameter();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = std::dynamic_pointer_cast<uml::StringExpression>(obj.getNameExpression()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  TimeObservationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new TimeObservationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> TimeObservationImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getTimeObservation();
}

//*********************************
// Attribute Setter Getter
//*********************************
void TimeObservationImpl::setFirstEvent(bool _firstEvent)
{
	m_firstEvent = _firstEvent;
} 

bool TimeObservationImpl::getFirstEvent() const 
{
	return m_firstEvent;
}

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::shared_ptr<uml::NamedElement > TimeObservationImpl::getEvent() const
{
//assert(m_event);
    return m_event;
}
void TimeObservationImpl::setEvent(std::shared_ptr<uml::NamedElement> _event)
{
    m_event = _event;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > TimeObservationImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > TimeObservationImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > TimeObservationImpl::getOwner() const
{
	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any TimeObservationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2574
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2570
		case UmlPackage::TIMEOBSERVATION_EVENT:
			return getEvent(); //25713
		case UmlPackage::TIMEOBSERVATION_FIRSTEVENT:
			return getFirstEvent(); //25714
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2575
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2576
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2577
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2571
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2572
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2573
		case UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE:
			return getOwningPackage(); //25712
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //2574
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2578
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //2575
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2579
	}
	return boost::any();
}
