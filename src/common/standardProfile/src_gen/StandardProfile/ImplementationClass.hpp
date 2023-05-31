//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_IMPLEMENTATIONCLASS__HPP
#define STANDARDPROFILE_IMPLEMENTATIONCLASS__HPP





//Forward Declaration for used types
namespace uml 
{
	class Class;
}

// base class includes 
#include "uml/Stereotype.hpp"





// include object activation
#include "fUML/Semantics/CommonBehavior/ObjectActivation.hpp"

namespace StandardProfile
{
	class ImplementationClass : virtual public uml::Stereotype 
	{
		protected:
			ImplementationClass(){}

		public:
			//destructor
			virtual ~ImplementationClass() {}

			//*********************************
			// Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Class> getBase_Class() const  = 0;
			virtual void setBase_Class(std::weak_ptr<uml::Class> _base_Class) = 0;
			
			
			
			//*********************************
			// Operations
			//*********************************
			

			//*********************************
			// ObjectActivation Forwarder SetGet
			//*********************************
			// Getter for Active Class
			virtual bool GetIsActive() const = 0;
			
		protected:
			//*********************************
			// Members
			//*********************************
			std::weak_ptr<uml::Class> m_base_Class;
			
			

			

		public:
			//*********************************
			// Union Getter
			//*********************************
			
	};
}
#endif /* end of include guard: STANDARDPROFILE_IMPLEMENTATIONCLASS__HPP */
