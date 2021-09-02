//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_SIMPLECLASSIFIERS_STRUCTUREDVALUESTRUCTUREDVALUEIMPL_HPP
#define FUML_SEMANTICS_SIMPLECLASSIFIERS_STRUCTUREDVALUESTRUCTUREDVALUEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../StructuredValue.hpp"

#include "fUML/Semantics/SimpleClassifiers/impl/SimpleClassifiersFactoryImpl.hpp"
#include "fUML/Semantics/Values/impl/ValueImpl.hpp"

//*********************************
namespace fUML::Semantics::SimpleClassifiers 
{
	class FUML_API StructuredValueImpl : virtual public fUML::Semantics::Values::ValueImpl, virtual public StructuredValue 
	{
		public: 
			StructuredValueImpl(const StructuredValueImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			StructuredValueImpl& operator=(StructuredValueImpl const&); 

		protected:
			friend class fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactoryImpl;
			StructuredValueImpl();
			virtual std::shared_ptr<StructuredValue> getThisStructuredValuePtr() const;
			virtual void setThisStructuredValuePtr(std::weak_ptr<StructuredValue> thisStructuredValuePtr);


		public:
			//destructor
			virtual ~StructuredValueImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual void assignFeatureValue(std::shared_ptr<uml::StructuralFeature> feature,std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values,int position) ;
			virtual void createFeatureValues() ;
			virtual std::shared_ptr<Bag<fUML::Semantics::Values::Value> > getValues(std::shared_ptr<uml::StructuralFeature> feature,std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues) ;
			virtual void removeValue(std::shared_ptr<uml::StructuralFeature> feature,std::shared_ptr<fUML::Semantics::Values::Value> value) ;
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> retrieveFeatureValue(std::shared_ptr<uml::StructuralFeature> feature) ;
			virtual std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue> > retrieveFeatureValues() ;
			virtual void setFeatureValue(std::shared_ptr<uml::StructuralFeature> feature,std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values,int position) ;
			virtual std::shared_ptr<uml::ValueSpecification> specify() ;
			
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
			std::weak_ptr<StructuredValue> m_thisStructuredValuePtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_SIMPLECLASSIFIERS_STRUCTUREDVALUESTRUCTUREDVALUEIMPL_HPP */
