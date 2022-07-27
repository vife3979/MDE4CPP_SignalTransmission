//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_SIMPLECLASSIFIERSFACTORY_HPP
#define FUML_SEMANTICS_SIMPLECLASSIFIERSFACTORY_HPP
// namespace macro header include
#include "fUML/fUML.hpp"

#include <map>
#include <memory>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EFactory.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"

namespace fUML::Semantics::Activities
{
	class ObjectToken;
}
namespace fUML::Semantics::CommonBehavior
{
	class ObjectActivation;
	class ParameterValue;
}



namespace fUML::Semantics::SimpleClassifiers 
{
	class FUML_API SimpleClassifiersFactory : virtual public ecore::EFactory 
	{
		private:    
			SimpleClassifiersFactory(SimpleClassifiersFactory const&) = delete;
			SimpleClassifiersFactory& operator=(SimpleClassifiersFactory const&) = delete;
		protected:
			SimpleClassifiersFactory(){}
		
			//Singleton Getter
			public:
				static std::shared_ptr<SimpleClassifiersFactory> eInstance();
		
			//Creator functions
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const = 0;

			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> createBooleanValue(const int metaElementID = SimpleClassifiersPackage::BOOLEANVALUE_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> createBooleanValue_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID = SimpleClassifiersPackage::BOOLEANVALUE_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> createBooleanValue_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID = SimpleClassifiersPackage::BOOLEANVALUE_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> createBooleanValue_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID = SimpleClassifiersPackage::BOOLEANVALUE_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::DataValue> createDataValue(const int metaElementID = SimpleClassifiersPackage::DATAVALUE_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::DataValue> createDataValue_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID = SimpleClassifiersPackage::DATAVALUE_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::DataValue> createDataValue_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID = SimpleClassifiersPackage::DATAVALUE_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::DataValue> createDataValue_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID = SimpleClassifiersPackage::DATAVALUE_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> createEnumerationValue(const int metaElementID = SimpleClassifiersPackage::ENUMERATIONVALUE_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> createEnumerationValue_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID = SimpleClassifiersPackage::ENUMERATIONVALUE_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> createEnumerationValue_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID = SimpleClassifiersPackage::ENUMERATIONVALUE_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> createEnumerationValue_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID = SimpleClassifiersPackage::ENUMERATIONVALUE_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> createFeatureValue(const int metaElementID = SimpleClassifiersPackage::FEATUREVALUE_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> createFeatureValue_as_featureValues_in_CompoundValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::CompoundValue> par_CompoundValue, const int metaElementID = SimpleClassifiersPackage::FEATUREVALUE_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> createIntegerValue(const int metaElementID = SimpleClassifiersPackage::INTEGERVALUE_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> createIntegerValue_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID = SimpleClassifiersPackage::INTEGERVALUE_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> createIntegerValue_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID = SimpleClassifiersPackage::INTEGERVALUE_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> createIntegerValue_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID = SimpleClassifiersPackage::INTEGERVALUE_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::RealValue> createRealValue(const int metaElementID = SimpleClassifiersPackage::REALVALUE_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::RealValue> createRealValue_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID = SimpleClassifiersPackage::REALVALUE_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::RealValue> createRealValue_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID = SimpleClassifiersPackage::REALVALUE_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::RealValue> createRealValue_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID = SimpleClassifiersPackage::REALVALUE_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> createSignalInstance(const int metaElementID = SimpleClassifiersPackage::SIGNALINSTANCE_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> createSignalInstance_as_eventPool_in_ObjectActivation(std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> par_ObjectActivation, const int metaElementID = SimpleClassifiersPackage::SIGNALINSTANCE_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> createSignalInstance_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID = SimpleClassifiersPackage::SIGNALINSTANCE_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> createSignalInstance_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID = SimpleClassifiersPackage::SIGNALINSTANCE_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> createSignalInstance_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID = SimpleClassifiersPackage::SIGNALINSTANCE_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> createStringValue(const int metaElementID = SimpleClassifiersPackage::STRINGVALUE_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> createStringValue_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID = SimpleClassifiersPackage::STRINGVALUE_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> createStringValue_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID = SimpleClassifiersPackage::STRINGVALUE_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> createStringValue_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID = SimpleClassifiersPackage::STRINGVALUE_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue> createUnlimitedNaturalValue(const int metaElementID = SimpleClassifiersPackage::UNLIMITEDNATURALVALUE_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue> createUnlimitedNaturalValue_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID = SimpleClassifiersPackage::UNLIMITEDNATURALVALUE_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue> createUnlimitedNaturalValue_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID = SimpleClassifiersPackage::UNLIMITEDNATURALVALUE_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue> createUnlimitedNaturalValue_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID = SimpleClassifiersPackage::UNLIMITEDNATURALVALUE_CLASS) const = 0;
			
	};
}
#endif /* end of include guard: FUML_SEMANTICS_SIMPLECLASSIFIERSFACTORY_HPP */
