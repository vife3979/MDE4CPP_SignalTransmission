//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_STARTCLASSIFIERBEHAVIORACTION_HPP
#define UML_STARTCLASSIFIERBEHAVIORACTION_HPP

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
	class Activity;
	class ActivityEdge;
	class ActivityGroup;
	class ActivityPartition;
	class Classifier;
	class Comment;
	class Constraint;
	class Dependency;
	class ExceptionHandler;
	class InputPin;
	class InterruptibleActivityRegion;
	class Namespace;
	class OutputPin;
	class StringExpression;
	class StructuredActivityNode;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Action.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A StartClassifierBehaviorAction is an Action that starts the classifierBehavior of the input object.
	<p>From package UML::Actions.</p>
	*/
	
	class UML_API StartClassifierBehaviorAction: virtual public Action
	{
		public:
 			StartClassifierBehaviorAction(const StartClassifierBehaviorAction &) {}

		protected:
			StartClassifierBehaviorAction(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~StartClassifierBehaviorAction() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The multiplicity of the object InputPin is 1..1
			object.is(1,1)
			*/
			 
			virtual bool multiplicity(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			If the InputPin has a type, then the type or one of its ancestors must have a classifierBehavior.
			object.type->notEmpty() implies 
			   (object.type.oclIsKindOf(BehavioredClassifier) and object.type.oclAsType(BehavioredClassifier).classifierBehavior<>null)
			*/
			 
			virtual bool type_has_classifier(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The InputPin that holds the object whose classifierBehavior is to be started.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::InputPin> getObject() const = 0;
			/*!
			The InputPin that holds the object whose classifierBehavior is to be started.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setObject(std::shared_ptr<uml::InputPin>) = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const = 0;
			/*!
			The ordered set of InputPins representing the inputs to the Action.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> getInput() const = 0;
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
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The InputPin that holds the object whose classifierBehavior is to be started.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::InputPin> m_object;
	};
}
#endif /* end of include guard: UML_STARTCLASSIFIERBEHAVIORACTION_HPP */
