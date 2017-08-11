//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_LOOPNODEACTIVATION_HPP
#define FUML_LOOPNODEACTIVATION_HPP

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
	class StructuredActivityNodeActivation;
}

namespace fUML 
{
	class Token;
}

namespace fUML 
{
	class Values;
}

// base class includes
#include "StructuredActivityNodeActivation.hpp"

// enum includes


//*********************************
namespace fUML 
{
	/*!
	 */
	class LoopNodeActivation:virtual public StructuredActivityNodeActivation	{
		public:
 			LoopNodeActivation(const LoopNodeActivation &) {}
			LoopNodeActivation& operator=(LoopNodeActivation const&) = delete;
	
		protected:
			LoopNodeActivation(){}

		public:
			virtual ecore::EObject* copy() const = 0;

			//destructor
			virtual ~LoopNodeActivation() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual bool runTest()  = 0;
			
			/*!
			 */ 
			virtual void runBody()  = 0;
			
			/*!
			 */ 
			virtual void runLoopVariables()  = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<uml::ActivityNode> makeLoopVariableList()  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr< Bag<fUML::Values> > getBodyOutputLists() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 */
			std::shared_ptr< Bag<fUML::Values> > m_bodyOutputLists;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			 
	};

}
#endif /* end of include guard: FUML_LOOPNODEACTIVATION_HPP */

