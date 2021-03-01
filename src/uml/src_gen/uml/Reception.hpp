//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_RECEPTION_HPP
#define UML_RECEPTION_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations

class AnyObject;
typedef std::shared_ptr<AnyObject> Any;

//*********************************
// generated Includes
#include <map> // used for Persistence
#include <vector> // used for Persistence
namespace persistence
{
	namespace interfaces
	{
		class XLoadHandler; // used for Persistence
		class XSaveHandler; // used for Persistence
	}
}

namespace uml
{
	class umlFactory;
}

//Forward Declaration for used types 
namespace uml 
{
	class Behavior;
	class Classifier;
	class Comment;
	class Constraint;
	class Dependency;
	class ElementImport;
	class PackageImport;
	class PackageableElement;
	class Parameter;
	class ParameterSet;
	class Signal;
	class StringExpression;
	class Type;
}

// base class includes
#include "uml/BehavioralFeature.hpp"

// enum includes
#include "uml/CallConcurrencyKind.hpp"

#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A Reception is a declaration stating that a Classifier is prepared to react to the receipt of a Signal.
	<p>From package UML::SimpleClassifiers.</p>
	*/
	
	class Reception: virtual public BehavioralFeature
	{
		public:
 			Reception(const Reception &) {}
		protected:
			Reception(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Reception() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			A Reception has the same name as its signal
			name = signal.name
			*/
			 
			virtual bool same_name_as_signal(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;/*!
			A Reception's parameters match the ownedAttributes of its signal by name, type, and multiplicity
			signal.ownedAttribute->size() = ownedParameter->size() and
			Sequence{1..signal.ownedAttribute->size()}->forAll( i | 
			    ownedParameter->at(i).direction = ParameterDirectionKind::_'in' and 
			    ownedParameter->at(i).name = signal.ownedAttribute->at(i).name and
			    ownedParameter->at(i).type = signal.ownedAttribute->at(i).type and
			    ownedParameter->at(i).lowerBound() = signal.ownedAttribute->at(i).lowerBound() and
			    ownedParameter->at(i).upperBound() = signal.ownedAttribute->at(i).upperBound()
			)
			*/
			 
			virtual bool same_structure_as_signal(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The Signal that this Reception handles.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			virtual std::shared_ptr<uml::Signal> getSignal() const = 0;
			/*!
			The Signal that this Reception handles.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			virtual void setSignal(std::shared_ptr<uml::Signal>) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The Signal that this Reception handles.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			std::shared_ptr<uml::Signal> m_signal;

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::NamedElement>> getMember() const = 0;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;/*!
			A collection of NamedElements owned by the Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> getOwnedMember() const = 0;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: UML_RECEPTION_HPP */
