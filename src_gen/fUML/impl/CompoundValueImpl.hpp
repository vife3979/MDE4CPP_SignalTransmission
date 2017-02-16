//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_COMPOUNDVALUECOMPOUNDVALUEIMPL_HPP
#define FUML_COMPOUNDVALUECOMPOUNDVALUEIMPL_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

//*********************************
// generated Includes

//Model includes
#include "../CompoundValue.hpp"

#include "impl/StructuredValueImpl.hpp"

#include "Classifier.hpp"
#include <FUMLFactory.hpp>
#include <cstdio>

#include "StructuralFeature.hpp"

//*********************************
namespace fUML 
{
	class CompoundValueImpl :virtual public StructuredValueImpl, virtual public CompoundValue
	{
		public: 
			CompoundValueImpl(const CompoundValueImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			CompoundValueImpl& operator=(CompoundValueImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			CompoundValueImpl();

		public:
			//destructor
			virtual ~CompoundValueImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual void removeFeatureValues(uml::Classifier *  classifier)  ;
			
			/*!
			 */ 
			virtual bool equals(fUML::Value *  otherValue)  ;
			
			/*!
			 */ 
			virtual std::string toString()  ;
			
			/*!
			 */ 
			virtual fUML::FeatureValue *  retrieveFeatureValue(uml::StructuralFeature *  feature)  ;
			
			/*!
			 */ 
			virtual void assignFeatureValue(uml::StructuralFeature *  feature,std::vector<fUML::Value * > *  values,int position)  ;
			
			/*!
			 */ 
			virtual std::vector<fUML::FeatureValue * > *  retrieveFeatureValues()  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::vector<fUML::FeatureValue * > *  getFeatureValues() const ;
			
							
			
			//*********************************
			// Union Getter
			//*********************************
			 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
			
			virtual boost::any eGet(int featureID, bool resolve, bool coreType) const ;
			
		protected:
			virtual ecore::EClass* eStaticClass() const;
	};
}
#endif /* end of include guard: FUML_COMPOUNDVALUECOMPOUNDVALUEIMPL_HPP */

