//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_VALUESPACKAGE_HPP
#define FUML_SEMANTICS_VALUESPACKAGE_HPP

// namespace macro header include
#include "fUML/fUML.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EStringToStringMapEntry;
	class EAnnotation;
	class EReference;
	class EGenericType;
	class EOperation;
	class EClass;
	class EParameter;
	class EDataType;
}

namespace fUML::Semantics::Values 
{
	class Evaluation;
	class LiteralBooleanEvaluation;
	class LiteralEvaluation;
	class LiteralIntegerEvaluation;
	class LiteralNullEvaluation;
	class LiteralRealEvaluation;
	class LiteralStringEvaluation;
	class LiteralUnlimitedNaturalEvaluation;
	class Value;
}
 
namespace fUML::Semantics::Values 
{
	/*!
	The Metamodel Package for the Values metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class FUML_API ValuesPackage : virtual public ecore::EPackage 
	{
		private:    
			ValuesPackage(ValuesPackage const&) = delete;
			ValuesPackage& operator=(ValuesPackage const&) = delete;

		protected:
			ValuesPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			// Begin Class Evaluation
			//Class and Feature IDs 
			static const unsigned long EVALUATION_CLASS = 1937172657;
			static const unsigned int EVALUATION_CLASS_FEATURE_COUNT = 2;
			static const unsigned int EVALUATION_CLASS_OPERATION_COUNT = 3;
			
			static const unsigned long EVALUATION_ATTRIBUTE_LOCUS = 62298639;
			static const unsigned long EVALUATION_ATTRIBUTE_SPECIFICATION = 1925928417;
			
			static const unsigned int EVALUATION_OPERATION_EVALUATE = 3829887513;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEvaluation_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getEvaluation_Attribute_locus() const = 0;
			virtual std::shared_ptr<ecore::EReference> getEvaluation_Attribute_specification() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getEvaluation_Operation_evaluate() const = 0;
			
			// End Class Evaluation


			// Begin Class LiteralBooleanEvaluation
			//Class and Feature IDs 
			static const unsigned long LITERALBOOLEANEVALUATION_CLASS = 1405002712;
			static const unsigned int LITERALBOOLEANEVALUATION_CLASS_FEATURE_COUNT = 2;
			static const unsigned int LITERALBOOLEANEVALUATION_CLASS_OPERATION_COUNT = 5;
			
			
			static const unsigned int LITERALBOOLEANEVALUATION_OPERATION_EVALUATE = 216489190;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getLiteralBooleanEvaluation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getLiteralBooleanEvaluation_Operation_evaluate() const = 0;
			
			// End Class LiteralBooleanEvaluation


			// Begin Class LiteralEvaluation
			//Class and Feature IDs 
			static const unsigned long LITERALEVALUATION_CLASS = 396602993;
			static const unsigned int LITERALEVALUATION_CLASS_FEATURE_COUNT = 2;
			static const unsigned int LITERALEVALUATION_CLASS_OPERATION_COUNT = 4;
			
			
			static const unsigned int LITERALEVALUATION_OPERATION_GETTYPE_ESTRING = 3047468424;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getLiteralEvaluation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getLiteralEvaluation_Operation_getType_EString() const = 0;
			
			// End Class LiteralEvaluation


			// Begin Class LiteralIntegerEvaluation
			//Class and Feature IDs 
			static const unsigned long LITERALINTEGEREVALUATION_CLASS = 49428087;
			static const unsigned int LITERALINTEGEREVALUATION_CLASS_FEATURE_COUNT = 2;
			static const unsigned int LITERALINTEGEREVALUATION_CLASS_OPERATION_COUNT = 5;
			
			
			static const unsigned int LITERALINTEGEREVALUATION_OPERATION_EVALUATE = 1437295956;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getLiteralIntegerEvaluation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getLiteralIntegerEvaluation_Operation_evaluate() const = 0;
			
			// End Class LiteralIntegerEvaluation


			// Begin Class LiteralNullEvaluation
			//Class and Feature IDs 
			static const unsigned long LITERALNULLEVALUATION_CLASS = 372444390;
			static const unsigned int LITERALNULLEVALUATION_CLASS_FEATURE_COUNT = 2;
			static const unsigned int LITERALNULLEVALUATION_CLASS_OPERATION_COUNT = 5;
			
			
			static const unsigned int LITERALNULLEVALUATION_OPERATION_EVALUATE = 297899813;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getLiteralNullEvaluation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getLiteralNullEvaluation_Operation_evaluate() const = 0;
			
			// End Class LiteralNullEvaluation


			// Begin Class LiteralRealEvaluation
			//Class and Feature IDs 
			static const unsigned long LITERALREALEVALUATION_CLASS = 1312489840;
			static const unsigned int LITERALREALEVALUATION_CLASS_FEATURE_COUNT = 2;
			static const unsigned int LITERALREALEVALUATION_CLASS_OPERATION_COUNT = 5;
			
			
			static const unsigned int LITERALREALEVALUATION_OPERATION_EVALUATE = 269404326;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getLiteralRealEvaluation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getLiteralRealEvaluation_Operation_evaluate() const = 0;
			
			// End Class LiteralRealEvaluation


			// Begin Class LiteralStringEvaluation
			//Class and Feature IDs 
			static const unsigned long LITERALSTRINGEVALUATION_CLASS = 1041297075;
			static const unsigned int LITERALSTRINGEVALUATION_CLASS_FEATURE_COUNT = 2;
			static const unsigned int LITERALSTRINGEVALUATION_CLASS_OPERATION_COUNT = 5;
			
			
			static const unsigned int LITERALSTRINGEVALUATION_OPERATION_EVALUATE = 3934677925;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getLiteralStringEvaluation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getLiteralStringEvaluation_Operation_evaluate() const = 0;
			
			// End Class LiteralStringEvaluation


			// Begin Class LiteralUnlimitedNaturalEvaluation
			//Class and Feature IDs 
			static const unsigned long LITERALUNLIMITEDNATURALEVALUATION_CLASS = 1271688193;
			static const unsigned int LITERALUNLIMITEDNATURALEVALUATION_CLASS_FEATURE_COUNT = 2;
			static const unsigned int LITERALUNLIMITEDNATURALEVALUATION_CLASS_OPERATION_COUNT = 5;
			
			
			static const unsigned int LITERALUNLIMITEDNATURALEVALUATION_OPERATION_EVALUATE = 926755692;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getLiteralUnlimitedNaturalEvaluation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getLiteralUnlimitedNaturalEvaluation_Operation_evaluate() const = 0;
			
			// End Class LiteralUnlimitedNaturalEvaluation


			// Begin Class Value
			//Class and Feature IDs 
			static const unsigned long VALUE_CLASS = 856918907;
			static const unsigned int VALUE_CLASS_FEATURE_COUNT = 0;
			static const unsigned int VALUE_CLASS_OPERATION_COUNT = 12;
			
			
			static const unsigned int VALUE_OPERATION_ISINSTANCEOF_CLASSIFIER = 708485784;
			static const unsigned int VALUE_OPERATION__COPY = 611324517;
			static const unsigned int VALUE_OPERATION_CHECKALLPARENTS_CLASSIFIER_CLASSIFIER = 4163434821;
			static const unsigned int VALUE_OPERATION_EQUALS_VALUE = 1172438202;
			static const unsigned int VALUE_OPERATION_GETTYPES = 3772499480;
			static const unsigned int VALUE_OPERATION_HASTYPES_CLASSIFIER = 2391965979;
			static const unsigned int VALUE_OPERATION_NEW_ = 2089540196;
			static const unsigned int VALUE_OPERATION_OBJECTID = 3339238689;
			static const unsigned int VALUE_OPERATION_SPECIFY = 3348978702;
			static const unsigned int VALUE_OPERATION_TOSTRING = 3303049319;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getValue_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getValue_Operation_isInstanceOf_Classifier() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getValue_Operation__copy() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getValue_Operation_checkAllParents_Classifier_Classifier() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getValue_Operation_equals_Value() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getValue_Operation_getTypes() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getValue_Operation_hasTypes_Classifier() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getValue_Operation_new_() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getValue_Operation_objectId() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getValue_Operation_specify() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getValue_Operation_toString() const = 0;
			
			// End Class Value

			
			

			

			//Singleton Instance and Getter
			private:
				static std::shared_ptr<ValuesPackage> instance;
			public:
				static std::shared_ptr<ValuesPackage> eInstance();
	};
}
#endif /* end of include guard: FUML_SEMANTICS_VALUESPACKAGE_HPP */
