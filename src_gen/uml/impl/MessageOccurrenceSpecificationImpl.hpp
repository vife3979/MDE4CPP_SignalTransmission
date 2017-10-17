//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_MESSAGEOCCURRENCESPECIFICATIONMESSAGEOCCURRENCESPECIFICATIONIMPL_HPP
#define UML_MESSAGEOCCURRENCESPECIFICATIONMESSAGEOCCURRENCESPECIFICATIONIMPL_HPP

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
#include "../MessageOccurrenceSpecification.hpp"

#include "impl/MessageEndImpl.hpp"
#include "impl/OccurrenceSpecificationImpl.hpp"

#include "SubsetUnion.hpp"



//*********************************
namespace uml 
{
	class MessageOccurrenceSpecificationImpl :virtual public MessageEndImpl, virtual public OccurrenceSpecificationImpl, virtual public MessageOccurrenceSpecification 
	{
		public: 
			MessageOccurrenceSpecificationImpl(const MessageOccurrenceSpecificationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			MessageOccurrenceSpecificationImpl& operator=(MessageOccurrenceSpecificationImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			MessageOccurrenceSpecificationImpl();

			//Additional constructors for the containments back reference
			MessageOccurrenceSpecificationImpl(std::weak_ptr<uml::Interaction > par_enclosingInteraction);


			//Additional constructors for the containments back reference
			MessageOccurrenceSpecificationImpl(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand);


			//Additional constructors for the containments back reference
			MessageOccurrenceSpecificationImpl(std::weak_ptr<uml::Namespace > par_namespace);


			//Additional constructors for the containments back reference
			MessageOccurrenceSpecificationImpl(std::weak_ptr<uml::Element > par_owner);




		public:
			//destructor
			virtual ~MessageOccurrenceSpecificationImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
							
			
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
#endif /* end of include guard: UML_MESSAGEOCCURRENCESPECIFICATIONMESSAGEOCCURRENCESPECIFICATIONIMPL_HPP */

