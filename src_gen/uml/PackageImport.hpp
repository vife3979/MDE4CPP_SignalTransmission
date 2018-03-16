//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_PACKAGEIMPORT_HPP
#define UML_PACKAGEIMPORT_HPP

#include <map>
#include <list>
#include <memory>
#include <string>


// forward declarations
template<class T, class ... U> class Subset;


namespace boost
{
	class any;
}

//*********************************
// generated Includes

#include <map>

namespace persistence
{
	namespace interface
	{
		class XLoadHandler; // used for Persistence
		class XSaveHandler; // used for Persistence
	}
}

namespace uml
{
	class UmlFactory;
}

//Forward Declaration for used types
namespace uml 
{
	class Comment;
}

namespace uml 
{
	class DirectedRelationship;
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
	class Namespace;
}

namespace uml 
{
	class Package;
}

// base class includes
#include "uml/DirectedRelationship.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"


//*********************************
namespace uml 
{
	/*!
	 A PackageImport is a Relationship that imports all the non-private members of a Package into the Namespace owning the PackageImport, so that those Elements may be referred to by their unqualified names in the importingNamespace.
	<p>From package UML::CommonStructure.</p> */
	class PackageImport:virtual public DirectedRelationship
	{
		public:
 			PackageImport(const PackageImport &) {}
			PackageImport& operator=(PackageImport const&) = delete;

		protected:
			PackageImport(){}


			//Additional constructors for the containments back reference

			PackageImport(std::weak_ptr<uml::Namespace > par_importingNamespace);

			//Additional constructors for the containments back reference

			PackageImport(std::weak_ptr<uml::Element > par_owner);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~PackageImport() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 The visibility of a PackageImport is either public or private.
			visibility = VisibilityKind::public or visibility = VisibilityKind::private */ 
			virtual bool public_or_private(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 Specifies the visibility of the imported PackageableElements within the importingNamespace, i.e., whether imported Elements will in turn be visible to other Namespaces. If the PackageImport is public, the imported Elements will be visible outside the importingNamespace, while, if the PackageImport is private, they will not.
			<p>From package UML::CommonStructure.</p> */ 
			virtual VisibilityKind getVisibility() const = 0;
			
			/*!
			 Specifies the visibility of the imported PackageableElements within the importingNamespace, i.e., whether imported Elements will in turn be visible to other Namespaces. If the PackageImport is public, the imported Elements will be visible outside the importingNamespace, while, if the PackageImport is private, they will not.
			<p>From package UML::CommonStructure.</p> */ 
			virtual void setVisibility (VisibilityKind _visibility)= 0; 
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 Specifies the Package whose members are imported into a Namespace.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<uml::Package > getImportedPackage() const = 0;
			
			/*!
			 Specifies the Package whose members are imported into a Namespace.
			<p>From package UML::CommonStructure.</p> */
			virtual void setImportedPackage(std::shared_ptr<uml::Package> _importedPackage_importedPackage) = 0;
			/*!
			 Specifies the Namespace that imports the members from a Package.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Namespace > getImportingNamespace() const = 0;
			
			/*!
			 Specifies the Namespace that imports the members from a Package.
			<p>From package UML::CommonStructure.</p> */
			virtual void setImportingNamespace(std::shared_ptr<uml::Namespace> _importingNamespace_importingNamespace) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			 Specifies the visibility of the imported PackageableElements within the importingNamespace, i.e., whether imported Elements will in turn be visible to other Namespaces. If the PackageImport is public, the imported Elements will be visible outside the importingNamespace, while, if the PackageImport is private, they will not.
			<p>From package UML::CommonStructure.</p> */ 
			VisibilityKind m_visibility = VisibilityKind::PUBLIC;
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 Specifies the Package whose members are imported into a Namespace.
			<p>From package UML::CommonStructure.</p> */
			std::shared_ptr<uml::Package > m_importedPackage;
			/*!
			 Specifies the Namespace that imports the members from a Package.
			<p>From package UML::CommonStructure.</p> */
			std::weak_ptr<uml::Namespace > m_importingNamespace;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Element > getOwner() const = 0;/*!
			 Specifies the elements related by the Relationship.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::Element>> getRelatedElement() const = 0;/*!
			 Specifies the source Element(s) of the DirectedRelationship.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> getSource() const = 0;/*!
			 Specifies the target Element(s) of the DirectedRelationship.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> getTarget() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: UML_PACKAGEIMPORT_HPP */
