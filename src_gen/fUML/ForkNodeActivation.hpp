//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_FORKNODEACTIVATION_HPP
#define FUML_FORKNODEACTIVATION_HPP

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
	class ActivityEdgeInstance;
}

namespace uml 
{
	class ActivityNode;
}

namespace fUML 
{
	class ActivityNodeActivationGroup;
}

namespace fUML 
{
	class ControlNodeActivation;
}

namespace fUML 
{
	class Token;
}

// base class includes
#include "ControlNodeActivation.hpp"

// enum includes


//*********************************
namespace fUML 
{
	/*!
	 */
	class ForkNodeActivation:virtual public ControlNodeActivation	{
		public:
 			ForkNodeActivation(const ForkNodeActivation &) {}
			ForkNodeActivation& operator=(ForkNodeActivation const&) = delete;
	
		protected:
			ForkNodeActivation(){}

		public:
			virtual ecore::EObject* copy() const = 0;

			//destructor
			virtual ~ForkNodeActivation() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual void fire(std::vector<fUML::Token * > *  incomingTokens)  = 0;
			
			/*!
			 */ 
			virtual void terminate()  = 0;
			
			
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
#endif /* end of include guard: FUML_FORKNODEACTIVATION_HPP */

