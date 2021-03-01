//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_PROFILEAPPLICATION_HPP
#define UML_PROFILEAPPLICATION_HPP


#include <memory>
#include <string>
// forward declarations
template<class T, class ... U> class Subset;


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
	class ENamedElement;
	class EPackage;
}
namespace uml 
{
	class Comment;
	class NamedElement;
	class Package;
	class Profile;
}

// base class includes
#include "uml/DirectedRelationship.hpp"

// enum includes



//*********************************
namespace uml 
{
	/*!
	A profile application is used to show which profiles have been applied to a package.
	<p>From package UML::Packages.</p>
	*/
	
	class ProfileApplication: virtual public DirectedRelationship
	{
		public:
 			ProfileApplication(const ProfileApplication &) {}
		protected:
			ProfileApplication(){}
			//Additional constructors for the containments back reference
			ProfileApplication(std::weak_ptr<uml::Package> par_applyingPackage);

			//Additional constructors for the containments back reference
			ProfileApplication(std::weak_ptr<uml::Element> par_owner);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ProfileApplication() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			Retrieves the definition (Ecore representation) of the profile associated with this profile application.
			*/
			 
			virtual std::shared_ptr<ecore::EPackage> getAppliedDefinition() = 0;/*!
			Retrieves the definition (Ecore representation) of the specified named element in the profile associated with this profile application.
			*/
			 
			virtual std::shared_ptr<ecore::ENamedElement> getAppliedDefinition(std::shared_ptr<uml::NamedElement> namedElement) = 0;
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			Specifies that the Profile filtering rules for the metaclasses of the referenced metamodel shall be strictly applied.
			<p>From package UML::Packages.</p>
			*/
			 
			virtual bool getIsStrict() const = 0;
			/*!
			Specifies that the Profile filtering rules for the metaclasses of the referenced metamodel shall be strictly applied.
			<p>From package UML::Packages.</p>
			*/
			 
			virtual void setIsStrict (bool _isStrict)= 0;
			
			//*********************************
			// Reference
			//*********************************
			/*!
			References the Profiles that are applied to a Package through this ProfileApplication.
			<p>From package UML::Packages.</p>
			*/
			
			virtual std::shared_ptr<uml::Profile> getAppliedProfile() const = 0;
			/*!
			References the Profiles that are applied to a Package through this ProfileApplication.
			<p>From package UML::Packages.</p>
			*/
			
			virtual void setAppliedProfile(std::shared_ptr<uml::Profile>) = 0;
			/*!
			The package that owns the profile application.
			<p>From package UML::Packages.</p>
			*/
			
			virtual std::weak_ptr<uml::Package> getApplyingPackage() const = 0;
			/*!
			The package that owns the profile application.
			<p>From package UML::Packages.</p>
			*/
			
			virtual void setApplyingPackage(std::weak_ptr<uml::Package>) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			Specifies that the Profile filtering rules for the metaclasses of the referenced metamodel shall be strictly applied.
			<p>From package UML::Packages.</p>
			*/
			 
			bool m_isStrict = false;
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			References the Profiles that are applied to a Package through this ProfileApplication.
			<p>From package UML::Packages.</p>
			*/
			
			std::shared_ptr<uml::Profile> m_appliedProfile;/*!
			The package that owns the profile application.
			<p>From package UML::Packages.</p>
			*/
			
			std::weak_ptr<uml::Package> m_applyingPackage;

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const = 0;/*!
			Specifies the elements related by the Relationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getRelatedElement() const = 0;/*!
			Specifies the source Element(s) of the DirectedRelationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> getSource() const = 0;/*!
			Specifies the target Element(s) of the DirectedRelationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> getTarget() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: UML_PROFILEAPPLICATION_HPP */
