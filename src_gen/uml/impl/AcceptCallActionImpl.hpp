//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_ACCEPTCALLACTIONACCEPTCALLACTIONIMPL_HPP
#define UML_ACCEPTCALLACTIONACCEPTCALLACTIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../AcceptCallAction.hpp"

#include "uml/impl/AcceptEventActionImpl.hpp"

//*********************************
namespace uml 
{
	class AcceptCallActionImpl :virtual public AcceptEventActionImpl, virtual public AcceptCallAction 
	{
		public: 
			AcceptCallActionImpl(const AcceptCallActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			AcceptCallActionImpl& operator=(AcceptCallActionImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			AcceptCallActionImpl();
			virtual std::shared_ptr<AcceptCallAction> getThisAcceptCallActionPtr();
			virtual void setThisAcceptCallActionPtr(std::weak_ptr<AcceptCallAction> thisAcceptCallActionPtr);

			//Additional constructors for the containments back reference
			AcceptCallActionImpl(std::weak_ptr<uml::Activity > par_activity);


			//Additional constructors for the containments back reference
			AcceptCallActionImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode);


			//Additional constructors for the containments back reference
			AcceptCallActionImpl(std::weak_ptr<uml::Namespace > par_namespace);


			//Additional constructors for the containments back reference
			AcceptCallActionImpl(std::weak_ptr<uml::Element > par_owner);




		public:
			//destructor
			virtual ~AcceptCallActionImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 The number of result OutputPins must be the same as the number of input (in and inout) ownedParameters of the Operation specified by the trigger Event. The type, ordering and multiplicity of each result OutputPin must be consistent with the corresponding input Parameter.
			let parameter: OrderedSet(Parameter) = trigger.event->asSequence()->first().oclAsType(CallEvent).operation.inputParameters() in
			result->size() = parameter->size() and
			Sequence{1..result->size()}->forAll(i | 
				parameter->at(i).type.conformsTo(result->at(i).type) and 
				parameter->at(i).isOrdered = result->at(i).isOrdered and
				parameter->at(i).compatibleWith(result->at(i))) */ 
			virtual bool result_pins(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 The action must have exactly one trigger, which must be for a CallEvent.
			trigger->size()=1 and
			trigger->asSequence()->first().event.oclIsKindOf(CallEvent) */ 
			virtual bool trigger_call_event(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 isUnmrashall must be true for an AcceptCallAction.
			isUnmarshall = true */ 
			virtual bool unmarshall(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 An OutputPin where a value is placed containing sufficient information to perform a subsequent ReplyAction and return control to the caller. The contents of this value are opaque. It can be passed and copied but it cannot be manipulated by the model.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<uml::OutputPin > getReturnInformation() const ;
			
			/*!
			 An OutputPin where a value is placed containing sufficient information to perform a subsequent ReplyAction and return control to the caller. The contents of this value are opaque. It can be passed and copied but it cannot be manipulated by the model.
			<p>From package UML::Actions.</p> */
			virtual void setReturnInformation(std::shared_ptr<uml::OutputPin> _returnInformation_returnInformation) ;
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p> */
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const ;/*!
			 The ordered set of OutputPins representing outputs from the Action.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> getOutput() const ;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Element > getOwner() const ;/*!
			 The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const ; 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************

			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interface::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual boost::any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, boost::any newValue) ;

		private:
			std::weak_ptr<AcceptCallAction> m_thisAcceptCallActionPtr;
	};
}
#endif /* end of include guard: UML_ACCEPTCALLACTIONACCEPTCALLACTIONIMPL_HPP */
