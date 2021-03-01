//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_OUTPUTPIN_HPP
#define UML_OUTPUTPIN_HPP

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
	class Action;
	class Activity;
	class ActivityEdge;
	class ActivityGroup;
	class ActivityPartition;
	class Behavior;
	class CallAction;
	class Classifier;
	class ClearStructuralFeatureAction;
	class Comment;
	class CreateObjectAction;
	class Dependency;
	class InterruptibleActivityRegion;
	class Namespace;
	class ReadSelfAction;
	class ReadStructuralFeatureAction;
	class State;
	class StringExpression;
	class StructuredActivityNode;
	class Type;
	class ValueSpecification;
	class ValueSpecificationAction;
	class WriteStructuralFeatureAction;
}

// base class includes
#include "uml/Pin.hpp"

// enum includes
#include "uml/ObjectNodeOrderingKind.hpp"

#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	An OutputPin is a Pin that holds output values produced by an Action.
	<p>From package UML::Actions.</p>
	*/
	
	class OutputPin: virtual public Pin
	{
		public:
 			OutputPin(const OutputPin &) {}
		protected:
			OutputPin(){}
			//Additional constructors for the containments back reference
			OutputPin(std::weak_ptr<uml::Action> par_action);

			//Additional constructors for the containments back reference
			OutputPin(std::weak_ptr<uml::Activity> par_activity);

			//Additional constructors for the containments back reference
			OutputPin(std::weak_ptr<uml::CallAction> par_callAction);

			//Additional constructors for the containments back reference
			OutputPin(std::weak_ptr<uml::ClearStructuralFeatureAction> par_clearStructuralFeatureAction);

			//Additional constructors for the containments back reference
			OutputPin(std::weak_ptr<uml::CreateObjectAction> par_createObjectAction);

			//Additional constructors for the containments back reference
			OutputPin(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);

			//Additional constructors for the containments back reference
			OutputPin(std::weak_ptr<uml::Namespace> par_namespace);

			//Additional constructors for the containments back reference
			OutputPin(std::weak_ptr<uml::Element> par_owner);

			//Additional constructors for the containments back reference
			OutputPin(std::weak_ptr<uml::ReadSelfAction> par_readSelfAction);

			//Additional constructors for the containments back reference
			OutputPin(std::weak_ptr<uml::ReadStructuralFeatureAction> par_readStructuralFeatureAction);

			//Additional constructors for the containments back reference
			OutputPin(std::weak_ptr<uml::ValueSpecificationAction> par_valueSpecificationAction);

			//Additional constructors for the containments back reference
			OutputPin(std::weak_ptr<uml::WriteStructuralFeatureAction> par_writeStructuralFeatureAction);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~OutputPin() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			An OutputPin may have incoming ActivityEdges only when it is owned by a StructuredActivityNode, and these edges must have sources contained (directly or indirectly) in the owning StructuredActivityNode.
			incoming->notEmpty() implies
				action<>null and
				action.oclIsKindOf(StructuredActivityNode) and
				action.oclAsType(StructuredActivityNode).allOwnedNodes()->includesAll(incoming.source)
			*/
			 
			virtual bool incoming_edges_structured_only(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::weak_ptr<uml::Action> getAction() const = 0;
			
			
			virtual std::weak_ptr<uml::CallAction> getCallAction() const = 0;
			
			virtual void setCallAction(std::weak_ptr<uml::CallAction>) = 0;
			
			virtual std::weak_ptr<uml::ClearStructuralFeatureAction> getClearStructuralFeatureAction() const = 0;
			
			virtual void setClearStructuralFeatureAction(std::weak_ptr<uml::ClearStructuralFeatureAction>) = 0;
			
			virtual std::weak_ptr<uml::CreateObjectAction> getCreateObjectAction() const = 0;
			
			virtual void setCreateObjectAction(std::weak_ptr<uml::CreateObjectAction>) = 0;
			
			virtual std::weak_ptr<uml::ReadSelfAction> getReadSelfAction() const = 0;
			
			virtual void setReadSelfAction(std::weak_ptr<uml::ReadSelfAction>) = 0;
			
			virtual std::weak_ptr<uml::ReadStructuralFeatureAction> getReadStructuralFeatureAction() const = 0;
			
			virtual void setReadStructuralFeatureAction(std::weak_ptr<uml::ReadStructuralFeatureAction>) = 0;
			
			virtual std::weak_ptr<uml::ValueSpecificationAction> getValueSpecificationAction() const = 0;
			
			virtual void setValueSpecificationAction(std::weak_ptr<uml::ValueSpecificationAction>) = 0;
			
			virtual std::weak_ptr<uml::WriteStructuralFeatureAction> getWriteStructuralFeatureAction() const = 0;
			
			virtual void setWriteStructuralFeatureAction(std::weak_ptr<uml::WriteStructuralFeatureAction>) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			
			std::weak_ptr<uml::Action> m_action;
			std::weak_ptr<uml::CallAction> m_callAction;
			std::weak_ptr<uml::ClearStructuralFeatureAction> m_clearStructuralFeatureAction;
			std::weak_ptr<uml::CreateObjectAction> m_createObjectAction;
			std::weak_ptr<uml::ReadSelfAction> m_readSelfAction;
			std::weak_ptr<uml::ReadStructuralFeatureAction> m_readStructuralFeatureAction;
			std::weak_ptr<uml::ValueSpecificationAction> m_valueSpecificationAction;
			std::weak_ptr<uml::WriteStructuralFeatureAction> m_writeStructuralFeatureAction;

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const = 0;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const = 0;/*!
			The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: UML_OUTPUTPIN_HPP */
