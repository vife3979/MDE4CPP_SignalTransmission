//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_VALUEPINVALUEPINIMPL_HPP
#define UML_VALUEPINVALUEPINIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../ValuePin.hpp"

#include "uml/impl/InputPinImpl.hpp"

//*********************************
namespace uml 
{
	class ValuePinImpl : virtual public InputPinImpl, virtual public ValuePin 
	{
		public: 
			ValuePinImpl(const ValuePinImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ValuePinImpl& operator=(ValuePinImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ValuePinImpl();
			virtual std::shared_ptr<ValuePin> getThisValuePinPtr() const;
			virtual void setThisValuePinPtr(std::weak_ptr<ValuePin> thisValuePinPtr);

			//Additional constructors for the containments back reference
			ValuePinImpl(std::weak_ptr<uml::Action> par_action);
			//Additional constructors for the containments back reference
			ValuePinImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			ValuePinImpl(std::weak_ptr<uml::AddStructuralFeatureValueAction> par_addStructuralFeatureValueAction);
			//Additional constructors for the containments back reference
			ValuePinImpl(std::weak_ptr<uml::CallOperationAction> par_callOperationAction);
			//Additional constructors for the containments back reference
			ValuePinImpl(std::weak_ptr<uml::DestroyObjectAction> par_destroyObjectAction);
			//Additional constructors for the containments back reference
			ValuePinImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			ValuePinImpl(std::weak_ptr<uml::InvocationAction> par_invocationAction);
			//Additional constructors for the containments back reference
			ValuePinImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			ValuePinImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			ValuePinImpl(std::weak_ptr<uml::RemoveStructuralFeatureValueAction> par_removeStructuralFeatureValueAction);
			//Additional constructors for the containments back reference
			ValuePinImpl(std::weak_ptr<uml::StructuralFeatureAction> par_structuralFeatureAction);
			//Additional constructors for the containments back reference
			ValuePinImpl(std::weak_ptr<uml::WriteStructuralFeatureAction> par_writeStructuralFeatureAction);

		public:
			//destructor
			virtual ~ValuePinImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The type of the value ValueSpecification must conform to the type of the ValuePin.
			value.type.conformsTo(type)
			*/
			 
			virtual bool compatible_type(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			A ValuePin may have no incoming ActivityEdges.
			incoming->isEmpty()
			*/
			 
			virtual bool no_incoming_edges(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The ValueSpecification that is evaluated to obtain the value that the ValuePin will provide.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::ValueSpecification> getValue() const ;
			/*!
			The ValueSpecification that is evaluated to obtain the value that the ValuePin will provide.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setValue(std::shared_ptr<uml::ValueSpecification>) ;
			
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const ;/*!
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
			std::weak_ptr<ValuePin> m_thisValuePinPtr;
	};
}
#endif /* end of include guard: UML_VALUEPINVALUEPINIMPL_HPP */
