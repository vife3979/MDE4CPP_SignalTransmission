//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_EXTENSIONALVALUEEXTENSIONALVALUEIMPL_HPP
#define FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_EXTENSIONALVALUEEXTENSIONALVALUEIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../ExtensionalValue.hpp"

#include "fUML/Semantics/StructuredClassifiers/impl/StructuredClassifiersFactoryImpl.hpp"
#include "fUML/Semantics/SimpleClassifiers/impl/CompoundValueImpl.hpp"

//*********************************
namespace fUML::Semantics::StructuredClassifiers 
{
	class ExtensionalValueImpl :virtual public fUML::Semantics::SimpleClassifiers::CompoundValueImpl, virtual public ExtensionalValue 
	{
		public: 
			ExtensionalValueImpl(const ExtensionalValueImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			ExtensionalValueImpl& operator=(ExtensionalValueImpl const&) = delete;

		protected:
			friend class fUML::Semantics::StructuredClassifiers::StructuredClassifiersFactoryImpl;
			ExtensionalValueImpl();
			virtual std::shared_ptr<ExtensionalValue> getThisExtensionalValuePtr() const;
			virtual void setThisExtensionalValuePtr(std::weak_ptr<ExtensionalValue> thisExtensionalValuePtr);



		public:
			//destructor
			virtual ~ExtensionalValueImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual void destroy() ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<fUML::Semantics::Loci::Locus > getLocus() const ;
			
			/*!
			 */
			virtual void setLocus(std::shared_ptr<fUML::Semantics::Loci::Locus> _locus_locus) ;
							
			
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
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<ExtensionalValue> m_thisExtensionalValuePtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_EXTENSIONALVALUEEXTENSIONALVALUEIMPL_HPP */
