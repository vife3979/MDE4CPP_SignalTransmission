//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_EENUMLITERALEENUMLITERALIMPL_HPP
#define ECORE_EENUMLITERALEENUMLITERALIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ecore/ecore.hpp" 

// model includes
#include "../EEnumLiteral.hpp"

#include "ecore/impl/ENamedElementImpl.hpp"

//*********************************
namespace ecore 
{
	class ECORE_API EEnumLiteralImpl : virtual public ENamedElementImpl, virtual public EEnumLiteral 
	{
		public: 
			EEnumLiteralImpl(const EEnumLiteralImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			EEnumLiteralImpl& operator=(EEnumLiteralImpl const&); 

		protected:
			friend class ecoreFactoryImpl;
			EEnumLiteralImpl();
			virtual std::shared_ptr<ecore::EEnumLiteral> getThisEEnumLiteralPtr() const;
			virtual void setThisEEnumLiteralPtr(std::weak_ptr<ecore::EEnumLiteral> thisEEnumLiteralPtr);

			//Additional constructors for the containments back reference
			EEnumLiteralImpl(std::weak_ptr<ecore::EObject> par_eContainer);
			//Additional constructors for the containments back reference
			EEnumLiteralImpl(std::weak_ptr<ecore::EEnum> par_eEnum);

		public:
			//destructor
			virtual ~EEnumLiteralImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual std::shared_ptr<Any> getInstance() const ;
			virtual void setInstance (std::shared_ptr<Any> _instance);
			virtual std::string getLiteral() const ;
			virtual void setLiteral (std::string _literal);
			virtual int getValue() const ;
			virtual void setValue (int _value);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::weak_ptr<ecore::EEnum> getEEnum() const ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			virtual std::shared_ptr<Union<ecore::EObject>> getEContentUnion() const ;
			
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
			virtual bool eSet(int featureID, std::shared_ptr<Any> newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments) ;

		private:
			std::weak_ptr<ecore::EEnumLiteral> m_thisEEnumLiteralPtr;
	};
}
#endif /* end of include guard: ECORE_EENUMLITERALEENUMLITERALIMPL_HPP */
