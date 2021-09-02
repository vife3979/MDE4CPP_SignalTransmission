//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_EGENERICTYPE_HPP
#define ECORE_EGENERICTYPE_HPP


#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 

class AnyObject;
typedef std::shared_ptr<AnyObject> Any;

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
	class EClassifier;
	class ETypeParameter;
}

// namespace macro header include
#include "ecore/ecore.hpp"



#include "ecore/EModelElement.hpp"


//*********************************
namespace ecore 
{
	
	class ECORE_API EGenericType : virtual public ecore::EModelElement
	{
		public:
 			EGenericType(const EGenericType &) {}

		protected:
			EGenericType(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~EGenericType() {}

			//*********************************
			// Operations
			//*********************************
			virtual bool isInstance(Any object) const = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<ecore::EClassifier> getEClassifier() const = 0;
			virtual void setEClassifier(std::shared_ptr<ecore::EClassifier>) = 0;
			virtual std::shared_ptr<ecore::EGenericType> getELowerBound() const = 0;
			virtual void setELowerBound(std::shared_ptr<ecore::EGenericType>) = 0;
			virtual std::shared_ptr<ecore::EClassifier> getERawType() const = 0;
			virtual void setERawType(std::shared_ptr<ecore::EClassifier>) = 0;
			virtual std::shared_ptr<Bag<ecore::EGenericType>> getETypeArguments() const = 0;
			virtual std::shared_ptr<ecore::ETypeParameter> getETypeParameter() const = 0;
			virtual void setETypeParameter(std::shared_ptr<ecore::ETypeParameter>) = 0;
			virtual std::shared_ptr<ecore::EGenericType> getEUpperBound() const = 0;
			virtual void setEUpperBound(std::shared_ptr<ecore::EGenericType>) = 0;

			//*********************************
			// Union Reference Getters
			//*********************************

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
			
			//*********************************
			// Reference Members
			//*********************************
			std::shared_ptr<ecore::EClassifier> m_eClassifier;
			std::shared_ptr<ecore::EGenericType> m_eLowerBound;
			std::shared_ptr<ecore::EClassifier> m_eRawType;
			mutable std::shared_ptr<Bag<ecore::EGenericType>> m_eTypeArguments;
			std::shared_ptr<ecore::ETypeParameter> m_eTypeParameter;
			std::shared_ptr<ecore::EGenericType> m_eUpperBound;
	};
}
#endif /* end of include guard: ECORE_EGENERICTYPE_HPP */
