//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_COMPOUNDVALUE_HPP
#define FUML_COMPOUNDVALUE_HPP

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
	class Classifier;
}

namespace fUML 
{
	class FeatureValue;
}

namespace uml 
{
	class StructuralFeature;
}

namespace fUML 
{
	class StructuredValue;
}

namespace fUML 
{
	class Value;
}

// base class includes
#include "StructuredValue.hpp"

// enum includes


//*********************************
namespace fUML 
{
	/*!
	 */
	class CompoundValue:virtual public StructuredValue	{
		public:
 			CompoundValue(const CompoundValue &) {}
			CompoundValue& operator=(CompoundValue const&) = delete;
	
		protected:
			CompoundValue(){}

		public:
			virtual ecore::EObject* copy() const = 0;

			//destructor
			virtual ~CompoundValue() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual void removeFeatureValues(uml::Classifier *  classifier)  = 0;
			
			/*!
			 */ 
			virtual bool equals(fUML::Value *  otherValue)  = 0;
			
			/*!
			 */ 
			virtual std::string toString()  = 0;
			
			/*!
			 */ 
			virtual fUML::FeatureValue *  retrieveFeatureValue(uml::StructuralFeature *  feature)  = 0;
			
			/*!
			 */ 
			virtual void assignFeatureValue(uml::StructuralFeature *  feature,std::vector<fUML::Value * > *  values,int position)  = 0;
			
			/*!
			 */ 
			virtual std::vector<fUML::FeatureValue * > *  retrieveFeatureValues()  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::vector<fUML::FeatureValue * > *  getFeatureValues() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 */
			std::vector<fUML::FeatureValue * > *  m_featureValues =  nullptr ;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			 
	};

}
#endif /* end of include guard: FUML_COMPOUNDVALUE_HPP */

