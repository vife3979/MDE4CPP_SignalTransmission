//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_OUTPUTPINOUTPUTPINIMPL_HPP
#define UML_OUTPUTPINOUTPUTPINIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../OutputPin.hpp"

#include "uml/impl/PinImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API OutputPinImpl : virtual public PinImpl, virtual public OutputPin 
	{
		public: 
			OutputPinImpl(const OutputPinImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			OutputPinImpl& operator=(OutputPinImpl const&); 

		protected:
			friend class umlFactoryImpl;
			OutputPinImpl();
			virtual std::shared_ptr<OutputPin> getThisOutputPinPtr() const;
			virtual void setThisOutputPinPtr(std::weak_ptr<OutputPin> thisOutputPinPtr);

			//Additional constructors for the containments back reference
			OutputPinImpl(std::weak_ptr<uml::Action> par_action);
			//Additional constructors for the containments back reference
			OutputPinImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			OutputPinImpl(std::weak_ptr<uml::CallAction> par_callAction);
			//Additional constructors for the containments back reference
			OutputPinImpl(std::weak_ptr<uml::ClearStructuralFeatureAction> par_clearStructuralFeatureAction);
			//Additional constructors for the containments back reference
			OutputPinImpl(std::weak_ptr<uml::CreateObjectAction> par_createObjectAction);
			//Additional constructors for the containments back reference
			OutputPinImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			OutputPinImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			OutputPinImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			OutputPinImpl(std::weak_ptr<uml::ReadSelfAction> par_readSelfAction);
			//Additional constructors for the containments back reference
			OutputPinImpl(std::weak_ptr<uml::ReadStructuralFeatureAction> par_readStructuralFeatureAction);
			//Additional constructors for the containments back reference
			OutputPinImpl(std::weak_ptr<uml::ValueSpecificationAction> par_valueSpecificationAction);
			//Additional constructors for the containments back reference
			OutputPinImpl(std::weak_ptr<uml::WriteStructuralFeatureAction> par_writeStructuralFeatureAction);

		public:
			//destructor
			virtual ~OutputPinImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			An OutputPin may have incoming ActivityEdges only when it is owned by a StructuredActivityNode, and these edges must have sources contained (directly or indirectly) in the owning StructuredActivityNode.
			incoming->notEmpty() implies
				action<>null and
				action.oclIsKindOf(StructuredActivityNode) and
				action.oclAsType(StructuredActivityNode).allOwnedNodes()->includesAll(incoming.source)
			*/
			 
			virtual bool incoming_edges_structured_only(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::weak_ptr<uml::Action> getAction() const ;
			virtual std::weak_ptr<uml::CallAction> getCallAction() const ;
			virtual void setCallAction(std::weak_ptr<uml::CallAction>) ;
			virtual std::weak_ptr<uml::ClearStructuralFeatureAction> getClearStructuralFeatureAction() const ;
			virtual void setClearStructuralFeatureAction(std::weak_ptr<uml::ClearStructuralFeatureAction>) ;
			virtual std::weak_ptr<uml::CreateObjectAction> getCreateObjectAction() const ;
			virtual void setCreateObjectAction(std::weak_ptr<uml::CreateObjectAction>) ;
			virtual std::weak_ptr<uml::ReadSelfAction> getReadSelfAction() const ;
			virtual void setReadSelfAction(std::weak_ptr<uml::ReadSelfAction>) ;
			virtual std::weak_ptr<uml::ReadStructuralFeatureAction> getReadStructuralFeatureAction() const ;
			virtual void setReadStructuralFeatureAction(std::weak_ptr<uml::ReadStructuralFeatureAction>) ;
			virtual std::weak_ptr<uml::ValueSpecificationAction> getValueSpecificationAction() const ;
			virtual void setValueSpecificationAction(std::weak_ptr<uml::ValueSpecificationAction>) ;
			virtual std::weak_ptr<uml::WriteStructuralFeatureAction> getWriteStructuralFeatureAction() const ;
			virtual void setWriteStructuralFeatureAction(std::weak_ptr<uml::WriteStructuralFeatureAction>) ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const ;
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;
			/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const ;
			/*!
			The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const ;
			
			//*********************************
			// Container Getter
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

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<OutputPin> m_thisOutputPinPtr;
	};
}
#endif /* end of include guard: UML_OUTPUTPINOUTPUTPINIMPL_HPP */
