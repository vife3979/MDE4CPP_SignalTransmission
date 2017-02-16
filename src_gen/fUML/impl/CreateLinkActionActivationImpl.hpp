//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_CREATELINKACTIONACTIVATIONCREATELINKACTIONACTIVATIONIMPL_HPP
#define FUML_CREATELINKACTIONACTIVATIONCREATELINKACTIONACTIVATIONIMPL_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

//*********************************
// generated Includes

//Model includes
#include "../CreateLinkActionActivation.hpp"

#include "impl/WriteLinkActionActivationImpl.hpp"


//*********************************
namespace fUML 
{
	class CreateLinkActionActivationImpl :virtual public WriteLinkActionActivationImpl, virtual public CreateLinkActionActivation
	{
		public: 
			CreateLinkActionActivationImpl(const CreateLinkActionActivationImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			CreateLinkActionActivationImpl& operator=(CreateLinkActionActivationImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			CreateLinkActionActivationImpl();

		public:
			//destructor
			virtual ~CreateLinkActionActivationImpl();
			
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
#endif /* end of include guard: FUML_CREATELINKACTIONACTIVATIONCREATELINKACTIONACTIVATIONIMPL_HPP */

