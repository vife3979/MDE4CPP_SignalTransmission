//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_ACTIVITYEXECUTIONACTIVITYEXECUTIONIMPL_HPP
#define FUML_ACTIVITYEXECUTIONACTIVITYEXECUTIONIMPL_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

//*********************************
// generated Includes

//Model includes
#include "../ActivityExecution.hpp"

#include "impl/ExecutionImpl.hpp"


#include "Parameter.hpp"
#include <ParameterDirectionKind.hpp>
#include <ParameterValue.hpp>
#include "ForkedToken.hpp"
#include <Execution.hpp>
#include "FUMLFactory.hpp"
#include "Object.hpp"
#include "Execution.hpp"
#include "Activity.hpp"
#include "ActivityParameterNode.hpp"

//*********************************
namespace fUML 
{
	class ActivityExecutionImpl :virtual public ExecutionImpl, virtual public ActivityExecution
	{
		public: 
			ActivityExecutionImpl(const ActivityExecutionImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			ActivityExecutionImpl& operator=(ActivityExecutionImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			ActivityExecutionImpl();

		public:
			//destructor
			virtual ~ActivityExecutionImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual void execute()  ;
			
			/*!
			 */ 
			virtual void terminate()  ;
			
			/*!
			 */ 
			virtual fUML::Value *  new_()  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual fUML::ActivityNodeActivationGroup *  getActivationGroup() const ;
			
			/*!
			 */
			virtual void setActivationGroup(fUML::ActivityNodeActivationGroup *  _activationGroup) ;
			
							
			
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
#endif /* end of include guard: FUML_ACTIVITYEXECUTIONACTIVITYEXECUTIONIMPL_HPP */

