//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EVALUATIONS_NAMEVALUEBINDINGNAMEVALUEBINDINGIMPL_HPP
#define OCL_EVALUATIONS_NAMEVALUEBINDINGNAMEVALUEBINDINGIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../NameValueBinding.hpp"

#include "ocl/Evaluations/impl/EvaluationsFactoryImpl.hpp"
#include "ecore/impl/ETypedElementImpl.hpp"

//*********************************
namespace ocl::Evaluations 
{
	class OCL_API NameValueBindingImpl : virtual public ecore::ETypedElementImpl, virtual public NameValueBinding 
	{
		public: 
			NameValueBindingImpl(const NameValueBindingImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			NameValueBindingImpl& operator=(NameValueBindingImpl const&); 

		protected:
			friend class ocl::Evaluations::EvaluationsFactoryImpl;
			NameValueBindingImpl();
			virtual std::shared_ptr<ocl::Evaluations::NameValueBinding> getThisNameValueBindingPtr() const;
			virtual void setThisNameValueBindingPtr(std::weak_ptr<ocl::Evaluations::NameValueBinding> thisNameValueBindingPtr);


		public:
			//destructor
			virtual ~NameValueBindingImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual std::string getName() const ;
			virtual void setName (std::string _name);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<ecore::EObject> getValue() const ;
			virtual void setValue(std::shared_ptr<ecore::EObject>) ;
			
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
			virtual std::shared_ptr<Any> eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, const std::shared_ptr<Any>& newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID,const std::shared_ptr<Bag<Any>>& arguments) ;

		private:
			std::weak_ptr<ocl::Evaluations::NameValueBinding> m_thisNameValueBindingPtr;
	};
}
#endif /* end of include guard: OCL_EVALUATIONS_NAMEVALUEBINDINGNAMEVALUEBINDINGIMPL_HPP */
