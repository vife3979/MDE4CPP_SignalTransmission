//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_LINKENDDATA_HPP
#define UML_LINKENDDATA_HPP

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

#include <string>
#include <map>
#include <vector>
#include "SubsetUnion.hpp"
#include "boost/shared_ptr.hpp"
#include "boost/any.hpp"

//*********************************
// generated Includes

//Forward Declaration for used types
namespace uml 
{
	class Comment;
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
	class InputPin;
}

namespace uml 
{
	class Property;
}

namespace uml 
{
	class QualifierValue;
}

// base class includes
#include "Element.hpp"

// enum includes


//*********************************
namespace uml 
{
	/*!
	 LinkEndData is an Element that identifies on end of a link to be read or written by a LinkAction. As a link (that is not a link object) cannot be passed as a runtime value to or from an Action, it is instead identified by its end objects and qualifier values, if any. A LinkEndData instance provides these values for a single Association end.
	<p>From package UML::Actions.</p> */
	class LinkEndData:virtual public Element
	{
		public:
 			LinkEndData(const LinkEndData &) {}
			LinkEndData& operator=(LinkEndData const&) = delete;

		protected:
			LinkEndData(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~LinkEndData() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 Returns all the InputPins referenced by this LinkEndData. By default this includes the value and qualifier InputPins, but subclasses may override the operation to add other InputPins.
			result = (value->asBag()->union(qualifier.value))
			<p>From package UML::Actions.</p> */ 
			virtual std::shared_ptr<Bag<uml::InputPin> > allPins()  = 0;
			
			/*!
			 The value InputPin is not also the qualifier value InputPin.
			value->excludesAll(qualifier.value) */ 
			virtual bool end_object_input_pin(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			/*!
			 The multiplicity of the value InputPin must be 1..1.
			value<>null implies value.is(1,1) */ 
			virtual bool multiplicity(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			/*!
			 The Property must be an Association memberEnd.
			end.association <> null */ 
			virtual bool property_is_association_end(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			/*!
			 The qualifiers must be qualifiers of the Association end.
			end.qualifier->includesAll(qualifier.qualifier) */ 
			virtual bool qualifiers(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			/*!
			 The type of the value InputPin conforms to the type of the Association end.
			value<>null implies value.type.conformsTo(end.type) */ 
			virtual bool same_type(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 The Association end for which this LinkEndData specifies values.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<uml::Property > getEnd() const = 0;
			
			/*!
			 The Association end for which this LinkEndData specifies values.
			<p>From package UML::Actions.</p> */
			virtual void setEnd(std::shared_ptr<uml::Property> _end_end) = 0;
			/*!
			 A set of QualifierValues used to provide values for the qualifiers of the end.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<Subset<uml::QualifierValue, uml::Element > > getQualifier() const = 0;
			
			/*!
			 The InputPin that provides the specified value for the given end. This InputPin is omitted if the LinkEndData specifies the "open" end for a ReadLinkAction.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<uml::InputPin > getValue() const = 0;
			
			/*!
			 The InputPin that provides the specified value for the given end. This InputPin is omitted if the LinkEndData specifies the "open" end for a ReadLinkAction.
			<p>From package UML::Actions.</p> */
			virtual void setValue(std::shared_ptr<uml::InputPin> _value_value) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 The Association end for which this LinkEndData specifies values.
			<p>From package UML::Actions.</p> */
			std::shared_ptr<uml::Property > m_end;
			/*!
			 A set of QualifierValues used to provide values for the qualifiers of the end.
			<p>From package UML::Actions.</p> */
			std::shared_ptr<Subset<uml::QualifierValue, uml::Element > > m_qualifier;
			/*!
			 The InputPin that provides the specified value for the given end. This InputPin is omitted if the LinkEndData specifies the "open" end for a ReadLinkAction.
			<p>From package UML::Actions.</p> */
			std::shared_ptr<uml::InputPin > m_value;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::Element> > getOwnedElement() const = 0; 
	};

}
#endif /* end of include guard: UML_LINKENDDATA_HPP */

