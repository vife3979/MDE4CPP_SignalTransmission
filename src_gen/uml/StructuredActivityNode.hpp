//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_STRUCTUREDACTIVITYNODE_HPP
#define UML_STRUCTUREDACTIVITYNODE_HPP

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
	class Action;
}

namespace uml 
{
	class Activity;
}

namespace uml 
{
	class ActivityEdge;
}

namespace uml 
{
	class ActivityGroup;
}

namespace uml 
{
	class ActivityNode;
}

namespace uml 
{
	class ActivityPartition;
}

namespace uml 
{
	class Classifier;
}

namespace uml 
{
	class Comment;
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
	class ExceptionHandler;
}

namespace uml 
{
	class InputPin;
}

namespace uml 
{
	class InterruptibleActivityRegion;
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
	class OutputPin;
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
	class RedefinableElement;
}

namespace uml 
{
	class StringExpression;
}

namespace uml 
{
	class StructuredActivityNode;
}

namespace uml 
{
	class Variable;
}

// base class includes
#include "uml/Action.hpp"

#include "uml/ActivityGroup.hpp"

#include "uml/Namespace.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"


//*********************************
namespace uml 
{
	/*!
	 A StructuredActivityNode is an Action that is also an ActivityGroup and whose behavior is specified by the ActivityNodes and ActivityEdges it so contains. Unlike other kinds of ActivityGroup, a StructuredActivityNode owns the ActivityNodes and ActivityEdges it contains, and so a node or edge can only be directly contained in one StructuredActivityNode, though StructuredActivityNodes may be nested.
	<p>From package UML::Actions.</p> */
	class StructuredActivityNode:virtual public Action,virtual public ActivityGroup,virtual public Namespace
	{
		public:
 			StructuredActivityNode(const StructuredActivityNode &) {}
			StructuredActivityNode& operator=(StructuredActivityNode const&) = delete;

		protected:
			StructuredActivityNode(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~StructuredActivityNode() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 The edges of a StructuredActivityNode are all the ActivityEdges with source and target ActivityNodes contained directly or indirectly within the StructuredActivityNode and at least one of the source or target not contained in any more deeply nested StructuredActivityNode.
			edge=self.sourceNodes().outgoing->intersection(self.allOwnedNodes().incoming)->
				union(self.targetNodes().incoming->intersection(self.allOwnedNodes().outgoing))->asSet() */ 
			virtual bool edges(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			/*!
			 The incoming ActivityEdges of an InputPin of a StructuredActivityNode must have sources that are not within the StructuredActivityNode.
			input.incoming.source->excludesAll(allOwnedNodes()-output) */ 
			virtual bool input_pin_edges(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			/*!
			 The outgoing ActivityEdges of the OutputPins of a StructuredActivityNode must have targets that are not within the StructuredActivityNode.
			output.outgoing.target->excludesAll(allOwnedNodes()-input) */ 
			virtual bool output_pin_edges(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			/*!
			 Return those ActivityNodes contained immediately within the StructuredActivityNode that may act as sources of edges owned by the StructuredActivityNode.
			result = (node->union(input.oclAsType(ActivityNode)->asSet())->
			  union(node->select(oclIsKindOf(Action)).oclAsType(Action).output)->asSet())
			<p>From package UML::Actions.</p> */ 
			virtual std::shared_ptr<Bag<uml::ActivityNode> > sourceNodes()  = 0;
			
			/*!
			 Return those ActivityNodes contained immediately within the StructuredActivityNode that may act as targets of edges owned by the StructuredActivityNode.
			result = (node->union(output.oclAsType(ActivityNode)->asSet())->
			  union(node->select(oclIsKindOf(Action)).oclAsType(Action).input)->asSet())
			<p>From package UML::Actions.</p> */ 
			virtual std::shared_ptr<Bag<uml::ActivityNode> > targetNodes()  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 If true, then any object used by an Action within the StructuredActivityNode cannot be accessed by any Action outside the node until the StructuredActivityNode as a whole completes. Any concurrent Actions that would result in accessing such objects are required to have their execution deferred until the completion of the StructuredActivityNode.
			<p>From package UML::Actions.</p> */ 
			virtual bool getMustIsolate() const = 0;
			
			/*!
			 If true, then any object used by an Action within the StructuredActivityNode cannot be accessed by any Action outside the node until the StructuredActivityNode as a whole completes. Any concurrent Actions that would result in accessing such objects are required to have their execution deferred until the completion of the StructuredActivityNode.
			<p>From package UML::Actions.</p> */ 
			virtual void setMustIsolate (bool _mustIsolate)= 0; 
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 The ActivityEdges immediately contained in the StructuredActivityNode.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<Subset<uml::ActivityEdge, uml::ActivityEdge,uml::Element>> getEdge() const = 0;
			
			/*!
			 The ActivityNodes immediately contained in the StructuredActivityNode.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode,uml::Element>> getNode() const = 0;
			
			/*!
			 The InputPins owned by the StructuredActivityNode.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<Subset<uml::InputPin, uml::InputPin>> getStructuredNodeInput() const = 0;
			
			/*!
			 The OutputPins owned by the StructuredActivityNode.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<Subset<uml::OutputPin, uml::OutputPin>> getStructuredNodeOutput() const = 0;
			
			/*!
			 The Variables defined in the scope of the StructuredActivityNode.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<Subset<uml::Variable, uml::NamedElement>> getVariable() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			 If true, then any object used by an Action within the StructuredActivityNode cannot be accessed by any Action outside the node until the StructuredActivityNode as a whole completes. Any concurrent Actions that would result in accessing such objects are required to have their execution deferred until the completion of the StructuredActivityNode.
			<p>From package UML::Actions.</p> */ 
			bool m_mustIsolate = false;
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 The ActivityEdges immediately contained in the StructuredActivityNode.
			<p>From package UML::Actions.</p> */
			std::shared_ptr<Subset<uml::ActivityEdge, uml::ActivityEdge,uml::Element>> m_edge;
			/*!
			 The ActivityNodes immediately contained in the StructuredActivityNode.
			<p>From package UML::Actions.</p> */
			std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode,uml::Element>> m_node;
			/*!
			 The InputPins owned by the StructuredActivityNode.
			<p>From package UML::Actions.</p> */
			std::shared_ptr<Subset<uml::InputPin, uml::InputPin>> m_structuredNodeInput;
			/*!
			 The OutputPins owned by the StructuredActivityNode.
			<p>From package UML::Actions.</p> */
			std::shared_ptr<Subset<uml::OutputPin, uml::OutputPin>> m_structuredNodeOutput;
			/*!
			 The Variables defined in the scope of the StructuredActivityNode.
			<p>From package UML::Actions.</p> */
			std::shared_ptr<Subset<uml::Variable, uml::NamedElement>> m_variable;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 ActivityEdges immediately contained in the ActivityGroup.
			<p>From package UML::Activities.</p> */
			virtual std::shared_ptr<Union<uml::ActivityEdge>> getContainedEdge() const = 0;/*!
			 ActivityNodes immediately contained in the ActivityGroup.
			<p>From package UML::Activities.</p> */
			virtual std::shared_ptr<Union<uml::ActivityNode>> getContainedNode() const = 0;/*!
			 ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p> */
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const = 0;/*!
			 The ordered set of InputPins representing the inputs to the Action.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> getInput() const = 0;/*!
			 A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::NamedElement>> getMember() const = 0;/*!
			 The ordered set of OutputPins representing outputs from the Action.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> getOutput() const = 0;/*!
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
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: UML_STRUCTUREDACTIVITYNODE_HPP */
