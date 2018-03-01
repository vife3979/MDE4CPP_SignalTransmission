//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef SUBSETUNIONBENCHMARKDEPTH_ELEMENT_LEVEL2_HPP
#define SUBSETUNIONBENCHMARKDEPTH_ELEMENT_LEVEL2_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

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
namespace subsetUnionBenchmarkDepth 
{
	class Element_Level1;
}

// base class includes
#include "Element_Level1.hpp"

// enum includes


//*********************************
namespace subsetUnionBenchmarkDepth 
{
	/*!
	 */
	class Element_Level2:virtual public Element_Level1
	{
		public:
 			Element_Level2(const Element_Level2 &) {}
			Element_Level2& operator=(Element_Level2 const&) = delete;

		protected:
			Element_Level2(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Element_Level2() {}

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
#endif /* end of include guard: SUBSETUNIONBENCHMARKDEPTH_ELEMENT_LEVEL2_HPP */

