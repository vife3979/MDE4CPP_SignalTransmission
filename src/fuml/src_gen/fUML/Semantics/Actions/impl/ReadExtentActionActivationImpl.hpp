//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_READEXTENTACTIONACTIVATIONREADEXTENTACTIONACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIONS_READEXTENTACTIONACTIVATIONREADEXTENTACTIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../ReadExtentActionActivation.hpp"

#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/ActionActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Actions 
{
	class FUML_API ReadExtentActionActivationImpl : virtual public ActionActivationImpl, virtual public ReadExtentActionActivation 
	{
		public: 
			ReadExtentActionActivationImpl(const ReadExtentActionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ReadExtentActionActivationImpl& operator=(ReadExtentActionActivationImpl const&); 

		protected:
			friend class fUML::Semantics::Actions::ActionsFactoryImpl;
			ReadExtentActionActivationImpl();
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadExtentActionActivation> getThisReadExtentActionActivationPtr() const;
			virtual void setThisReadExtentActionActivationPtr(std::weak_ptr<fUML::Semantics::Actions::ReadExtentActionActivation> thisReadExtentActionActivationPtr);

			//Additional constructors for the containments back reference
			ReadExtentActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			//destructor
			virtual ~ReadExtentActionActivationImpl();
			
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
			virtual std::shared_ptr<uml::ReadExtentAction> getReadExtentAction() const ;
			virtual void setReadExtentAction(std::shared_ptr<uml::ReadExtentAction>) ;
			/*Additional Setter for 'ActionActivation::action' redefined by reference 'readExtentAction'*/
			virtual void setAction(std::shared_ptr<uml::Action>) ;
			/*Additional Setter for 'ActivityNodeActivation::node' redefined by reference 'readExtentAction'*/
			virtual void setNode(std::shared_ptr<uml::ActivityNode>) ;
			
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
			virtual bool eSet(int featureID, std::shared_ptr<Any> newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments) ;

		private:
			std::weak_ptr<fUML::Semantics::Actions::ReadExtentActionActivation> m_thisReadExtentActionActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_READEXTENTACTIONACTIVATIONREADEXTENTACTIONACTIVATIONIMPL_HPP */
