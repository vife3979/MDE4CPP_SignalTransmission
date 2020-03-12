//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_WRITESTRUCTURALFEATUREACTIONACTIVATIONWRITESTRUCTURALFEATUREACTIONACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIONS_WRITESTRUCTURALFEATUREACTIONACTIVATIONWRITESTRUCTURALFEATUREACTIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../WriteStructuralFeatureActionActivation.hpp"

#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/StructuralFeatureActionActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Actions 
{
	class WriteStructuralFeatureActionActivationImpl :virtual public StructuralFeatureActionActivationImpl, virtual public WriteStructuralFeatureActionActivation 
	{
		public: 
			WriteStructuralFeatureActionActivationImpl(const WriteStructuralFeatureActionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			WriteStructuralFeatureActionActivationImpl& operator=(WriteStructuralFeatureActionActivationImpl const&) = delete;

		protected:
			friend class fUML::Semantics::Actions::ActionsFactoryImpl;
			WriteStructuralFeatureActionActivationImpl();
			virtual std::shared_ptr<WriteStructuralFeatureActionActivation> getThisWriteStructuralFeatureActionActivationPtr() const;
			virtual void setThisWriteStructuralFeatureActionActivationPtr(std::weak_ptr<WriteStructuralFeatureActionActivation> thisWriteStructuralFeatureActionActivationPtr);

			//Additional constructors for the containments back reference
			WriteStructuralFeatureActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group);




		public:
			//destructor
			virtual ~WriteStructuralFeatureActionActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual int position(std::shared_ptr<fUML::Semantics::Values::Value>  value,std::shared_ptr<Bag<fUML::Semantics::Values::Value> >  list,int startAt) ;
			
			
			
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
			std::weak_ptr<WriteStructuralFeatureActionActivation> m_thisWriteStructuralFeatureActionActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_WRITESTRUCTURALFEATUREACTIONACTIVATIONWRITESTRUCTURALFEATUREACTIONACTIVATIONIMPL_HPP */
