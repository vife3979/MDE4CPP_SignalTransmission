//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef FOUNDATIONALMODELLIBRARY_PLUGIN_HPP
#define FOUNDATIONALMODELLIBRARY_PLUGIN_HPP

#include "pluginFramework/UMLExecutionModelPlugin.hpp"

namespace FoundationalModelLibrary
{
	class FoundationalModelLibraryExecPlugin : virtual public UMLExecutionModelPlugin
	{
		public:
			static std::shared_ptr<MDE4CPPPlugin> eInstance();
			
		protected:
			FoundationalModelLibraryExecPlugin(){};
			virtual ~FoundationalModelLibraryExecPlugin(){};	
	};
}
#endif /* end of include guard: FOUNDATIONALMODELLIBRARY_EXECPLUGIN_HPP */
