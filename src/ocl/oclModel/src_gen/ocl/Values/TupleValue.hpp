//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_VALUES_TUPLEVALUE_HPP
#define OCL_VALUES_TUPLEVALUE_HPP


#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 


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

namespace ocl
{
	class oclFactory;
}

//Forward Declaration for used types 
namespace ocl::Types 
{
	class TupleType;
}
namespace ocl::Values 
{
	class NameValueBinding;
}

// namespace macro header include
#include "ocl/ocl.hpp"

// base class includes
#include "ocl/Values/StaticValue.hpp"




//*********************************
namespace ocl::Values 
{
	
	class OCL_API TupleValue: virtual public StaticValue
	{
		public:
 			TupleValue(const TupleValue &) {}

		protected:
			TupleValue(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~TupleValue() {}

			//*********************************
			// Operations
			//*********************************
			virtual bool equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue) = 0;
			virtual std::string toString() = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<Bag<ocl::Values::NameValueBinding>> getElements() const = 0;
			virtual std::shared_ptr<ocl::Types::TupleType> getModel() const = 0;
			virtual void setModel(std::shared_ptr<ocl::Types::TupleType>) = 0;

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
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			//*********************************
			// Reference Members
			//*********************************
			mutable std::shared_ptr<Bag<ocl::Values::NameValueBinding>> m_elements;
			std::shared_ptr<ocl::Types::TupleType> m_model;
	};
}
#endif /* end of include guard: OCL_VALUES_TUPLEVALUE_HPP */
