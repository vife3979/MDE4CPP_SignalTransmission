//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef UML_PLUGIN_HPP
#define UML_PLUGIN_HPP

#include "pluginFramework/UMLExecutionModelPlugin.hpp"

namespace uml
{
	class OpaqueBehavior;
}

namespace PSCS::Semantics::Loci
{
	class CS_Executor;
	class CS_ExecutionFactory;
}

namespace umlReflection
{
	class UmlReflectionLocus;
}


namespace UML
{
	class UMLExecPlugin : virtual public UMLExecutionModelPlugin
	{
		public:
			static std::shared_ptr<MDE4CPPPlugin> eInstance();
	
			virtual std::string eclipseURI() = 0;
			virtual std::string eNAME() = 0;
			virtual std::string eNS_URI() = 0;
			virtual std::string eNS_PREFIX() = 0;
	
			virtual std::shared_ptr<ecore::EObject> create(const std::string& name) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(const std::string& name, std::shared_ptr<ecore::EObject> container, const unsigned int referenceID = -1) const = 0;
			virtual Any executeActivity(std::shared_ptr<uml::Activity> activity, std::shared_ptr<std::vector<Any>> parameterList, std::shared_ptr<uml::Element> element) = 0;

		protected:
			UMLExecPlugin(){};
			virtual ~UMLExecPlugin(){};
	
		private:
			static std::shared_ptr<MDE4CPPPlugin> instance;

		protected:
			//Execution Environment
			
	};
}
#endif /* end of include guard: UML_EXECPLUGIN_HPP */
