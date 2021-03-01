//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_ACTIONACTIVATION_HPP
#define FUML_SEMANTICS_ACTIONS_ACTIONACTIVATION_HPP


#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 
template<class T, class ... U> class Subset;
template<class T> class Union;

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
namespace fUML::Semantics::Actions 
{
	class InputPinActivation;
	class OutputPinActivation;
	class PinActivation;
}
namespace fUML::Semantics::Activities 
{
	class ActivityEdgeInstance;
	class ActivityNodeActivationGroup;
	class Token;
}
namespace fUML::Semantics::SimpleClassifiers 
{
	class BooleanValue;
}
namespace fUML::Semantics::StructuredClassifiers 
{
	class Link;
}
namespace fUML::Semantics::Values 
{
	class Value;
}
namespace uml 
{
	class Action;
	class ActivityNode;
	class InputPin;
	class OutputPin;
	class Pin;
}

// base class includes
#include "fUML/Semantics/Activities/ActivityNodeActivation.hpp"

// enum includes



//*********************************
namespace fUML::Semantics::Actions 
{
	
	class ActionActivation: virtual public fUML::Semantics::Activities::ActivityNodeActivation
	{
		public:
 			ActionActivation(const ActionActivation &) {}
		protected:
			ActionActivation(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ActionActivation() {}

			//*********************************
			// Operations
			//*********************************
			 
			virtual void addOutgoingEdge(std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> edge) = 0; 
			virtual void addPinActivation(std::shared_ptr<fUML::Semantics::Actions::PinActivation> pinActivation) = 0; 
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > completeAction() = 0; 
			virtual void createNodeActivations() = 0; 
			virtual void doAction() = 0; 
			virtual void fire(std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incomingTokens) = 0; 
			virtual std::shared_ptr<Bag<fUML::Semantics::Values::Value> > getTokens(std::shared_ptr<uml::InputPin> pin) = 0; 
			virtual bool isFirng() = 0; 
			virtual bool isReady() = 0; 
			virtual bool isSourceFor(std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> edgeInstance) = 0; 
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> makeBooleanValue(bool value) = 0; 
			virtual void putToken(std::shared_ptr<uml::OutputPin> pin,std::shared_ptr<fUML::Semantics::Values::Value> value) = 0; 
			virtual void putTokens(std::shared_ptr<uml::OutputPin> pin,std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values) = 0; 
			virtual std::shared_ptr<fUML::Semantics::Actions::PinActivation> retrievePinActivation(std::shared_ptr<uml::Pin> pin) = 0; 
			virtual void run() = 0; 
			virtual void sendOffers() = 0; 
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > takeOfferedTokens() = 0; 
			virtual std::shared_ptr<Bag<fUML::Semantics::Values::Value> > takeTokens(std::shared_ptr<uml::InputPin> pin) = 0; 
			virtual void terminate() = 0; 
			virtual bool valueParticipatesInLink(std::shared_ptr<fUML::Semantics::Values::Value> value,std::shared_ptr<fUML::Semantics::StructuredClassifiers::Link> link) = 0;
			//*********************************
			// Attributes Getter Setter
			//*********************************
			 
			virtual bool isFiring() const = 0;
			 
			virtual void setFiring (bool _firing)= 0;
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<uml::Action> getAction() const = 0;
			
			virtual void setAction(std::shared_ptr<uml::Action>) = 0;
			/*Additional Setter for 'ActivityNodeActivation::node' redefined by reference 'action'*/
			
			virtual void setNode(std::shared_ptr<uml::ActivityNode>) = 0;
			virtual std::shared_ptr<Subset<fUML::Semantics::Actions::InputPinActivation, fUML::Semantics::Actions::PinActivation>> getInputPinActivation() const = 0;
			
			
			virtual std::shared_ptr<Subset<fUML::Semantics::Actions::OutputPinActivation, fUML::Semantics::Actions::PinActivation>> getOutputPinActivation() const = 0;
			
			
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			 
			bool m_firing = false;
			
			
			//*********************************
			// Reference Members
			//*********************************
			
			std::shared_ptr<uml::Action> m_action;
			mutable std::shared_ptr<Subset<fUML::Semantics::Actions::InputPinActivation, fUML::Semantics::Actions::PinActivation>> m_inputPinActivation;
			mutable std::shared_ptr<Subset<fUML::Semantics::Actions::OutputPinActivation, fUML::Semantics::Actions::PinActivation>> m_outputPinActivation;
			mutable std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> m_pinActivation;

		public:
			//*********************************
			// Union Getter
			//*********************************
			
			virtual std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> getPinActivation() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_ACTIONACTIVATION_HPP */
