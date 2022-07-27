//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUMLPACKAGE_HPP
#define FUMLPACKAGE_HPP

// namespace macro header include
#include "fUML/fUML.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EAnnotation;
	class EOperation;
	class EPackage;
	class EAttribute;
	class EDataType;
	class EStringToStringMapEntry;
	class EReference;
	class EParameter;
	class EGenericType;
	class EClass;
}

namespace fUML 
{
	namespace Semantics 
	{
		class SemanticsPackage;
	}

}
 
namespace fUML 
{
	/*!
	The Metamodel Package for the fUML metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class FUML_API fUMLPackage : virtual public ecore::EPackage 
	{
		private:    
			fUMLPackage(fUMLPackage const&) = delete;
			fUMLPackage& operator=(fUMLPackage const&) = delete;

		protected:
			fUMLPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			
			

			virtual std::shared_ptr<fUML::Semantics::SemanticsPackage> getSemantics_Package() const = 0;
			

			//Singleton Getter
			public:
				static std::shared_ptr<fUMLPackage> eInstance();
	};
}
#endif /* end of include guard: FUMLPACKAGE_HPP */
