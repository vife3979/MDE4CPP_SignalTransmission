//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_EXECUTABLE__HPP
#define STANDARDPROFILE_EXECUTABLE__HPP





//Forward Declaration for used types
namespace uml 
{
	class Artifact;
}

// base class includes 
#include "StandardProfile/File.hpp"





// include object activation
#include "fUML/Semantics/CommonBehavior/ObjectActivation.hpp"

namespace StandardProfile
{
	class Executable:virtual public File	{
		protected:
			Executable(){}

		public:
			//destructor
			virtual ~Executable() {}

			//*********************************
			// Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Artifact> getBase_Artifact() const  = 0;
			virtual void setBase_Artifact(std::weak_ptr<uml::Artifact> _base_Artifact) = 0;
			
			
			
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
			std::weak_ptr<uml::Artifact> m_base_Artifact;
			
			

			

		public:
			//*********************************
			// Union Getter
			//*********************************
			
	};
}
#endif /* end of include guard: STANDARDPROFILE_EXECUTABLE__HPP */
