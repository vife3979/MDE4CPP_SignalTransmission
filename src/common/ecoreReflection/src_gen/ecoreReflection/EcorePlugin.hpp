//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef ECORE_PLUGIN_HPP
#define ECORE_PLUGIN_HPP

#include "pluginFramework/UMLModelPlugin.hpp"

namespace Ecore
{
	class EcorePlugin : virtual public UMLModelPlugin
	{
		public:
			static std::shared_ptr<MDE4CPPPlugin> eInstance();
	
			virtual std::string eclipseURI() = 0;
			virtual std::string eNAME() = 0;
			virtual std::string eNS_URI() = 0;
			virtual std::string eNS_PREFIX() = 0;
	
			virtual std::shared_ptr<ecore::EObject> create(const std::string& name) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(const std::string& name, std::shared_ptr<ecore::EObject> container, const unsigned int referenceID = -1) const = 0;
			virtual std::shared_ptr<uml::Factory> getFactory() = 0;
			virtual std::shared_ptr<uml::Package> getPackage() = 0;
	
		protected:
			EcorePlugin(){};
			virtual ~EcorePlugin(){};
	};
}
#endif /* end of include guard: ECORE_PLUGIN_HPP */
