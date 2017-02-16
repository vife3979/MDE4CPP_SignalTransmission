//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_EXECUTIONFACTORYEXECUTIONFACTORYIMPL_HPP
#define FUML_EXECUTIONFACTORYEXECUTIONFACTORYIMPL_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

//*********************************
// generated Includes

//Model includes
#include "../ExecutionFactory.hpp"


#include "impl/EObjectImpl.hpp"

#include "fUMLPackage.hpp"
#include "OpaqueBehavior.hpp"
#include "OpaqueBehaviorExecution.hpp"
#include "Value.hpp"
#include "Evaluation.hpp"
#include "Element.hpp"
#include "ValueSpecification.hpp"

//*********************************
namespace fUML 
{
	class ExecutionFactoryImpl :virtual public ecore::EObjectImpl,
virtual public ExecutionFactory
	{
		public: 
			ExecutionFactoryImpl(const ExecutionFactoryImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			ExecutionFactoryImpl& operator=(ExecutionFactoryImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			ExecutionFactoryImpl();

		public:
			//destructor
			virtual ~ExecutionFactoryImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual fUML::Execution *  createExecution(uml::Behavior *  behavior,fUML::Object *  context)  ;
			
			/*!
			 */ 
			virtual fUML::Evaluation *  createEvaluation(uml::ValueSpecification *  specification)  ;
			
			/*!
			 */ 
			virtual fUML::SemanticVisitor *  instantiateVisitor(uml::Element *  element)  ;
			
			/*!
			 */ 
			virtual fUML::OpaqueBehaviorExecution *  instantiateOpaqueBehaviorExecution(uml::OpaqueBehavior *  behavior)  ;
			
			/*!
			 */ 
			virtual void addPrimitiveBehaviorPrototype(fUML::OpaqueBehaviorExecution *  execution)  ;
			
			/*!
			 */ 
			virtual void addBuiltInType(uml::PrimitiveType *  type)  ;
			
			/*!
			 */ 
			virtual uml::PrimitiveType *  getBuiltInType(std::string name)  ;
			
			/*!
			 */ 
			virtual void assignStrategy(fUML::SemanticStrategy *  strategy)  ;
			
			/*!
			 */ 
			virtual fUML::SemanticStrategy *  getStrategy(std::string name)  ;
			
			/*!
			 */ 
			virtual int getStrategyIndex(std::string name)  ;
			
			
			
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
			
			/*!
			 */
			virtual std::vector<fUML::SemanticStrategy * > *  getStrategies() const ;
			
			/*!
			 */
			virtual std::vector<fUML::OpaqueBehaviorExecution * > *  getPrimitiveBehaviorPrototypes() const ;
			
			/*!
			 */
			virtual std::vector<uml::PrimitiveType * > *  getBuiltInTypes() const ;
			
							
			
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
#endif /* end of include guard: FUML_EXECUTIONFACTORYEXECUTIONFACTORYIMPL_HPP */

