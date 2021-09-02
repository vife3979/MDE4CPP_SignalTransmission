//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_ACTIONS_CS_CREATEOBJECTACTIONACTIVATIONCS_CREATEOBJECTACTIONACTIVATIONIMPL_HPP
#define PSCS_SEMANTICS_ACTIONS_CS_CREATEOBJECTACTIONACTIVATIONCS_CREATEOBJECTACTIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "PSCS/PSCS.hpp" 

// model includes
#include "../CS_CreateObjectActionActivation.hpp"

#include "PSCS/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/CreateObjectActionActivationImpl.hpp"

//*********************************
namespace PSCS::Semantics::Actions 
{
	class PSCS_API CS_CreateObjectActionActivationImpl : virtual public fUML::Semantics::Actions::CreateObjectActionActivationImpl, virtual public CS_CreateObjectActionActivation 
	{
		public: 
			CS_CreateObjectActionActivationImpl(const CS_CreateObjectActionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			CS_CreateObjectActionActivationImpl& operator=(CS_CreateObjectActionActivationImpl const&); 

		protected:
			friend class PSCS::Semantics::Actions::ActionsFactoryImpl;
			CS_CreateObjectActionActivationImpl();
			virtual std::shared_ptr<CS_CreateObjectActionActivation> getThisCS_CreateObjectActionActivationPtr() const;
			virtual void setThisCS_CreateObjectActionActivationPtr(std::weak_ptr<CS_CreateObjectActionActivation> thisCS_CreateObjectActionActivationPtr);

			//Additional constructors for the containments back reference
			CS_CreateObjectActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			//destructor
			virtual ~CS_CreateObjectActionActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual void doAction() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			
			//*********************************
			// Union Reference Getters
			//*********************************
			virtual std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> getPinActivation() const ;
			
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
			std::weak_ptr<CS_CreateObjectActionActivation> m_thisCS_CreateObjectActionActivationPtr;
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_ACTIONS_CS_CREATEOBJECTACTIONACTIVATIONCS_CREATEOBJECTACTIONACTIVATIONIMPL_HPP */
