//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_REDUCEACTIONACTIVATIONREDUCEACTIONACTIVATIONIMPL_HPP
#define FUML_REDUCEACTIONACTIVATIONREDUCEACTIONACTIVATIONIMPL_HPP

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
#include "../ReduceActionActivation.hpp"

#include "impl/ActionActivationImpl.hpp"

#include "SubsetUnion.hpp"



//*********************************
namespace fUML 
{
	class ReduceActionActivationImpl :virtual public ActionActivationImpl, virtual public ReduceActionActivation 
	{
		public: 
			ReduceActionActivationImpl(const ReduceActionActivationImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			ReduceActionActivationImpl& operator=(ReduceActionActivationImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			ReduceActionActivationImpl();

		public:
			//destructor
			virtual ~ReduceActionActivationImpl();
			
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
			virtual std::shared_ptr<fUML::Execution > getCurrentExecution() const ;
			
			/*!
			 */
			virtual void setCurrentExecution(std::shared_ptr<fUML::Execution> _currentExecution_currentExecution) ;
							
			
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
#endif /* end of include guard: FUML_REDUCEACTIONACTIVATIONREDUCEACTIONACTIVATIONIMPL_HPP */

