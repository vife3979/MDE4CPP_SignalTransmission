//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_ACTIVITYNODE_HPP
#define UML_ACTIVITYNODE_HPP


#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 
template<class T, class ... U> class Subset;
template<class T> class Union;

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
}

// base class includes
#include "uml/RedefinableElement.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	ActivityNode is an abstract class for points in the flow of an Activity connected by ActivityEdges.
	<p>From package UML::Activities.</p>
	*/
	
	class ActivityNode: virtual public RedefinableElement
	{
		public:
 			ActivityNode(const ActivityNode &) {}
		protected:
			ActivityNode(){}
			//Additional constructors for the containments back reference
			ActivityNode(std::weak_ptr<uml::Activity> par_activity);

			//Additional constructors for the containments back reference
			ActivityNode(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);

			//Additional constructors for the containments back reference
			ActivityNode(std::weak_ptr<uml::Namespace> par_namespace);

			//Additional constructors for the containments back reference
			ActivityNode(std::weak_ptr<uml::Element> par_owner);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ActivityNode() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The Activity that directly or indirectly contains this ActivityNode.
			result = (if inStructuredNode<>null then inStructuredNode.containingActivity()
			else activity
			endif)
			<p>From package UML::Activities.</p>
			*/
			 
			virtual std::shared_ptr<uml::Activity> containingActivity() = 0;
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The Activity containing the ActivityNode, if it is directly owned by an Activity.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::weak_ptr<uml::Activity> getActivity() const = 0;
			/*!
			The Activity containing the ActivityNode, if it is directly owned by an Activity.
			<p>From package UML::Activities.</p>
			*/
			
			virtual void setActivity(std::weak_ptr<uml::Activity>) = 0;
			
			
			/*!
			InterruptibleActivityRegions containing the ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::InterruptibleActivityRegion, uml::ActivityGroup>> getInInterruptibleRegion() const = 0;
			
			/*!
			ActivityPartitions containing the ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup>> getInPartition() const = 0;
			
			/*!
			The StructuredActivityNode containing the ActvityNode, if it is directly owned by a StructuredActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::weak_ptr<uml::StructuredActivityNode> getInStructuredNode() const = 0;
			/*!
			The StructuredActivityNode containing the ActvityNode, if it is directly owned by a StructuredActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual void setInStructuredNode(std::weak_ptr<uml::StructuredActivityNode>) = 0;
			/*!
			ActivityEdges that have the ActivityNode as their target.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::ActivityEdge>> getIncoming() const = 0;
			
			/*!
			ActivityEdges that have the ActivityNode as their source.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::ActivityEdge>> getOutgoing() const = 0;
			
			/*!
			ActivityNodes from a generalization of the Activity containining this ActivityNode that are redefined by this ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ActivityNode, uml::RedefinableElement>> getRedefinedNode() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The Activity containing the ActivityNode, if it is directly owned by an Activity.
			<p>From package UML::Activities.</p>
			*/
			
			std::weak_ptr<uml::Activity> m_activity;/*!
			ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			mutable std::shared_ptr<Union<uml::ActivityGroup>> m_inGroup;/*!
			InterruptibleActivityRegions containing the ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::InterruptibleActivityRegion, uml::ActivityGroup>> m_inInterruptibleRegion;/*!
			ActivityPartitions containing the ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup>> m_inPartition;/*!
			The StructuredActivityNode containing the ActvityNode, if it is directly owned by a StructuredActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			std::weak_ptr<uml::StructuredActivityNode> m_inStructuredNode;/*!
			ActivityEdges that have the ActivityNode as their target.
			<p>From package UML::Activities.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::ActivityEdge>> m_incoming;/*!
			ActivityEdges that have the ActivityNode as their source.
			<p>From package UML::Activities.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::ActivityEdge>> m_outgoing;/*!
			ActivityNodes from a generalization of the Activity containining this ActivityNode that are redefined by this ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::ActivityNode, uml::RedefinableElement>> m_redefinedNode;

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
#endif /* end of include guard: UML_ACTIVITYNODE_HPP */
