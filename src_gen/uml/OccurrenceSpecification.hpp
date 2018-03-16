//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_OCCURRENCESPECIFICATION_HPP
#define UML_OCCURRENCESPECIFICATION_HPP

#include <list>
#include <memory>
#include <string>


// forward declarations
template<class T> class Bag;



//*********************************
// generated Includes

#include <map>

namespace persistence
{
	namespace interface
	{
		class XLoadHandler; // used for Persistence
		class XSaveHandler; // used for Persistence
	}
}

namespace uml
{
	class UmlFactory;
}

//Forward Declaration for used types
namespace uml 
{
	class Comment;
}

namespace uml 
{
	class Dependency;
}

namespace ecore 
{
	class EAnnotation;
}

namespace uml 
{
	class Element;
}

namespace uml 
{
	class GeneralOrdering;
}

namespace uml 
{
	class Interaction;
}

namespace uml 
{
	class InteractionFragment;
}

namespace uml 
{
	class InteractionOperand;
}

namespace uml 
{
	class Lifeline;
}

namespace uml 
{
	class Namespace;
}

namespace uml 
{
	class StringExpression;
}

// base class includes
#include "uml/InteractionFragment.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"


//*********************************
namespace uml 
{
	/*!
	 An OccurrenceSpecification is the basic semantic unit of Interactions. The sequences of occurrences specified by them are the meanings of Interactions.
	<p>From package UML::Interactions.</p> */
	class OccurrenceSpecification:virtual public InteractionFragment
	{
		public:
 			OccurrenceSpecification(const OccurrenceSpecification &) {}
			OccurrenceSpecification& operator=(OccurrenceSpecification const&) = delete;

		protected:
			OccurrenceSpecification(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~OccurrenceSpecification() {}

			//*********************************
			// Operations
			//*********************************
			
			
			/*!
			 Sets the Lifeline on which the OccurrenceSpecification appears. */ 
			virtual void setCovered(std::shared_ptr<uml::Lifeline>  value)  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 References the GeneralOrderings that specify EventOcurrences that must occur after this OccurrenceSpecification.
			<p>From package UML::Interactions.</p> */
			virtual std::shared_ptr<Bag<uml::GeneralOrdering>> getToAfter() const = 0;
			
			/*!
			 References the GeneralOrderings that specify EventOcurrences that must occur before this OccurrenceSpecification.
			<p>From package UML::Interactions.</p> */
			virtual std::shared_ptr<Bag<uml::GeneralOrdering>> getToBefore() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 References the GeneralOrderings that specify EventOcurrences that must occur after this OccurrenceSpecification.
			<p>From package UML::Interactions.</p> */
			std::shared_ptr<Bag<uml::GeneralOrdering>> m_toAfter;
			/*!
			 References the GeneralOrderings that specify EventOcurrences that must occur before this OccurrenceSpecification.
			<p>From package UML::Interactions.</p> */
			std::shared_ptr<Bag<uml::GeneralOrdering>> m_toBefore;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Namespace > getNamespace() const = 0;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Element > getOwner() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: UML_OCCURRENCESPECIFICATION_HPP */
