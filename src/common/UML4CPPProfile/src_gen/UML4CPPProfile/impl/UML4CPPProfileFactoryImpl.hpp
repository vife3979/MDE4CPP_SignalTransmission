//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef UML4CPPPROFILE_FACTORYIMPL_HPP
#define UML4CPPPROFILE_FACTORYIMPL_HPP

#include <functional>
#include <map>

#include "uml/impl/FactoryImpl.hpp"
#include "UML4CPPProfile/UML4CPPProfileFactory.hpp"

namespace UML4CPPProfile 
{
	class UML4CPPProfileFactoryImpl : virtual public uml::FactoryImpl , virtual public UML4CPPProfileFactory 
	{
		protected:
			friend class UML4CPPProfileFactory;
			// Constructor
			UML4CPPProfileFactoryImpl();

		public:
			virtual ~UML4CPPProfileFactoryImpl();
			virtual std::shared_ptr<uml::Element> create(const unsigned int _metaClassId,  std::shared_ptr<uml::Element> container= nullptr, const unsigned int referenceID = -1) const;
			virtual std::shared_ptr<uml::Element> create(const std::shared_ptr<uml::Class> _class,  std::shared_ptr<uml::Element> container= nullptr, const unsigned int referenceID = -1) const;
			virtual std::shared_ptr<uml::Element> create(const std::string _className,  std::shared_ptr<uml::Element> container= nullptr, const unsigned int referenceID = -1) const;

			//Creator functions
			//START Create methods for class DoNotGenerate
			virtual std::shared_ptr<UML4CPPProfile::DoNotGenerate> createDoNotGenerate(const int metaElementID = UML4CPPProfilePackage::DONOTGENERATE_STEREOTYPE) const ;
			//END Create methods for class DoNotGenerate
			//START Create methods for class ExternalLibrary
			virtual std::shared_ptr<UML4CPPProfile::ExternalLibrary> createExternalLibrary(const int metaElementID = UML4CPPProfilePackage::EXTERNALLIBRARY_STEREOTYPE) const ;
			//END Create methods for class ExternalLibrary
			//START Create methods for class GetterName
			virtual std::shared_ptr<UML4CPPProfile::GetterName> createGetterName(const int metaElementID = UML4CPPProfilePackage::GETTERNAME_STEREOTYPE) const ;
			//END Create methods for class GetterName
			//START Create methods for class MainBehavior
			virtual std::shared_ptr<UML4CPPProfile::MainBehavior> createMainBehavior(const int metaElementID = UML4CPPProfilePackage::MAINBEHAVIOR_STEREOTYPE) const ;
			//END Create methods for class MainBehavior
			//START Create methods for class NonExecutable
			virtual std::shared_ptr<UML4CPPProfile::NonExecutable> createNonExecutable(const int metaElementID = UML4CPPProfilePackage::NONEXECUTABLE_STEREOTYPE) const ;
			//END Create methods for class NonExecutable
			//START Create methods for class SetterName
			virtual std::shared_ptr<UML4CPPProfile::SetterName> createSetterName(const int metaElementID = UML4CPPProfilePackage::SETTERNAME_STEREOTYPE) const ;
			//END Create methods for class SetterName
			//START Create methods for class Singleton
			virtual std::shared_ptr<UML4CPPProfile::Singleton> createSingleton(const int metaElementID = UML4CPPProfilePackage::SINGLETON_STEREOTYPE) const ;
			//END Create methods for class Singleton
			//START Create methods for class UML4CPPPackage
			virtual std::shared_ptr<UML4CPPProfile::UML4CPPPackage> createUML4CPPPackage(const int metaElementID = UML4CPPProfilePackage::UML4CPPPACKAGE_STEREOTYPE) const ;
			//END Create methods for class UML4CPPPackage
			

			//Package
			virtual std::shared_ptr<UML4CPPProfilePackage> getUML4CPPProfilePackage();

		private:
			static UML4CPPProfileFactory * create();
			std::map<std::string,unsigned int> m_idMap;
			virtual void init() {}
	};
}
#endif /* end of include guard: UML4CPPPROFILE_FACTORYIMPL_HPP */
