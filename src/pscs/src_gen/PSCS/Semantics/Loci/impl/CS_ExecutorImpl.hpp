//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_LOCI_CS_EXECUTORCS_EXECUTORIMPL_HPP
#define PSCS_SEMANTICS_LOCI_CS_EXECUTORCS_EXECUTORIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../CS_Executor.hpp"

#include "PSCS/Semantics/Loci/impl/LociFactoryImpl.hpp"
#include "fUML/Semantics/Loci/impl/ExecutorImpl.hpp"

//*********************************
namespace PSCS::Semantics::Loci 
{
	class CS_ExecutorImpl : virtual public fUML::Semantics::Loci::ExecutorImpl, virtual public CS_Executor 
	{
		public: 
			CS_ExecutorImpl(const CS_ExecutorImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			CS_ExecutorImpl& operator=(CS_ExecutorImpl const&); 

		protected:
			friend class PSCS::Semantics::Loci::LociFactoryImpl;
			CS_ExecutorImpl();
			virtual std::shared_ptr<CS_Executor> getThisCS_ExecutorPtr() const;
			virtual void setThisCS_ExecutorPtr(std::weak_ptr<CS_Executor> thisCS_ExecutorPtr);

			//Additional constructors for the containments back reference
			CS_ExecutorImpl(std::weak_ptr<fUML::Semantics::Loci::Locus> par_locus);

		public:
			//destructor
			virtual ~CS_ExecutorImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> start(std::shared_ptr<uml::Class> type,std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> inputs) ;
			
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
			std::weak_ptr<CS_Executor> m_thisCS_ExecutorPtr;
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_LOCI_CS_EXECUTORCS_EXECUTORIMPL_HPP */
