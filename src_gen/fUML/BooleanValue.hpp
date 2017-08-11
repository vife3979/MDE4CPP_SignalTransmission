//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_BOOLEANVALUE_HPP
#define FUML_BOOLEANVALUE_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

#define ACTIVITY_DEBUG_ON

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
	class PrimitiveType;
}

namespace fUML 
{
	class PrimitiveValue;
}

namespace fUML 
{
	class Value;
}

namespace uml 
{
	class ValueSpecification;
}

// base class includes
#include "PrimitiveValue.hpp"

// enum includes


//*********************************
namespace fUML 
{
	/*!
	 */
	class BooleanValue:virtual public PrimitiveValue	{
		public:
 			BooleanValue(const BooleanValue &) {}
			BooleanValue& operator=(BooleanValue const&) = delete;
	
		protected:
			BooleanValue(){}

		public:
			virtual ecore::EObject* copy() const = 0;

			//destructor
			virtual ~BooleanValue() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual std::shared_ptr<uml::ValueSpecification> specify()  = 0;
			
			/*!
			 */ 
			virtual bool equals(std::shared_ptr<fUML::Value>  otherValue)  = 0;
			
			/*!
			 */ 
			virtual std::string toString()  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 */ 
			virtual bool isValue() const = 0;
			
			/*!
			 */ 
			virtual void setValue (bool _value)= 0; 
			
			
			//*********************************
			// Reference
			//*********************************
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			 */ 
			bool m_value ;
			
			
			//*********************************
			// Reference Members
			//*********************************
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			 
	};

}
#endif /* end of include guard: FUML_BOOLEANVALUE_HPP */

