//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_MULTIPLICITYELEMENT_HPP
#define UML_MULTIPLICITYELEMENT_HPP

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
	class ValueSpecification;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Element.hpp"




//*********************************
namespace uml 
{
	/*!
	A multiplicity is a definition of an inclusive interval of non-negative integers beginning with a lower bound and ending with a (possibly infinite) upper bound. A MultiplicityElement embeds this information to specify the allowable cardinalities for an instantiation of the Element.
	<p>From package UML::CommonStructure.</p>
	*/
	
	class UML_API MultiplicityElement: virtual public Element
	{
		public:
 			MultiplicityElement(const MultiplicityElement &) {}

		protected:
			MultiplicityElement(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~MultiplicityElement() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The operation compatibleWith takes another multiplicity as input. It returns true if the other multiplicity is wider than, or the same as, self.
			result = ((other.lowerBound() <= self.lowerBound()) and ((other.upperBound() = *) or (self.upperBound() <= other.upperBound())))
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual bool compatibleWith(std::shared_ptr<uml::MultiplicityElement> other) = 0;
			/*!
			The query includesMultiplicity() checks whether this multiplicity includes all the cardinalities allowed by the specified multiplicity.
			self.upperBound()->notEmpty() and self.lowerBound()->notEmpty() and M.upperBound()->notEmpty() and M.lowerBound()->notEmpty()
			result = ((self.lowerBound() <= M.lowerBound()) and (self.upperBound() >= M.upperBound()))
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual bool includesMultiplicity(std::shared_ptr<uml::MultiplicityElement> M) = 0;
			/*!
			The operation is determines if the upper and lower bound of the ranges are the ones given.
			result = (lowerbound = self.lowerBound() and upperbound = self.upperBound())
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual bool is(int lowerbound,int upperbound) = 0;
			/*!
			The query isMultivalued() checks whether this multiplicity has an upper bound greater than one.
			upperBound()->notEmpty()
			result = (upperBound() > 1)
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual bool isMultivalued() = 0;
			/*!
			The query lowerBound() returns the lower bound of the multiplicity as an integer, which is the integerValue of lowerValue, if this is given, and 1 otherwise.
			result = (if (lowerValue=null or lowerValue.integerValue()=null) then 1 else lowerValue.integerValue() endif)
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual int lowerBound() = 0;
			/*!
			The lower bound must be a non-negative integer literal.
			lowerBound() >= 0
			*/
			 
			virtual bool lower_ge_0(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			If it is not empty, then lowerValue must have an Integer value.
			lowerValue <> null implies lowerValue.integerValue() <> null
			*/
			 
			virtual bool lower_is_integer(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			The query upperBound() returns the upper bound of the multiplicity for a bounded multiplicity as an unlimited natural, which is the unlimitedNaturalValue of upperValue, if given, and 1, otherwise.
			result = (if (upperValue=null or upperValue.unlimitedValue()=null) then 1 else upperValue.unlimitedValue() endif)
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual int upperBound() = 0;
			/*!
			The upper bound must be greater than or equal to the lower bound.
			upperBound() >= lowerBound()
			*/
			 
			virtual bool upper_ge_lower(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			If it is not empty, then upperValue must have an UnlimitedNatural value.
			upperValue <> null implies upperValue.unlimitedValue() <> null
			*/
			 
			virtual bool upper_is_unlimitedNatural(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			If a non-literal ValueSpecification is used for lowerValue or upperValue, then that specification must be a constant expression.
			*/
			 
			virtual bool value_specification_constant(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			If a non-literal ValueSpecification is used for lowerValue or upperValue, then evaluating that specification must not have side effects.
			*/
			 
			virtual bool value_specification_no_side_effects(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			For a multivalued multiplicity, this attribute specifies whether the values in an instantiation of this MultiplicityElement are sequentially ordered.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual bool getIsOrdered() const = 0;
			/*!
			For a multivalued multiplicity, this attribute specifies whether the values in an instantiation of this MultiplicityElement are sequentially ordered.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual void setIsOrdered (bool _isOrdered)= 0;
			/*!
			For a multivalued multiplicity, this attributes specifies whether the values in an instantiation of this MultiplicityElement are unique.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual bool getIsUnique() const = 0;
			/*!
			For a multivalued multiplicity, this attributes specifies whether the values in an instantiation of this MultiplicityElement are unique.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual void setIsUnique (bool _isUnique)= 0;
			/*!
			The lower bound of the multiplicity interval.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual int getLower() const = 0;
			/*!
			The lower bound of the multiplicity interval.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual void setLower (int _lower)= 0;
			/*!
			The upper bound of the multiplicity interval.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual int getUpper() const = 0;
			/*!
			The upper bound of the multiplicity interval.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual void setUpper (int _upper)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The specification of the lower bound for this multiplicity.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<uml::ValueSpecification> getLowerValue() const = 0;
			/*!
			The specification of the lower bound for this multiplicity.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setLowerValue(std::shared_ptr<uml::ValueSpecification>) = 0;
			/*!
			The specification of the upper bound for this multiplicity.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<uml::ValueSpecification> getUpperValue() const = 0;
			/*!
			The specification of the upper bound for this multiplicity.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setUpperValue(std::shared_ptr<uml::ValueSpecification>) = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;

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
			For a multivalued multiplicity, this attribute specifies whether the values in an instantiation of this MultiplicityElement are sequentially ordered.
			<p>From package UML::CommonStructure.</p>
			*/
			
			bool m_isOrdered= false;
			/*!
			For a multivalued multiplicity, this attributes specifies whether the values in an instantiation of this MultiplicityElement are unique.
			<p>From package UML::CommonStructure.</p>
			*/
			
			bool m_isUnique= true;
			/*!
			The lower bound of the multiplicity interval.
			<p>From package UML::CommonStructure.</p>
			*/
			
			int m_lower= 1;
			/*!
			The upper bound of the multiplicity interval.
			<p>From package UML::CommonStructure.</p>
			*/
			
			int m_upper= 1;
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The specification of the lower bound for this multiplicity.
			<p>From package UML::CommonStructure.</p>
			*/
			
			std::shared_ptr<uml::ValueSpecification> m_lowerValue;
			/*!
			The specification of the upper bound for this multiplicity.
			<p>From package UML::CommonStructure.</p>
			*/
			
			std::shared_ptr<uml::ValueSpecification> m_upperValue;
	};
}
#endif /* end of include guard: UML_MULTIPLICITYELEMENT_HPP */
