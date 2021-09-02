//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_CLASSIFICATION_INSTANCEVALUEEVALUATION_HPP
#define FUML_SEMANTICS_CLASSIFICATION_INSTANCEVALUEEVALUATION_HPP


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

namespace fUML
{
	class fUMLFactory;
}

//Forward Declaration for used types 
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
#include "fUML/fUML.hpp"

// base class includes
#include "fUML/Semantics/Values/Evaluation.hpp"




//*********************************
namespace fUML::Semantics::Classification 
{
	
	class FUML_API InstanceValueEvaluation: virtual public fUML::Semantics::Values::Evaluation
	{
		public:
 			InstanceValueEvaluation(const InstanceValueEvaluation &) {}

		protected:
			InstanceValueEvaluation(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~InstanceValueEvaluation() {}

			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<fUML::Semantics::Values::Value> evaluate() = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************

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
	};
}
#endif /* end of include guard: FUML_SEMANTICS_CLASSIFICATION_INSTANCEVALUEEVALUATION_HPP */
