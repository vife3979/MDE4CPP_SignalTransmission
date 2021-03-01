//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef UML_OBJECTNODE_EXECUTION_HPP
#define UML_OBJECTNODE_EXECUTION_HPP

#include "PSCS/Semantics/StructuredClassifiers/impl/CS_ObjectImpl.hpp"
#include "umlReflectionExec/ActivityNodeObject.hpp"
#include "umlReflectionExec/TypedElementObject.hpp"

template <class T> 
class Bag;

namespace uml
{
	class ObjectNode;
}

namespace uml
{
	class Element;
	class ConnectorEnd;
}

namespace UML 
{
	class ObjectNodeObject : virtual public UML::ActivityNodeObject , virtual public UML::TypedElementObject
	{
		public:
		    //constructors
		    ObjectNodeObject(ObjectNodeObject &obj);
		    ObjectNodeObject(std::shared_ptr<uml::ObjectNode>);
		 	ObjectNodeObject();
		    //destructor
		    virtual ~ObjectNodeObject();
		
		    virtual std::shared_ptr<ecore::EObject> copy();
			ObjectNodeObject& operator=(ObjectNodeObject const&);

			virtual void destroy();
			
			virtual std::shared_ptr<uml::ObjectNode> getObjectNodeValue() const;
			virtual std::shared_ptr<uml::Element> getUmlValue() const;
			virtual void setUmlValue(std::shared_ptr<uml::Element>);
			virtual void setObjectNodeValue(std::shared_ptr<uml::ObjectNode>);
			virtual void setThisObjectNodeObjectPtr(std::weak_ptr<ObjectNodeObject> thisObjectPtr);
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
			std::shared_ptr<uml::ObjectNode> m_ObjectNodeValue = nullptr;
	};
}
#endif /* end of include guard: UML_OBJECTNODE_OBJECT_HPP */
