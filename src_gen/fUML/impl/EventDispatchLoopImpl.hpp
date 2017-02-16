//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_EVENTDISPATCHLOOPEVENTDISPATCHLOOPIMPL_HPP
#define FUML_EVENTDISPATCHLOOPEVENTDISPATCHLOOPIMPL_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

//*********************************
// generated Includes

//Model includes
#include "../EventDispatchLoop.hpp"


#include "impl/EObjectImpl.hpp"


//*********************************
namespace fUML 
{
	class EventDispatchLoopImpl :virtual public ecore::EObjectImpl,
virtual public EventDispatchLoop
	{
		public: 
			EventDispatchLoopImpl(const EventDispatchLoopImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			EventDispatchLoopImpl& operator=(EventDispatchLoopImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			EventDispatchLoopImpl();

		public:
			//destructor
			virtual ~EventDispatchLoopImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
							
			
			//*********************************
			// Union Getter
			//*********************************
			 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
			
			virtual boost::any eGet(int featureID, bool resolve, bool coreType) const ;
			
		protected:
			virtual ecore::EClass* eStaticClass() const;
	};
}
#endif /* end of include guard: FUML_EVENTDISPATCHLOOPEVENTDISPATCHLOOPIMPL_HPP */

