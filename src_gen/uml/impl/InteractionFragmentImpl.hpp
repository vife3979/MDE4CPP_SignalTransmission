//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INTERACTIONFRAGMENTINTERACTIONFRAGMENTIMPL_HPP
#define UML_INTERACTIONFRAGMENTINTERACTIONFRAGMENTIMPL_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//*********************************
// generated Includes

//Model includes
#include "../InteractionFragment.hpp"

#include "impl/NamedElementImpl.hpp"

#include "SubsetUnion.hpp"



//*********************************
namespace uml 
{
	class InteractionFragmentImpl :virtual public NamedElementImpl, virtual public InteractionFragment 
	{
		public: 
			InteractionFragmentImpl(const InteractionFragmentImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			InteractionFragmentImpl& operator=(InteractionFragmentImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			InteractionFragmentImpl();

			//Additional constructors for the containments back reference
			InteractionFragmentImpl(std::weak_ptr<uml::Interaction > par_enclosingInteraction);


			//Additional constructors for the containments back reference
			InteractionFragmentImpl(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand);


			//Additional constructors for the containments back reference
			InteractionFragmentImpl(std::weak_ptr<uml::Namespace > par_namespace);


			//Additional constructors for the containments back reference
			InteractionFragmentImpl(std::weak_ptr<uml::Element > par_owner);




		public:
			//destructor
			virtual ~InteractionFragmentImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 References the Lifelines that the InteractionFragment involves.
			<p>From package UML::Interactions.</p> */
			virtual std::shared_ptr< Bag<uml::Lifeline> > getCovered() const ;
			
			/*!
			 The Interaction enclosing this InteractionFragment.
			<p>From package UML::Interactions.</p> */
			virtual std::weak_ptr<uml::Interaction > getEnclosingInteraction() const ;
			
			/*!
			 The Interaction enclosing this InteractionFragment.
			<p>From package UML::Interactions.</p> */
			virtual void setEnclosingInteraction(std::shared_ptr<uml::Interaction> _enclosingInteraction_enclosingInteraction) ;
			/*!
			 The operand enclosing this InteractionFragment (they may nest recursively).
			<p>From package UML::Interactions.</p> */
			virtual std::weak_ptr<uml::InteractionOperand > getEnclosingOperand() const ;
			
			/*!
			 The operand enclosing this InteractionFragment (they may nest recursively).
			<p>From package UML::Interactions.</p> */
			virtual void setEnclosingOperand(std::shared_ptr<uml::InteractionOperand> _enclosingOperand_enclosingOperand) ;
			/*!
			 The general ordering relationships contained in this fragment.
			<p>From package UML::Interactions.</p> */
			virtual std::shared_ptr<Subset<uml::GeneralOrdering, uml::Element > > getGeneralOrdering() const ;
			
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Namespace > getNamespace() const ;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::Element> > getOwnedElement() const ;/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Element > getOwner() const ; 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
			
			virtual boost::any eGet(int featureID, bool resolve, bool coreType) const ;
			
		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
	};
}
#endif /* end of include guard: UML_INTERACTIONFRAGMENTINTERACTIONFRAGMENTIMPL_HPP */

