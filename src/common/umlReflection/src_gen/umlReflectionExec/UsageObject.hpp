//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef UML_USAGE_EXECUTION_HPP
#define UML_USAGE_EXECUTION_HPP

#include "PSCS/Semantics/StructuredClassifiers/impl/CS_ObjectImpl.hpp"
#include "umlReflectionExec/DependencyObject.hpp"

template <class T> 
class Bag;

namespace uml
{
	class Usage;
}

namespace uml
{
	class Element;
	class ConnectorEnd;
}

namespace UML 
{
	class UsageObject : virtual public UML::DependencyObject
	{
		public:
		    //constructors
		    UsageObject(UsageObject &obj);
		    UsageObject(std::shared_ptr<uml::Usage>);
		 	UsageObject();
		    //destructor
		    virtual ~UsageObject();
		
		    virtual std::shared_ptr<ecore::EObject> copy();

			virtual void destroy();
			
			virtual std::shared_ptr<uml::Usage> getUsageValue() const;
			virtual std::shared_ptr<uml::Element> getUmlValue() const;
			virtual void setUmlValue(std::shared_ptr<uml::Element>);
			virtual void setUsageValue(std::shared_ptr<uml::Usage>);
			virtual void setThisUsageObjectPtr(std::weak_ptr<UsageObject> thisObjectPtr);
			virtual bool equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue);
			virtual std::string toString();
			virtual std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> getDirectContainers();
			virtual void removeValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<fUML::Semantics::Values::Value> values);
			virtual std::shared_ptr<Bag<fUML::Semantics::Values::Value>> getValues(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues);
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> retrieveFeatureValue(std::shared_ptr<uml::StructuralFeature> feature);
			virtual void setFeatureValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::Values::Value>> value, int position);
			virtual void assignFeatureValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::Values::Value>> value, int position);
			virtual std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> retrieveFeatureValues();

			virtual std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> getLinks(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint);
			virtual std::shared_ptr<Bag<fUML::Semantics::Values::Value>> retrieveEndValueAsInteractionPoint(std::shared_ptr<fUML::Semantics::Values::Value> endValue, std::shared_ptr<uml::ConnectorEnd> end);

		protected:
			std::shared_ptr<uml::Usage> m_UsageValue = nullptr;
	};
}
#endif /* end of include guard: UML_USAGE_OBJECT_HPP */
