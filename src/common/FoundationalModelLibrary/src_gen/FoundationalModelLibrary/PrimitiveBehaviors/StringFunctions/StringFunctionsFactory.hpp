//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_STRINGFUNCTIONS_FACTORY_HPP
#define FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_STRINGFUNCTIONS_FACTORY_HPP

#include "uml/Factory.hpp"
#include "FoundationalModelLibrary/PrimitiveBehaviors/StringFunctions/StringFunctionsPackage.hpp"


namespace FoundationalModelLibrary::PrimitiveBehaviors::StringFunctions 
{
	class StringFunctionsPackage;
	class StringFunctionsFactory;

	class StringFunctionsFactory : virtual public uml::Factory 
	{ 
		protected:
			//protected default construcotr
			StringFunctionsFactory(){}

			//Singleton Getter
			public:
				static std::shared_ptr<StringFunctionsFactory> eInstance();

			//Creator functions
			virtual std::shared_ptr<uml::Element> create(const unsigned int _metaClassId,  std::shared_ptr<uml::Element> container= nullptr, const unsigned int referenceID = -1) const = 0;
			virtual std::shared_ptr<uml::Element> create(const std::shared_ptr<uml::Class> _class,  std::shared_ptr<uml::Element> container= nullptr, const unsigned int referenceID = -1) const = 0;
			virtual std::shared_ptr<uml::Element> create(const std::string _className,  std::shared_ptr<uml::Element> container= nullptr, const unsigned int referenceID = -1) const = 0;

			
			//Package
			virtual std::shared_ptr<StringFunctionsPackage> getStringFunctionsPackage() = 0;
	};
}
#endif /* end of include guard: FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_STRINGFUNCTIONS_FACTORY_HPP */
