//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef UML4CPPPROFILE_METAMODELPACKAGE_HPP
#define UML4CPPPROFILE_METAMODELPACKAGE_HPP
#include "uml/Profile.hpp"

namespace uml 
{
	class Extension;
	class ExtensionEnd;
	class Property;
	class Stereotype;
	class ConnectorEnd;
}


namespace UML4CPPProfile 
{
	/*!
	The Metamodel Package for the UML4CPPProfile metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	class UML4CPPProfilePackage : virtual public uml::Profile
	{
		//protected default construcotr
		protected:
			UML4CPPProfilePackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			//getter for the ownedMember
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_DoNotGenerate_UML4CPPProfile_DoNotGenerate() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_ExternalLibrary_UML4CPPProfile_ExternalLibrary() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_GetterName_UML4CPPProfile_GetterName() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_MainBehavior_UML4CPPProfile_MainBehavior() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_NonExecutable_UML4CPPProfile_NonExecutable() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_SetterName_UML4CPPProfile_SetterName() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Singleton_UML4CPPProfile_Singleton() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_UML4CPPPackage_UML4CPPProfile_UML4CPPPackage() = 0;  
			virtual std::shared_ptr<uml::Extension> get_UML4CPPProfile_Behavior_MainBehavior() = 0;  
			virtual std::shared_ptr<uml::Extension> get_UML4CPPProfile_Class_Singleton() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_UML4CPPProfile_DoNotGenerate() = 0;  
			virtual std::shared_ptr<uml::Property> get_UML4CPPProfile_DoNotGenerate_base_Element() = 0;  
			virtual std::shared_ptr<uml::Extension> get_UML4CPPProfile_Element_DoNotGenerate() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_UML4CPPProfile_ExternalLibrary() = 0;  
			virtual std::shared_ptr<uml::Property> get_UML4CPPProfile_ExternalLibrary_base_Package() = 0;  
			virtual std::shared_ptr<uml::Property> get_UML4CPPProfile_ExternalLibrary_includePath() = 0;  
			virtual std::shared_ptr<uml::Property> get_UML4CPPProfile_ExternalLibrary_libraryName() = 0;  
			virtual std::shared_ptr<uml::Property> get_UML4CPPProfile_ExternalLibrary_libraryPath() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_UML4CPPProfile_GetterName() = 0;  
			virtual std::shared_ptr<uml::Property> get_UML4CPPProfile_GetterName_base_Property() = 0;  
			virtual std::shared_ptr<uml::Property> get_UML4CPPProfile_GetterName_getterName() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_UML4CPPProfile_MainBehavior() = 0;  
			virtual std::shared_ptr<uml::Property> get_UML4CPPProfile_MainBehavior_base_Behavior() = 0;  
			virtual std::shared_ptr<uml::Extension> get_UML4CPPProfile_NamedElement_NonExecutable() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_UML4CPPProfile_NonExecutable() = 0;  
			virtual std::shared_ptr<uml::Property> get_UML4CPPProfile_NonExecutable_base_NamedElement() = 0;  
			virtual std::shared_ptr<uml::Extension> get_UML4CPPProfile_Package_ExternalLibrary() = 0;  
			virtual std::shared_ptr<uml::Extension> get_UML4CPPProfile_Package_UML4CPPPackage() = 0;  
			virtual std::shared_ptr<uml::Extension> get_UML4CPPProfile_Property_GetterName() = 0;  
			virtual std::shared_ptr<uml::Extension> get_UML4CPPProfile_Property_SetterName() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_UML4CPPProfile_SetterName() = 0;  
			virtual std::shared_ptr<uml::Property> get_UML4CPPProfile_SetterName_base_Property() = 0;  
			virtual std::shared_ptr<uml::Property> get_UML4CPPProfile_SetterName_setterName() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_UML4CPPProfile_Singleton() = 0;  
			virtual std::shared_ptr<uml::Property> get_UML4CPPProfile_Singleton_base_Class() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_UML4CPPProfile_UML4CPPPackage() = 0;  
			virtual std::shared_ptr<uml::Property> get_UML4CPPProfile_UML4CPPPackage_base_Package() = 0;  
			virtual std::shared_ptr<uml::Property> get_UML4CPPProfile_UML4CPPPackage_eclipseURI() = 0;  
			virtual std::shared_ptr<uml::Property> get_UML4CPPProfile_UML4CPPPackage_ignoreNamespace() = 0;  
			virtual std::shared_ptr<uml::Property> get_UML4CPPProfile_UML4CPPPackage_packageOnly() = 0;  
			
			

			//getter for subPackages

			//Singleton Getter
			public:
				static std::shared_ptr<UML4CPPProfilePackage> eInstance();

			//Static IDs
			//Stereotype UML4CPPProfile::DoNotGenerate
			static const unsigned long DONOTGENERATE_STEREOTYPE = 173581214;
			static const unsigned int DONOTGENERATE_STEREOTYPE_FEATURE_COUNT = 1;
			static const unsigned int DONOTGENERATE_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long DONOTGENERATE_PROPERTY_BASE_ELEMENT = 1158171776;
			
			//Stereotype UML4CPPProfile::ExternalLibrary
			static const unsigned long EXTERNALLIBRARY_STEREOTYPE = 744219230;
			static const unsigned int EXTERNALLIBRARY_STEREOTYPE_FEATURE_COUNT = 4;
			static const unsigned int EXTERNALLIBRARY_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long EXTERNALLIBRARY_PROPERTY_BASE_PACKAGE = 441090789;
			static const unsigned long EXTERNALLIBRARY_PROPERTY_INCLUDEPATH = 83544771;
			static const unsigned long EXTERNALLIBRARY_PROPERTY_LIBRARYNAME = 596096889;
			static const unsigned long EXTERNALLIBRARY_PROPERTY_LIBRARYPATH = 1321918160;
			
			//Stereotype UML4CPPProfile::GetterName
			static const unsigned long GETTERNAME_STEREOTYPE = 1711019851;
			static const unsigned int GETTERNAME_STEREOTYPE_FEATURE_COUNT = 2;
			static const unsigned int GETTERNAME_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long GETTERNAME_PROPERTY_BASE_PROPERTY = 14802423;
			static const unsigned long GETTERNAME_PROPERTY_GETTERNAME = 1932053206;
			
			//Stereotype UML4CPPProfile::MainBehavior
			static const unsigned long MAINBEHAVIOR_STEREOTYPE = 1527007467;
			static const unsigned int MAINBEHAVIOR_STEREOTYPE_FEATURE_COUNT = 1;
			static const unsigned int MAINBEHAVIOR_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long MAINBEHAVIOR_PROPERTY_BASE_BEHAVIOR = 1956712138;
			
			//Stereotype UML4CPPProfile::NonExecutable
			static const unsigned long NONEXECUTABLE_STEREOTYPE = 1641344257;
			static const unsigned int NONEXECUTABLE_STEREOTYPE_FEATURE_COUNT = 1;
			static const unsigned int NONEXECUTABLE_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long NONEXECUTABLE_PROPERTY_BASE_NAMEDELEMENT = 488558520;
			
			//Stereotype UML4CPPProfile::SetterName
			static const unsigned long SETTERNAME_STEREOTYPE = 103590585;
			static const unsigned int SETTERNAME_STEREOTYPE_FEATURE_COUNT = 2;
			static const unsigned int SETTERNAME_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long SETTERNAME_PROPERTY_BASE_PROPERTY = 554856804;
			static const unsigned long SETTERNAME_PROPERTY_SETTERNAME = 1550049626;
			
			//Stereotype UML4CPPProfile::Singleton
			static const unsigned long SINGLETON_STEREOTYPE = 1215028894;
			static const unsigned int SINGLETON_STEREOTYPE_FEATURE_COUNT = 1;
			static const unsigned int SINGLETON_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long SINGLETON_PROPERTY_BASE_CLASS = 2027377001;
			
			//Stereotype UML4CPPProfile::UML4CPPPackage
			static const unsigned long UML4CPPPACKAGE_STEREOTYPE = 1707580997;
			static const unsigned int UML4CPPPACKAGE_STEREOTYPE_FEATURE_COUNT = 4;
			static const unsigned int UML4CPPPACKAGE_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long UML4CPPPACKAGE_PROPERTY_BASE_PACKAGE = 364749133;
			static const unsigned long UML4CPPPACKAGE_PROPERTY_ECLIPSEURI = 1162675821;
			static const unsigned long UML4CPPPACKAGE_PROPERTY_IGNORENAMESPACE = 1716152545;
			static const unsigned long UML4CPPPACKAGE_PROPERTY_PACKAGEONLY = 262131715;
			
			
			
	};
}
#endif /* end of include guard: UML4CPPPROFILE_METAMODELPACKAGE_HPP */
