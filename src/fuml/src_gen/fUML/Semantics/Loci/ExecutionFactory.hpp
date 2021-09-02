//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_LOCI_EXECUTIONFACTORY_HPP
#define FUML_SEMANTICS_LOCI_EXECUTIONFACTORY_HPP


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

namespace fUML
{
	class fUMLFactory;
}

//Forward Declaration for used types 
namespace fUML::Semantics::CommonBehavior 
{
	class Execution;
	class OpaqueBehaviorExecution;
}
namespace fUML::Semantics::Loci 
{
	class Locus;
	class SemanticStrategy;
	class SemanticVisitor;
}
namespace fUML::Semantics::StructuredClassifiers 
{
	class Object;
}
namespace fUML::Semantics::Values 
{
	class Evaluation;
}
namespace uml 
{
	class Behavior;
	class Element;
	class OpaqueBehavior;
	class PrimitiveType;
	class ValueSpecification;
}

// namespace macro header include
#include "fUML/fUML.hpp"



#include "ecore/EModelElement.hpp"


//*********************************
namespace fUML::Semantics::Loci 
{
	
	class FUML_API ExecutionFactory : virtual public ecore::EModelElement
	{
		public:
 			ExecutionFactory(const ExecutionFactory &) {}

		protected:
			ExecutionFactory(){}
			//Additional constructors for the containments back reference
			ExecutionFactory(std::weak_ptr<fUML::Semantics::Loci::Locus> par_locus);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ExecutionFactory() {}

			//*********************************
			// Operations
			//*********************************
			virtual void addBuiltInType(std::shared_ptr<uml::PrimitiveType> type) = 0;
			virtual void addPrimitiveBehaviorPrototype(std::shared_ptr<fUML::Semantics::CommonBehavior::OpaqueBehaviorExecution> execution) = 0;
			virtual void assignStrategy(std::shared_ptr<fUML::Semantics::Loci::SemanticStrategy> strategy) = 0;
			virtual std::shared_ptr<fUML::Semantics::Values::Evaluation> createEvaluation(std::shared_ptr<uml::ValueSpecification> specification) = 0;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> createExecution(std::shared_ptr<uml::Behavior> behavior,std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> context) = 0;
			virtual std::shared_ptr<uml::PrimitiveType> getBuiltInType(std::string name) = 0;
			virtual std::shared_ptr<fUML::Semantics::Loci::SemanticStrategy> getStrategy(std::string name) = 0;
			virtual int getStrategyIndex(std::string name) = 0;
			
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::OpaqueBehaviorExecution> instantiateOpaqueBehaviorExecution(std::shared_ptr<uml::Behavior> behavior) = 0;
			virtual std::shared_ptr<fUML::Semantics::Loci::SemanticVisitor> instantiateVisitor(std::shared_ptr<uml::Element> element) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<Bag<uml::PrimitiveType>> getBuiltInTypes() const = 0;
			virtual std::weak_ptr<fUML::Semantics::Loci::Locus> getLocus() const = 0;
			virtual void setLocus(std::weak_ptr<fUML::Semantics::Loci::Locus>) = 0;
			virtual std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::OpaqueBehaviorExecution>> getPrimitiveBehaviorPrototypes() const = 0;
			virtual std::shared_ptr<Bag<fUML::Semantics::Loci::SemanticStrategy>> getStrategies() const = 0;

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
			mutable std::shared_ptr<Bag<uml::PrimitiveType>> m_builtInTypes;
			std::weak_ptr<fUML::Semantics::Loci::Locus> m_locus;
			mutable std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::OpaqueBehaviorExecution>> m_primitiveBehaviorPrototypes;
			mutable std::shared_ptr<Bag<fUML::Semantics::Loci::SemanticStrategy>> m_strategies;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_LOCI_EXECUTIONFACTORY_HPP */
