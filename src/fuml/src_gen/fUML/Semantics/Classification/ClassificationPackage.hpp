//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_CLASSIFICATIONPACKAGE_HPP
#define FUML_SEMANTICS_CLASSIFICATIONPACKAGE_HPP

// namespace macro header include
#include "fUML/fUML.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EStringToStringMapEntry;
	class EGenericType;
	class EOperation;
	class EAnnotation;
	class EClass;
}

namespace fUML::Semantics::Classification 
{

}
 
namespace fUML::Semantics::Classification 
{
	/*!
	The Metamodel Package for the Classification metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class FUML_API ClassificationPackage : virtual public ecore::EPackage 
	{
		private:    
			ClassificationPackage(ClassificationPackage const&) = delete;
			ClassificationPackage& operator=(ClassificationPackage const&) = delete;

		protected:
			ClassificationPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			
			

			

			//Singleton Instance and Getter
			private:
				static std::shared_ptr<ClassificationPackage> instance;
			public:
				static std::shared_ptr<ClassificationPackage> eInstance();
	};
}
#endif /* end of include guard: FUML_SEMANTICS_CLASSIFICATIONPACKAGE_HPP */
