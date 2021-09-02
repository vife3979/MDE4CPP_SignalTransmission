//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_VALUES_BAGTYPEVALUEBAGTYPEVALUEIMPL_HPP
#define OCL_VALUES_BAGTYPEVALUEBAGTYPEVALUEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../BagTypeValue.hpp"

#include "ocl/Values/impl/ValuesFactoryImpl.hpp"
#include "ocl/Values/impl/CollectionValueImpl.hpp"

//*********************************
namespace ocl::Values 
{
	class OCL_API BagTypeValueImpl : virtual public CollectionValueImpl, virtual public BagTypeValue 
	{
		public: 
			BagTypeValueImpl(const BagTypeValueImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			BagTypeValueImpl& operator=(BagTypeValueImpl const&); 

		protected:
			friend class ocl::Values::ValuesFactoryImpl;
			BagTypeValueImpl();
			virtual std::shared_ptr<BagTypeValue> getThisBagTypeValuePtr() const;
			virtual void setThisBagTypeValuePtr(std::weak_ptr<BagTypeValue> thisBagTypeValuePtr);


		public:
			//destructor
			virtual ~BagTypeValueImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual bool addValue(std::shared_ptr<fUML::Semantics::Values::Value> value) ;
			
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
			std::weak_ptr<BagTypeValue> m_thisBagTypeValuePtr;
	};
}
#endif /* end of include guard: OCL_VALUES_BAGTYPEVALUEBAGTYPEVALUEIMPL_HPP */
