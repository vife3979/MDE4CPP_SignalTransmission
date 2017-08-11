//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_EXPANSIONACTIVATIONGROUP_HPP
#define FUML_EXPANSIONACTIVATIONGROUP_HPP

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

namespace fUML 
{
	class ActivityExecution;
}

namespace fUML 
{
	class ActivityNodeActivation;
}

namespace fUML 
{
	class ActivityNodeActivationGroup;
}

namespace fUML 
{
	class ExpansionRegionActivation;
}

namespace fUML 
{
	class StructuredActivityNodeActivation;
}

// base class includes
#include "ActivityNodeActivationGroup.hpp"

// enum includes


//*********************************
namespace fUML 
{
	/*!
	 */
	class ExpansionActivationGroup:virtual public ActivityNodeActivationGroup	{
		public:
 			ExpansionActivationGroup(const ExpansionActivationGroup &) {}
			ExpansionActivationGroup& operator=(ExpansionActivationGroup const&) = delete;
	
		protected:
			ExpansionActivationGroup(){}

		public:
			virtual ecore::EObject* copy() const = 0;

			//destructor
			virtual ~ExpansionActivationGroup() {}

			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<fUML::ExpansionRegionActivation > getRegionActivation() const = 0;
			
			/*!
			 */
			virtual void setRegionActivation(std::shared_ptr<fUML::ExpansionRegionActivation> _regionActivation_regionActivation) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 */
			std::shared_ptr<fUML::ExpansionRegionActivation > m_regionActivation;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			 
	};

}
#endif /* end of include guard: FUML_EXPANSIONACTIVATIONGROUP_HPP */

