//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_STRUCTUREDCLASSIFIERS_CS_DISPATCHOPERATIONOFINTERFACESTRATEGY_HPP
#define PSCS_SEMANTICS_STRUCTUREDCLASSIFIERS_CS_DISPATCHOPERATIONOFINTERFACESTRATEGY_HPP


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

namespace PSCS
{
	class PSCSFactory;
}

//Forward Declaration for used types 
namespace uml 
{
	class Operation;
}

// namespace macro header include
#include "PSCS/PSCS.hpp"

// base class includes
#include "fUML/Semantics/StructuredClassifiers/RedefinitionBasedDispatchStrategy.hpp"




//*********************************
namespace PSCS::Semantics::StructuredClassifiers 
{
	
	class PSCS_API CS_DispatchOperationOfInterfaceStrategy: virtual public fUML::Semantics::StructuredClassifiers::RedefinitionBasedDispatchStrategy
	{
		public:
 			CS_DispatchOperationOfInterfaceStrategy(const CS_DispatchOperationOfInterfaceStrategy &) {}

		protected:
			CS_DispatchOperationOfInterfaceStrategy(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~CS_DispatchOperationOfInterfaceStrategy() {}

			//*********************************
			// Operations
			//*********************************
			virtual bool operationsMatch(std::shared_ptr<uml::Operation> ownedOperation,std::shared_ptr<uml::Operation> baseOperation) = 0;

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
#endif /* end of include guard: PSCS_SEMANTICS_STRUCTUREDCLASSIFIERS_CS_DISPATCHOPERATIONOFINTERFACESTRATEGY_HPP */
