//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIVITIES_JOINNODEACTIVATIONJOINNODEACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIVITIES_JOINNODEACTIVATIONJOINNODEACTIVATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../JoinNodeActivation.hpp"

#include "fUML/Semantics/Activities/impl/ActivitiesFactoryImpl.hpp"
#include "fUML/Semantics/Activities/impl/ControlNodeActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Activities 
{
	class JoinNodeActivationImpl : virtual public ControlNodeActivationImpl, virtual public JoinNodeActivation 
	{
		public: 
			JoinNodeActivationImpl(const JoinNodeActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			JoinNodeActivationImpl& operator=(JoinNodeActivationImpl const&); 

		protected:
			friend class fUML::Semantics::Activities::ActivitiesFactoryImpl;
			JoinNodeActivationImpl();
			virtual std::shared_ptr<JoinNodeActivation> getThisJoinNodeActivationPtr() const;
			virtual void setThisJoinNodeActivationPtr(std::weak_ptr<JoinNodeActivation> thisJoinNodeActivationPtr);

			//Additional constructors for the containments back reference
			JoinNodeActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			//destructor
			virtual ~JoinNodeActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual void fire(std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incomingTokens) ; 
			virtual bool isReady() ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			
			
			//*********************************
			// Union Getter
			//*********************************
			 
			 
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
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<JoinNodeActivation> m_thisJoinNodeActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIES_JOINNODEACTIVATIONJOINNODEACTIVATIONIMPL_HPP */
