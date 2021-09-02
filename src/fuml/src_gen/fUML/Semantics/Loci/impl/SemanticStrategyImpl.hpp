//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_LOCI_SEMANTICSTRATEGYSEMANTICSTRATEGYIMPL_HPP
#define FUML_SEMANTICS_LOCI_SEMANTICSTRATEGYSEMANTICSTRATEGYIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../SemanticStrategy.hpp"

#include "fUML/Semantics/Loci/impl/LociFactoryImpl.hpp"

#include "ecore/impl/EModelElementImpl.hpp"

//*********************************
namespace fUML::Semantics::Loci 
{
	class FUML_API SemanticStrategyImpl : virtual public ecore::EModelElementImpl,
virtual public SemanticStrategy 
	{
		public: 
			SemanticStrategyImpl(const SemanticStrategyImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			SemanticStrategyImpl& operator=(SemanticStrategyImpl const&); 

		protected:
			friend class fUML::Semantics::Loci::LociFactoryImpl;
			SemanticStrategyImpl();
			virtual std::shared_ptr<SemanticStrategy> getThisSemanticStrategyPtr() const;
			virtual void setThisSemanticStrategyPtr(std::weak_ptr<SemanticStrategy> thisSemanticStrategyPtr);


		public:
			//destructor
			virtual ~SemanticStrategyImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual std::string getName() ;
			
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
			std::weak_ptr<SemanticStrategy> m_thisSemanticStrategyPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_LOCI_SEMANTICSTRATEGYSEMANTICSTRATEGYIMPL_HPP */
