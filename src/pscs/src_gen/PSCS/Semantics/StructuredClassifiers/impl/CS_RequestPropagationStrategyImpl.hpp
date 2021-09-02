//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_STRUCTUREDCLASSIFIERS_CS_REQUESTPROPAGATIONSTRATEGYCS_REQUESTPROPAGATIONSTRATEGYIMPL_HPP
#define PSCS_SEMANTICS_STRUCTUREDCLASSIFIERS_CS_REQUESTPROPAGATIONSTRATEGYCS_REQUESTPROPAGATIONSTRATEGYIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "PSCS/PSCS.hpp" 

// model includes
#include "../CS_RequestPropagationStrategy.hpp"

#include "PSCS/Semantics/StructuredClassifiers/impl/StructuredClassifiersFactoryImpl.hpp"
#include "fUML/Semantics/Loci/impl/SemanticStrategyImpl.hpp"

//*********************************
namespace PSCS::Semantics::StructuredClassifiers 
{
	class PSCS_API CS_RequestPropagationStrategyImpl : virtual public fUML::Semantics::Loci::SemanticStrategyImpl, virtual public CS_RequestPropagationStrategy 
	{
		public: 
			CS_RequestPropagationStrategyImpl(const CS_RequestPropagationStrategyImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			CS_RequestPropagationStrategyImpl& operator=(CS_RequestPropagationStrategyImpl const&); 

		protected:
			friend class PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactoryImpl;
			CS_RequestPropagationStrategyImpl();
			virtual std::shared_ptr<CS_RequestPropagationStrategy> getThisCS_RequestPropagationStrategyPtr() const;
			virtual void setThisCS_RequestPropagationStrategyPtr(std::weak_ptr<CS_RequestPropagationStrategy> thisCS_RequestPropagationStrategyPtr);


		public:
			//destructor
			virtual ~CS_RequestPropagationStrategyImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual std::string getName() ;
			virtual std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference> > select(std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference>> potentialTargets,std::shared_ptr<fUML::Semantics::Loci::SemanticVisitor> context) ;
			
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
			std::weak_ptr<CS_RequestPropagationStrategy> m_thisCS_RequestPropagationStrategyPtr;
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_STRUCTUREDCLASSIFIERS_CS_REQUESTPROPAGATIONSTRATEGYCS_REQUESTPROPAGATIONSTRATEGYIMPL_HPP */
