//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_EXTENSIONALVALUELISTEXTENSIONALVALUELISTIMPL_HPP
#define FUML_EXTENSIONALVALUELISTEXTENSIONALVALUELISTIMPL_HPP

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
#include "../ExtensionalValueList.hpp"

#include "impl/ExtensionalValueImpl.hpp"

#include "SubsetUnion.hpp"



//*********************************
namespace fUML 
{
	class ExtensionalValueListImpl :virtual public ExtensionalValueImpl, virtual public ExtensionalValueList 
	{
		public: 
			ExtensionalValueListImpl(const ExtensionalValueListImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			ExtensionalValueListImpl& operator=(ExtensionalValueListImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			ExtensionalValueListImpl();

		public:
			//destructor
			virtual ~ExtensionalValueListImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual std::shared_ptr<fUML::ExtensionalValue> getValue()  ;
			
			/*!
			 */ 
			virtual bool addValue(std::shared_ptr<fUML::ExtensionalValue>  value)  ;
			
			/*!
			 */ 
			virtual void addValue(std::shared_ptr<fUML::ExtensionalValue>  value,int i)  ;
			
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Value> setValue(std::shared_ptr<fUML::ExtensionalValue>  value,int i)  ;
			
			/*!
			 */ 
			virtual std::string removeValue(int i)  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
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
#endif /* end of include guard: FUML_EXTENSIONALVALUELISTEXTENSIONALVALUELISTIMPL_HPP */

