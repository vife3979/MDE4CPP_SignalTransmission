#include "ExtensionPointImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "UmlPackageImpl.hpp"

//Forward declaration includes
#include "Classifier.hpp"

#include "Comment.hpp"

#include "Dependency.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "Namespace.hpp"

#include "RedefinableElement.hpp"

#include "StringExpression.hpp"

#include "UseCase.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ExtensionPointImpl::ExtensionPointImpl()
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

ExtensionPointImpl::~ExtensionPointImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExtensionPoint "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			ExtensionPointImpl::ExtensionPointImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:ExtensionPointImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			ExtensionPointImpl::ExtensionPointImpl(std::weak_ptr<uml::Element > par_owner)
			:ExtensionPointImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			ExtensionPointImpl::ExtensionPointImpl(std::weak_ptr<uml::UseCase > par_useCase)
			:ExtensionPointImpl()
			{
			    m_useCase = par_useCase;
			}






ExtensionPointImpl::ExtensionPointImpl(const ExtensionPointImpl & obj):ExtensionPointImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExtensionPoint "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isLeaf = obj.getIsLeaf();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::RedefinableElement> > _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier> > _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));

	m_useCase  = obj.getUseCase();


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

std::shared_ptr<ecore::EObject>  ExtensionPointImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ExtensionPointImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ExtensionPointImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getExtensionPoint();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ExtensionPointImpl::must_have_name(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::weak_ptr<uml::UseCase > ExtensionPointImpl::getUseCase() const
{
//assert(m_useCase);
    return m_useCase;
}
void ExtensionPointImpl::setUseCase(std::shared_ptr<uml::UseCase> _useCase)
{
    m_useCase = _useCase;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > ExtensionPointImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > ExtensionPointImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ExtensionPointImpl::getOwner() const
{
	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ExtensionPointImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1004
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1000
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //10010
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1005
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1006
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1007
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1001
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1002
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1003
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1008
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //10011
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //10012
		case UmlPackage::EXTENSIONPOINT_USECASE:
			return getUseCase(); //10013
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1009
	}
	return boost::any();
}
