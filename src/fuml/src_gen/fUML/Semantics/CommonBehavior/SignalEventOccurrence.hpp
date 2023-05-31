//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_COMMONBEHAVIOR_SIGNALEVENTOCCURRENCE_HPP
#define FUML_SEMANTICS_COMMONBEHAVIOR_SIGNALEVENTOCCURRENCE_HPP


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
namespace fUML::Semantics::CommonBehavior 
{
	class ParameterValue;
}
namespace fUML::Semantics::SimpleClassifiers 
{
	class SignalInstance;
}
namespace fUML::Semantics::StructuredClassifiers 
{
	class Reference;
}
namespace uml 
{
	class Event;
	class Trigger;
}

// namespace macro header include
#include "fUML/fUML.hpp"

// base class includes
#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"




//*********************************
namespace fUML::Semantics::CommonBehavior 
{
	
	class FUML_API SignalEventOccurrence: virtual public EventOccurrence
	{
		public:
 			SignalEventOccurrence(const SignalEventOccurrence &) {}

		protected:
			SignalEventOccurrence(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~SignalEventOccurrence() {}

			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> > getParameterValues(std::shared_ptr<uml::Event> event) = 0;
			virtual bool match(std::shared_ptr<uml::Trigger> trigger) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> getSignalInstance() const = 0;
			virtual void setSignalInstance(std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance>) = 0;

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
			std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> m_signalInstance;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_COMMONBEHAVIOR_SIGNALEVENTOCCURRENCE_HPP */
