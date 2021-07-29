//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_COMMONBEHAVIORPACKAGE_HPP
#define FUML_SEMANTICS_COMMONBEHAVIORPACKAGE_HPP

// namespace macro header include
#include "fUML/fUML.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EAnnotation;
	class EAttribute;
	class EClass;
	class EDataType;
	class EGenericType;
	class EOperation;
	class EParameter;
	class EReference;
	class EStringToStringMapEntry;
}

namespace fUML::Semantics::CommonBehavior 
{
	class CallEventBehavior;
	class CallEventExecution;
	class CallEventOccurrence;
	class ClassifierBehaviorExecution;
	class ClassifierBehaviorInvocationEventAccepter;
	class EventAccepter;
	class EventDispatchLoop;
	class EventOccurrence;
	class Execution;
	class FIFOGetNextEventStrategy;
	class GetNextEventStrategy;
	class InvocationEventOccurrence;
	class ObjectActivation;
	class OpaqueBehaviorExecution;
	class ParameterValue;
	class SignalEventOccurrence;
}
 
namespace fUML::Semantics::CommonBehavior 
{
	/*!
	The Metamodel Package for the CommonBehavior metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class FUML_API CommonBehaviorPackage : virtual public ecore::EPackage 
	{
		private:    
			CommonBehaviorPackage(CommonBehaviorPackage const&) = delete;
			CommonBehaviorPackage& operator=(CommonBehaviorPackage const&) = delete;

		protected:
			CommonBehaviorPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			// Begin Class CallEventBehavior
			//Class and Feature IDs 
			static const long long CALLEVENTBEHAVIOR_CLASS = 3715801;
			static const unsigned int CALLEVENTBEHAVIOR_CLASS_FEATURE_COUNT = 1;
			static const unsigned int CALLEVENTBEHAVIOR_CLASS_OPERATION_COUNT = 1;
			
			static const long long CALLEVENTBEHAVIOR_ATTRIBUTE_OPERATION = 1230758055;
			
			static const int CALLEVENTBEHAVIOR_OPERATION_ASSIGNOPERATION_OPERATION = 155240255;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCallEventBehavior_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getCallEventBehavior_Attribute_operation() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getCallEventBehavior_Operation_assignOperation_Operation() const = 0;
			
			// End Class CallEventBehavior


			// Begin Class CallEventExecution
			//Class and Feature IDs 
			static const long long CALLEVENTEXECUTION_CLASS = 1815999052;
			static const unsigned int CALLEVENTEXECUTION_CLASS_FEATURE_COUNT = 8;
			static const unsigned int CALLEVENTEXECUTION_CLASS_OPERATION_COUNT = 56;
			static const long long CALLEVENTEXECUTION_ATTRIBUTE_CALLERSUSPENDED = 384714071;
			
			
			static const int CALLEVENTEXECUTION_OPERATION__COPY = 365434602;
			static const int CALLEVENTEXECUTION_OPERATION_CREATEEVENTOCCURRENCE = 1037240855;
			static const int CALLEVENTEXECUTION_OPERATION_EXECUTE = 1955768148;
			static const int CALLEVENTEXECUTION_OPERATION_GETINPUTPARAMETERVALUES = 1409780026;
			static const int CALLEVENTEXECUTION_OPERATION_GETOPERATION = 112595245;
			static const int CALLEVENTEXECUTION_OPERATION_ISCALLERSUSPENDED = 1912744245;
			static const int CALLEVENTEXECUTION_OPERATION_MAKECALL = 2136758151;
			static const int CALLEVENTEXECUTION_OPERATION_NEW_ = 774092792;
			static const int CALLEVENTEXECUTION_OPERATION_RELEASECALLER = 590616214;
			static const int CALLEVENTEXECUTION_OPERATION_SETOUTPUTPARAMETERVALUES_PARAMETERVALUE = 1245179222;
			static const int CALLEVENTEXECUTION_OPERATION_SUSPENDCALLER = 310021980;
			static const int CALLEVENTEXECUTION_OPERATION_WAIT_ = 1324700976;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCallEventExecution_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getCallEventExecution_Attribute_callerSuspended() const = 0;
			
			
			virtual std::shared_ptr<ecore::EOperation> getCallEventExecution_Operation__copy() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallEventExecution_Operation_createEventOccurrence() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallEventExecution_Operation_execute() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallEventExecution_Operation_getInputParameterValues() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallEventExecution_Operation_getOperation() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallEventExecution_Operation_isCallerSuspended() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallEventExecution_Operation_makeCall() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallEventExecution_Operation_new_() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallEventExecution_Operation_releaseCaller() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallEventExecution_Operation_setOutputParameterValues_ParameterValue() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallEventExecution_Operation_suspendCaller() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallEventExecution_Operation_wait_() const = 0;
			
			// End Class CallEventExecution


			// Begin Class CallEventOccurrence
			//Class and Feature IDs 
			static const long long CALLEVENTOCCURRENCE_CLASS = 1651938494;
			static const unsigned int CALLEVENTOCCURRENCE_CLASS_FEATURE_COUNT = 2;
			static const unsigned int CALLEVENTOCCURRENCE_CLASS_OPERATION_COUNT = 10;
			
			static const long long CALLEVENTOCCURRENCE_ATTRIBUTE_EXECUTION = 1485285345;
			
			static const int CALLEVENTOCCURRENCE_OPERATION_GETOPERATION = 112595245;
			static const int CALLEVENTOCCURRENCE_OPERATION_GETPARAMETERVALUES = 788216257;
			static const int CALLEVENTOCCURRENCE_OPERATION_MATCH_TRIGGER = 934614501;
			static const int CALLEVENTOCCURRENCE_OPERATION_RELEASECALLER = 590616214;
			static const int CALLEVENTOCCURRENCE_OPERATION_SETOUTPUTPARAMETERVALUES_PARAMETERVALUE = 1245179222;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCallEventOccurrence_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getCallEventOccurrence_Attribute_execution() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getCallEventOccurrence_Operation_getOperation() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallEventOccurrence_Operation_getParameterValues() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallEventOccurrence_Operation_match_Trigger() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallEventOccurrence_Operation_releaseCaller() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallEventOccurrence_Operation_setOutputParameterValues_ParameterValue() const = 0;
			
			// End Class CallEventOccurrence


			// Begin Class ClassifierBehaviorExecution
			//Class and Feature IDs 
			static const long long CLASSIFIERBEHAVIOREXECUTION_CLASS = 1551835842;
			static const unsigned int CLASSIFIERBEHAVIOREXECUTION_CLASS_FEATURE_COUNT = 3;
			static const unsigned int CLASSIFIERBEHAVIOREXECUTION_CLASS_OPERATION_COUNT = 3;
			
			static const long long CLASSIFIERBEHAVIOREXECUTION_ATTRIBUTE_CLASSIFIER = 1878160875;
			static const long long CLASSIFIERBEHAVIOREXECUTION_ATTRIBUTE_EXECUTION = 1485285345;
			static const long long CLASSIFIERBEHAVIOREXECUTION_ATTRIBUTE_OBJECTACTIVATION = 169916866;
			
			static const int CLASSIFIERBEHAVIOREXECUTION_OPERATION__STARTOBJECTBEHAVIOR = 681115547;
			static const int CLASSIFIERBEHAVIOREXECUTION_OPERATION_EXECUTE_CLASS_PARAMETERVALUE = 558444606;
			static const int CLASSIFIERBEHAVIOREXECUTION_OPERATION_TERMINATE = 1906802226;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getClassifierBehaviorExecution_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getClassifierBehaviorExecution_Attribute_classifier() const = 0;
			virtual std::shared_ptr<ecore::EReference> getClassifierBehaviorExecution_Attribute_execution() const = 0;
			virtual std::shared_ptr<ecore::EReference> getClassifierBehaviorExecution_Attribute_objectActivation() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getClassifierBehaviorExecution_Operation__startObjectBehavior() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getClassifierBehaviorExecution_Operation_execute_Class_ParameterValue() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getClassifierBehaviorExecution_Operation_terminate() const = 0;
			
			// End Class ClassifierBehaviorExecution


			// Begin Class ClassifierBehaviorInvocationEventAccepter
			//Class and Feature IDs 
			static const long long CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_CLASS = 165051968;
			static const unsigned int CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_CLASS_FEATURE_COUNT = 3;
			static const unsigned int CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_CLASS_OPERATION_COUNT = 6;
			
			static const long long CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_ATTRIBUTE_CLASSIFIER = 1878160875;
			static const long long CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_ATTRIBUTE_EXECUTION = 1485285345;
			static const long long CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_ATTRIBUTE_OBJECTACTIVATION = 169916866;
			
			static const int CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_OPERATION_ACCEPT_EVENTOCCURRENCE = 1585689486;
			static const int CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_OPERATION_INVOKEBEHAVIOR_CLASS_PARAMETERVALUE = 1878643851;
			static const int CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_OPERATION_MATCH_EVENTOCCURRENCE = 1928562931;
			static const int CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_OPERATION_TERMINATE = 1906802226;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getClassifierBehaviorInvocationEventAccepter_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getClassifierBehaviorInvocationEventAccepter_Attribute_classifier() const = 0;
			virtual std::shared_ptr<ecore::EReference> getClassifierBehaviorInvocationEventAccepter_Attribute_execution() const = 0;
			virtual std::shared_ptr<ecore::EReference> getClassifierBehaviorInvocationEventAccepter_Attribute_objectActivation() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getClassifierBehaviorInvocationEventAccepter_Operation_accept_EventOccurrence() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getClassifierBehaviorInvocationEventAccepter_Operation_invokeBehavior_Class_ParameterValue() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getClassifierBehaviorInvocationEventAccepter_Operation_match_EventOccurrence() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getClassifierBehaviorInvocationEventAccepter_Operation_terminate() const = 0;
			
			// End Class ClassifierBehaviorInvocationEventAccepter


			// Begin Class EventAccepter
			//Class and Feature IDs 
			static const long long EVENTACCEPTER_CLASS = 720513438;
			static const unsigned int EVENTACCEPTER_CLASS_FEATURE_COUNT = 0;
			static const unsigned int EVENTACCEPTER_CLASS_OPERATION_COUNT = 2;
			
			
			static const int EVENTACCEPTER_OPERATION_ACCEPT_SIGNALINSTANCE = 214110413;
			static const int EVENTACCEPTER_OPERATION_MATCH_SIGNALINSTANCE = 878562459;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEventAccepter_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getEventAccepter_Operation_accept_SignalInstance() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEventAccepter_Operation_match_SignalInstance() const = 0;
			
			// End Class EventAccepter


			// Begin Class EventDispatchLoop
			//Class and Feature IDs 
			static const long long EVENTDISPATCHLOOP_CLASS = 1354650361;
			static const unsigned int EVENTDISPATCHLOOP_CLASS_FEATURE_COUNT = 0;
			static const unsigned int EVENTDISPATCHLOOP_CLASS_OPERATION_COUNT = 0;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEventDispatchLoop_Class() const = 0;
			
			
			
			
			// End Class EventDispatchLoop


			// Begin Class EventOccurrence
			//Class and Feature IDs 
			static const long long EVENTOCCURRENCE_CLASS = 1863789533;
			static const unsigned int EVENTOCCURRENCE_CLASS_FEATURE_COUNT = 1;
			static const unsigned int EVENTOCCURRENCE_CLASS_OPERATION_COUNT = 5;
			
			static const long long EVENTOCCURRENCE_ATTRIBUTE_TARGET = 1323838518;
			
			static const int EVENTOCCURRENCE_OPERATION_DOSEND = 1562634019;
			static const int EVENTOCCURRENCE_OPERATION_GETPARAMETERVALUES = 788216257;
			static const int EVENTOCCURRENCE_OPERATION_MATCH_TRIGGER = 934614501;
			static const int EVENTOCCURRENCE_OPERATION_MATCHANY_TRIGGER = 1110681855;
			static const int EVENTOCCURRENCE_OPERATION_SENDTO_REFERENCE = 390090762;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEventOccurrence_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getEventOccurrence_Attribute_target() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getEventOccurrence_Operation_doSend() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEventOccurrence_Operation_getParameterValues() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEventOccurrence_Operation_match_Trigger() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEventOccurrence_Operation_matchAny_Trigger() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEventOccurrence_Operation_sendTo_Reference() const = 0;
			
			// End Class EventOccurrence


			// Begin Class Execution
			//Class and Feature IDs 
			static const long long EXECUTION_CLASS = 921905715;
			static const unsigned int EXECUTION_CLASS_FEATURE_COUNT = 7;
			static const unsigned int EXECUTION_CLASS_OPERATION_COUNT = 44;
			
			static const long long EXECUTION_ATTRIBUTE_BEHAVIOR = 765607700;
			static const long long EXECUTION_ATTRIBUTE_CONTEXT = 1470700146;
			static const long long EXECUTION_ATTRIBUTE_PARAMETERVALUES = 750810245;
			
			static const int EXECUTION_OPERATION__COPY = 365434602;
			static const int EXECUTION_OPERATION_EXECUTE = 1955768148;
			static const int EXECUTION_OPERATION_GETBEHAVIOR = 1159250533;
			static const int EXECUTION_OPERATION_GETOUTPUTPARAMETERVALUES = 1909090304;
			static const int EXECUTION_OPERATION_GETPARAMETERVALUE_PARAMETER = 1608001909;
			static const int EXECUTION_OPERATION_NEW_ = 774092792;
			static const int EXECUTION_OPERATION_SETPARAMETERVALUE_PARAMETERVALUE = 871130390;
			static const int EXECUTION_OPERATION_TERMINATE = 1906802226;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getExecution_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getExecution_Attribute_behavior() const = 0;
			virtual std::shared_ptr<ecore::EReference> getExecution_Attribute_context() const = 0;
			virtual std::shared_ptr<ecore::EReference> getExecution_Attribute_parameterValues() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getExecution_Operation__copy() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecution_Operation_execute() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecution_Operation_getBehavior() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecution_Operation_getOutputParameterValues() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecution_Operation_getParameterValue_Parameter() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecution_Operation_new_() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecution_Operation_setParameterValue_ParameterValue() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecution_Operation_terminate() const = 0;
			
			// End Class Execution


			// Begin Class FIFOGetNextEventStrategy
			//Class and Feature IDs 
			static const long long FIFOGETNEXTEVENTSTRATEGY_CLASS = 860953508;
			static const unsigned int FIFOGETNEXTEVENTSTRATEGY_CLASS_FEATURE_COUNT = 0;
			static const unsigned int FIFOGETNEXTEVENTSTRATEGY_CLASS_OPERATION_COUNT = 3;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getFIFOGetNextEventStrategy_Class() const = 0;
			
			
			
			
			// End Class FIFOGetNextEventStrategy


			// Begin Class GetNextEventStrategy
			//Class and Feature IDs 
			static const long long GETNEXTEVENTSTRATEGY_CLASS = 2103787987;
			static const unsigned int GETNEXTEVENTSTRATEGY_CLASS_FEATURE_COUNT = 0;
			static const unsigned int GETNEXTEVENTSTRATEGY_CLASS_OPERATION_COUNT = 3;
			
			
			static const int GETNEXTEVENTSTRATEGY_OPERATION_GETNAME = 1609505757;
			static const int GETNEXTEVENTSTRATEGY_OPERATION_RETRIEVENEXTEVENT_OBJECTACTIVATION = 1328738124;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getGetNextEventStrategy_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getGetNextEventStrategy_Operation_getName() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getGetNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation() const = 0;
			
			// End Class GetNextEventStrategy


			// Begin Class InvocationEventOccurrence
			//Class and Feature IDs 
			static const long long INVOCATIONEVENTOCCURRENCE_CLASS = 1468408266;
			static const unsigned int INVOCATIONEVENTOCCURRENCE_CLASS_FEATURE_COUNT = 2;
			static const unsigned int INVOCATIONEVENTOCCURRENCE_CLASS_OPERATION_COUNT = 7;
			
			static const long long INVOCATIONEVENTOCCURRENCE_ATTRIBUTE_EXECUTION = 1485285345;
			
			static const int INVOCATIONEVENTOCCURRENCE_OPERATION_GETPARAMETERVALUES = 788216257;
			static const int INVOCATIONEVENTOCCURRENCE_OPERATION_MATCH_TRIGGER = 934614501;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getInvocationEventOccurrence_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getInvocationEventOccurrence_Attribute_execution() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getInvocationEventOccurrence_Operation_getParameterValues() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getInvocationEventOccurrence_Operation_match_Trigger() const = 0;
			
			// End Class InvocationEventOccurrence


			// Begin Class ObjectActivation
			//Class and Feature IDs 
			static const long long OBJECTACTIVATION_CLASS = 1754020883;
			static const unsigned int OBJECTACTIVATION_CLASS_FEATURE_COUNT = 4;
			static const unsigned int OBJECTACTIVATION_CLASS_OPERATION_COUNT = 9;
			
			static const long long OBJECTACTIVATION_ATTRIBUTE_CLASSIFIERBEHAVIOREXECUTIONS = 127140702;
			static const long long OBJECTACTIVATION_ATTRIBUTE_EVENTPOOL = 1955117661;
			static const long long OBJECTACTIVATION_ATTRIBUTE_OBJECT = 1402854008;
			static const long long OBJECTACTIVATION_ATTRIBUTE_WAITINGEVENTACCEPTERS = 1885401111;
			
			static const int OBJECTACTIVATION_OPERATION__REGISTER_EVENTACCEPTER = 807410903;
			static const int OBJECTACTIVATION_OPERATION__SEND_EJAVAOBJECT = 1213347731;
			static const int OBJECTACTIVATION_OPERATION__STARTOBJECTBEHAVIOR = 681115547;
			static const int OBJECTACTIVATION_OPERATION_DISPATCHNEXTEVENT = 2143939712;
			static const int OBJECTACTIVATION_OPERATION_RETRIEVENEXTEVENT = 534163045;
			static const int OBJECTACTIVATION_OPERATION_SEND_SIGNALINSTANCE = 296191803;
			static const int OBJECTACTIVATION_OPERATION_STARTBEHAVIOR_CLASS_PARAMETERVALUE = 511415934;
			static const int OBJECTACTIVATION_OPERATION_STOP = 1111078337;
			static const int OBJECTACTIVATION_OPERATION_UNREGISTER_EVENTACCEPTER = 842618335;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getObjectActivation_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getObjectActivation_Attribute_classifierBehaviorExecutions() const = 0;
			virtual std::shared_ptr<ecore::EReference> getObjectActivation_Attribute_eventPool() const = 0;
			virtual std::shared_ptr<ecore::EReference> getObjectActivation_Attribute_object() const = 0;
			virtual std::shared_ptr<ecore::EReference> getObjectActivation_Attribute_waitingEventAccepters() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getObjectActivation_Operation__register_EventAccepter() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getObjectActivation_Operation__send_EJavaObject() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getObjectActivation_Operation__startObjectBehavior() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getObjectActivation_Operation_dispatchNextEvent() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getObjectActivation_Operation_retrieveNextEvent() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getObjectActivation_Operation_send_SignalInstance() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getObjectActivation_Operation_startBehavior_Class_ParameterValue() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getObjectActivation_Operation_stop() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getObjectActivation_Operation_unregister_EventAccepter() const = 0;
			
			// End Class ObjectActivation


			// Begin Class OpaqueBehaviorExecution
			//Class and Feature IDs 
			static const long long OPAQUEBEHAVIOREXECUTION_CLASS = 1247403081;
			static const unsigned int OPAQUEBEHAVIOREXECUTION_CLASS_FEATURE_COUNT = 7;
			static const unsigned int OPAQUEBEHAVIOREXECUTION_CLASS_OPERATION_COUNT = 46;
			
			
			static const int OPAQUEBEHAVIOREXECUTION_OPERATION_DOBODY_PARAMETERVALUE_PARAMETERVALUE = 74510588;
			static const int OPAQUEBEHAVIOREXECUTION_OPERATION_EXECUTE = 1955768148;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getOpaqueBehaviorExecution_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getOpaqueBehaviorExecution_Operation_doBody_ParameterValue_ParameterValue() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getOpaqueBehaviorExecution_Operation_execute() const = 0;
			
			// End Class OpaqueBehaviorExecution


			// Begin Class ParameterValue
			//Class and Feature IDs 
			static const long long PARAMETERVALUE_CLASS = 1804530160;
			static const unsigned int PARAMETERVALUE_CLASS_FEATURE_COUNT = 2;
			static const unsigned int PARAMETERVALUE_CLASS_OPERATION_COUNT = 1;
			
			static const long long PARAMETERVALUE_ATTRIBUTE_PARAMETER = 2094753783;
			static const long long PARAMETERVALUE_ATTRIBUTE_VALUES = 618518159;
			
			static const int PARAMETERVALUE_OPERATION__COPY = 858179039;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getParameterValue_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getParameterValue_Attribute_parameter() const = 0;
			virtual std::shared_ptr<ecore::EReference> getParameterValue_Attribute_values() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getParameterValue_Operation__copy() const = 0;
			
			// End Class ParameterValue


			// Begin Class SignalEventOccurrence
			//Class and Feature IDs 
			static const long long SIGNALEVENTOCCURRENCE_CLASS = 1277756023;
			static const unsigned int SIGNALEVENTOCCURRENCE_CLASS_FEATURE_COUNT = 2;
			static const unsigned int SIGNALEVENTOCCURRENCE_CLASS_OPERATION_COUNT = 7;
			
			static const long long SIGNALEVENTOCCURRENCE_ATTRIBUTE_SIGNALINSTANCE = 1849742418;
			
			static const int SIGNALEVENTOCCURRENCE_OPERATION_GETPARAMETERVALUES = 788216257;
			static const int SIGNALEVENTOCCURRENCE_OPERATION_MATCH_TRIGGER = 934614501;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getSignalEventOccurrence_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getSignalEventOccurrence_Attribute_signalInstance() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getSignalEventOccurrence_Operation_getParameterValues() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getSignalEventOccurrence_Operation_match_Trigger() const = 0;
			
			// End Class SignalEventOccurrence

			
			

			

			//Singleton Instance and Getter
			private:
				static std::shared_ptr<CommonBehaviorPackage> instance;
			public:
				static std::shared_ptr<CommonBehaviorPackage> eInstance();
	};
}
#endif /* end of include guard: FUML_SEMANTICS_COMMONBEHAVIORPACKAGE_HPP */
