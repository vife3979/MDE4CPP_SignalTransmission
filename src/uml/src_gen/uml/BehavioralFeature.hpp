//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_BEHAVIORALFEATURE_HPP
#define UML_BEHAVIORALFEATURE_HPP

#include <map>
#include <list>
#include <memory>
#include <string>


// forward declarations
template<class T> class Bag;
template<class T, class ... U> class Subset;


class AnyObject;
typedef std::shared_ptr<AnyObject> Any;

//*********************************
// generated Includes

#include <map>

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
	class UmlFactory;
}

//Forward Declaration for used types
namespace uml 
{
	class Behavior;
}

namespace uml 
{
	class Classifier;
}

namespace uml 
{
	class Comment;
}

namespace uml 
{
	class Constraint;
}

namespace uml 
{
	class Dependency;
}

namespace uml 
{
	class Element;
}

namespace uml 
{
	class ElementImport;
}

namespace uml 
{
	class Feature;
}

namespace uml 
{
	class NamedElement;
}

namespace uml 
{
	class Namespace;
}

namespace uml 
{
	class PackageImport;
}

namespace uml 
{
	class PackageableElement;
}

namespace uml 
{
	class Parameter;
}

namespace uml 
{
	class ParameterSet;
}

namespace uml 
{
	class RedefinableElement;
}

namespace uml 
{
	class StringExpression;
}

namespace uml 
{
	class Type;
}

// base class includes
#include "uml/Feature.hpp"

#include "uml/Namespace.hpp"

// enum includes
#include "uml/CallConcurrencyKind.hpp"

#include "uml/VisibilityKind.hpp"


//*********************************
namespace uml 
{
	/*!
	 A BehavioralFeature is a feature of a Classifier that specifies an aspect of the behavior of its instances.  A BehavioralFeature is implemented (realized) by a Behavior. A BehavioralFeature specifies that a Classifier will respond to a designated request by invoking its implementing method.
	<p>From package UML::Classification.</p> */
	class BehavioralFeature:virtual public Feature,virtual public Namespace
	{
		public:
 			BehavioralFeature(const BehavioralFeature &) {}
			BehavioralFeature& operator=(BehavioralFeature const&) = delete;

		protected:
			BehavioralFeature(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~BehavioralFeature() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 When isAbstract is true there are no methods.
			isAbstract implies method->isEmpty() */ 
			virtual bool abstract_no_method(Any diagnostics,std::map <   Any, Any >  context) = 0;
			
			/*!
			 Creates a return result parameter with the specified name and type. */ 
			virtual std::shared_ptr<uml::Parameter> createReturnResult(std::string name,std::shared_ptr<uml::Type>  type) = 0;
			
			/*!
			 The ownedParameters with direction in and inout.
			result = (ownedParameter->select(direction=ParameterDirectionKind::_'in' or direction=ParameterDirectionKind::inout))
			<p>From package UML::Classification.</p> */ 
			virtual std::shared_ptr<Bag<uml::Parameter> > inputParameters() = 0;
			
			/*!
			 The ownedParameters with direction out, inout, or return.
			result = (ownedParameter->select(direction=ParameterDirectionKind::out or direction=ParameterDirectionKind::inout or direction=ParameterDirectionKind::return))
			<p>From package UML::Classification.</p> */ 
			virtual std::shared_ptr<Bag<uml::Parameter> > outputParameters() = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 Specifies the semantics of concurrent calls to the same passive instance (i.e., an instance originating from a Class with isActive being false). Active instances control access to their own BehavioralFeatures.
			<p>From package UML::Classification.</p> */ 
			virtual uml::CallConcurrencyKind getConcurrency() const = 0;
			
			/*!
			 Specifies the semantics of concurrent calls to the same passive instance (i.e., an instance originating from a Class with isActive being false). Active instances control access to their own BehavioralFeatures.
			<p>From package UML::Classification.</p> */ 
			virtual void setConcurrency (uml::CallConcurrencyKind _concurrency)= 0; 
			
			/*!
			 If true, then the BehavioralFeature does not have an implementation, and one must be supplied by a more specific Classifier. If false, the BehavioralFeature must have an implementation in the Classifier or one must be inherited.
			<p>From package UML::Classification.</p> */ 
			virtual bool getIsAbstract() const = 0;
			
			/*!
			 If true, then the BehavioralFeature does not have an implementation, and one must be supplied by a more specific Classifier. If false, the BehavioralFeature must have an implementation in the Classifier or one must be inherited.
			<p>From package UML::Classification.</p> */ 
			virtual void setIsAbstract (bool _isAbstract)= 0; 
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 A Behavior that implements the BehavioralFeature. There may be at most one Behavior for a particular pairing of a Classifier (as owner of the Behavior) and a BehavioralFeature (as specification of the Behavior).
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<Bag<uml::Behavior>> getMethod() const = 0;
			
			/*!
			 The ordered set of formal Parameters of this BehavioralFeature.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<Subset<uml::Parameter, uml::NamedElement>> getOwnedParameter() const = 0;
			
			/*!
			 The ParameterSets owned by this BehavioralFeature.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<Subset<uml::ParameterSet, uml::NamedElement>> getOwnedParameterSet() const = 0;
			
			/*!
			 The Types representing exceptions that may be raised during an invocation of this BehavioralFeature.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<Bag<uml::Type>> getRaisedException() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			 Specifies the semantics of concurrent calls to the same passive instance (i.e., an instance originating from a Class with isActive being false). Active instances control access to their own BehavioralFeatures.
			<p>From package UML::Classification.</p> */ 
			uml::CallConcurrencyKind m_concurrency = CallConcurrencyKind::SEQUENTIAL;
			/*!
			 If true, then the BehavioralFeature does not have an implementation, and one must be supplied by a more specific Classifier. If false, the BehavioralFeature must have an implementation in the Classifier or one must be inherited.
			<p>From package UML::Classification.</p> */ 
			bool m_isAbstract = false;
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 A Behavior that implements the BehavioralFeature. There may be at most one Behavior for a particular pairing of a Classifier (as owner of the Behavior) and a BehavioralFeature (as specification of the Behavior).
			<p>From package UML::Classification.</p> */
			std::shared_ptr<Bag<uml::Behavior>> m_method;
			/*!
			 The ordered set of formal Parameters of this BehavioralFeature.
			<p>From package UML::Classification.</p> */
			std::shared_ptr<Subset<uml::Parameter, uml::NamedElement>> m_ownedParameter;
			/*!
			 The ParameterSets owned by this BehavioralFeature.
			<p>From package UML::Classification.</p> */
			std::shared_ptr<Subset<uml::ParameterSet, uml::NamedElement>> m_ownedParameterSet;
			/*!
			 The Types representing exceptions that may be raised during an invocation of this BehavioralFeature.
			<p>From package UML::Classification.</p> */
			std::shared_ptr<Bag<uml::Type>> m_raisedException;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::NamedElement>> getMember() const = 0;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;/*!
			 A collection of NamedElements owned by the Namespace.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> getOwnedMember() const = 0;/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Element > getOwner() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: UML_BEHAVIORALFEATURE_HPP */
