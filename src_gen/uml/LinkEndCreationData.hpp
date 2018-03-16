//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_LINKENDCREATIONDATA_HPP
#define UML_LINKENDCREATIONDATA_HPP

#include <map>
#include <list>
#include <memory>
#include <string>


// forward declarations


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
	class LinkEndData;
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
#include "uml/LinkEndData.hpp"

// enum includes


//*********************************
namespace uml 
{
	/*!
	 LinkEndCreationData is LinkEndData used to provide values for one end of a link to be created by a CreateLinkAction.
	<p>From package UML::Actions.</p> */
	class LinkEndCreationData:virtual public LinkEndData
	{
		public:
 			LinkEndCreationData(const LinkEndCreationData &) {}
			LinkEndCreationData& operator=(LinkEndCreationData const&) = delete;

		protected:
			LinkEndCreationData(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~LinkEndCreationData() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 LinkEndCreationData for ordered Association ends must have a single insertAt InputPin for the insertion point with type UnlimitedNatural and multiplicity of 1..1, if isReplaceAll=false, and must have no InputPin for the insertion point when the association ends are unordered.
			if  not end.isOrdered
			then insertAt = null
			else
				not isReplaceAll=false implies
				insertAt <> null and insertAt->forAll(type=UnlimitedNatural and is(1,1))
			endif */ 
			virtual bool insertAt_pin(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 Specifies whether the existing links emanating from the object on this end should be destroyed before creating a new link.
			<p>From package UML::Actions.</p> */ 
			virtual bool getIsReplaceAll() const = 0;
			
			/*!
			 Specifies whether the existing links emanating from the object on this end should be destroyed before creating a new link.
			<p>From package UML::Actions.</p> */ 
			virtual void setIsReplaceAll (bool _isReplaceAll)= 0; 
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 For ordered Association ends, the InputPin that provides the position where the new link should be inserted or where an existing link should be moved to. The type of the insertAt InputPin is UnlimitedNatural, but the input cannot be zero. It is omitted for Association ends that are not ordered.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<uml::InputPin > getInsertAt() const = 0;
			
			/*!
			 For ordered Association ends, the InputPin that provides the position where the new link should be inserted or where an existing link should be moved to. The type of the insertAt InputPin is UnlimitedNatural, but the input cannot be zero. It is omitted for Association ends that are not ordered.
			<p>From package UML::Actions.</p> */
			virtual void setInsertAt(std::shared_ptr<uml::InputPin> _insertAt_insertAt) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			 Specifies whether the existing links emanating from the object on this end should be destroyed before creating a new link.
			<p>From package UML::Actions.</p> */ 
			bool m_isReplaceAll = false;
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 For ordered Association ends, the InputPin that provides the position where the new link should be inserted or where an existing link should be moved to. The type of the insertAt InputPin is UnlimitedNatural, but the input cannot be zero. It is omitted for Association ends that are not ordered.
			<p>From package UML::Actions.</p> */
			std::shared_ptr<uml::InputPin > m_insertAt;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: UML_LINKENDCREATIONDATA_HPP */
