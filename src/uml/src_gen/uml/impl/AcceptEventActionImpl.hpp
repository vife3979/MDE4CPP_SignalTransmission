//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_ACCEPTEVENTACTIONACCEPTEVENTACTIONIMPL_HPP
#define UML_ACCEPTEVENTACTIONACCEPTEVENTACTIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../AcceptEventAction.hpp"

#include "uml/impl/ActionImpl.hpp"

//*********************************
namespace uml 
{
	class AcceptEventActionImpl : virtual public ActionImpl, virtual public AcceptEventAction 
	{
		public: 
			AcceptEventActionImpl(const AcceptEventActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			AcceptEventActionImpl& operator=(AcceptEventActionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			AcceptEventActionImpl();
			virtual std::shared_ptr<AcceptEventAction> getThisAcceptEventActionPtr() const;
			virtual void setThisAcceptEventActionPtr(std::weak_ptr<AcceptEventAction> thisAcceptEventActionPtr);

			//Additional constructors for the containments back reference
			AcceptEventActionImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			AcceptEventActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			AcceptEventActionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			AcceptEventActionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~AcceptEventActionImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			If isUnmarshall=false and all the triggers are for SignalEvents, then the type of the single result OutputPin must either be null or all the signals must conform to it.
			not isUnmarshall implies 
				result->isEmpty() or
				let type: Type = result->first().type in
				type=null or 
					(trigger->forAll(event.oclIsKindOf(SignalEvent)) and 
					 trigger.event.oclAsType(SignalEvent).signal->forAll(s | s.conformsTo(type)))
			*/
			 
			virtual bool conforming_type(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			AcceptEventActions may have no input pins.
			input->size() = 0
			*/
			 
			virtual bool no_input_pins(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			There are no OutputPins if the trigger events are only ChangeEvents and/or CallEvents when this action is an instance of AcceptEventAction and not an instance of a descendant of AcceptEventAction (such as AcceptCallAction).
			(self.oclIsTypeOf(AcceptEventAction) and
			   (trigger->forAll(event.oclIsKindOf(ChangeEvent) or  
			                             event.oclIsKindOf(CallEvent))))
			implies output->size() = 0
			*/
			 
			virtual bool no_output_pins(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			If isUnmarshall=false and any of the triggers are for SignalEvents or TimeEvents, there must be exactly one result OutputPin with multiplicity 1..1.
			not isUnmarshall and trigger->exists(event.oclIsKindOf(SignalEvent) or event.oclIsKindOf(TimeEvent)) implies 
				output->size() = 1 and output->first().is(1,1)
			*/
			 
			virtual bool one_output_pin(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			If isUnmarshall is true (and this is not an AcceptCallAction), there must be exactly one trigger, which is for a SignalEvent. The number of result output pins must be the same as the number of attributes of the signal. The type and ordering of each result output pin must be the same as the corresponding attribute of the signal. The multiplicity of each result output pin must be compatible with the multiplicity of the corresponding attribute.
			isUnmarshall and self.oclIsTypeOf(AcceptEventAction) implies
				trigger->size()=1 and
				trigger->asSequence()->first().event.oclIsKindOf(SignalEvent) and
				let attribute: OrderedSet(Property) = trigger->asSequence()->first().event.oclAsType(SignalEvent).signal.allAttributes() in
				attribute->size()>0 and result->size() = attribute->size() and
				Sequence{1..result->size()}->forAll(i | 
					result->at(i).type = attribute->at(i).type and 
					result->at(i).isOrdered = attribute->at(i).isOrdered and
					result->at(i).includesMultiplicity(attribute->at(i)))
			*/
			 
			virtual bool unmarshall_signal_events(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			Indicates whether there is a single OutputPin for a SignalEvent occurrence, or multiple OutputPins for attribute values of the instance of the Signal associated with a SignalEvent occurrence.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual bool getIsUnmarshall() const ;
			/*!
			Indicates whether there is a single OutputPin for a SignalEvent occurrence, or multiple OutputPins for attribute values of the instance of the Signal associated with a SignalEvent occurrence.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual void setIsUnmarshall (bool _isUnmarshall);
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			OutputPins holding the values received from an Event occurrence.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::OutputPin, uml::OutputPin>> getResult() const ;
			
			/*!
			The Triggers specifying the Events of which the AcceptEventAction waits for occurrences.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Trigger, uml::Element>> getTrigger() const ;
			
			
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const ;/*!
			The ordered set of OutputPins representing outputs from the Action.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> getOutput() const ;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const ;/*!
			The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const ; 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************

			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<AcceptEventAction> m_thisAcceptEventActionPtr;
	};
}
#endif /* end of include guard: UML_ACCEPTEVENTACTIONACCEPTEVENTACTIONIMPL_HPP */
