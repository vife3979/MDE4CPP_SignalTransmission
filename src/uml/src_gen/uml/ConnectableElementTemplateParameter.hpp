//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CONNECTABLEELEMENTTEMPLATEPARAMETER_HPP
#define UML_CONNECTABLEELEMENTTEMPLATEPARAMETER_HPP


#include <memory>
#include <string>
// forward declarations


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
	class Comment;
	class ParameterableElement;
	class TemplateSignature;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/TemplateParameter.hpp"




//*********************************
namespace uml 
{
	/*!
	A ConnectableElementTemplateParameter exposes a ConnectableElement as a formal parameter for a template.
	<p>From package UML::StructuredClassifiers.</p>
	*/
	
	class UML_API ConnectableElementTemplateParameter: virtual public TemplateParameter
	{
		public:
 			ConnectableElementTemplateParameter(const ConnectableElementTemplateParameter &) {}

		protected:
			ConnectableElementTemplateParameter(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ConnectableElementTemplateParameter() {}

			//*********************************
			// Operations
			//*********************************

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************

			//*********************************
			// Union Reference Getters
			//*********************************
			
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;
			/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const = 0;
			

			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 

			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			//*********************************
			// Reference Members
			//*********************************
	};
}
#endif /* end of include guard: UML_CONNECTABLEELEMENTTEMPLATEPARAMETER_HPP */
