//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_JOINNODEACTIVATIONJOINNODEACTIVATIONIMPL_HPP
#define FUML_JOINNODEACTIVATIONJOINNODEACTIVATIONIMPL_HPP

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
#include "../JoinNodeActivation.hpp"

#include "impl/ControlNodeActivationImpl.hpp"

#include "SubsetUnion.hpp"



//*********************************
namespace fUML 
{
	class JoinNodeActivationImpl :virtual public ControlNodeActivationImpl, virtual public JoinNodeActivation 
	{
		public: 
			JoinNodeActivationImpl(const JoinNodeActivationImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			JoinNodeActivationImpl& operator=(JoinNodeActivationImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			JoinNodeActivationImpl();

		public:
			//destructor
			virtual ~JoinNodeActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual bool isReady()  ;
			
			
			
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
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
	};
}
#endif /* end of include guard: FUML_JOINNODEACTIVATIONJOINNODEACTIVATIONIMPL_HPP */

