//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_DEPLOYMENTSPECIFICATION_HPP
#define UML_DEPLOYMENTSPECIFICATION_HPP

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
	class CollaborationUse;
	class Comment;
	class Constraint;
	class Dependency;
	class Deployment;
	class ElementImport;
	class Feature;
	class Generalization;
	class GeneralizationSet;
	class Manifestation;
	class Operation;
	class Package;
	class PackageImport;
	class Property;
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
#include "uml/Artifact.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A deployment specification specifies a set of properties that determine execution parameters of a component artifact that is deployed on a node. A deployment specification can be aimed at a specific type of container. An artifact that reifies or implements deployment specification properties is a deployment descriptor.
	<p>From package UML::Deployments.</p>
	*/
	
	class UML_API DeploymentSpecification: virtual public Artifact
	{
		public:
 			DeploymentSpecification(const DeploymentSpecification &) {}

		protected:
			DeploymentSpecification(){}
			//Additional constructors for the containments back reference
			DeploymentSpecification(std::weak_ptr<uml::Deployment> par_deployment);

			//Additional constructors for the containments back reference
			DeploymentSpecification(std::weak_ptr<uml::Namespace> par_namespace);

			//Additional constructors for the containments back reference
			DeploymentSpecification(std::weak_ptr<uml::Element> par_owner);

			//Additional constructors for the containments back reference
			DeploymentSpecification(std::weak_ptr<uml::Package> par_Package, const int reference_id);

			//Additional constructors for the containments back reference
			DeploymentSpecification(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);

			//Additional constructors for the containments back reference

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~DeploymentSpecification() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The deployedElements of a DeploymentTarget that are involved in a Deployment that has an associated Deployment-Specification is a kind of Component (i.e., the configured components).
			deployment->forAll (location.deployedElement->forAll (oclIsKindOf(Component)))
			*/
			 
			virtual bool deployed_elements(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			The DeploymentTarget of a DeploymentSpecification is a kind of ExecutionEnvironment.
			deployment->forAll (location.oclIsKindOf(ExecutionEnvironment))
			*/
			 
			virtual bool deployment_target(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			The location where an Artifact is deployed onto a Node. This is typically a 'directory' or 'memory address.'
			<p>From package UML::Deployments.</p>
			*/
			 
			virtual std::string getDeploymentLocation() const = 0;
			/*!
			The location where an Artifact is deployed onto a Node. This is typically a 'directory' or 'memory address.'
			<p>From package UML::Deployments.</p>
			*/
			 
			virtual void setDeploymentLocation (std::string _deploymentLocation)= 0;
			/*!
			The location where a component Artifact executes. This may be a local or remote location.
			<p>From package UML::Deployments.</p>
			*/
			 
			virtual std::string getExecutionLocation() const = 0;
			/*!
			The location where a component Artifact executes. This may be a local or remote location.
			<p>From package UML::Deployments.</p>
			*/
			 
			virtual void setExecutionLocation (std::string _executionLocation)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The deployment with which the DeploymentSpecification is associated.
			<p>From package UML::Deployments.</p>
			*/
			
			virtual std::weak_ptr<uml::Deployment> getDeployment() const = 0;
			/*!
			The deployment with which the DeploymentSpecification is associated.
			<p>From package UML::Deployments.</p>
			*/
			
			virtual void setDeployment(std::weak_ptr<uml::Deployment>) = 0;

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
			The location where an Artifact is deployed onto a Node. This is typically a 'directory' or 'memory address.'
			<p>From package UML::Deployments.</p>
			*/
			
			std::string m_deploymentLocation= "";
			/*!
			The location where a component Artifact executes. This may be a local or remote location.
			<p>From package UML::Deployments.</p>
			*/
			
			std::string m_executionLocation= "";
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The deployment with which the DeploymentSpecification is associated.
			<p>From package UML::Deployments.</p>
			*/
			
			std::weak_ptr<uml::Deployment> m_deployment;
	};
}
#endif /* end of include guard: UML_DEPLOYMENTSPECIFICATION_HPP */
