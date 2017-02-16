//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_EXECUTIONFACTORYL1_HPP
#define FUML_EXECUTIONFACTORYL1_HPP

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
	class Element;
}

namespace fUML 
{
	class ExecutionFactory;
}

namespace fUML 
{
	class Locus;
}

namespace fUML 
{
	class OpaqueBehaviorExecution;
}

namespace uml 
{
	class PrimitiveType;
}

namespace fUML 
{
	class SemanticStrategy;
}

namespace fUML 
{
	class SemanticVisitor;
}

// base class includes
#include "ExecutionFactory.hpp"

// enum includes


//*********************************
namespace fUML 
{
	/*!
	 */
	class ExecutionFactoryL1:virtual public ExecutionFactory	{
		public:
 			ExecutionFactoryL1(const ExecutionFactoryL1 &) {}
			ExecutionFactoryL1& operator=(ExecutionFactoryL1 const&) = delete;
	
		protected:
			ExecutionFactoryL1(){}

		public:
			virtual ecore::EObject* copy() const = 0;

			//destructor
			virtual ~ExecutionFactoryL1() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual fUML::SemanticVisitor *  instantiateVisitor(uml::Element *  element)  = 0;
			
			
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
#endif /* end of include guard: FUML_EXECUTIONFACTORYL1_HPP */

