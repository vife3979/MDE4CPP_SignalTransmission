//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIVITIES_EXPANSIONNODEACTIVATIONEXPANSIONNODEACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIVITIES_EXPANSIONNODEACTIVATIONEXPANSIONNODEACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../ExpansionNodeActivation.hpp"

#include "fUML/Semantics/Activities/impl/ActivitiesFactoryImpl.hpp"
#include "fUML/Semantics/Activities/impl/ObjectNodeActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Activities 
{
	class FUML_API ExpansionNodeActivationImpl : virtual public ObjectNodeActivationImpl, virtual public ExpansionNodeActivation 
	{
		public: 
			ExpansionNodeActivationImpl(const ExpansionNodeActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ExpansionNodeActivationImpl& operator=(ExpansionNodeActivationImpl const&); 

		protected:
			friend class fUML::Semantics::Activities::ActivitiesFactoryImpl;
			ExpansionNodeActivationImpl();
			virtual std::shared_ptr<ExpansionNodeActivation> getThisExpansionNodeActivationPtr() const;
			virtual void setThisExpansionNodeActivationPtr(std::weak_ptr<ExpansionNodeActivation> thisExpansionNodeActivationPtr);

			//Additional constructors for the containments back reference
			ExpansionNodeActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			//destructor
			virtual ~ExpansionNodeActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual void fire(std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incomingTokens) ;
			virtual std::shared_ptr<fUML::Semantics::Activities::ExpansionRegionActivation> getExpansionRegionActivation() ;
			virtual bool isReady() ;
			virtual void receiveOffer() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			
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
			std::weak_ptr<ExpansionNodeActivation> m_thisExpansionNodeActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIES_EXPANSIONNODEACTIVATIONEXPANSIONNODEACTIVATIONIMPL_HPP */
