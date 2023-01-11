//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_FACTORY_HPP
#define STANDARDPROFILE_FACTORY_HPP

#include "uml/Factory.hpp"
#include "StandardProfile/StandardProfilePackage.hpp"

namespace StandardProfile
{
	class Auxiliary;
	class BuildComponent;
	class Call;
	class Create;
	class Derive;
	class Destroy;
	class Document;
	class Entity;
	class Executable;
	class File;
	class Focus;
	class Framework;
	class Implement;
	class ImplementationClass;
	class Instantiate;
	class Library;
	class Metaclass;
	class Metamodel;
	class ModelLibrary;
	class Process;
	class Realization;
	class Refine;
	class Responsibility;
	class Script;
	class Send;
	class Service;
	class Source;
	class Specification;
	class Subsystem;
	class SystemModel;
	class Trace;
	class Type;
	class Utility;
}

namespace StandardProfile 
{
	class StandardProfilePackage;
	class StandardProfileFactory;

	class StandardProfileFactory : virtual public uml::Factory 
	{ 
		protected:
			//protected default construcotr
			StandardProfileFactory(){}

			//Singleton Instance and Getter
			
			private:
				static std::shared_ptr<StandardProfileFactory> instance;
			public:
				static std::shared_ptr<StandardProfileFactory> eInstance();

			//Creator functions
			virtual std::shared_ptr<uml::Element> create(const unsigned int _metaClassId,  std::shared_ptr<uml::Element> container= nullptr, const unsigned int referenceID = -1) const = 0;
			virtual std::shared_ptr<uml::Element> create(const std::shared_ptr<uml::Class> _class,  std::shared_ptr<uml::Element> container= nullptr, const unsigned int referenceID = -1) const = 0;
			virtual std::shared_ptr<uml::Element> create(const std::string _className,  std::shared_ptr<uml::Element> container= nullptr, const unsigned int referenceID = -1) const = 0;

			//START Create methods for class Auxiliary
			virtual std::shared_ptr<StandardProfile::Auxiliary> createAuxiliary(const int metaElementID = StandardProfilePackage::AUXILIARY_STEREOTYPE) const  = 0;
			//END Create methods for class Auxiliary
			//START Create methods for class BuildComponent
			virtual std::shared_ptr<StandardProfile::BuildComponent> createBuildComponent(const int metaElementID = StandardProfilePackage::BUILDCOMPONENT_STEREOTYPE) const  = 0;
			//END Create methods for class BuildComponent
			//START Create methods for class Call
			virtual std::shared_ptr<StandardProfile::Call> createCall(const int metaElementID = StandardProfilePackage::CALL_STEREOTYPE) const  = 0;
			//END Create methods for class Call
			//START Create methods for class Create
			virtual std::shared_ptr<StandardProfile::Create> createCreate(const int metaElementID = StandardProfilePackage::CREATE_STEREOTYPE) const  = 0;
			//END Create methods for class Create
			//START Create methods for class Derive
			virtual std::shared_ptr<StandardProfile::Derive> createDerive(const int metaElementID = StandardProfilePackage::DERIVE_STEREOTYPE) const  = 0;
			//END Create methods for class Derive
			//START Create methods for class Destroy
			virtual std::shared_ptr<StandardProfile::Destroy> createDestroy(const int metaElementID = StandardProfilePackage::DESTROY_STEREOTYPE) const  = 0;
			//END Create methods for class Destroy
			//START Create methods for class Document
			virtual std::shared_ptr<StandardProfile::Document> createDocument(const int metaElementID = StandardProfilePackage::DOCUMENT_STEREOTYPE) const  = 0;
			//END Create methods for class Document
			//START Create methods for class Entity
			virtual std::shared_ptr<StandardProfile::Entity> createEntity(const int metaElementID = StandardProfilePackage::ENTITY_STEREOTYPE) const  = 0;
			//END Create methods for class Entity
			//START Create methods for class Executable
			virtual std::shared_ptr<StandardProfile::Executable> createExecutable(const int metaElementID = StandardProfilePackage::EXECUTABLE_STEREOTYPE) const  = 0;
			//END Create methods for class Executable
			//START Create methods for class File
			virtual std::shared_ptr<StandardProfile::File> createFile(const int metaElementID = StandardProfilePackage::FILE_STEREOTYPE) const  = 0;
			//END Create methods for class File
			//START Create methods for class Focus
			virtual std::shared_ptr<StandardProfile::Focus> createFocus(const int metaElementID = StandardProfilePackage::FOCUS_STEREOTYPE) const  = 0;
			//END Create methods for class Focus
			//START Create methods for class Framework
			virtual std::shared_ptr<StandardProfile::Framework> createFramework(const int metaElementID = StandardProfilePackage::FRAMEWORK_STEREOTYPE) const  = 0;
			//END Create methods for class Framework
			//START Create methods for class Implement
			virtual std::shared_ptr<StandardProfile::Implement> createImplement(const int metaElementID = StandardProfilePackage::IMPLEMENT_STEREOTYPE) const  = 0;
			//END Create methods for class Implement
			//START Create methods for class ImplementationClass
			virtual std::shared_ptr<StandardProfile::ImplementationClass> createImplementationClass(const int metaElementID = StandardProfilePackage::IMPLEMENTATIONCLASS_STEREOTYPE) const  = 0;
			//END Create methods for class ImplementationClass
			//START Create methods for class Instantiate
			virtual std::shared_ptr<StandardProfile::Instantiate> createInstantiate(const int metaElementID = StandardProfilePackage::INSTANTIATE_STEREOTYPE) const  = 0;
			//END Create methods for class Instantiate
			//START Create methods for class Library
			virtual std::shared_ptr<StandardProfile::Library> createLibrary(const int metaElementID = StandardProfilePackage::LIBRARY_STEREOTYPE) const  = 0;
			//END Create methods for class Library
			//START Create methods for class Metaclass
			virtual std::shared_ptr<StandardProfile::Metaclass> createMetaclass(const int metaElementID = StandardProfilePackage::METACLASS_STEREOTYPE) const  = 0;
			//END Create methods for class Metaclass
			//START Create methods for class Metamodel
			virtual std::shared_ptr<StandardProfile::Metamodel> createMetamodel(const int metaElementID = StandardProfilePackage::METAMODEL_STEREOTYPE) const  = 0;
			//END Create methods for class Metamodel
			//START Create methods for class ModelLibrary
			virtual std::shared_ptr<StandardProfile::ModelLibrary> createModelLibrary(const int metaElementID = StandardProfilePackage::MODELLIBRARY_STEREOTYPE) const  = 0;
			//END Create methods for class ModelLibrary
			//START Create methods for class Process
			virtual std::shared_ptr<StandardProfile::Process> createProcess(const int metaElementID = StandardProfilePackage::PROCESS_STEREOTYPE) const  = 0;
			//END Create methods for class Process
			//START Create methods for class Realization
			virtual std::shared_ptr<StandardProfile::Realization> createRealization(const int metaElementID = StandardProfilePackage::REALIZATION_STEREOTYPE) const  = 0;
			//END Create methods for class Realization
			//START Create methods for class Refine
			virtual std::shared_ptr<StandardProfile::Refine> createRefine(const int metaElementID = StandardProfilePackage::REFINE_STEREOTYPE) const  = 0;
			//END Create methods for class Refine
			//START Create methods for class Responsibility
			virtual std::shared_ptr<StandardProfile::Responsibility> createResponsibility(const int metaElementID = StandardProfilePackage::RESPONSIBILITY_STEREOTYPE) const  = 0;
			//END Create methods for class Responsibility
			//START Create methods for class Script
			virtual std::shared_ptr<StandardProfile::Script> createScript(const int metaElementID = StandardProfilePackage::SCRIPT_STEREOTYPE) const  = 0;
			//END Create methods for class Script
			//START Create methods for class Send
			virtual std::shared_ptr<StandardProfile::Send> createSend(const int metaElementID = StandardProfilePackage::SEND_STEREOTYPE) const  = 0;
			//END Create methods for class Send
			//START Create methods for class Service
			virtual std::shared_ptr<StandardProfile::Service> createService(const int metaElementID = StandardProfilePackage::SERVICE_STEREOTYPE) const  = 0;
			//END Create methods for class Service
			//START Create methods for class Source
			virtual std::shared_ptr<StandardProfile::Source> createSource(const int metaElementID = StandardProfilePackage::SOURCE_STEREOTYPE) const  = 0;
			//END Create methods for class Source
			//START Create methods for class Specification
			virtual std::shared_ptr<StandardProfile::Specification> createSpecification(const int metaElementID = StandardProfilePackage::SPECIFICATION_STEREOTYPE) const  = 0;
			//END Create methods for class Specification
			//START Create methods for class Subsystem
			virtual std::shared_ptr<StandardProfile::Subsystem> createSubsystem(const int metaElementID = StandardProfilePackage::SUBSYSTEM_STEREOTYPE) const  = 0;
			//END Create methods for class Subsystem
			//START Create methods for class SystemModel
			virtual std::shared_ptr<StandardProfile::SystemModel> createSystemModel(const int metaElementID = StandardProfilePackage::SYSTEMMODEL_STEREOTYPE) const  = 0;
			//END Create methods for class SystemModel
			//START Create methods for class Trace
			virtual std::shared_ptr<StandardProfile::Trace> createTrace(const int metaElementID = StandardProfilePackage::TRACE_STEREOTYPE) const  = 0;
			//END Create methods for class Trace
			//START Create methods for class Type
			virtual std::shared_ptr<StandardProfile::Type> createType(const int metaElementID = StandardProfilePackage::TYPE_STEREOTYPE) const  = 0;
			//END Create methods for class Type
			//START Create methods for class Utility
			virtual std::shared_ptr<StandardProfile::Utility> createUtility(const int metaElementID = StandardProfilePackage::UTILITY_STEREOTYPE) const  = 0;
			//END Create methods for class Utility
			
			//Package
			virtual std::shared_ptr<StandardProfilePackage> getStandardProfilePackage() = 0;
	};
}
#endif /* end of include guard: STANDARDPROFILE_FACTORY_HPP */
