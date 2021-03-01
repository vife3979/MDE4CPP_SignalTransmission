//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_TIMEEXPRESSIONTIMEEXPRESSIONIMPL_HPP
#define UML_TIMEEXPRESSIONTIMEEXPRESSIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../TimeExpression.hpp"

#include "uml/impl/ValueSpecificationImpl.hpp"

//*********************************
namespace uml 
{
	class TimeExpressionImpl : virtual public ValueSpecificationImpl, virtual public TimeExpression 
	{
		public: 
			TimeExpressionImpl(const TimeExpressionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			TimeExpressionImpl& operator=(TimeExpressionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			TimeExpressionImpl();
			virtual std::shared_ptr<TimeExpression> getThisTimeExpressionPtr() const;
			virtual void setThisTimeExpressionPtr(std::weak_ptr<TimeExpression> thisTimeExpressionPtr);

			//Additional constructors for the containments back reference
			TimeExpressionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			TimeExpressionImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			TimeExpressionImpl(std::weak_ptr<uml::Package> par_owningPackage);
			//Additional constructors for the containments back reference
			TimeExpressionImpl(std::weak_ptr<uml::Slot> par_owningSlot);
			//Additional constructors for the containments back reference
			TimeExpressionImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);
			//Additional constructors for the containments back reference
			TimeExpressionImpl(std::weak_ptr<uml::ValueSpecificationAction> par_valueSpecificationAction);

		public:
			//destructor
			virtual ~TimeExpressionImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			If a TimeExpression has no expr, then it must have a single observation that is a TimeObservation.
			expr = null implies (observation->size() = 1 and observation->forAll(oclIsKindOf(TimeObservation)))
			*/
			 
			virtual bool no_expr_requires_observation(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			A ValueSpecification that evaluates to the value of the TimeExpression.
			<p>From package UML::Values.</p>
			*/
			
			virtual std::shared_ptr<uml::ValueSpecification> getExpr() const ;
			/*!
			A ValueSpecification that evaluates to the value of the TimeExpression.
			<p>From package UML::Values.</p>
			*/
			
			virtual void setExpr(std::shared_ptr<uml::ValueSpecification>) ;
			/*!
			Refers to the Observations that are involved in the computation of the TimeExpression value.
			<p>From package UML::Values.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Observation>> getObservation() const ;
			
			
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const ;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const ; 
			 
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
			std::weak_ptr<TimeExpression> m_thisTimeExpressionPtr;
	};
}
#endif /* end of include guard: UML_TIMEEXPRESSIONTIMEEXPRESSIONIMPL_HPP */
