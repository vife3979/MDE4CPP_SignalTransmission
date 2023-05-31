//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_STRUCTUREDCLASSIFIERSPACKAGE_HPP
#define PSCS_SEMANTICS_STRUCTUREDCLASSIFIERSPACKAGE_HPP

// namespace macro header include
#include "PSCS/PSCS.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EStringToStringMapEntry;
	class EAnnotation;
	class EReference;
	class EGenericType;
	class EEnum;
	class EOperation;
	class EClass;
	class EParameter;
	class EDataType;
	class EEnumLiteral;
}

namespace PSCS::Semantics::StructuredClassifiers 
{
	class CS_DefaultRequestPropagationStrategy;
	class CS_DispatchOperationOfInterfaceStrategy;
	class CS_InteractionPoint;
	class CS_Link;
	class CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy;
	class CS_Object;
	class CS_Reference;
	class CS_RequestPropagationStrategy;
	class CS_StructuralFeatureOfInterfaceAccessStrategy;
}
 
namespace PSCS::Semantics::StructuredClassifiers 
{
	/*!
	The Metamodel Package for the StructuredClassifiers metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class PSCS_API StructuredClassifiersPackage : virtual public ecore::EPackage 
	{
		private:    
			StructuredClassifiersPackage(StructuredClassifiersPackage const&) = delete;
			StructuredClassifiersPackage& operator=(StructuredClassifiersPackage const&) = delete;

		protected:
			StructuredClassifiersPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			// Begin Class CS_DefaultRequestPropagationStrategy
			//Class and Feature IDs 
			static const unsigned long CS_DEFAULTREQUESTPROPAGATIONSTRATEGY_CLASS = 114292004;
			static const unsigned int CS_DEFAULTREQUESTPROPAGATIONSTRATEGY_CLASS_FEATURE_COUNT = 0;
			static const unsigned int CS_DEFAULTREQUESTPROPAGATIONSTRATEGY_CLASS_OPERATION_COUNT = 4;
			
			
			static const unsigned int CS_DEFAULTREQUESTPROPAGATIONSTRATEGY_OPERATION_SELECT_REFERENCE_SEMANTICVISITOR = 785142002;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_DefaultRequestPropagationStrategy_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_DefaultRequestPropagationStrategy_Operation_select_Reference_SemanticVisitor() const = 0;
			
			// End Class CS_DefaultRequestPropagationStrategy


			// Begin Class CS_DispatchOperationOfInterfaceStrategy
			//Class and Feature IDs 
			static const unsigned long CS_DISPATCHOPERATIONOFINTERFACESTRATEGY_CLASS = 732334652;
			static const unsigned int CS_DISPATCHOPERATIONOFINTERFACESTRATEGY_CLASS_FEATURE_COUNT = 0;
			static const unsigned int CS_DISPATCHOPERATIONOFINTERFACESTRATEGY_CLASS_OPERATION_COUNT = 7;
			
			
			static const unsigned int CS_DISPATCHOPERATIONOFINTERFACESTRATEGY_OPERATION_OPERATIONSMATCH_OPERATION_OPERATION = 746775994;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_DispatchOperationOfInterfaceStrategy_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_DispatchOperationOfInterfaceStrategy_Operation_operationsMatch_Operation_Operation() const = 0;
			
			// End Class CS_DispatchOperationOfInterfaceStrategy


			// Begin Class CS_InteractionPoint
			//Class and Feature IDs 
			static const unsigned long CS_INTERACTIONPOINT_CLASS = 314391515;
			static const unsigned int CS_INTERACTIONPOINT_CLASS_FEATURE_COUNT = 3;
			static const unsigned int CS_INTERACTIONPOINT_CLASS_OPERATION_COUNT = 43;
			
			static const unsigned long CS_INTERACTIONPOINT_ATTRIBUTE_DEFININGPORT = 342702236;
			static const unsigned long CS_INTERACTIONPOINT_ATTRIBUTE_OWNER = 165744507;
			
			static const unsigned int CS_INTERACTIONPOINT_OPERATION_CHECKALLPARENTS_CLASSIFIER_CLASSIFIER = 956192241;
			static const unsigned int CS_INTERACTIONPOINT_OPERATION_DISPATCH_OPERATION = 2507438394;
			static const unsigned int CS_INTERACTIONPOINT_OPERATION_SEND_EVENTOCCURRENCE = 1027936062;
			static const unsigned int CS_INTERACTIONPOINT_OPERATION_STARTBEHAVIOR_CLASS_PARAMETERVALUE = 3659703839;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_InteractionPoint_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getCS_InteractionPoint_Attribute_definingPort() const = 0;
			virtual std::shared_ptr<ecore::EReference> getCS_InteractionPoint_Attribute_owner() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getCS_InteractionPoint_Operation_checkAllParents_Classifier_Classifier() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_InteractionPoint_Operation_dispatch_Operation() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_InteractionPoint_Operation_send_EventOccurrence() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_InteractionPoint_Operation_startBehavior_Class_ParameterValue() const = 0;
			
			// End Class CS_InteractionPoint


			// Begin Class CS_Link
			//Class and Feature IDs 
			static const unsigned long CS_LINK_CLASS = 225228270;
			static const unsigned int CS_LINK_CLASS_FEATURE_COUNT = 3;
			static const unsigned int CS_LINK_CLASS_OPERATION_COUNT = 40;
			
			
			static const unsigned int CS_LINK_OPERATION_GETFEATURE_VALUE = 3546412222;
			static const unsigned int CS_LINK_OPERATION_HASVALUEFORAFEATURE_VALUE = 1213928788;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_Link_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_Link_Operation_getFeature_Value() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_Link_Operation_hasValueForAFeature_Value() const = 0;
			
			// End Class CS_Link


			// Begin Class CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy
			//Class and Feature IDs 
			static const unsigned long CS_NAMEBASED_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_CLASS = 1596515744;
			static const unsigned int CS_NAMEBASED_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_CLASS_FEATURE_COUNT = 0;
			static const unsigned int CS_NAMEBASED_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_CLASS_OPERATION_COUNT = 6;
			
			
			static const unsigned int CS_NAMEBASED_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_OPERATION_READ_CS_OBJECT_STRUCTURALFEATURE = 2662439450;
			static const unsigned int CS_NAMEBASED_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_OPERATION_WRITE_CS_OBJECT_EINT = 2035586850;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_EInt() const = 0;
			
			// End Class CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy


			// Begin Class CS_Object
			//Class and Feature IDs 
			static const unsigned long CS_OBJECT_CLASS = 1305137753;
			static const unsigned int CS_OBJECT_CLASS_FEATURE_COUNT = 4;
			static const unsigned int CS_OBJECT_CLASS_OPERATION_COUNT = 64;
			
			
			static const unsigned int CS_OBJECT_OPERATION_CHECKALLPARENTS_CLASSIFIER_CLASSIFIER = 1038258742;
			static const unsigned int CS_OBJECT_OPERATION_CONTAINS_OBJECT = 3067656778;
			static const unsigned int CS_OBJECT_OPERATION_DIRECTLYCONTAINS_OBJECT = 744324758;
			static const unsigned int CS_OBJECT_OPERATION_DISPATCHIN_OPERATION_CS_INTERACTIONPOINT = 657350718;
			static const unsigned int CS_OBJECT_OPERATION_DISPATCHIN_OPERATION_PORT = 3289525413;
			static const unsigned int CS_OBJECT_OPERATION_DISPATCHOUT_OPERATION_CS_INTERACTIONPOINT = 3478769199;
			static const unsigned int CS_OBJECT_OPERATION_DISPATCHOUT_OPERATION_PORT = 1250107266;
			static const unsigned int CS_OBJECT_OPERATION_GETDIRECTCONTAINERS = 3389575504;
			static const unsigned int CS_OBJECT_OPERATION_GETFEATUREVALUE_STRUCTURALFEATURE = 2046500626;
			static const unsigned int CS_OBJECT_OPERATION_GETLINKKIND_CS_LINK_CS_INTERACTIONPOINT = 1695153034;
			static const unsigned int CS_OBJECT_OPERATION_GETLINKS_CS_INTERACTIONPOINT = 1582068159;
			static const unsigned int CS_OBJECT_OPERATION_HASVALUEFORAFEATURE_VALUE = 906111845;
			static const unsigned int CS_OBJECT_OPERATION_ISDESCENDANT_INTERFACE_INTERFACE = 3965248275;
			static const unsigned int CS_OBJECT_OPERATION_ISOPERATIONPROVIDED_REFERENCE_OPERATION = 3805653372;
			static const unsigned int CS_OBJECT_OPERATION_ISOPERATIONREQUIRED_REFERENCE_OPERATION = 2795367960;
			static const unsigned int CS_OBJECT_OPERATION_REALIZESINTERFACE_CLASS_INTERFACE = 4261124103;
			static const unsigned int CS_OBJECT_OPERATION_SELECTTARGETSFORDISPATCHING_CS_LINK_EBOOLEAN = 1803445854;
			static const unsigned int CS_OBJECT_OPERATION_SELECTTARGETSFORSENDING_CS_LINK_EBOOLEAN = 2943712457;
			static const unsigned int CS_OBJECT_OPERATION_SENDIN_EVENTOCCURRENCE_CS_INTERACTIONPOINT = 477199882;
			static const unsigned int CS_OBJECT_OPERATION_SENDIN_EVENTOCCURRENCE_PORT = 3108271737;
			static const unsigned int CS_OBJECT_OPERATION_SENDOUT_EVENTOCCURRENCE_CS_INTERACTIONPOINT = 3285401235;
			static const unsigned int CS_OBJECT_OPERATION_SENDOUT_EVENTOCCURRENCE_PORT = 998288782;
			static const unsigned int CS_OBJECT_OPERATION_SETFEATUREVALUE_STRUCTURALFEATURE_EINT = 575812663;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_Object_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_checkAllParents_Classifier_Classifier() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_contains_Object() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_directlyContains_Object() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_dispatchIn_Operation_CS_InteractionPoint() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_dispatchIn_Operation_Port() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_dispatchOut_Operation_CS_InteractionPoint() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_dispatchOut_Operation_Port() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_getDirectContainers() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_getFeatureValue_StructuralFeature() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_getLinkKind_CS_Link_CS_InteractionPoint() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_getLinks_CS_InteractionPoint() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_hasValueForAFeature_Value() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_isDescendant_Interface_Interface() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_isOperationProvided_Reference_Operation() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_isOperationRequired_Reference_Operation() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_realizesInterface_Class_Interface() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_selectTargetsForDispatching_CS_Link_EBoolean() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_selectTargetsForSending_CS_Link_EBoolean() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_sendIn_EventOccurrence_CS_InteractionPoint() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_sendIn_EventOccurrence_Port() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_sendOut_EventOccurrence_CS_InteractionPoint() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_sendOut_EventOccurrence_Port() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_setFeatureValue_StructuralFeature_EInt() const = 0;
			
			// End Class CS_Object


			// Begin Class CS_Reference
			//Class and Feature IDs 
			static const unsigned long CS_REFERENCE_CLASS = 1875601966;
			static const unsigned int CS_REFERENCE_CLASS_FEATURE_COUNT = 2;
			static const unsigned int CS_REFERENCE_CLASS_OPERATION_COUNT = 48;
			
			static const unsigned long CS_REFERENCE_ATTRIBUTE_COMPOSITEREFERENT = 1632489384;
			
			static const unsigned int CS_REFERENCE_OPERATION__COPY = 3174464878;
			static const unsigned int CS_REFERENCE_OPERATION_DISPATCHIN_OPERATION_CS_INTERACTIONPOINT = 2316325302;
			static const unsigned int CS_REFERENCE_OPERATION_DISPATCHIN_OPERATION_PORT = 4067273073;
			static const unsigned int CS_REFERENCE_OPERATION_DISPATCHOUT_OPERATION_PORT = 1439890986;
			static const unsigned int CS_REFERENCE_OPERATION_DISPATCHOUT_OPERATION_CS_INTERACTIONPOINT = 3128939635;
			static const unsigned int CS_REFERENCE_OPERATION_SENDIN_EVENTOCCURRENCE_CS_INTERACTIONPOINT = 4071077650;
			static const unsigned int CS_REFERENCE_OPERATION_SENDIN_EVENTOCCURRENCE_PORT = 548304693;
			static const unsigned int CS_REFERENCE_OPERATION_SENDOUT_EVENTOCCURRENCE_PORT = 2228975302;
			static const unsigned int CS_REFERENCE_OPERATION_SENDOUT_EVENTOCCURRENCE_CS_INTERACTIONPOINT = 4252348295;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_Reference_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getCS_Reference_Attribute_compositeReferent() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getCS_Reference_Operation__copy() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_Reference_Operation_dispatchIn_Operation_CS_InteractionPoint() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_Reference_Operation_dispatchIn_Operation_Port() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_Reference_Operation_dispatchOut_Operation_Port() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_Reference_Operation_dispatchOut_Operation_CS_InteractionPoint() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_Reference_Operation_sendIn_EventOccurrence_CS_InteractionPoint() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_Reference_Operation_sendIn_EventOccurrence_Port() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_Reference_Operation_sendOut_EventOccurrence_Port() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_Reference_Operation_sendOut_EventOccurrence_CS_InteractionPoint() const = 0;
			
			// End Class CS_Reference


			// Begin Class CS_RequestPropagationStrategy
			//Class and Feature IDs 
			static const unsigned long CS_REQUESTPROPAGATIONSTRATEGY_CLASS = 1044958815;
			static const unsigned int CS_REQUESTPROPAGATIONSTRATEGY_CLASS_FEATURE_COUNT = 0;
			static const unsigned int CS_REQUESTPROPAGATIONSTRATEGY_CLASS_OPERATION_COUNT = 3;
			
			
			static const unsigned int CS_REQUESTPROPAGATIONSTRATEGY_OPERATION_GETNAME = 2901676164;
			static const unsigned int CS_REQUESTPROPAGATIONSTRATEGY_OPERATION_SELECT_REFERENCE_SEMANTICVISITOR = 552630845;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_RequestPropagationStrategy_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_RequestPropagationStrategy_Operation_getName() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_RequestPropagationStrategy_Operation_select_Reference_SemanticVisitor() const = 0;
			
			// End Class CS_RequestPropagationStrategy


			// Begin Class CS_StructuralFeatureOfInterfaceAccessStrategy
			//Class and Feature IDs 
			static const unsigned long CS_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_CLASS = 1746875136;
			static const unsigned int CS_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_CLASS_FEATURE_COUNT = 0;
			static const unsigned int CS_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_CLASS_OPERATION_COUNT = 4;
			
			
			static const unsigned int CS_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_OPERATION_GETNAME = 2308162148;
			static const unsigned int CS_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_OPERATION_READ_CS_OBJECT_STRUCTURALFEATURE = 3747474563;
			static const unsigned int CS_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_OPERATION_WRITE_CS_OBJECT_INTEGER = 2987083979;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_StructuralFeatureOfInterfaceAccessStrategy_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_Integer() const = 0;
			
			// End Class CS_StructuralFeatureOfInterfaceAccessStrategy

			static const int CS_LINKKIND_CLASS = 19;
			
			virtual std::shared_ptr<ecore::EEnum> getCS_LinkKind_Class() const = 0;
			

			

			//Singleton Instance and Getter
			private:
				static std::shared_ptr<StructuredClassifiersPackage> instance;
			public:
				static std::shared_ptr<StructuredClassifiersPackage> eInstance();
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_STRUCTUREDCLASSIFIERSPACKAGE_HPP */
