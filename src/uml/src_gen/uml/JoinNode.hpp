//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_JOINNODE_HPP
#define UML_JOINNODE_HPP

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
	class Dependency;
	class InterruptibleActivityRegion;
	class Namespace;
	class StringExpression;
	class StructuredActivityNode;
	class ValueSpecification;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/ControlNode.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A JoinNode is a ControlNode that synchronizes multiple flows.
	<p>From package UML::Activities.</p>
	*/
	
	class UML_API JoinNode: virtual public ControlNode
	{
		public:
 			JoinNode(const JoinNode &) {}

		protected:
			JoinNode(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~JoinNode() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			If one of the incoming ActivityEdges of a JoinNode is an ObjectFlow, then its outgoing ActivityEdge must be an ObjectFlow. Otherwise its outgoing ActivityEdge must be a ControlFlow.
			if incoming->exists(oclIsKindOf(ObjectFlow)) then outgoing->forAll(oclIsKindOf(ObjectFlow))
			else outgoing->forAll(oclIsKindOf(ControlFlow))
			endif
			*/
			 
			virtual bool incoming_object_flow(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			A JoinNode has one outgoing ActivityEdge.
			outgoing->size() = 1
			*/
			 
			virtual bool one_outgoing_edge(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Indicates whether incoming tokens having objects with the same identity are combined into one by the JoinNode.
			<p>From package UML::Activities.</p>
			*/
			 
			virtual bool getIsCombineDuplicate() const = 0;
			/*!
			Indicates whether incoming tokens having objects with the same identity are combined into one by the JoinNode.
			<p>From package UML::Activities.</p>
			*/
			 
			virtual void setIsCombineDuplicate (bool _isCombineDuplicate)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			A ValueSpecification giving the condition under which the JoinNode will offer a token on its outgoing ActivityEdge. If no joinSpec is specified, then the JoinNode will offer an outgoing token if tokens are offered on all of its incoming ActivityEdges (an "and" condition).
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<uml::ValueSpecification> getJoinSpec() const = 0;
			/*!
			A ValueSpecification giving the condition under which the JoinNode will offer a token on its outgoing ActivityEdge. If no joinSpec is specified, then the JoinNode will offer an outgoing token if tokens are offered on all of its incoming ActivityEdges (an "and" condition).
			<p>From package UML::Activities.</p>
			*/
			
			virtual void setJoinSpec(std::shared_ptr<uml::ValueSpecification>) = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const = 0;
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
			/*!
			Indicates whether incoming tokens having objects with the same identity are combined into one by the JoinNode.
			<p>From package UML::Activities.</p>
			*/
			
			bool m_isCombineDuplicate= true;
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			A ValueSpecification giving the condition under which the JoinNode will offer a token on its outgoing ActivityEdge. If no joinSpec is specified, then the JoinNode will offer an outgoing token if tokens are offered on all of its incoming ActivityEdges (an "and" condition).
			<p>From package UML::Activities.</p>
			*/
			
			std::shared_ptr<uml::ValueSpecification> m_joinSpec;
	};
}
#endif /* end of include guard: UML_JOINNODE_HPP */
