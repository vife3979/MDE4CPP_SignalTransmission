//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INTERACTIONCONSTRAINT_HPP
#define UML_INTERACTIONCONSTRAINT_HPP

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
	class Comment;
	class Dependency;
	class Namespace;
	class Package;
	class StringExpression;
	class TemplateParameter;
	class ValueSpecification;
}

// base class includes
#include "uml/Constraint.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	An InteractionConstraint is a Boolean expression that guards an operand in a CombinedFragment.
	<p>From package UML::Interactions.</p>
	*/
	
	class InteractionConstraint: virtual public Constraint
	{
		public:
 			InteractionConstraint(const InteractionConstraint &) {}
		protected:
			InteractionConstraint(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~InteractionConstraint() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The dynamic variables that take part in the constraint must be owned by the ConnectableElement corresponding to the covered Lifeline.
			*/
			 
			virtual bool dynamic_variables(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;/*!
			The constraint may contain references to global data or write-once data.
			*/
			 
			virtual bool global_data(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;/*!
			If maxint is specified, then minint must be specified and the evaluation of maxint must be >= the evaluation of minint.
			maxint->notEmpty() implies (minint->notEmpty() and 
			maxint->asSequence()->first().integerValue() >=
			minint->asSequence()->first().integerValue() )
			*/
			 
			virtual bool maxint_greater_equal_minint(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;/*!
			If maxint is specified, then the expression must evaluate to a positive integer.
			maxint->notEmpty() implies 
			maxint->asSequence()->first().integerValue() > 0
			*/
			 
			virtual bool maxint_positive(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;/*!
			Minint/maxint can only be present if the InteractionConstraint is associated with the operand of a loop CombinedFragment.
			maxint->notEmpty() or minint->notEmpty() implies
			interactionOperand.combinedFragment.interactionOperator =
			InteractionOperatorKind::loop
			*/
			 
			virtual bool minint_maxint(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;/*!
			If minint is specified, then the expression must evaluate to a non-negative integer.
			minint->notEmpty() implies 
			minint->asSequence()->first().integerValue() >= 0
			*/
			 
			virtual bool minint_non_negative(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The maximum number of iterations of a loop
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::ValueSpecification> getMaxint() const = 0;
			/*!
			The maximum number of iterations of a loop
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setMaxint(std::shared_ptr<uml::ValueSpecification>) = 0;
			/*!
			The minimum number of iterations of a loop
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::ValueSpecification> getMinint() const = 0;
			/*!
			The minimum number of iterations of a loop
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setMinint(std::shared_ptr<uml::ValueSpecification>) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The maximum number of iterations of a loop
			<p>From package UML::Interactions.</p>
			*/
			
			std::shared_ptr<uml::ValueSpecification> m_maxint;/*!
			The minimum number of iterations of a loop
			<p>From package UML::Interactions.</p>
			*/
			
			std::shared_ptr<uml::ValueSpecification> m_minint;

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const = 0;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: UML_INTERACTIONCONSTRAINT_HPP */
