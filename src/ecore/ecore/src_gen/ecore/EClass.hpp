//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_ECLASS_HPP
#define ECORE_ECLASS_HPP


#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 
template<class T, class ... U> class Subset;
template<class T, class ... U> class SubsetUnion;


//*********************************
// generated Includes
#include <map> // used for Persistence
#include <vector> // used for Persistence
namespace persistence
{
	namespace interfaces
	{
		class XLoadHandler; // used for Persistence
		class XSaveHandler; // used for Persistence
	}
}

namespace ecore
{
	class ecoreFactory;
}

//Forward Declaration for used types 
namespace ecore 
{
	class EAnnotation;
	class EAttribute;
	class EGenericType;
	class EOperation;
	class EPackage;
	class EReference;
	class EStructuralFeature;
	class ETypeParameter;
}

// namespace macro header include
#include "ecore/ecore.hpp"

// base class includes
#include "ecore/EClassifier.hpp"




//*********************************
namespace ecore 
{
	
	class ECORE_API EClass: virtual public EClassifier
	{
		public:
 			EClass(const EClass &) {}

		protected:
			EClass(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~EClass() {}

			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<ecore::EOperation> getEOperation(int operationID) const = 0;
			virtual std::shared_ptr<ecore::EStructuralFeature> getEStructuralFeature(int featureID) const = 0;
			virtual std::shared_ptr<ecore::EStructuralFeature> getEStructuralFeature(std::string featureName) const = 0;
			virtual int getFeatureCount() const = 0;
			virtual int getFeatureID(std::shared_ptr<ecore::EStructuralFeature> feature) const = 0;
			virtual std::shared_ptr<ecore::EGenericType> getFeatureType(std::shared_ptr<ecore::EStructuralFeature> feature) const = 0;
			virtual int getOperationCount() const = 0;
			virtual int getOperationID(std::shared_ptr<ecore::EOperation> operation) const = 0;
			virtual std::shared_ptr<ecore::EOperation> getOverride(std::shared_ptr<ecore::EOperation> operation) const = 0;
			virtual bool isSuperTypeOf(std::shared_ptr<ecore::EClass> someClass) const = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual bool isAbstract() const = 0;
			virtual void setAbstract (bool _abstract)= 0;
			virtual bool isInterface() const = 0;
			virtual void setInterface (bool _interface)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<Bag<ecore::EAttribute>> getEAllAttributes() const = 0;
			virtual std::shared_ptr<Bag<ecore::EReference>> getEAllContainments() const = 0;
			virtual std::shared_ptr<Bag<ecore::EGenericType>> getEAllGenericSuperTypes() const = 0;
			virtual std::shared_ptr<Bag<ecore::EOperation>> getEAllOperations() const = 0;
			virtual std::shared_ptr<Bag<ecore::EReference>> getEAllReferences() const = 0;
			virtual std::shared_ptr<Bag<ecore::EStructuralFeature>> getEAllStructuralFeatures() const = 0;
			virtual std::shared_ptr<Bag<ecore::EClass>> getEAllSuperTypes() const = 0;
			virtual std::shared_ptr<Subset<ecore::EAttribute, ecore::EStructuralFeature>> getEAttributes() const = 0;
			virtual std::shared_ptr<Bag<ecore::EGenericType>> getEGenericSuperTypes() const = 0;
			virtual std::shared_ptr<ecore::EAttribute> getEIDAttribute() const = 0;
			virtual void setEIDAttribute(std::shared_ptr<ecore::EAttribute>) = 0;
			virtual std::shared_ptr<Subset<ecore::EOperation, ecore::EObject>> getEOperations() const = 0;
			virtual std::shared_ptr<Subset<ecore::EReference, ecore::EStructuralFeature>> getEReferences() const = 0;
			
			virtual std::shared_ptr<Bag<ecore::EClass>> getESuperTypes() const = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
			virtual std::shared_ptr<Union<ecore::EObject>> getEContens() const = 0;
			virtual std::shared_ptr<SubsetUnion<ecore::EStructuralFeature, ecore::EObject>> getEStructuralFeatures() const = 0;

			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 

			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			bool m_abstract= false;
			bool m_interface= false;
			
			//*********************************
			// Reference Members
			//*********************************
			mutable std::shared_ptr<Bag<ecore::EAttribute>> m_eAllAttributes;
			mutable std::shared_ptr<Bag<ecore::EReference>> m_eAllContainments;
			mutable std::shared_ptr<Bag<ecore::EGenericType>> m_eAllGenericSuperTypes;
			mutable std::shared_ptr<Bag<ecore::EOperation>> m_eAllOperations;
			mutable std::shared_ptr<Bag<ecore::EReference>> m_eAllReferences;
			mutable std::shared_ptr<Bag<ecore::EStructuralFeature>> m_eAllStructuralFeatures;
			mutable std::shared_ptr<Bag<ecore::EClass>> m_eAllSuperTypes;
			mutable std::shared_ptr<Subset<ecore::EAttribute, ecore::EStructuralFeature>> m_eAttributes;
			mutable std::shared_ptr<Bag<ecore::EGenericType>> m_eGenericSuperTypes;
			std::shared_ptr<ecore::EAttribute> m_eIDAttribute;
			mutable std::shared_ptr<Subset<ecore::EOperation, ecore::EObject>> m_eOperations;
			mutable std::shared_ptr<Subset<ecore::EReference, ecore::EStructuralFeature>> m_eReferences;
			mutable std::shared_ptr<SubsetUnion<ecore::EStructuralFeature, ecore::EObject>> m_eStructuralFeatures;
			mutable std::shared_ptr<Bag<ecore::EClass>> m_eSuperTypes;
	};
}
#endif /* end of include guard: ECORE_ECLASS_HPP */
