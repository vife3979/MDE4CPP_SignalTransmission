//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_LOCIPACKAGE_HPP
#define PSCS_SEMANTICS_LOCIPACKAGE_HPP

// namespace macro header include
#include "PSCS/PSCS.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EAnnotation;
	class EOperation;
	class EDataType;
	class EStringToStringMapEntry;
	class EReference;
	class EParameter;
	class EGenericType;
	class EClass;
}

namespace PSCS::Semantics::Loci 
{
	class CS_ExecutionFactory;
	class CS_Executor;
	class CS_Locus;
}
 
namespace PSCS::Semantics::Loci 
{
	/*!
	The Metamodel Package for the Loci metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class PSCS_API LociPackage : virtual public ecore::EPackage 
	{
		private:    
			LociPackage(LociPackage const&) = delete;
			LociPackage& operator=(LociPackage const&) = delete;

		protected:
			LociPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			// Begin Class CS_ExecutionFactory
			//Class and Feature IDs 
			static const unsigned long CS_EXECUTIONFACTORY_CLASS = 1845389668;
			static const unsigned int CS_EXECUTIONFACTORY_CLASS_FEATURE_COUNT = 5;
			static const unsigned int CS_EXECUTIONFACTORY_CLASS_OPERATION_COUNT = 13;
			
			static const unsigned long CS_EXECUTIONFACTORY_ATTRIBUTE_APPLIEDPROFILES = 167161141;
			
			static const unsigned int CS_EXECUTIONFACTORY_OPERATION_GETSTEREOTYPEAPPLICATION_CLASS_ELEMENT = 96017842;
			static const unsigned int CS_EXECUTIONFACTORY_OPERATION_GETSTEREOTYPECLASS_ESTRING_ESTRING = 2486099920;
			static const unsigned int CS_EXECUTIONFACTORY_OPERATION_INSTANTIATEVISITOR_ELEMENT = 3579698249;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_ExecutionFactory_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getCS_ExecutionFactory_Attribute_appliedProfiles() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getCS_ExecutionFactory_Operation_getStereotypeApplication_Class_Element() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_ExecutionFactory_Operation_getStereotypeClass_EString_EString() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_ExecutionFactory_Operation_instantiateVisitor_Element() const = 0;
			
			// End Class CS_ExecutionFactory


			// Begin Class CS_Executor
			//Class and Feature IDs 
			static const unsigned long CS_EXECUTOR_CLASS = 1795074587;
			static const unsigned int CS_EXECUTOR_CLASS_FEATURE_COUNT = 1;
			static const unsigned int CS_EXECUTOR_CLASS_OPERATION_COUNT = 4;
			
			
			static const unsigned int CS_EXECUTOR_OPERATION_START_CLASS_PARAMETERVALUE = 435271847;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_Executor_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_Executor_Operation_start_Class_ParameterValue() const = 0;
			
			// End Class CS_Executor


			// Begin Class CS_Locus
			//Class and Feature IDs 
			static const unsigned long CS_LOCUS_CLASS = 264779363;
			static const unsigned int CS_LOCUS_CLASS_FEATURE_COUNT = 3;
			static const unsigned int CS_LOCUS_CLASS_OPERATION_COUNT = 8;
			
			
			static const unsigned int CS_LOCUS_OPERATION_INSTANTIATE_CLASS = 3451729688;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_Locus_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_Locus_Operation_instantiate_Class() const = 0;
			
			// End Class CS_Locus

			
			

			

			//Singleton Getter
			public:
				static std::shared_ptr<LociPackage> eInstance();
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_LOCIPACKAGE_HPP */
