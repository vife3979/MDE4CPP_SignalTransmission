//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_PACKAGEABLEELEMENT_HPP
#define UML_PACKAGEABLEELEMENT_HPP

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

#include <string>
#include <map>
#include <vector>
#include "SubsetUnion.hpp"
#include "boost/shared_ptr.hpp"
#include "boost/any.hpp"

//*********************************
// generated Includes

//Forward Declaration for used types
namespace uml 
{
	class Comment;
}

namespace uml 
{
	class Dependency;
}

namespace ecore 
{
	class EAnnotation;
}

namespace uml 
{
	class Element;
}

namespace uml 
{
	class NamedElement;
}

namespace uml 
{
	class Namespace;
}

namespace uml 
{
	class Package;
}

namespace uml 
{
	class ParameterableElement;
}

namespace uml 
{
	class StringExpression;
}

namespace uml 
{
	class TemplateParameter;
}

// base class includes
#include "NamedElement.hpp"

#include "ParameterableElement.hpp"

// enum includes
#include "VisibilityKind.hpp"


//*********************************
namespace uml 
{
	/*!
	 A PackageableElement is a NamedElement that may be owned directly by a Package. A PackageableElement is also able to serve as the parameteredElement of a TemplateParameter.
	<p>From package UML::CommonStructure.</p> */
	class PackageableElement:virtual public NamedElement,virtual public ParameterableElement
	{
		public:
 			PackageableElement(const PackageableElement &) {}
			PackageableElement& operator=(PackageableElement const&) = delete;

		protected:
			PackageableElement(){}


			//Additional constructors for the containments back reference

			PackageableElement(std::weak_ptr<uml::Namespace > par_namespace);

			//Additional constructors for the containments back reference

			PackageableElement(std::weak_ptr<uml::Element > par_owner);

			//Additional constructors for the containments back reference

			PackageableElement(std::weak_ptr<uml::Package > par_owningPackage);

			//Additional constructors for the containments back reference

			PackageableElement(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~PackageableElement() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 A PackageableElement owned by a Namespace must have a visibility.
			visibility = null implies namespace = null */ 
			virtual bool namespace_needs_visibility(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::weak_ptr<uml::Package > getOwningPackage() const = 0;
			
			/*!
			 */
			virtual void setOwningPackage(std::shared_ptr<uml::Package> _owningPackage_owningPackage) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 */
			std::weak_ptr<uml::Package > m_owningPackage;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Namespace > getNamespace() const = 0;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::Element> > getOwnedElement() const = 0;/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Element > getOwner() const = 0; 
	};

}
#endif /* end of include guard: UML_PACKAGEABLEELEMENT_HPP */

