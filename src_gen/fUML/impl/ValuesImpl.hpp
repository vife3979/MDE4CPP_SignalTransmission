//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_VALUESVALUESIMPL_HPP
#define FUML_VALUESVALUESIMPL_HPP

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
#include "../Values.hpp"


#include "impl/EObjectImpl.hpp"

#include "SubsetUnion.hpp"



//*********************************
namespace fUML 
{
	class ValuesImpl :virtual public ecore::EObjectImpl,
virtual public Values 
	{
		public: 
			ValuesImpl(const ValuesImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			ValuesImpl& operator=(ValuesImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			ValuesImpl();

		public:
			//destructor
			virtual ~ValuesImpl();
			
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
			virtual std::shared_ptr< Bag<fUML::Value> > getValues() const ;
			
							
			
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
#endif /* end of include guard: FUML_VALUESVALUESIMPL_HPP */

