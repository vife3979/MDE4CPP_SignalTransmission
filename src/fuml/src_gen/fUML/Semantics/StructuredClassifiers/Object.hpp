//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_OBJECT_HPP
#define FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_OBJECT_HPP


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
	class EventAccepter;
	class EventOccurrence;
	class Execution;
	class ObjectActivation;
	class ParameterValue;
}
namespace fUML::Semantics::Loci 
{
	class Locus;
}
namespace fUML::Semantics::SimpleClassifiers 
{
	class FeatureValue;
	class SignalInstance;
}
namespace uml 
{
	class Class;
	class Classifier;
	class Operation;
}

// base class includes
#include "fUML/Semantics/StructuredClassifiers/ExtensionalValue.hpp"

// enum includes



//*********************************
namespace fUML::Semantics::StructuredClassifiers 
{
	
	class Object: virtual public ExtensionalValue
	{
		public:
 			Object(const Object &) {}
			Object& operator=(Object const&) = delete;

		protected:
			Object(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Object() {}

			//*********************************
			// Operations
			//*********************************
			 
			virtual std::shared_ptr<fUML::Semantics::Values::Value> _copy() = 0; 
			virtual void _register(std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter> accepter) = 0; 
			virtual void destroy() = 0; 
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> dispatch(std::shared_ptr<uml::Operation> operation) = 0; 
			virtual std::shared_ptr<fUML::Semantics::Values::Value> new_() = 0; 
			virtual void send(std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> signalInstance) = 0; 
			virtual void send(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> eventOccurrence) = 0; 
			virtual void startBehavior(std::shared_ptr<uml::Class> classifier,std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> inputs) = 0; 
			virtual void unregister(std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter> accepter) = 0;
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> getObjectActivation() const = 0;
			
			virtual void setObjectActivation(std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation>) = 0;
			
			virtual std::shared_ptr<Bag<uml::Classifier>> getTypes() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			
			std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> m_objectActivation;
			mutable std::shared_ptr<Bag<uml::Classifier>> m_types;

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
#endif /* end of include guard: FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_OBJECT_HPP */
