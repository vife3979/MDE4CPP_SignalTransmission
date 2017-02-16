//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICVISITOR_HPP
#define FUML_SEMANTICVISITOR_HPP

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

// base class includes

// enum includes

#include "EObject.hpp"

//*********************************
namespace fUML 
{
	/*!
	 */
	class SemanticVisitor : virtual public ecore::EObject 
	{
		public:
 			SemanticVisitor(const SemanticVisitor &) {}
			SemanticVisitor& operator=(SemanticVisitor const&) = delete;
	
		protected:
			SemanticVisitor(){}

		public:
			virtual ecore::EObject* copy() const = 0;

			//destructor
			virtual ~SemanticVisitor() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual void _endIsolation()  = 0;
			
			/*!
			 */ 
			virtual void _beginIsolation()  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			 
	};

}
#endif /* end of include guard: FUML_SEMANTICVISITOR_HPP */

