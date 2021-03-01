//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_WRITESTRUCTURALFEATUREACTIONACTIVATION_HPP
#define FUML_SEMANTICS_ACTIONS_WRITESTRUCTURALFEATUREACTIONACTIVATION_HPP


#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 


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

namespace fUML
{
	class fUMLFactory;
}

//Forward Declaration for used types 
namespace fUML::Semantics::Actions 
{
	class InputPinActivation;
	class OutputPinActivation;
	class PinActivation;
}
namespace fUML::Semantics::Activities 
{
	class ActivityEdgeInstance;
	class ActivityNodeActivationGroup;
	class Token;
}
namespace fUML::Semantics::Values 
{
	class Value;
}
namespace uml 
{
	class Action;
	class ActivityNode;
}

// base class includes
#include "fUML/Semantics/Actions/StructuralFeatureActionActivation.hpp"

// enum includes



//*********************************
namespace fUML::Semantics::Actions 
{
	
	class WriteStructuralFeatureActionActivation: virtual public StructuralFeatureActionActivation
	{
		public:
 			WriteStructuralFeatureActionActivation(const WriteStructuralFeatureActionActivation &) {}
		protected:
			WriteStructuralFeatureActionActivation(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~WriteStructuralFeatureActionActivation() {}

			//*********************************
			// Operations
			//*********************************
			 
			virtual int position(std::shared_ptr<fUML::Semantics::Values::Value> value,std::shared_ptr<Bag<fUML::Semantics::Values::Value>> list,int startAt) = 0;
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			
			virtual std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> getPinActivation() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_WRITESTRUCTURALFEATUREACTIONACTIVATION_HPP */
