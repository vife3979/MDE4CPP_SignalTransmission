//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_BOOLEANVALUEBOOLEANVALUEIMPL_HPP
#define FUML_BOOLEANVALUEBOOLEANVALUEIMPL_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

//*********************************
// generated Includes

//Model includes
#include "../BooleanValue.hpp"

#include "impl/PrimitiveValueImpl.hpp"

#include "FUMLFactory.hpp"
#include "UmlFactory.hpp"
#include "LiteralBoolean.hpp"
#include "Type.hpp"
#include "PrimitiveType.hpp"

//*********************************
namespace fUML 
{
	class BooleanValueImpl :virtual public PrimitiveValueImpl, virtual public BooleanValue
	{
		public: 
			BooleanValueImpl(const BooleanValueImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			BooleanValueImpl& operator=(BooleanValueImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			BooleanValueImpl();

		public:
			//destructor
			virtual ~BooleanValueImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual uml::ValueSpecification *  specify()  ;
			
			/*!
			 */ 
			virtual bool equals(fUML::Value *  otherValue)  ;
			
			/*!
			 */ 
			virtual std::string toString()  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 */ 
			virtual bool isValue() const ;
			
			/*!
			 */ 
			virtual void setValue (bool _value); 
			
			
			
			//*********************************
			// Reference
			//*********************************
							
			
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
#endif /* end of include guard: FUML_BOOLEANVALUEBOOLEANVALUEIMPL_HPP */

