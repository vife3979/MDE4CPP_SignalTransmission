//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_ESTRUCTURALFEATURE_HPP
#define ECORE_ESTRUCTURALFEATURE_HPP


#include <memory>
#include <string>
#include "abstractDataTypes/Any.hpp"
// forward declarations


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
	class EClass;
	class EClassifier;
	class EGenericType;
}

// namespace macro header include
#include "ecore/ecore.hpp"

// base class includes
#include "ecore/ETypedElement.hpp"




//*********************************
namespace ecore 
{
	
	class ECORE_API EStructuralFeature: virtual public ETypedElement
	{
		public:
 			EStructuralFeature(const EStructuralFeature &) {}

		protected:
			EStructuralFeature(){}
			//Additional constructors for the containments back reference
			EStructuralFeature(std::weak_ptr<ecore::EObject> par_eContainer);

			//Additional constructors for the containments back reference
			EStructuralFeature(std::weak_ptr<ecore::EClass> par_eContainingClass);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~EStructuralFeature() {}

			//*********************************
			// Operations
			//*********************************
			virtual void * getContainerClass() = 0;
			

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual bool isChangeable() const = 0;
			virtual void setChangeable (bool _changeable)= 0;
			virtual std::shared_ptr<Any> getDefaultValue() const = 0;
			virtual void setDefaultValue (std::shared_ptr<Any> _defaultValue)= 0;
			virtual std::string getDefaultValueLiteral() const = 0;
			virtual void setDefaultValueLiteral (std::string _defaultValueLiteral)= 0;
			virtual bool isDerived() const = 0;
			virtual void setDerived (bool _derived)= 0;
			virtual int getFeatureID() const = 0;
			virtual bool isTransient() const = 0;
			virtual void setTransient (bool _transient)= 0;
			virtual bool isUnsettable() const = 0;
			virtual void setUnsettable (bool _unsettable)= 0;
			virtual bool isVolatile() const = 0;
			virtual void setVolatile (bool _volatile)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::weak_ptr<ecore::EClass> getEContainingClass() const = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
			virtual std::shared_ptr<Union<ecore::EObject>> getEContentUnion() const = 0;

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
			bool m_changeable= true;
			std::shared_ptr<Any> m_defaultValue= nullptr;
			std::string m_defaultValueLiteral= "";
			bool m_derived= false;
			int m_featureID= -1;
			bool m_transient= false;
			bool m_unsettable= false;
			bool m_volatile= false;
			
			//*********************************
			// Reference Members
			//*********************************
			std::weak_ptr<ecore::EClass> m_eContainingClass;
	};
}
#endif /* end of include guard: ECORE_ESTRUCTURALFEATURE_HPP */
