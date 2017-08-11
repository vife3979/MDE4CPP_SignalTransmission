//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_DATASTORENODEACTIVATION_HPP
#define FUML_DATASTORENODEACTIVATION_HPP

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
	class CentralBufferNodeActivation;
}

namespace fUML 
{
	class Token;
}

// base class includes
#include "CentralBufferNodeActivation.hpp"

// enum includes


//*********************************
namespace fUML 
{
	/*!
	 */
	class DataStoreNodeActivation:virtual public CentralBufferNodeActivation	{
		public:
 			DataStoreNodeActivation(const DataStoreNodeActivation &) {}
			DataStoreNodeActivation& operator=(DataStoreNodeActivation const&) = delete;
	
		protected:
			DataStoreNodeActivation(){}

		public:
			virtual ecore::EObject* copy() const = 0;

			//destructor
			virtual ~DataStoreNodeActivation() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual int removeToken(std::shared_ptr<fUML::Token>  token)  = 0;
			
			/*!
			 */ 
			virtual void addToken(std::shared_ptr<fUML::Token>  token)  = 0;
			
			
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
#endif /* end of include guard: FUML_DATASTORENODEACTIVATION_HPP */

