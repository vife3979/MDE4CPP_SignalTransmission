//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_BEHAVIOR_HPP
#define UML_BEHAVIOR_HPP

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
	class Behavior;
}

namespace uml 
{
	class BehavioralFeature;
}

namespace uml 
{
	class BehavioredClassifier;
}

namespace uml 
{
	class Class;
}

namespace uml 
{
	class Classifier;
}

namespace uml 
{
	class CollaborationUse;
}

namespace uml 
{
	class Comment;
}

namespace uml 
{
	class ConnectableElement;
}

namespace uml 
{
	class Connector;
}

namespace uml 
{
	class Constraint;
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
	class ElementImport;
}

namespace uml 
{
	class Extension;
}

namespace uml 
{
	class Feature;
}

namespace uml 
{
	class Generalization;
}

namespace uml 
{
	class GeneralizationSet;
}

namespace uml 
{
	class InterfaceRealization;
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
	class Operation;
}

namespace uml 
{
	class Package;
}

namespace uml 
{
	class PackageImport;
}

namespace uml 
{
	class PackageableElement;
}

namespace uml 
{
	class Parameter;
}

namespace uml 
{
	class ParameterSet;
}

namespace uml 
{
	class Port;
}

namespace uml 
{
	class Property;
}

namespace uml 
{
	class Reception;
}

namespace uml 
{
	class RedefinableElement;
}

namespace uml 
{
	class StringExpression;
}

namespace uml 
{
	class Substitution;
}

namespace uml 
{
	class TemplateBinding;
}

namespace uml 
{
	class TemplateParameter;
}

namespace uml 
{
	class TemplateSignature;
}

namespace uml 
{
	class UseCase;
}

// base class includes
#include "uml/Class.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"


//*********************************
namespace uml 
{
	/*!
	 Behavior is a specification of how its context BehavioredClassifier changes state over time. This specification may be either a definition of possible behavior execution or emergent behavior, or a selective illustration of an interesting subset of possible executions. The latter form is typically used for capturing examples, such as a trace of a particular execution.
	<p>From package UML::CommonBehavior.</p> */
	class Behavior:virtual public Class
	{
		public:
 			Behavior(const Behavior &) {}
			Behavior& operator=(Behavior const&) = delete;

		protected:
			Behavior(){}


			//Additional constructors for the containments back reference

			Behavior(std::weak_ptr<uml::BehavioredClassifier > par_behavioredClassifier);

			//Additional constructors for the containments back reference

			Behavior(std::weak_ptr<uml::Namespace > par_namespace);

			//Additional constructors for the containments back reference

			Behavior(std::weak_ptr<uml::Element > par_owner);

			//Additional constructors for the containments back reference

			Behavior(std::weak_ptr<uml::Package > par_Package, const int reference_id);

			//Additional constructors for the containments back reference

			Behavior(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter);

			//Additional constructors for the containments back reference


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Behavior() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 The first BehavioredClassifier reached by following the chain of owner relationships from the Behavior, if any.
			if from.oclIsKindOf(BehavioredClassifier) then
			    from.oclAsType(BehavioredClassifier)
			else if from.owner = null then
			    null
			else
			    self.behavioredClassifier(from.owner)
			endif
			endif
			<p>From package UML::CommonBehavior.</p> */ 
			virtual std::shared_ptr<uml::BehavioredClassifier> behavioredClassifier(std::shared_ptr<uml::Element>  from)  = 0;
			
			/*!
			 The specification BehavioralFeature must be a feature (possibly inherited) of the context BehavioredClassifier of the Behavior.
			_'context'.feature->includes(specification) */ 
			virtual bool feature_of_context_classifier(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			
			
			/*!
			 The in and inout ownedParameters of the Behavior.
			result = (ownedParameter->select(direction=ParameterDirectionKind::_'in' or direction=ParameterDirectionKind::inout))
			<p>From package UML::CommonBehavior.</p> */ 
			virtual std::shared_ptr<Bag<uml::Parameter> > inputParameters()  = 0;
			
			/*!
			 There may be at most one Behavior for a given pairing of BehavioredClassifier (as owner of the Behavior) and BehavioralFeature (as specification of the Behavior).
			specification <> null implies _'context'.ownedBehavior->select(specification=self.specification)->size() = 1 */ 
			virtual bool most_one_behavior(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			/*!
			 The out, inout and return ownedParameters.
			result = (ownedParameter->select(direction=ParameterDirectionKind::out or direction=ParameterDirectionKind::inout or direction=ParameterDirectionKind::return))
			<p>From package UML::CommonBehavior.</p> */ 
			virtual std::shared_ptr<Bag<uml::Parameter> > outputParameters()  = 0;
			
			/*!
			 If a Behavior has a specification BehavioralFeature, then it must have the same number of ownedParameters as its specification. The Behavior Parameters must also "match" the BehavioralParameter Parameters, but the exact requirements for this matching are not formalized.
			specification <> null implies ownedParameter->size() = specification.ownedParameter->size() */ 
			virtual bool parameters_match(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 Tells whether the Behavior can be invoked while it is still executing from a previous invocation.
			<p>From package UML::CommonBehavior.</p> */ 
			virtual bool getIsReentrant() const = 0;
			
			/*!
			 Tells whether the Behavior can be invoked while it is still executing from a previous invocation.
			<p>From package UML::CommonBehavior.</p> */ 
			virtual void setIsReentrant (bool _isReentrant)= 0; 
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::weak_ptr<uml::BehavioredClassifier > getBehavioredClassifier() const = 0;
			
			/*!
			 */
			virtual void setBehavioredClassifier(std::shared_ptr<uml::BehavioredClassifier> _behavioredClassifier_behavioredClassifier) = 0;
			/*!
			 The BehavioredClassifier that is the context for the execution of the Behavior. A Behavior that is directly owned as a nestedClassifier does not have a context. Otherwise, to determine the context of a Behavior, find the first BehavioredClassifier reached by following the chain of owner relationships from the Behavior, if any. If there is such a BehavioredClassifier, then it is the context, unless it is itself a Behavior with a non-empty context, in which case that is also the context for the original Behavior. For example, following this algorithm, the context of an entry Behavior in a StateMachine is the BehavioredClassifier that owns the StateMachine. The features of the context BehavioredClassifier as well as the Elements visible to the context Classifier are visible to the Behavior.
			<p>From package UML::CommonBehavior.</p> */
			virtual std::shared_ptr<uml::BehavioredClassifier > getContext() const = 0;
			
			/*!
			 References a list of Parameters to the Behavior which describes the order and type of arguments that can be given when the Behavior is invoked and of the values which will be returned when the Behavior completes its execution.
			<p>From package UML::CommonBehavior.</p> */
			virtual std::shared_ptr<Subset<uml::Parameter, uml::NamedElement>> getOwnedParameter() const = 0;
			
			/*!
			 The ParameterSets owned by this Behavior.
			<p>From package UML::CommonBehavior.</p> */
			virtual std::shared_ptr<Subset<uml::ParameterSet, uml::NamedElement>> getOwnedParameterSet() const = 0;
			
			/*!
			 An optional set of Constraints specifying what is fulfilled after the execution of the Behavior is completed, if its precondition was fulfilled before its invocation.
			<p>From package UML::CommonBehavior.</p> */
			virtual std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/>> getPostcondition() const = 0;
			
			/*!
			 An optional set of Constraints specifying what must be fulfilled before the Behavior is invoked.
			<p>From package UML::CommonBehavior.</p> */
			virtual std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/>> getPrecondition() const = 0;
			
			/*!
			 References the Behavior that this Behavior redefines. A subtype of Behavior may redefine any other subtype of Behavior. If the Behavior implements a BehavioralFeature, it replaces the redefined Behavior. If the Behavior is a classifierBehavior, it extends the redefined Behavior.
			<p>From package UML::CommonBehavior.</p> */
			virtual std::shared_ptr<Subset<uml::Behavior, uml::Classifier /*Subset does not reference a union*/>> getRedefinedBehavior() const = 0;
			
			/*!
			 Designates a BehavioralFeature that the Behavior implements. The BehavioralFeature must be owned by the BehavioredClassifier that owns the Behavior or be inherited by it. The Parameters of the BehavioralFeature and the implementing Behavior must match. A Behavior does not need to have a specification, in which case it either is the classifierBehavior of a BehavioredClassifier or it can only be invoked by another Behavior of the Classifier.
			<p>From package UML::CommonBehavior.</p> */
			virtual std::shared_ptr<uml::BehavioralFeature > getSpecification() const = 0;
			
			/*!
			 Designates a BehavioralFeature that the Behavior implements. The BehavioralFeature must be owned by the BehavioredClassifier that owns the Behavior or be inherited by it. The Parameters of the BehavioralFeature and the implementing Behavior must match. A Behavior does not need to have a specification, in which case it either is the classifierBehavior of a BehavioredClassifier or it can only be invoked by another Behavior of the Classifier.
			<p>From package UML::CommonBehavior.</p> */
			virtual void setSpecification(std::shared_ptr<uml::BehavioralFeature> _specification_specification) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			 Tells whether the Behavior can be invoked while it is still executing from a previous invocation.
			<p>From package UML::CommonBehavior.</p> */ 
			bool m_isReentrant = true;
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 */
			std::weak_ptr<uml::BehavioredClassifier > m_behavioredClassifier;
			/*!
			 The BehavioredClassifier that is the context for the execution of the Behavior. A Behavior that is directly owned as a nestedClassifier does not have a context. Otherwise, to determine the context of a Behavior, find the first BehavioredClassifier reached by following the chain of owner relationships from the Behavior, if any. If there is such a BehavioredClassifier, then it is the context, unless it is itself a Behavior with a non-empty context, in which case that is also the context for the original Behavior. For example, following this algorithm, the context of an entry Behavior in a StateMachine is the BehavioredClassifier that owns the StateMachine. The features of the context BehavioredClassifier as well as the Elements visible to the context Classifier are visible to the Behavior.
			<p>From package UML::CommonBehavior.</p> */
			std::shared_ptr<uml::BehavioredClassifier > m_context;
			/*!
			 References a list of Parameters to the Behavior which describes the order and type of arguments that can be given when the Behavior is invoked and of the values which will be returned when the Behavior completes its execution.
			<p>From package UML::CommonBehavior.</p> */
			std::shared_ptr<Subset<uml::Parameter, uml::NamedElement>> m_ownedParameter;
			/*!
			 The ParameterSets owned by this Behavior.
			<p>From package UML::CommonBehavior.</p> */
			std::shared_ptr<Subset<uml::ParameterSet, uml::NamedElement>> m_ownedParameterSet;
			/*!
			 An optional set of Constraints specifying what is fulfilled after the execution of the Behavior is completed, if its precondition was fulfilled before its invocation.
			<p>From package UML::CommonBehavior.</p> */
			std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/>> m_postcondition;
			/*!
			 An optional set of Constraints specifying what must be fulfilled before the Behavior is invoked.
			<p>From package UML::CommonBehavior.</p> */
			std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/>> m_precondition;
			/*!
			 References the Behavior that this Behavior redefines. A subtype of Behavior may redefine any other subtype of Behavior. If the Behavior implements a BehavioralFeature, it replaces the redefined Behavior. If the Behavior is a classifierBehavior, it extends the redefined Behavior.
			<p>From package UML::CommonBehavior.</p> */
			std::shared_ptr<Subset<uml::Behavior, uml::Classifier /*Subset does not reference a union*/>> m_redefinedBehavior;
			/*!
			 Designates a BehavioralFeature that the Behavior implements. The BehavioralFeature must be owned by the BehavioredClassifier that owns the Behavior or be inherited by it. The Parameters of the BehavioralFeature and the implementing Behavior must match. A Behavior does not need to have a specification, in which case it either is the classifierBehavior of a BehavioredClassifier or it can only be invoked by another Behavior of the Classifier.
			<p>From package UML::CommonBehavior.</p> */
			std::shared_ptr<uml::BehavioralFeature > m_specification;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 All of the Properties that are direct (i.e., not inherited or imported) attributes of the Classifier.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> getAttribute() const = 0;/*!
			 Specifies each Feature directly defined in the classifier. Note that there may be members of the Classifier that are of the type Feature but are not included, e.g., inherited features.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> getFeature() const = 0;/*!
			 A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::NamedElement>> getMember() const = 0;/*!
			 Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Namespace > getNamespace() const = 0;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;/*!
			 A collection of NamedElements owned by the Namespace.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> getOwnedMember() const = 0;/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Element > getOwner() const = 0;/*!
			 The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const = 0;/*!
			 The contexts that this element may be redefined from.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<Union<uml::Classifier>> getRedefinitionContext() const = 0;/*!
			 The roles that instances may play in this StructuredClassifier.
			<p>From package UML::StructuredClassifiers.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::ConnectableElement, uml::NamedElement>> getRole() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: UML_BEHAVIOR_HPP */
