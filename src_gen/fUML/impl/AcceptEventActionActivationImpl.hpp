//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_ACCEPTEVENTACTIONACTIVATIONACCEPTEVENTACTIONACTIVATIONIMPL_HPP
#define FUML_ACCEPTEVENTACTIONACTIVATIONACCEPTEVENTACTIONACTIVATIONIMPL_HPP

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

//*********************************
// generated Includes

//Model includes
#include "../AcceptEventActionActivation.hpp"

#include "impl/ActionActivationImpl.hpp"

#include "SubsetUnion.hpp"



//*********************************
namespace fUML 
{
	class AcceptEventActionActivationImpl :virtual public ActionActivationImpl, virtual public AcceptEventActionActivation 
	{
		public: 
			AcceptEventActionActivationImpl(const AcceptEventActionActivationImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			AcceptEventActionActivationImpl& operator=(AcceptEventActionActivationImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			AcceptEventActionActivationImpl();

		public:
			//destructor
			virtual ~AcceptEventActionActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual void accept(std::shared_ptr<fUML::SignalInstance>  signalInstance)  ;
			
			/*!
			 */ 
			virtual bool match(std::shared_ptr<fUML::SignalInstance>  signalInstance)  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 */ 
			virtual bool isWaiting() const ;
			
			/*!
			 */ 
			virtual void setWaiting (bool _waiting); 
			
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<fUML::AcceptEventActionEventAccepter > getEventAccepter() const ;
			
			/*!
			 */
			virtual void setEventAccepter(std::shared_ptr<fUML::AcceptEventActionEventAccepter> _eventAccepter_eventAccepter) ;
							
			
			//*********************************
			// Union Getter
			//*********************************
			 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
			
			virtual boost::any eGet(int featureID, bool resolve, bool coreType) const ;
			
		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
	};
}
#endif /* end of include guard: FUML_ACCEPTEVENTACTIONACTIVATIONACCEPTEVENTACTIONACTIVATIONIMPL_HPP */

