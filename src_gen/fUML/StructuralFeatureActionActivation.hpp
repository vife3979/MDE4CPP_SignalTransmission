//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_STRUCTURALFEATUREACTIONACTIVATION_HPP
#define FUML_STRUCTURALFEATUREACTIONACTIVATION_HPP

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

namespace uml 
{
	class Association;
}

namespace fUML 
{
	class Link;
}

namespace fUML 
{
	class PinActivation;
}

namespace uml 
{
	class Property;
}

namespace uml 
{
	class StructuralFeature;
}

namespace fUML 
{
	class Token;
}

namespace fUML 
{
	class Value;
}

// base class includes
#include "ActionActivation.hpp"

// enum includes


//*********************************
namespace fUML 
{
	/*!
	 */
	class StructuralFeatureActionActivation:virtual public ActionActivation	{
		public:
 			StructuralFeatureActionActivation(const StructuralFeatureActionActivation &) {}
			StructuralFeatureActionActivation& operator=(StructuralFeatureActionActivation const&) = delete;
	
		protected:
			StructuralFeatureActionActivation(){}

		public:
			virtual ecore::EObject* copy() const = 0;

			//destructor
			virtual ~StructuralFeatureActionActivation() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual std::shared_ptr<uml::Association> getAssociation(std::shared_ptr<uml::StructuralFeature>  feature)  = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<Bag<fUML::Link> > getMatchingLinks(std::shared_ptr<uml::Association>  association,std::shared_ptr<uml::StructuralFeature>  end,std::shared_ptr<fUML::Value>  oppositeValue)  = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<uml::Property> getOppositeEnd(std::shared_ptr<uml::Association>  association,std::shared_ptr<uml::StructuralFeature>  end)  = 0;
			
			
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
#endif /* end of include guard: FUML_STRUCTURALFEATUREACTIONACTIVATION_HPP */

