//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EVALUATIONS_COLLECTIONITEMEVAL_HPP
#define OCL_EVALUATIONS_COLLECTIONITEMEVAL_HPP


#include <memory>
#include <string>
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

namespace ocl
{
	class oclFactory;
}

//Forward Declaration for used types 
namespace ocl::Evaluations 
{
	class OclExpEval;
}
namespace fUML::Semantics::Loci 
{
	class Locus;
}
namespace fUML::Semantics::Values 
{
	class Value;
}
namespace uml 
{
	class ValueSpecification;
}

// namespace macro header include
#include "ocl/ocl.hpp"

// base class includes
#include "ocl/Evaluations/CollectionLiteralPartEval.hpp"




//*********************************
namespace ocl::Evaluations 
{
	
	class OCL_API CollectionItemEval: virtual public CollectionLiteralPartEval
	{
		public:
 			CollectionItemEval(const CollectionItemEval &) {}

		protected:
			CollectionItemEval(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~CollectionItemEval() {}

			//*********************************
			// Operations
			//*********************************

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<ocl::Evaluations::OclExpEval> getItem() const = 0;
			virtual void setItem(std::shared_ptr<ocl::Evaluations::OclExpEval>) = 0;

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
			std::shared_ptr<ocl::Evaluations::OclExpEval> m_item;
	};
}
#endif /* end of include guard: OCL_EVALUATIONS_COLLECTIONITEMEVAL_HPP */
