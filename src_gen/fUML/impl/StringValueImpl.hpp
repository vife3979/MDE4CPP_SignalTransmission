//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_STRINGVALUESTRINGVALUEIMPL_HPP
#define FUML_STRINGVALUESTRINGVALUEIMPL_HPP

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

//*********************************
// generated Includes

//Model includes
#include "../StringValue.hpp"

#include "impl/PrimitiveValueImpl.hpp"

#include "SubsetUnion.hpp"

#include "FUMLFactory.hpp"
#include "UmlFactory.hpp"
#include "LiteralString.hpp"
#include "Type.hpp"
#include "PrimitiveType.hpp"


//*********************************
namespace fUML 
{
	class StringValueImpl :virtual public PrimitiveValueImpl, virtual public StringValue 
	{
		public: 
			StringValueImpl(const StringValueImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			StringValueImpl& operator=(StringValueImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			StringValueImpl();

		public:
			//destructor
			virtual ~StringValueImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual std::shared_ptr<uml::ValueSpecification> specify()  ;
			
			/*!
			 */ 
			virtual bool equals(std::shared_ptr<fUML::Value>  otherValue)  ;
			
			/*!
			 */ 
			virtual std::string toString()  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 */ 
			virtual std::string getValue() const ;
			
			/*!
			 */ 
			virtual void setValue (std::string _value); 
			
			
			
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
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
	};
}
#endif /* end of include guard: FUML_STRINGVALUESTRINGVALUEIMPL_HPP */

