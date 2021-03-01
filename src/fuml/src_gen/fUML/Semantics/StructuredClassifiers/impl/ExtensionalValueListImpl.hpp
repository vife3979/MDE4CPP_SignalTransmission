//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_EXTENSIONALVALUELISTEXTENSIONALVALUELISTIMPL_HPP
#define FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_EXTENSIONALVALUELISTEXTENSIONALVALUELISTIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../ExtensionalValueList.hpp"

#include "fUML/Semantics/StructuredClassifiers/impl/StructuredClassifiersFactoryImpl.hpp"
#include "fUML/Semantics/StructuredClassifiers/impl/ExtensionalValueImpl.hpp"

//*********************************
namespace fUML::Semantics::StructuredClassifiers 
{
	class ExtensionalValueListImpl : virtual public ExtensionalValueImpl, virtual public ExtensionalValueList 
	{
		public: 
			ExtensionalValueListImpl(const ExtensionalValueListImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ExtensionalValueListImpl& operator=(ExtensionalValueListImpl const&); 

		protected:
			friend class fUML::Semantics::StructuredClassifiers::StructuredClassifiersFactoryImpl;
			ExtensionalValueListImpl();
			virtual std::shared_ptr<ExtensionalValueList> getThisExtensionalValueListPtr() const;
			virtual void setThisExtensionalValueListPtr(std::weak_ptr<ExtensionalValueList> thisExtensionalValueListPtr);


		public:
			//destructor
			virtual ~ExtensionalValueListImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual bool addValue(std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> value) ; 
			virtual void addValue(std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> value,int i) ; 
			virtual std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> getValue() ; 
			virtual std::string removeValue(int i) ; 
			virtual std::shared_ptr<fUML::Semantics::Values::Value> setValue(std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> value,int i) ;
			
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
			std::weak_ptr<ExtensionalValueList> m_thisExtensionalValueListPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_EXTENSIONALVALUELISTEXTENSIONALVALUELISTIMPL_HPP */
