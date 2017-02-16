//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_CLEARSTRUCTURALFEATUREACTIONACTIVATION_HPP
#define FUML_CLEARSTRUCTURALFEATUREACTIONACTIVATION_HPP

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
	class PinActivation;
}

namespace fUML 
{
	class StructuralFeatureActionActivation;
}

namespace fUML 
{
	class Token;
}

// base class includes
#include "StructuralFeatureActionActivation.hpp"

// enum includes


//*********************************
namespace fUML 
{
	/*!
	 */
	class ClearStructuralFeatureActionActivation:virtual public StructuralFeatureActionActivation	{
		public:
 			ClearStructuralFeatureActionActivation(const ClearStructuralFeatureActionActivation &) {}
			ClearStructuralFeatureActionActivation& operator=(ClearStructuralFeatureActionActivation const&) = delete;
	
		protected:
			ClearStructuralFeatureActionActivation(){}

		public:
			virtual ecore::EObject* copy() const = 0;

			//destructor
			virtual ~ClearStructuralFeatureActionActivation() {}

			//*********************************
			// Operations
			//*********************************
			
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
#endif /* end of include guard: FUML_CLEARSTRUCTURALFEATUREACTIONACTIVATION_HPP */

