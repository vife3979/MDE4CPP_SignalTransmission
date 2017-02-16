//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_RECLASSIFYOBJECTACTIONACTIVATIONRECLASSIFYOBJECTACTIONACTIVATIONIMPL_HPP
#define FUML_RECLASSIFYOBJECTACTIONACTIVATIONRECLASSIFYOBJECTACTIONACTIVATIONIMPL_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

//*********************************
// generated Includes

//Model includes
#include "../ReclassifyObjectActionActivation.hpp"

#include "impl/ActionActivationImpl.hpp"


//*********************************
namespace fUML 
{
	class ReclassifyObjectActionActivationImpl :virtual public ActionActivationImpl, virtual public ReclassifyObjectActionActivation
	{
		public: 
			ReclassifyObjectActionActivationImpl(const ReclassifyObjectActionActivationImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			ReclassifyObjectActionActivationImpl& operator=(ReclassifyObjectActionActivationImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			ReclassifyObjectActionActivationImpl();

		public:
			//destructor
			virtual ~ReclassifyObjectActionActivationImpl();
			
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
#endif /* end of include guard: FUML_RECLASSIFYOBJECTACTIONACTIVATIONRECLASSIFYOBJECTACTIONACTIVATIONIMPL_HPP */

