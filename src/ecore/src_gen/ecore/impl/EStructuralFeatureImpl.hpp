//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_ESTRUCTURALFEATUREESTRUCTURALFEATUREIMPL_HPP
#define ECORE_ESTRUCTURALFEATUREESTRUCTURALFEATUREIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ecore/ecore.hpp" 

// model includes
#include "../EStructuralFeature.hpp"

#include "ecore/impl/ETypedElementImpl.hpp"

//*********************************
namespace ecore 
{
	class ECORE_API EStructuralFeatureImpl : virtual public ETypedElementImpl, virtual public EStructuralFeature 
	{
		public: 
			EStructuralFeatureImpl(const EStructuralFeatureImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			EStructuralFeatureImpl& operator=(EStructuralFeatureImpl const&); 

		protected:
			friend class ecoreFactoryImpl;
			EStructuralFeatureImpl();
			virtual std::shared_ptr<ecore::EStructuralFeature> getThisEStructuralFeaturePtr() const;
			virtual void setThisEStructuralFeaturePtr(std::weak_ptr<ecore::EStructuralFeature> thisEStructuralFeaturePtr);

			//Additional constructors for the containments back reference
			EStructuralFeatureImpl(std::weak_ptr<ecore::EObject> par_eContainer);
			//Additional constructors for the containments back reference
			EStructuralFeatureImpl(std::weak_ptr<ecore::EClass> par_eContainingClass);

		public:
			//destructor
			virtual ~EStructuralFeatureImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			virtual void * getContainerClass() ;
			virtual int getFeatureID() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual bool isChangeable() const ;
			virtual void setChangeable (bool _changeable);
			virtual std::shared_ptr<Any> getDefaultValue() const ;
			virtual void setDefaultValue (const std::shared_ptr<Any>& _defaultValue);
			virtual std::string getDefaultValueLiteral() const ;
			virtual void setDefaultValueLiteral (std::string _defaultValueLiteral);
			virtual bool isDerived() const ;
			virtual void setDerived (bool _derived);
			virtual bool isTransient() const ;
			virtual void setTransient (bool _transient);
			virtual bool isUnsettable() const ;
			virtual void setUnsettable (bool _unsettable);
			virtual bool isVolatile() const ;
			virtual void setVolatile (bool _volatile);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::weak_ptr<ecore::EClass> getEContainingClass() const ;
			
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
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;

		protected:
			virtual std::shared_ptr<EClass> eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual std::shared_ptr<Any> eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, const std::shared_ptr<Any>& newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID,const std::shared_ptr<Bag<Any>>& arguments) ;

		private:
			std::weak_ptr<ecore::EStructuralFeature> m_thisEStructuralFeaturePtr;
	};
}
#endif /* end of include guard: ECORE_ESTRUCTURALFEATUREESTRUCTURALFEATUREIMPL_HPP */
