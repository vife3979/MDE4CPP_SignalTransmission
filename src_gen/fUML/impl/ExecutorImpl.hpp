//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_EXECUTOREXECUTORIMPL_HPP
#define FUML_EXECUTOREXECUTORIMPL_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

//*********************************
// generated Includes

//Model includes
#include "../Executor.hpp"


#include "impl/EObjectImpl.hpp"

#include "Object.hpp"
#include "FUMLFactory.hpp"

//*********************************
namespace fUML 
{
	class ExecutorImpl :virtual public ecore::EObjectImpl,
virtual public Executor
	{
		public: 
			ExecutorImpl(const ExecutorImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			ExecutorImpl& operator=(ExecutorImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			ExecutorImpl();

		public:
			//destructor
			virtual ~ExecutorImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual fUML::Value *  evaluate(uml::ValueSpecification *  specification)  ;
			
			/*!
			 */ 
			virtual fUML::Reference *  start(uml::Class *  type,std::vector<fUML::ParameterValue * > *  inputs)  ;
			
			/*!
			 */ 
			virtual std::vector<fUML::ParameterValue * > *  execute(uml::Behavior *  behavior,fUML::Object *  context,std::vector<fUML::ParameterValue * > *  inputs)  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual fUML::Locus *  getLocus() const ;
			
			/*!
			 */
			virtual void setLocus(fUML::Locus *  _locus) ;
			
							
			
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
#endif /* end of include guard: FUML_EXECUTOREXECUTORIMPL_HPP */

