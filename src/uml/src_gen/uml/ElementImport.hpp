//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_ELEMENTIMPORT_HPP
#define UML_ELEMENTIMPORT_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations
template<class T, class ... U> class Subset;

class AnyObject;
typedef std::shared_ptr<AnyObject> Any;

//*********************************
// generated Includes
#include <map> // used for Persistence
#include <vector> // used for Persistence
namespace persistence
{
	namespace interfaces
	{
		class XLoadHandler; // used for Persistence
		class XSaveHandler; // used for Persistence
	}
}

namespace uml
{
	class umlFactory;
}

//Forward Declaration for used types 
namespace uml 
{
	class Comment;
	class Namespace;
	class PackageableElement;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/DirectedRelationship.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	An ElementImport identifies a NamedElement in a Namespace other than the one that owns that NamedElement and allows the NamedElement to be referenced using an unqualified name in the Namespace owning the ElementImport.
	<p>From package UML::CommonStructure.</p>
	*/
	
	class UML_API ElementImport: virtual public DirectedRelationship
	{
		public:
 			ElementImport(const ElementImport &) {}

		protected:
			ElementImport(){}
			//Additional constructors for the containments back reference
			ElementImport(std::weak_ptr<uml::Namespace> par_importingNamespace);

			//Additional constructors for the containments back reference
			ElementImport(std::weak_ptr<uml::Element> par_owner);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ElementImport() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The query getName() returns the name under which the imported PackageableElement will be known in the importing namespace.
			result = (if alias->notEmpty() then
			  alias
			else
			  importedElement.name
			endif)
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual std::string getName() = 0;
			/*!
			An importedElement has either public visibility or no visibility at all.
			importedElement.visibility <> null implies importedElement.visibility = VisibilityKind::public
			*/
			 
			virtual bool imported_element_is_public(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			The visibility of an ElementImport is either public or private.
			visibility = VisibilityKind::public or visibility = VisibilityKind::private
			*/
			 
			virtual bool visibility_public_or_private(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Specifies the name that should be added to the importing Namespace in lieu of the name of the imported PackagableElement. The alias must not clash with any other member in the importing Namespace. By default, no alias is used.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual std::string getAlias() const = 0;
			/*!
			Specifies the name that should be added to the importing Namespace in lieu of the name of the imported PackagableElement. The alias must not clash with any other member in the importing Namespace. By default, no alias is used.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual void setAlias (std::string _alias)= 0;
			/*!
			Specifies the visibility of the imported PackageableElement within the importingNamespace, i.e., whether the  importedElement will in turn be visible to other Namespaces. If the ElementImport is public, the importedElement will be visible outside the importingNamespace while, if the ElementImport is private, it will not.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual uml::VisibilityKind getVisibility() const = 0;
			/*!
			Specifies the visibility of the imported PackageableElement within the importingNamespace, i.e., whether the  importedElement will in turn be visible to other Namespaces. If the ElementImport is public, the importedElement will be visible outside the importingNamespace while, if the ElementImport is private, it will not.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual void setVisibility (uml::VisibilityKind _visibility)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			Specifies the PackageableElement whose name is to be added to a Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<uml::PackageableElement> getImportedElement() const = 0;
			/*!
			Specifies the PackageableElement whose name is to be added to a Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setImportedElement(std::shared_ptr<uml::PackageableElement>) = 0;
			/*!
			Specifies the Namespace that imports a PackageableElement from another Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getImportingNamespace() const = 0;
			/*!
			Specifies the Namespace that imports a PackageableElement from another Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setImportingNamespace(std::weak_ptr<uml::Namespace>) = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;
			/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const = 0;
			/*!
			Specifies the elements related by the Relationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getRelatedElement() const = 0;
			/*!
			Specifies the source Element(s) of the DirectedRelationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> getSource() const = 0;
			/*!
			Specifies the target Element(s) of the DirectedRelationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> getTarget() const = 0;

			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 

			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			Specifies the name that should be added to the importing Namespace in lieu of the name of the imported PackagableElement. The alias must not clash with any other member in the importing Namespace. By default, no alias is used.
			<p>From package UML::CommonStructure.</p>
			*/
			
			std::string m_alias= "";
			/*!
			Specifies the visibility of the imported PackageableElement within the importingNamespace, i.e., whether the  importedElement will in turn be visible to other Namespaces. If the ElementImport is public, the importedElement will be visible outside the importingNamespace while, if the ElementImport is private, it will not.
			<p>From package UML::CommonStructure.</p>
			*/
			
			uml::VisibilityKind m_visibility= VisibilityKind::PUBLIC;
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			Specifies the PackageableElement whose name is to be added to a Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			std::shared_ptr<uml::PackageableElement> m_importedElement;
			/*!
			Specifies the Namespace that imports a PackageableElement from another Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			std::weak_ptr<uml::Namespace> m_importingNamespace;
	};
}
#endif /* end of include guard: UML_ELEMENTIMPORT_HPP */
