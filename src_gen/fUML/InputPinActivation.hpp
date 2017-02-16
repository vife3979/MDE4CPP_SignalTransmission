//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_INPUTPINACTIVATION_HPP
#define FUML_INPUTPINACTIVATION_HPP

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
	class ActionActivation;
}

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
	class PinActivation;
}

namespace fUML 
{
	class Token;
}

// base class includes
#include "PinActivation.hpp"

// enum includes


//*********************************
namespace fUML 
{
	/*!
	 */
	class InputPinActivation:virtual public PinActivation	{
		public:
 			InputPinActivation(const InputPinActivation &) {}
			InputPinActivation& operator=(InputPinActivation const&) = delete;
	
		protected:
			InputPinActivation(){}

		public:
			virtual ecore::EObject* copy() const = 0;

			//destructor
			virtual ~InputPinActivation() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual void recieveOffer()  = 0;
			
			/*!
			 */ 
			virtual bool isReady()  = 0;
			
			
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
#endif /* end of include guard: FUML_INPUTPINACTIVATION_HPP */

