//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_ECLASSIFIERECLASSIFIERIMPL_HPP
#define ECORE_ECLASSIFIERECLASSIFIERIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../EClassifier.hpp"

#include "ecore/impl/ENamedElementImpl.hpp"

//*********************************
namespace ecore 
{
	class EClassifierImpl : virtual public ENamedElementImpl, virtual public EClassifier 
	{
		public: 
			EClassifierImpl(const EClassifierImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:
			EClassifierImpl& operator=(EClassifierImpl const&) = delete;

		protected:
			friend class ecoreFactoryImpl;
			EClassifierImpl();
			virtual std::shared_ptr<EClassifier> getThisEClassifierPtr() const;
			virtual void setThisEClassifierPtr(std::weak_ptr<EClassifier> thisEClassifierPtr);

			//Additional constructors for the containments back reference
			EClassifierImpl(std::weak_ptr<ecore::EObject> par_eContainer);
			//Additional constructors for the containments back reference
			EClassifierImpl(std::weak_ptr<ecore::EPackage> par_ePackage);

		public:
			//destructor
			virtual ~EClassifierImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual int getClassifierID() ; 
			virtual bool isInstance(Any object) const ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			virtual Any getDefaultValue() const ;
			
			 
			virtual void setDefaultValue (Any _defaultValue);virtual void * getInstanceClass() const ;virtual std::string getInstanceClassName() const ;
			
			 
			virtual void setInstanceClassName (std::string _instanceClassName);virtual std::string getInstanceTypeName() const ;
			
			 
			virtual void setInstanceTypeName (std::string _instanceTypeName);
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::weak_ptr<ecore::EPackage> getEPackage() const ;
			
			
			
			virtual std::shared_ptr<Bag<ecore::ETypeParameter>> getETypeParameters() const ;
			
			
			
			
			//*********************************
			// Union Getter
			//*********************************
			
			virtual std::shared_ptr<Union<ecore::EObject>> getEContens() const ; 
			 
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
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<EClassifier> m_thisEClassifierPtr;
	};
}
#endif /* end of include guard: ECORE_ECLASSIFIERECLASSIFIERIMPL_HPP */
