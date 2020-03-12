//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_ACTIONS_CS_CREATELINKACTIONACTIVATIONCS_CREATELINKACTIONACTIVATIONIMPL_HPP
#define PSCS_SEMANTICS_ACTIONS_CS_CREATELINKACTIONACTIVATIONCS_CREATELINKACTIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../CS_CreateLinkActionActivation.hpp"

#include "PSCS/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/CreateLinkActionActivationImpl.hpp"

//*********************************
namespace PSCS::Semantics::Actions 
{
	class CS_CreateLinkActionActivationImpl :virtual public fUML::Semantics::Actions::CreateLinkActionActivationImpl, virtual public CS_CreateLinkActionActivation 
	{
		public: 
			CS_CreateLinkActionActivationImpl(const CS_CreateLinkActionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			CS_CreateLinkActionActivationImpl& operator=(CS_CreateLinkActionActivationImpl const&) = delete;

		protected:
			friend class PSCS::Semantics::Actions::ActionsFactoryImpl;
			CS_CreateLinkActionActivationImpl();
			virtual std::shared_ptr<CS_CreateLinkActionActivation> getThisCS_CreateLinkActionActivationPtr() const;
			virtual void setThisCS_CreateLinkActionActivationPtr(std::weak_ptr<CS_CreateLinkActionActivation> thisCS_CreateLinkActionActivationPtr);

			//Additional constructors for the containments back reference
			CS_CreateLinkActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group);




		public:
			//destructor
			virtual ~CS_CreateLinkActionActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual void doAction() ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> getPinActivation() const ; 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************

			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<CS_CreateLinkActionActivation> m_thisCS_CreateLinkActionActivationPtr;
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_ACTIONS_CS_CREATELINKACTIONACTIVATIONCS_CREATELINKACTIONACTIVATIONIMPL_HPP */
