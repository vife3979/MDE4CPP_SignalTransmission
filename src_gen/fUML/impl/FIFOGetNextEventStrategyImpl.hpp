//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_FIFOGETNEXTEVENTSTRATEGYFIFOGETNEXTEVENTSTRATEGYIMPL_HPP
#define FUML_FIFOGETNEXTEVENTSTRATEGYFIFOGETNEXTEVENTSTRATEGYIMPL_HPP

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
#include "../FIFOGetNextEventStrategy.hpp"

#include "impl/GetNextEventStrategyImpl.hpp"

#include "SubsetUnion.hpp"



//*********************************
namespace fUML 
{
	class FIFOGetNextEventStrategyImpl :virtual public GetNextEventStrategyImpl, virtual public FIFOGetNextEventStrategy 
	{
		public: 
			FIFOGetNextEventStrategyImpl(const FIFOGetNextEventStrategyImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			FIFOGetNextEventStrategyImpl& operator=(FIFOGetNextEventStrategyImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			FIFOGetNextEventStrategyImpl();

		public:
			//destructor
			virtual ~FIFOGetNextEventStrategyImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
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
#endif /* end of include guard: FUML_FIFOGETNEXTEVENTSTRATEGYFIFOGETNEXTEVENTSTRATEGYIMPL_HPP */

