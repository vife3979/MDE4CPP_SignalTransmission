//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_EOBJECTEOBJECTIMPL_HPP
#define ECORE_EOBJECTEOBJECTIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../EObject.hpp"



//*********************************
namespace ecore 
{
	class EObjectImpl : 
virtual public EObject 
	{
		public: 
			EObjectImpl(const EObjectImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			EObjectImpl& operator=(EObjectImpl const&) = delete;

		protected:
			friend class EcoreFactoryImpl;
			EObjectImpl();
			virtual std::shared_ptr<EObject> getThisEObjectPtr() const;
			virtual void setThisEObjectPtr(std::weak_ptr<EObject> thisEObjectPtr);

			//Additional constructors for the containments back reference
			EObjectImpl(std::weak_ptr<ecore::EObject > par_eContainer);




		public:
			//destructor
			virtual ~EObjectImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual std::shared_ptr<Bag <   ecore::EObject > > eAllContents() const ;
			
			 
			virtual std::shared_ptr<ecore::EClass> eClass() const ;
			
			
			
			 
			virtual std::shared_ptr<ecore::EStructuralFeature> eContainingFeature() const ;
			
			 
			virtual std::shared_ptr<ecore::EReference> eContainmentFeature() const ;
			
			 
			virtual std::shared_ptr<Bag <   ecore::EObject > > eContents() const ;
			
			 
			virtual std::shared_ptr<Bag <   ecore::EObject > > eCrossReferences() const ;
			
			 
			virtual Any eGet(std::shared_ptr<ecore::EStructuralFeature>  feature) const ;
			
			 
			virtual Any eGet(std::shared_ptr<ecore::EStructuralFeature>  feature,bool resolve) const ;
			
			 
			virtual Any eInvoke(std::shared_ptr<ecore::EOperation>  operation,Bag <   Any >  arguments) const ;
			
			 
			virtual bool eIsProxy() const ;
			
			 
			virtual bool eIsSet(std::shared_ptr<ecore::EStructuralFeature>  feature) const ;
			
			 
			virtual int eResource() const ;
			
			 
			virtual void eSet(std::shared_ptr<ecore::EStructuralFeature>  feature,Any newValue) ;
			
			 
			virtual void eUnset(std::shared_ptr<ecore::EStructuralFeature>  feature) const ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			 
			virtual int getMetaElementID() const ;
			
			 
			virtual void setMetaElementID (int _metaElementID); 
			
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::weak_ptr<ecore::EObject > getEContainer() const ;
			
			
			virtual void setEContainer(std::shared_ptr<ecore::EObject> _eContainer) ;
			
			
			
							
			
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
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<EObject> m_thisEObjectPtr;
	};
}
#endif /* end of include guard: ECORE_EOBJECTEOBJECTIMPL_HPP */
