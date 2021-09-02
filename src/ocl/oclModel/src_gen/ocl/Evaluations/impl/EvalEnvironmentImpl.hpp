//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EVALUATIONS_EVALENVIRONMENTEVALENVIRONMENTIMPL_HPP
#define OCL_EVALUATIONS_EVALENVIRONMENTEVALENVIRONMENTIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../EvalEnvironment.hpp"

#include "ocl/Evaluations/impl/EvaluationsFactoryImpl.hpp"

#include "ecore/impl/EModelElementImpl.hpp"

//*********************************
namespace ocl::Evaluations 
{
	class OCL_API EvalEnvironmentImpl : virtual public ecore::EModelElementImpl,
virtual public EvalEnvironment 
	{
		public: 
			EvalEnvironmentImpl(const EvalEnvironmentImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			EvalEnvironmentImpl& operator=(EvalEnvironmentImpl const&); 

		protected:
			friend class ocl::Evaluations::EvaluationsFactoryImpl;
			EvalEnvironmentImpl();
			virtual std::shared_ptr<EvalEnvironment> getThisEvalEnvironmentPtr() const;
			virtual void setThisEvalEnvironmentPtr(std::weak_ptr<EvalEnvironment> thisEvalEnvironmentPtr);


		public:
			//destructor
			virtual ~EvalEnvironmentImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual void add(std::shared_ptr<ocl::Values::NameValueBinding> n) ;
			virtual void addAll(std::shared_ptr<Bag<ocl::Values::NameValueBinding>> nvbs) ;
			virtual std::shared_ptr<ocl::Values::NameValueBinding> find(std::string name) ;
			virtual std::shared_ptr<fUML::Semantics::Values::Value> getValueOf(std::string n) ;
			virtual void replace(std::shared_ptr<ocl::Values::NameValueBinding> n) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<Bag<ocl::Values::NameValueBinding>> getBindings() const ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			
			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<EvalEnvironment> m_thisEvalEnvironmentPtr;
	};
}
#endif /* end of include guard: OCL_EVALUATIONS_EVALENVIRONMENTEVALENVIRONMENTIMPL_HPP */
