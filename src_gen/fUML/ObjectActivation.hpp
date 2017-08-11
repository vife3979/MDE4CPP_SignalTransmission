//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_OBJECTACTIVATION_HPP
#define FUML_OBJECTACTIVATION_HPP

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
namespace uml 
{
	class Class;
}

namespace fUML 
{
	class ClassifierBehaviorExecution;
}

namespace fUML 
{
	class EventAccepter;
}

namespace fUML 
{
	class Object;
}

namespace fUML 
{
	class ParameterValue;
}

namespace fUML 
{
	class SignalInstance;
}

// base class includes

// enum includes

#include "EObject.hpp"

//*********************************
namespace fUML 
{
	/*!
	 */
	class ObjectActivation : virtual public ecore::EObject 
	{
		public:
 			ObjectActivation(const ObjectActivation &) {}
			ObjectActivation& operator=(ObjectActivation const&) = delete;
	
		protected:
			ObjectActivation(){}

		public:
			virtual ecore::EObject* copy() const = 0;

			//destructor
			virtual ~ObjectActivation() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual void startBehavior(std::shared_ptr<uml::Class>  classifier,std::shared_ptr<Bag<fUML::ParameterValue> >  inputs)  = 0;
			
			/*!
			 */ 
			virtual void stop()  = 0;
			
			/*!
			 */ 
			virtual void _register(std::shared_ptr<fUML::EventAccepter>  accepter)  = 0;
			
			/*!
			 */ 
			virtual void unregister(std::shared_ptr<fUML::EventAccepter>  accepter)  = 0;
			
			/*!
			 */ 
			virtual void send(std::shared_ptr<fUML::SignalInstance>  signalInstance)  = 0;
			
			/*!
			 */ 
			virtual void dispatchNextEvent()  = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<fUML::SignalInstance> retrieveNextEvent()  = 0;
			
			/*!
			 */ 
			virtual void _startObjectBehavior()  = 0;
			
			/*!
			 */ 
			virtual void _send(boost::any signal)  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr< Bag<fUML::EventAccepter> > getWaitingEventAccepters() const = 0;
			
			/*!
			 */
			virtual std::shared_ptr< Bag<fUML::SignalInstance> > getEventPool() const = 0;
			
			/*!
			 */
			virtual std::shared_ptr<fUML::Object > getObject() const = 0;
			
			/*!
			 */
			virtual void setObject(std::shared_ptr<fUML::Object> _object_object) = 0;
			/*!
			 */
			virtual std::shared_ptr< Bag<fUML::ClassifierBehaviorExecution> > getClassifierBehaviorExecutions() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 */
			std::shared_ptr< Bag<fUML::EventAccepter> > m_waitingEventAccepters;
			/*!
			 */
			std::shared_ptr< Bag<fUML::SignalInstance> > m_eventPool;
			/*!
			 */
			std::shared_ptr<fUML::Object > m_object;
			/*!
			 */
			std::shared_ptr< Bag<fUML::ClassifierBehaviorExecution> > m_classifierBehaviorExecutions;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			 
	};

}
#endif /* end of include guard: FUML_OBJECTACTIVATION_HPP */

