//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CONSIDERIGNOREFRAGMENTCONSIDERIGNOREFRAGMENTIMPL_HPP
#define UML_CONSIDERIGNOREFRAGMENTCONSIDERIGNOREFRAGMENTIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../ConsiderIgnoreFragment.hpp"

#include "uml/impl/CombinedFragmentImpl.hpp"

//*********************************
namespace uml 
{
	class ConsiderIgnoreFragmentImpl :virtual public CombinedFragmentImpl, virtual public ConsiderIgnoreFragment 
	{
		public: 
			ConsiderIgnoreFragmentImpl(const ConsiderIgnoreFragmentImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			ConsiderIgnoreFragmentImpl& operator=(ConsiderIgnoreFragmentImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			ConsiderIgnoreFragmentImpl();
			virtual std::shared_ptr<ConsiderIgnoreFragment> getThisConsiderIgnoreFragmentPtr();
			virtual void setThisConsiderIgnoreFragmentPtr(std::weak_ptr<ConsiderIgnoreFragment> thisConsiderIgnoreFragmentPtr);

			//Additional constructors for the containments back reference
			ConsiderIgnoreFragmentImpl(std::weak_ptr<uml::Interaction > par_enclosingInteraction);


			//Additional constructors for the containments back reference
			ConsiderIgnoreFragmentImpl(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand);


			//Additional constructors for the containments back reference
			ConsiderIgnoreFragmentImpl(std::weak_ptr<uml::Namespace > par_namespace);


			//Additional constructors for the containments back reference
			ConsiderIgnoreFragmentImpl(std::weak_ptr<uml::Element > par_owner);




		public:
			//destructor
			virtual ~ConsiderIgnoreFragmentImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 The interaction operator of a ConsiderIgnoreFragment must be either 'consider' or 'ignore'.
			(interactionOperator =  InteractionOperatorKind::consider) or (interactionOperator =  InteractionOperatorKind::ignore) */ 
			virtual bool consider_or_ignore(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 The NamedElements must be of a type of element that can be a signature for a message (i.e.., an Operation, or a Signal).
			message->forAll(m | m.oclIsKindOf(Operation) or m.oclIsKindOf(Signal)) */ 
			virtual bool type(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 The set of messages that apply to this fragment.
			<p>From package UML::Interactions.</p> */
			virtual std::shared_ptr<Bag<uml::NamedElement>> getMessage() const ;
			
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Namespace > getNamespace() const ;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Element > getOwner() const ; 
			 
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
			std::weak_ptr<ConsiderIgnoreFragment> m_thisConsiderIgnoreFragmentPtr;
	};
}
#endif /* end of include guard: UML_CONSIDERIGNOREFRAGMENTCONSIDERIGNOREFRAGMENTIMPL_HPP */
