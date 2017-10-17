//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_EXECUTIONOCCURRENCESPECIFICATION_HPP
#define UML_EXECUTIONOCCURRENCESPECIFICATION_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

#include <string>
#include <map>
#include <vector>
#include "SubsetUnion.hpp"
#include "boost/shared_ptr.hpp"
#include "boost/any.hpp"

//*********************************
// generated Includes

//Forward Declaration for used types
namespace uml 
{
	class Comment;
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
	class ExecutionSpecification;
}

namespace uml 
{
	class GeneralOrdering;
}

namespace uml 
{
	class Interaction;
}

namespace uml 
{
	class InteractionOperand;
}

namespace uml 
{
	class Lifeline;
}

namespace uml 
{
	class Namespace;
}

namespace uml 
{
	class OccurrenceSpecification;
}

namespace uml 
{
	class StringExpression;
}

// base class includes
#include "OccurrenceSpecification.hpp"

// enum includes
#include "VisibilityKind.hpp"


//*********************************
namespace uml 
{
	/*!
	 An ExecutionOccurrenceSpecification represents moments in time at which Actions or Behaviors start or finish.
	<p>From package UML::Interactions.</p> */
	class ExecutionOccurrenceSpecification:virtual public OccurrenceSpecification
	{
		public:
 			ExecutionOccurrenceSpecification(const ExecutionOccurrenceSpecification &) {}
			ExecutionOccurrenceSpecification& operator=(ExecutionOccurrenceSpecification const&) = delete;

		protected:
			ExecutionOccurrenceSpecification(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ExecutionOccurrenceSpecification() {}

			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 References the execution specification describing the execution that is started or finished at this execution event.
			<p>From package UML::Interactions.</p> */
			virtual std::shared_ptr<uml::ExecutionSpecification > getExecution() const = 0;
			
			/*!
			 References the execution specification describing the execution that is started or finished at this execution event.
			<p>From package UML::Interactions.</p> */
			virtual void setExecution(std::shared_ptr<uml::ExecutionSpecification> _execution_execution) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 References the execution specification describing the execution that is started or finished at this execution event.
			<p>From package UML::Interactions.</p> */
			std::shared_ptr<uml::ExecutionSpecification > m_execution;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Namespace > getNamespace() const = 0;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::Element> > getOwnedElement() const = 0;/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Element > getOwner() const = 0; 
	};

}
#endif /* end of include guard: UML_EXECUTIONOCCURRENCESPECIFICATION_HPP */

