//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_STEREOTYPE_HPP
#define UML_STEREOTYPE_HPP

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
namespace ecore 
{
	class EClass;
}
namespace uml 
{
	class Behavior;
	class CollaborationUse;
	class Comment;
	class ConnectableElement;
	class Connector;
	class Constraint;
	class Dependency;
	class ElementImport;
	class Extension;
	class Feature;
	class Generalization;
	class GeneralizationSet;
	class Image;
	class InterfaceRealization;
	class Operation;
	class Package;
	class PackageImport;
	class Port;
	class Profile;
	class Property;
	class Reception;
	class StringExpression;
	class Substitution;
	class TemplateBinding;
	class TemplateParameter;
	class TemplateSignature;
	class UseCase;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Class.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A stereotype defines how an existing metaclass may be extended, and enables the use of platform or domain specific terminology or notation in place of, or in addition to, the ones used for the extended metaclass.
	<p>From package UML::Packages.</p>
	*/
	
	class UML_API Stereotype: virtual public Class
	{
		public:
 			Stereotype(const Stereotype &) {}

		protected:
			Stereotype(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Stereotype() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			Where a stereotype’s property is an association end for an association other than a kind of extension, and the other end is not a stereotype, the other end must be owned by the association itself.
			ownedAttribute
			->select(association->notEmpty() and not association.oclIsKindOf(Extension) and not type.oclIsKindOf(Stereotype))
			->forAll(opposite.owner = association)
			*/
			 
			virtual bool associationEndOwnership(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			If a Stereotype extends more than one metaclass, the multiplicity of the corresponding base-properties shall be [0..1]. At any point in time, only one of these base-properties can contain a metaclass instance during runtime.
			*/
			 
			virtual bool base_property_multiplicity_multiple_extension(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			If a Stereotype extends only one metaclass, the multiplicity of the corresponding base-property shall be 1..1.
			*/
			 
			virtual bool base_property_multiplicity_single_extension(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			The upper bound of base-properties is exactly 1.
			*/
			 
			virtual bool base_property_upper_bound(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			Stereotypes may only participate in binary associations.
			ownedAttribute.association->forAll(memberEnd->size()=2)
			*/
			 
			virtual bool binaryAssociationsOnly(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			The query containingProfile returns the closest profile directly or indirectly containing this stereotype.
			result = (self.namespace.oclAsType(Package).containingProfile())
			<p>From package UML::Packages.</p>
			*/
			 
			virtual std::shared_ptr<uml::Profile> containingProfile() = 0;
			/*!
			Creates a(n) (required) extension of the specified metaclass with this stereotype.
			*/
			 
			virtual std::shared_ptr<uml::Extension> createExtension(std::shared_ptr<uml::Class> metaclass,bool isRequired) = 0;
			/*!
			Creates an icon with the specified location for this stereotype.
			*/
			 
			virtual std::shared_ptr<uml::Image> createIcon(std::string location) = 0;
			/*!
			Creates an icon with the specified format and content for this stereotype.
			*/
			 
			virtual std::shared_ptr<uml::Image> createIcon(std::string format,std::string content) = 0;
			/*!
			A Stereotype may only generalize or specialize another Stereotype.
			allParents()->forAll(oclIsKindOf(Stereotype)) 
			and Classifier.allInstances()->forAll(c | c.allParents()->exists(oclIsKindOf(Stereotype)) implies c.oclIsKindOf(Stereotype))
			*/
			 
			virtual bool generalize(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			Retrieves all the metaclasses extended by this stereotype, including the metaclasses extended by its superstereotypes.
			*/
			 
			virtual std::shared_ptr<Bag<uml::Class> > getAllExtendedMetaclasses() = 0;
			/*!
			Retrieves the current definition (Ecore representation) of this stereotype.
			*/
			 
			virtual std::shared_ptr<ecore::EClass> getDefinition() = 0;
			/*!
			Retrieves the metaclasses extended by this stereotype.
			*/
			 
			virtual std::shared_ptr<Bag<uml::Class> > getExtendedMetaclasses() = 0;
			/*!
			Retrieves the localized keyword for this stereotype.
			*/
			 
			virtual std::string getKeyword() = 0;
			/*!
			Retrieves the keyword for this stereotype, localized if indicated.
			*/
			 
			virtual std::string getKeyword(bool localize) = 0;
			
			/*!
			Stereotype names should not clash with keyword names for the extended model element.
			*/
			 
			virtual bool name_not_clash(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			Stereotype can change the graphical appearance of the extended model element by using attached icons. When this association is not null, it references the location of the icon content to be displayed within diagrams presenting the extended model elements.
			<p>From package UML::Packages.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Image, uml::Element>> getIcon() const = 0;
			/*!
			The profile that directly or indirectly contains this stereotype.
			<p>From package UML::Packages.</p>
			*/
			
			virtual std::shared_ptr<uml::Profile> getProfile() const = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			All of the Properties that are direct (i.e., not inherited or imported) attributes of the Classifier.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> getAttribute() const = 0;
			/*!
			Specifies each Feature directly defined in the classifier. Note that there may be members of the Classifier that are of the type Feature but are not included, e.g., inherited features.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> getFeature() const = 0;
			/*!
			A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::NamedElement>> getMember() const = 0;
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const = 0;
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;
			/*!
			A collection of NamedElements owned by the Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement>> getOwnedMember() const = 0;
			/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const = 0;
			/*!
			The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const = 0;
			/*!
			The roles that instances may play in this StructuredClassifier.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::ConnectableElement, uml::NamedElement>> getRole() const = 0;
			

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
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			Stereotype can change the graphical appearance of the extended model element by using attached icons. When this association is not null, it references the location of the icon content to be displayed within diagrams presenting the extended model elements.
			<p>From package UML::Packages.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Image, uml::Element>> m_icon;
			/*!
			The profile that directly or indirectly contains this stereotype.
			<p>From package UML::Packages.</p>
			*/
			
			std::shared_ptr<uml::Profile> m_profile;
	};
}
#endif /* end of include guard: UML_STEREOTYPE_HPP */
