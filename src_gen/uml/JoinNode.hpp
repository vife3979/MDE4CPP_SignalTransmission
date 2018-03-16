//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_JOINNODE_HPP
#define UML_JOINNODE_HPP

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
	class ControlNode;
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
	class InterruptibleActivityRegion;
}

namespace uml 
{
	class Namespace;
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
	class ValueSpecification;
}

// base class includes
#include "uml/ControlNode.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"


//*********************************
namespace uml 
{
	/*!
	 A JoinNode is a ControlNode that synchronizes multiple flows.
	<p>From package UML::Activities.</p> */
	class JoinNode:virtual public ControlNode
	{
		public:
 			JoinNode(const JoinNode &) {}
			JoinNode& operator=(JoinNode const&) = delete;

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
			endif */ 
			virtual bool incoming_object_flow(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			/*!
			 A JoinNode has one outgoing ActivityEdge.
			outgoing->size() = 1 */ 
			virtual bool one_outgoing_edge(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 Indicates whether incoming tokens having objects with the same identity are combined into one by the JoinNode.
			<p>From package UML::Activities.</p> */ 
			virtual bool getIsCombineDuplicate() const = 0;
			
			/*!
			 Indicates whether incoming tokens having objects with the same identity are combined into one by the JoinNode.
			<p>From package UML::Activities.</p> */ 
			virtual void setIsCombineDuplicate (bool _isCombineDuplicate)= 0; 
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 A ValueSpecification giving the condition under which the JoinNode will offer a token on its outgoing ActivityEdge. If no joinSpec is specified, then the JoinNode will offer an outgoing token if tokens are offered on all of its incoming ActivityEdges (an "and" condition).
			<p>From package UML::Activities.</p> */
			virtual std::shared_ptr<uml::ValueSpecification > getJoinSpec() const = 0;
			
			/*!
			 A ValueSpecification giving the condition under which the JoinNode will offer a token on its outgoing ActivityEdge. If no joinSpec is specified, then the JoinNode will offer an outgoing token if tokens are offered on all of its incoming ActivityEdges (an "and" condition).
			<p>From package UML::Activities.</p> */
			virtual void setJoinSpec(std::shared_ptr<uml::ValueSpecification> _joinSpec_joinSpec) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			 Indicates whether incoming tokens having objects with the same identity are combined into one by the JoinNode.
			<p>From package UML::Activities.</p> */ 
			bool m_isCombineDuplicate = true;
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 A ValueSpecification giving the condition under which the JoinNode will offer a token on its outgoing ActivityEdge. If no joinSpec is specified, then the JoinNode will offer an outgoing token if tokens are offered on all of its incoming ActivityEdges (an "and" condition).
			<p>From package UML::Activities.</p> */
			std::shared_ptr<uml::ValueSpecification > m_joinSpec;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p> */
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const = 0;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;/*!
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
#endif /* end of include guard: UML_JOINNODE_HPP */
