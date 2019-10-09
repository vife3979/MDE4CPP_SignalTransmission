//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_ECLASSIFIER_HPP
#define ECORE_ECLASSIFIER_HPP

#include <list>
#include <memory>
#include <string>

#include "abstractDataTypes/Any.hpp"

// forward declarations
template<class T> class Bag;



//*********************************
// generated Includes

#include <map>

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
	class EcoreFactory;
}

//Forward Declaration for used types
namespace ecore 
{
	class EAnnotation;
}

namespace ecore 
{
	class ENamedElement;
}

namespace ecore 
{
	class EObject;
}

namespace ecore 
{
	class EPackage;
}

namespace ecore 
{
	class ETypeParameter;
}

// base class includes
#include "ecore/ENamedElement.hpp"

// enum includes


//*********************************
namespace ecore 
{
	/*!
	 */
	class EClassifier:virtual public ENamedElement
	{
		public:
 			EClassifier(const EClassifier &) {}
			EClassifier& operator=(EClassifier const&) = delete;

		protected:
			EClassifier(){}


			//Additional constructors for the containments back reference

			EClassifier(std::weak_ptr<ecore::EObject > par_eContainer);

			//Additional constructors for the containments back reference

			EClassifier(std::weak_ptr<ecore::EPackage > par_ePackage);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~EClassifier() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual int getClassifierID() = 0;
			
			/*!
			 */ 
			virtual bool isInstance(Any object) const = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 */ 
			virtual Any getDefaultValue() const = 0;
			
			/*!
			 */ 
			virtual void setDefaultValue (Any _defaultValue)= 0; 
			
			/*!
			 */ 
			virtual void *  getInstanceClass() const = 0;
			
			/*!
			 */ 
			virtual std::string getInstanceClassName() const = 0;
			
			/*!
			 */ 
			virtual void setInstanceClassName (std::string _instanceClassName)= 0; 
			
			/*!
			 */ 
			virtual std::string getInstanceTypeName() const = 0;
			
			/*!
			 */ 
			virtual void setInstanceTypeName (std::string _instanceTypeName)= 0; 
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::weak_ptr<ecore::EPackage > getEPackage() const = 0;
			
			/*!
			 */
			virtual std::shared_ptr<Bag<ecore::ETypeParameter>> getETypeParameters() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			 */ 
			Any m_defaultValue = nullptr;
			/*!
			 */ 
			void *  m_instanceClass = nullptr;
			/*!
			 */ 
			std::string m_instanceClassName = "";
			/*!
			 */ 
			std::string m_instanceTypeName = "";
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 */
			std::weak_ptr<ecore::EPackage > m_ePackage;
			/*!
			 */
			std::shared_ptr<Bag<ecore::ETypeParameter>> m_eTypeParameters;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<Union<ecore::EObject>> getEContens() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: ECORE_ECLASSIFIER_HPP */
