//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_STRINGVALUE_HPP
#define FUML_STRINGVALUE_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

#include <string>
#include <map>
#include <vector>
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
	class StringValue:virtual public PrimitiveValue	{
		public:
 			StringValue(const StringValue &) {}
			StringValue& operator=(StringValue const&) = delete;
	
		protected:
			StringValue(){}

		public:
			virtual ecore::EObject* copy() const = 0;

			//destructor
			virtual ~StringValue() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual uml::ValueSpecification *  specify()  = 0;
			
			/*!
			 */ 
			virtual bool equals(fUML::Value *  otherValue)  = 0;
			
			/*!
			 */ 
			virtual std::string toString()  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 */ 
			virtual std::string getValue() const = 0;
			
			/*!
			 */ 
			virtual void setValue (std::string _value)= 0; 
			
			
			//*********************************
			// Reference
			//*********************************
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			 */ 
			std::string m_value ;
			
			
			//*********************************
			// Reference Members
			//*********************************
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			 
	};

}
#endif /* end of include guard: FUML_STRINGVALUE_HPP */

