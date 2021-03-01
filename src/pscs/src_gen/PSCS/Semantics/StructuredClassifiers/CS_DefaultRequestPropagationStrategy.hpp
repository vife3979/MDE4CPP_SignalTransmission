//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_STRUCTUREDCLASSIFIERS_CS_DEFAULTREQUESTPROPAGATIONSTRATEGY_HPP
#define PSCS_SEMANTICS_STRUCTUREDCLASSIFIERS_CS_DEFAULTREQUESTPROPAGATIONSTRATEGY_HPP


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

namespace PSCS
{
	class PSCSFactory;
}

//Forward Declaration for used types 
namespace fUML::Semantics::Loci 
{
	class SemanticVisitor;
}
namespace fUML::Semantics::StructuredClassifiers 
{
	class Reference;
}

// base class includes
#include "PSCS/Semantics/StructuredClassifiers/CS_RequestPropagationStrategy.hpp"

// enum includes



//*********************************
namespace PSCS::Semantics::StructuredClassifiers 
{
	
	class CS_DefaultRequestPropagationStrategy: virtual public CS_RequestPropagationStrategy
	{
		public:
 			CS_DefaultRequestPropagationStrategy(const CS_DefaultRequestPropagationStrategy &) {}
		protected:
			CS_DefaultRequestPropagationStrategy(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~CS_DefaultRequestPropagationStrategy() {}

			//*********************************
			// Operations
			//*********************************
			 
			virtual std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference> > select(std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference>> potentialTargets,std::shared_ptr<fUML::Semantics::Loci::SemanticVisitor> context) = 0;
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: PSCS_SEMANTICS_STRUCTUREDCLASSIFIERS_CS_DEFAULTREQUESTPROPAGATIONSTRATEGY_HPP */
