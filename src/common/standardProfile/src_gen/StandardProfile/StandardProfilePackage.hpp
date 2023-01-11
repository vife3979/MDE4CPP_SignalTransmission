//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_METAMODELPACKAGE_HPP
#define STANDARDPROFILE_METAMODELPACKAGE_HPP
#include "uml/Profile.hpp"

namespace uml 
{
	class Extension;
	class ExtensionEnd;
	class Property;
	class Stereotype;
	class ConnectorEnd;
}


namespace StandardProfile 
{
	/*!
	The Metamodel Package for the StandardProfile metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	class StandardProfilePackage : virtual public uml::Profile
	{
		//protected default construcotr
		protected:
			StandardProfilePackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			//getter for the ownedMember
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Auxiliary_StandardProfile_Auxiliary() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_BehavioralFeature_Create_StandardProfile_Create() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_BuildComponent_StandardProfile_BuildComponent() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Call_StandardProfile_Call() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Derive_StandardProfile_Derive() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Destroy_StandardProfile_Destroy() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Document_StandardProfile_Document() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Entity_StandardProfile_Entity() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Executable_StandardProfile_Executable() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_File_StandardProfile_File() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Focus_StandardProfile_Focus() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Framework_StandardProfile_Framework() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Implement_StandardProfile_Implement() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_ImplementationClass_StandardProfile_ImplementationClass() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Instantiate_StandardProfile_Instantiate() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Library_StandardProfile_Library() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Metaclass_StandardProfile_Metaclass() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Metamodel_StandardProfile_Metamodel() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_ModelLibrary_StandardProfile_ModelLibrary() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Process_StandardProfile_Process() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Realization_StandardProfile_Realization() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Refine_StandardProfile_Refine() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Responsibility_StandardProfile_Responsibility() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Script_StandardProfile_Script() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Send_StandardProfile_Send() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Service_StandardProfile_Service() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Source_StandardProfile_Source() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Specification_StandardProfile_Specification() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Subsystem_StandardProfile_Subsystem() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_SystemModel_StandardProfile_SystemModel() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Trace_StandardProfile_Trace() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Type_StandardProfile_Type() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Usage_Create_StandardProfile_Create() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Utility_StandardProfile_Utility() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Abstraction_Derive() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Abstraction_Refine() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Abstraction_Trace() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Artifact_Document() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Artifact_Executable() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Artifact_File() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Artifact_Library() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Artifact_Script() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Artifact_Source() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Auxiliary() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Auxiliary_base_Class() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_BehavioralFeature_Create() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_BehavioralFeature_Destroy() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_BuildComponent() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_BuildComponent_base_Component() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Call() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Call_base_Usage() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Class_Auxiliary() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Class_Focus() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Class_ImplementationClass() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Class_Metaclass() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Class_Type() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Class_Utility() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Classifier_Realization() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Classifier_Specification() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Component_BuildComponent() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Component_Entity() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Component_Implement() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Component_Process() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Component_Service() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Component_Subsystem() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Create() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Create_base_BehavioralFeature() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Create_base_Usage() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Derive() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Derive_base_Abstraction() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Destroy() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Destroy_base_BehavioralFeature() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Document() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Document_base_Artifact() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Entity() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Entity_base_Component() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Executable() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Executable_base_Artifact() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_File() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_File_base_Artifact() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Focus() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Focus_base_Class() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Framework() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Framework_base_Package() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Implement() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Implement_base_Component() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_ImplementationClass() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_ImplementationClass_base_Class() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Instantiate() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Instantiate_base_Usage() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Library() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Library_base_Artifact() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Metaclass() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Metaclass_base_Class() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Metamodel() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Metamodel_base_Model() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_ModelLibrary() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_ModelLibrary_base_Package() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Model_Metamodel() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Model_SystemModel() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Package_Framework() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Package_ModelLibrary() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Process() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Process_base_Component() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Realization() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Realization_base_Classifier() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Refine() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Refine_base_Abstraction() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Responsibility() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Responsibility_base_Usage() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Script() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Script_base_Artifact() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Send() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Send_base_Usage() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Service() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Service_base_Component() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Source() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Source_base_Artifact() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Specification() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Specification_base_Classifier() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Subsystem() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Subsystem_base_Component() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_SystemModel() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_SystemModel_base_Model() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Trace() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Trace_base_Abstraction() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Type() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Type_base_Class() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Usage_Call() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Usage_Create() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Usage_Instantiate() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Usage_Responsibility() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Usage_Send() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Utility() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Utility_base_Class() = 0;  
			
			

			//getter for subPackages

			//Singleton Instance and Getter
			
			private:
				static std::shared_ptr<StandardProfilePackage> instance;
			public:
				static std::shared_ptr<StandardProfilePackage> eInstance();

			//Static IDs
			//Stereotype StandardProfile::Auxiliary
			static const unsigned long AUXILIARY_STEREOTYPE = 1466047990;
			static const unsigned int AUXILIARY_STEREOTYPE_FEATURE_COUNT = 1;
			static const unsigned int AUXILIARY_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long AUXILIARY_ATTRIBUTE_BASE_CLASS = 1570824721;
			
			//Stereotype StandardProfile::BuildComponent
			static const unsigned long BUILDCOMPONENT_STEREOTYPE = 133779747;
			static const unsigned int BUILDCOMPONENT_STEREOTYPE_FEATURE_COUNT = 1;
			static const unsigned int BUILDCOMPONENT_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long BUILDCOMPONENT_ATTRIBUTE_BASE_COMPONENT = 1091275515;
			
			//Stereotype StandardProfile::Call
			static const unsigned long CALL_STEREOTYPE = 495006810;
			static const unsigned int CALL_STEREOTYPE_FEATURE_COUNT = 1;
			static const unsigned int CALL_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long CALL_ATTRIBUTE_BASE_USAGE = 803516267;
			
			//Stereotype StandardProfile::Create
			static const unsigned long CREATE_STEREOTYPE = 841207773;
			static const unsigned int CREATE_STEREOTYPE_FEATURE_COUNT = 2;
			static const unsigned int CREATE_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long CREATE_ATTRIBUTE_BASE_BEHAVIORALFEATURE = 2108279685;
			static const unsigned long CREATE_ATTRIBUTE_BASE_USAGE = 2008362745;
			
			//Stereotype StandardProfile::Derive
			static const unsigned long DERIVE_STEREOTYPE = 501351344;
			static const unsigned int DERIVE_STEREOTYPE_FEATURE_COUNT = 1;
			static const unsigned int DERIVE_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long DERIVE_ATTRIBUTE_BASE_ABSTRACTION = 893379002;
			
			//Stereotype StandardProfile::Destroy
			static const unsigned long DESTROY_STEREOTYPE = 308948604;
			static const unsigned int DESTROY_STEREOTYPE_FEATURE_COUNT = 1;
			static const unsigned int DESTROY_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long DESTROY_ATTRIBUTE_BASE_BEHAVIORALFEATURE = 891766883;
			
			//Stereotype StandardProfile::Document
			static const unsigned long DOCUMENT_STEREOTYPE = 301496007;
			static const unsigned int DOCUMENT_STEREOTYPE_FEATURE_COUNT = 2;
			static const unsigned int DOCUMENT_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long DOCUMENT_ATTRIBUTE_BASE_ARTIFACT = 1856461285;
			
			//Stereotype StandardProfile::Entity
			static const unsigned long ENTITY_STEREOTYPE = 2070209470;
			static const unsigned int ENTITY_STEREOTYPE_FEATURE_COUNT = 1;
			static const unsigned int ENTITY_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long ENTITY_ATTRIBUTE_BASE_COMPONENT = 1668028860;
			
			//Stereotype StandardProfile::Executable
			static const unsigned long EXECUTABLE_STEREOTYPE = 1083872305;
			static const unsigned int EXECUTABLE_STEREOTYPE_FEATURE_COUNT = 2;
			static const unsigned int EXECUTABLE_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long EXECUTABLE_ATTRIBUTE_BASE_ARTIFACT = 999600209;
			
			//Stereotype StandardProfile::File
			static const unsigned long FILE_STEREOTYPE = 242613410;
			static const unsigned int FILE_STEREOTYPE_FEATURE_COUNT = 1;
			static const unsigned int FILE_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long FILE_ATTRIBUTE_BASE_ARTIFACT = 220023674;
			
			//Stereotype StandardProfile::Focus
			static const unsigned long FOCUS_STEREOTYPE = 2011110723;
			static const unsigned int FOCUS_STEREOTYPE_FEATURE_COUNT = 1;
			static const unsigned int FOCUS_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long FOCUS_ATTRIBUTE_BASE_CLASS = 1705935987;
			
			//Stereotype StandardProfile::Framework
			static const unsigned long FRAMEWORK_STEREOTYPE = 758834892;
			static const unsigned int FRAMEWORK_STEREOTYPE_FEATURE_COUNT = 1;
			static const unsigned int FRAMEWORK_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long FRAMEWORK_ATTRIBUTE_BASE_PACKAGE = 1921700257;
			
			//Stereotype StandardProfile::Implement
			static const unsigned long IMPLEMENT_STEREOTYPE = 1810753173;
			static const unsigned int IMPLEMENT_STEREOTYPE_FEATURE_COUNT = 1;
			static const unsigned int IMPLEMENT_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long IMPLEMENT_ATTRIBUTE_BASE_COMPONENT = 359640210;
			
			//Stereotype StandardProfile::ImplementationClass
			static const unsigned long IMPLEMENTATIONCLASS_STEREOTYPE = 1555601512;
			static const unsigned int IMPLEMENTATIONCLASS_STEREOTYPE_FEATURE_COUNT = 1;
			static const unsigned int IMPLEMENTATIONCLASS_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long IMPLEMENTATIONCLASS_ATTRIBUTE_BASE_CLASS = 1590218076;
			
			//Stereotype StandardProfile::Instantiate
			static const unsigned long INSTANTIATE_STEREOTYPE = 1393463882;
			static const unsigned int INSTANTIATE_STEREOTYPE_FEATURE_COUNT = 1;
			static const unsigned int INSTANTIATE_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long INSTANTIATE_ATTRIBUTE_BASE_USAGE = 1382406183;
			
			//Stereotype StandardProfile::Library
			static const unsigned long LIBRARY_STEREOTYPE = 1931384455;
			static const unsigned int LIBRARY_STEREOTYPE_FEATURE_COUNT = 2;
			static const unsigned int LIBRARY_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long LIBRARY_ATTRIBUTE_BASE_ARTIFACT = 1798649185;
			
			//Stereotype StandardProfile::Metaclass
			static const unsigned long METACLASS_STEREOTYPE = 1110600536;
			static const unsigned int METACLASS_STEREOTYPE_FEATURE_COUNT = 1;
			static const unsigned int METACLASS_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long METACLASS_ATTRIBUTE_BASE_CLASS = 1215377267;
			
			//Stereotype StandardProfile::Metamodel
			static const unsigned long METAMODEL_STEREOTYPE = 269527075;
			static const unsigned int METAMODEL_STEREOTYPE_FEATURE_COUNT = 1;
			static const unsigned int METAMODEL_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long METAMODEL_ATTRIBUTE_BASE_MODEL = 377161386;
			
			//Stereotype StandardProfile::ModelLibrary
			static const unsigned long MODELLIBRARY_STEREOTYPE = 690477192;
			static const unsigned int MODELLIBRARY_STEREOTYPE_FEATURE_COUNT = 1;
			static const unsigned int MODELLIBRARY_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long MODELLIBRARY_ATTRIBUTE_BASE_PACKAGE = 908252098;
			
			//Stereotype StandardProfile::Process
			static const unsigned long PROCESS_STEREOTYPE = 985526206;
			static const unsigned int PROCESS_STEREOTYPE_FEATURE_COUNT = 1;
			static const unsigned int PROCESS_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long PROCESS_ATTRIBUTE_BASE_COMPONENT = 1144790346;
			
			//Stereotype StandardProfile::Realization
			static const unsigned long REALIZATION_STEREOTYPE = 1122657704;
			static const unsigned int REALIZATION_STEREOTYPE_FEATURE_COUNT = 1;
			static const unsigned int REALIZATION_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long REALIZATION_ATTRIBUTE_BASE_CLASSIFIER = 2125524565;
			
			//Stereotype StandardProfile::Refine
			static const unsigned long REFINE_STEREOTYPE = 1523062016;
			static const unsigned int REFINE_STEREOTYPE_FEATURE_COUNT = 1;
			static const unsigned int REFINE_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long REFINE_ATTRIBUTE_BASE_ABSTRACTION = 1915089674;
			
			//Stereotype StandardProfile::Responsibility
			static const unsigned long RESPONSIBILITY_STEREOTYPE = 737133505;
			static const unsigned int RESPONSIBILITY_STEREOTYPE_FEATURE_COUNT = 1;
			static const unsigned int RESPONSIBILITY_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long RESPONSIBILITY_ATTRIBUTE_BASE_USAGE = 1620036731;
			
			//Stereotype StandardProfile::Script
			static const unsigned long SCRIPT_STEREOTYPE = 364379155;
			static const unsigned int SCRIPT_STEREOTYPE_FEATURE_COUNT = 2;
			static const unsigned int SCRIPT_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long SCRIPT_ATTRIBUTE_BASE_ARTIFACT = 1334320141;
			
			//Stereotype StandardProfile::Send
			static const unsigned long SEND_STEREOTYPE = 1722014911;
			static const unsigned int SEND_STEREOTYPE_FEATURE_COUNT = 1;
			static const unsigned int SEND_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long SEND_ATTRIBUTE_BASE_USAGE = 2030524368;
			
			//Stereotype StandardProfile::Service
			static const unsigned long SERVICE_STEREOTYPE = 1531161909;
			static const unsigned int SERVICE_STEREOTYPE_FEATURE_COUNT = 1;
			static const unsigned int SERVICE_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long SERVICE_ATTRIBUTE_BASE_COMPONENT = 1690426049;
			
			//Stereotype StandardProfile::Source
			static const unsigned long SOURCE_STEREOTYPE = 548518589;
			static const unsigned int SOURCE_STEREOTYPE_FEATURE_COUNT = 2;
			static const unsigned int SOURCE_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long SOURCE_ATTRIBUTE_BASE_ARTIFACT = 1518459575;
			
			//Stereotype StandardProfile::Specification
			static const unsigned long SPECIFICATION_STEREOTYPE = 504804019;
			static const unsigned int SPECIFICATION_STEREOTYPE_FEATURE_COUNT = 1;
			static const unsigned int SPECIFICATION_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long SPECIFICATION_ATTRIBUTE_BASE_CLASSIFIER = 59271704;
			
			//Stereotype StandardProfile::Subsystem
			static const unsigned long SUBSYSTEM_STEREOTYPE = 1825466533;
			static const unsigned int SUBSYSTEM_STEREOTYPE_FEATURE_COUNT = 1;
			static const unsigned int SUBSYSTEM_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long SUBSYSTEM_ATTRIBUTE_BASE_COMPONENT = 374353570;
			
			//Stereotype StandardProfile::SystemModel
			static const unsigned long SYSTEMMODEL_STEREOTYPE = 275535946;
			static const unsigned int SYSTEMMODEL_STEREOTYPE_FEATURE_COUNT = 1;
			static const unsigned int SYSTEMMODEL_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long SYSTEMMODEL_ATTRIBUTE_BASE_MODEL = 1972604965;
			
			//Stereotype StandardProfile::Trace
			static const unsigned long TRACE_STEREOTYPE = 1903938062;
			static const unsigned int TRACE_STEREOTYPE_FEATURE_COUNT = 1;
			static const unsigned int TRACE_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long TRACE_ATTRIBUTE_BASE_ABSTRACTION = 1668223454;
			
			//Stereotype StandardProfile::Type
			static const unsigned long TYPE_STEREOTYPE = 66837757;
			static const unsigned int TYPE_STEREOTYPE_FEATURE_COUNT = 1;
			static const unsigned int TYPE_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long TYPE_ATTRIBUTE_BASE_CLASS = 263672540;
			
			//Stereotype StandardProfile::Utility
			static const unsigned long UTILITY_STEREOTYPE = 995008667;
			static const unsigned int UTILITY_STEREOTYPE_FEATURE_COUNT = 1;
			static const unsigned int UTILITY_STEREOTYPE_OPERATION_COUNT = 0;
			//Properties
			static const unsigned long UTILITY_ATTRIBUTE_BASE_CLASS = 605150396;
			
			
			
	};
}
#endif /* end of include guard: STANDARDPROFILE_METAMODELPACKAGE_HPP */
