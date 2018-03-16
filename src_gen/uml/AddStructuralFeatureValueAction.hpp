//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_ADDSTRUCTURALFEATUREVALUEACTION_HPP
#define UML_ADDSTRUCTURALFEATUREVALUEACTION_HPP

#include <map>
#include <list>
#include <memory>
#include <string>


// forward declarations
template<class T, class ... U> class Subset;


namespace boost
{
	class any;
}

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
	class Activity;
}

namespace uml 
{
	class ActivityEdge;
}

namespace uml 
{
	class ActivityGroup;
}

namespace uml 
{
	class ActivityNode;
}

namespace uml 
{
	class ActivityPartition;
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
	class ExceptionHandler;
}

namespace uml 
{
	class InputPin;
}

namespace uml 
{
	class InterruptibleActivityRegion;
}

namespace uml 
{
	class Namespace;
}

namespace uml 
{
	class OutputPin;
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
	class StructuralFeature;
}

namespace uml 
{
	class StructuredActivityNode;
}

namespace uml 
{
	class WriteStructuralFeatureAction;
}

// base class includes
#include "uml/WriteStructuralFeatureAction.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"


//*********************************
namespace uml 
{
	/*!
	 An AddStructuralFeatureValueAction is a WriteStructuralFeatureAction for adding values to a StructuralFeature.
	<p>From package UML::Actions.</p> */
	class AddStructuralFeatureValueAction:virtual public WriteStructuralFeatureAction
	{
		public:
 			AddStructuralFeatureValueAction(const AddStructuralFeatureValueAction &) {}
			AddStructuralFeatureValueAction& operator=(AddStructuralFeatureValueAction const&) = delete;

		protected:
			AddStructuralFeatureValueAction(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~AddStructuralFeatureValueAction() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 AddStructuralFeatureActions adding a value to ordered StructuralFeatures must have a single InputPin for the insertion point with type UnlimitedNatural and multiplicity of 1..1 if isReplaceAll=false, and must have no Input Pin for the insertion point when the StructuralFeature is unordered.
			if not structuralFeature.isOrdered then insertAt = null
			else 
			  not isReplaceAll implies
			  	insertAt<>null and 
			  	insertAt->forAll(type=UnlimitedNatural and is(1,1.oclAsType(UnlimitedNatural)))
			endif */ 
			virtual bool insertAt_pin(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			/*!
			 A value InputPin is required.
			value<>null */ 
			virtual bool required_value(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 Specifies whether existing values of the StructuralFeature should be removed before adding the new value.
			<p>From package UML::Actions.</p> */ 
			virtual bool getIsReplaceAll() const = 0;
			
			/*!
			 Specifies whether existing values of the StructuralFeature should be removed before adding the new value.
			<p>From package UML::Actions.</p> */ 
			virtual void setIsReplaceAll (bool _isReplaceAll)= 0; 
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 The InputPin that gives the position at which to insert the value in an ordered StructuralFeature. The type of the insertAt InputPin is UnlimitedNatural, but the value cannot be zero. It is omitted for unordered StructuralFeatures.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<uml::InputPin > getInsertAt() const = 0;
			
			/*!
			 The InputPin that gives the position at which to insert the value in an ordered StructuralFeature. The type of the insertAt InputPin is UnlimitedNatural, but the value cannot be zero. It is omitted for unordered StructuralFeatures.
			<p>From package UML::Actions.</p> */
			virtual void setInsertAt(std::shared_ptr<uml::InputPin> _insertAt_insertAt) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			 Specifies whether existing values of the StructuralFeature should be removed before adding the new value.
			<p>From package UML::Actions.</p> */ 
			bool m_isReplaceAll = false;
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 The InputPin that gives the position at which to insert the value in an ordered StructuralFeature. The type of the insertAt InputPin is UnlimitedNatural, but the value cannot be zero. It is omitted for unordered StructuralFeatures.
			<p>From package UML::Actions.</p> */
			std::shared_ptr<uml::InputPin > m_insertAt;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p> */
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const = 0;/*!
			 The ordered set of InputPins representing the inputs to the Action.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> getInput() const = 0;/*!
			 The ordered set of OutputPins representing outputs from the Action.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> getOutput() const = 0;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Element > getOwner() const = 0;/*!
			 The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: UML_ADDSTRUCTURALFEATUREVALUEACTION_HPP */
