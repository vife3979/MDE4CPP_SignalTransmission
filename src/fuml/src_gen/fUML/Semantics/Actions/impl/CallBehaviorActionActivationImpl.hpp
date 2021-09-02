//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_CALLBEHAVIORACTIONACTIVATIONCALLBEHAVIORACTIONACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIONS_CALLBEHAVIORACTIONACTIVATIONCALLBEHAVIORACTIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../CallBehaviorActionActivation.hpp"

#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/CallActionActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Actions 
{
	class FUML_API CallBehaviorActionActivationImpl : virtual public CallActionActivationImpl, virtual public CallBehaviorActionActivation 
	{
		public: 
			CallBehaviorActionActivationImpl(const CallBehaviorActionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			CallBehaviorActionActivationImpl& operator=(CallBehaviorActionActivationImpl const&); 

		protected:
			friend class fUML::Semantics::Actions::ActionsFactoryImpl;
			CallBehaviorActionActivationImpl();
			virtual std::shared_ptr<CallBehaviorActionActivation> getThisCallBehaviorActionActivationPtr() const;
			virtual void setThisCallBehaviorActionActivationPtr(std::weak_ptr<CallBehaviorActionActivation> thisCallBehaviorActionActivationPtr);

			//Additional constructors for the containments back reference
			CallBehaviorActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			//destructor
			virtual ~CallBehaviorActionActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> getCallExecution() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<uml::CallBehaviorAction> getCallBehaviorAction() const ;
			virtual void setCallBehaviorAction(std::shared_ptr<uml::CallBehaviorAction>) ;
			/*Additional Setter for 'CallActionActivation::callAction' redefined by reference 'callBehaviorAction'*/
			virtual void setCallAction(std::shared_ptr<uml::CallAction>) ;
			/*Additional Setter for 'ActionActivation::action' redefined by reference 'callBehaviorAction'*/
			virtual void setAction(std::shared_ptr<uml::Action>) ;
			/*Additional Setter for 'ActivityNodeActivation::node' redefined by reference 'callBehaviorAction'*/
			virtual void setNode(std::shared_ptr<uml::ActivityNode>) ;
			
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
			std::weak_ptr<CallBehaviorActionActivation> m_thisCallBehaviorActionActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_CALLBEHAVIORACTIONACTIVATIONCALLBEHAVIORACTIONACTIVATIONIMPL_HPP */
