//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_CREATEOBJECTACTIONACTIVATIONCREATEOBJECTACTIONACTIVATIONIMPL_HPP
#define FUML_CREATEOBJECTACTIONACTIVATIONCREATEOBJECTACTIONACTIVATIONIMPL_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

//*********************************
// generated Includes

//Model includes
#include "../CreateObjectActionActivation.hpp"

#include "impl/ActionActivationImpl.hpp"


//*********************************
namespace fUML 
{
	class CreateObjectActionActivationImpl :virtual public ActionActivationImpl, virtual public CreateObjectActionActivation
	{
		public: 
			CreateObjectActionActivationImpl(const CreateObjectActionActivationImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			CreateObjectActionActivationImpl& operator=(CreateObjectActionActivationImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			CreateObjectActionActivationImpl();

		public:
			//destructor
			virtual ~CreateObjectActionActivationImpl();
			
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
#endif /* end of include guard: FUML_CREATEOBJECTACTIONACTIVATIONCREATEOBJECTACTIONACTIVATIONIMPL_HPP */

