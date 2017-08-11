//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_DECISIONNODEACTIVATION_HPP
#define FUML_DECISIONNODEACTIVATION_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

#define ACTIVITY_DEBUG_ON

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

#include <string>
#include <map>
#include <vector>
#include "SubsetUnion.hpp"
#include "boost/shared_ptr.hpp"
#include "boost/any.hpp"

//*********************************
// generated Includes

//Forward Declaration for used types
namespace fUML 
{
	class ActivityEdgeInstance;
}

namespace uml 
{
	class ActivityNode;
}

namespace fUML 
{
	class ActivityNodeActivationGroup;
}

namespace fUML 
{
	class ControlNodeActivation;
}

namespace fUML 
{
	class Execution;
}

namespace fUML 
{
	class Token;
}

namespace fUML 
{
	class Value;
}

namespace uml 
{
	class ValueSpecification;
}

// base class includes
#include "ControlNodeActivation.hpp"

// enum includes


//*********************************
namespace fUML 
{
	/*!
	 */
	class DecisionNodeActivation:virtual public ControlNodeActivation	{
		public:
 			DecisionNodeActivation(const DecisionNodeActivation &) {}
			DecisionNodeActivation& operator=(DecisionNodeActivation const&) = delete;
	
		protected:
			DecisionNodeActivation(){}

		public:
			virtual ecore::EObject* copy() const = 0;

			//destructor
			virtual ~DecisionNodeActivation() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual std::shared_ptr<Bag<fUML::Value> > getDecisionValues(std::shared_ptr<Bag<fUML::Token> >  incomingTokens)  = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Value> executeDecisionInputBehavior(std::shared_ptr<fUML::Value>  inputValue,std::shared_ptr<fUML::Value>  decisionInputValue)  = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Value> getDecisionInputFlowValue()  = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<fUML::ActivityEdgeInstance> getDecisionInputFlowInstance()  = 0;
			
			/*!
			 */ 
			virtual bool test(std::shared_ptr<uml::ValueSpecification>  gaurd,std::shared_ptr<fUML::Value>  value)  = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<Bag<fUML::Token> > removeJoinedControlTokens(std::shared_ptr<Bag<fUML::Token> >  incomingTokens)  = 0;
			
			/*!
			 */ 
			virtual bool hasObjectFlowInput()  = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<Bag<fUML::Token> > takeOfferedTokens()  = 0;
			
			/*!
			 */ 
			virtual void fire(std::shared_ptr<Bag<fUML::Token> >  incomingTokens)  = 0;
			
			/*!
			 */ 
			virtual void terminate()  = 0;
			
			/*!
			 */ 
			virtual bool isReady()  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<fUML::Execution > getDecisionInputExecution() const = 0;
			
			/*!
			 */
			virtual void setDecisionInputExecution(std::shared_ptr<fUML::Execution> _decisionInputExecution_decisionInputExecution) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 */
			std::shared_ptr<fUML::Execution > m_decisionInputExecution;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			 
	};

}
#endif /* end of include guard: FUML_DECISIONNODEACTIVATION_HPP */

