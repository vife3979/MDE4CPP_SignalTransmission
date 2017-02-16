//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_CLASSIFIERBEHAVIOREXECUTIONACTIVITYCLASSIFIERBEHAVIOREXECUTIONACTIVITYIMPL_HPP
#define FUML_CLASSIFIERBEHAVIOREXECUTIONACTIVITYCLASSIFIERBEHAVIOREXECUTIONACTIVITYIMPL_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

//*********************************
// generated Includes

//Model includes
#include "../ClassifierBehaviorExecutionActivity.hpp"


#include "impl/EObjectImpl.hpp"


//*********************************
namespace fUML 
{
	class ClassifierBehaviorExecutionActivityImpl :virtual public ecore::EObjectImpl,
virtual public ClassifierBehaviorExecutionActivity
	{
		public: 
			ClassifierBehaviorExecutionActivityImpl(const ClassifierBehaviorExecutionActivityImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			ClassifierBehaviorExecutionActivityImpl& operator=(ClassifierBehaviorExecutionActivityImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			ClassifierBehaviorExecutionActivityImpl();

		public:
			//destructor
			virtual ~ClassifierBehaviorExecutionActivityImpl();
			
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
			virtual ecore::EClass* eStaticClass() const;
	};
}
#endif /* end of include guard: FUML_CLASSIFIERBEHAVIOREXECUTIONACTIVITYCLASSIFIERBEHAVIOREXECUTIONACTIVITYIMPL_HPP */

