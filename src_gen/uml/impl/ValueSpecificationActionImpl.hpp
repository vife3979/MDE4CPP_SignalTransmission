//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_VALUESPECIFICATIONACTIONVALUESPECIFICATIONACTIONIMPL_HPP
#define UML_VALUESPECIFICATIONACTIONVALUESPECIFICATIONACTIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../ValueSpecificationAction.hpp"

#include "uml/impl/ActionImpl.hpp"

//*********************************
namespace uml 
{
	class ValueSpecificationActionImpl :virtual public ActionImpl, virtual public ValueSpecificationAction 
	{
		public: 
			ValueSpecificationActionImpl(const ValueSpecificationActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			ValueSpecificationActionImpl& operator=(ValueSpecificationActionImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			ValueSpecificationActionImpl();
			virtual std::shared_ptr<ValueSpecificationAction> getThisValueSpecificationActionPtr();
			virtual void setThisValueSpecificationActionPtr(std::weak_ptr<ValueSpecificationAction> thisValueSpecificationActionPtr);

			//Additional constructors for the containments back reference
			ValueSpecificationActionImpl(std::weak_ptr<uml::Activity > par_activity);


			//Additional constructors for the containments back reference
			ValueSpecificationActionImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode);


			//Additional constructors for the containments back reference
			ValueSpecificationActionImpl(std::weak_ptr<uml::Namespace > par_namespace);


			//Additional constructors for the containments back reference
			ValueSpecificationActionImpl(std::weak_ptr<uml::Element > par_owner);




		public:
			//destructor
			virtual ~ValueSpecificationActionImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 The type of the value ValueSpecification must conform to the type of the result OutputPin.
			value.type.conformsTo(result.type) */ 
			virtual bool compatible_type(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 The multiplicity of the result OutputPin is 1..1
			result.is(1,1) */ 
			virtual bool multiplicity(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 The OutputPin on which the result value is placed.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<uml::OutputPin > getResult() const ;
			
			/*!
			 The OutputPin on which the result value is placed.
			<p>From package UML::Actions.</p> */
			virtual void setResult(std::shared_ptr<uml::OutputPin> _result_result) ;
			/*!
			 The ValueSpecification to be evaluated.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<uml::ValueSpecification > getValue() const ;
			
			/*!
			 The ValueSpecification to be evaluated.
			<p>From package UML::Actions.</p> */
			virtual void setValue(std::shared_ptr<uml::ValueSpecification> _value_value) ;
							
			
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
			std::weak_ptr<ValueSpecificationAction> m_thisValueSpecificationActionPtr;
	};
}
#endif /* end of include guard: UML_VALUESPECIFICATIONACTIONVALUESPECIFICATIONACTIONIMPL_HPP */
