//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_CHOICESTRATEGY_HPP
#define FUML_CHOICESTRATEGY_HPP

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
namespace fUML 
{
	class SemanticStrategy;
}

// base class includes
#include "SemanticStrategy.hpp"

// enum includes


//*********************************
namespace fUML 
{
	/*!
	 */
	class ChoiceStrategy:virtual public SemanticStrategy	{
		public:
 			ChoiceStrategy(const ChoiceStrategy &) {}
			ChoiceStrategy& operator=(ChoiceStrategy const&) = delete;
	
		protected:
			ChoiceStrategy(){}

		public:
			virtual ecore::EObject* copy() const = 0;

			//destructor
			virtual ~ChoiceStrategy() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual int choose(int size)  = 0;
			
			/*!
			 */ 
			virtual std::string retrieveName()  = 0;
			
			
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
#endif /* end of include guard: FUML_CHOICESTRATEGY_HPP */

