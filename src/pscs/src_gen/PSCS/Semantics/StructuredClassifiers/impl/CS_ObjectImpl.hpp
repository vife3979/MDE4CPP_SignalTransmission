//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_STRUCTUREDCLASSIFIERS_CS_OBJECTCS_OBJECTIMPL_HPP
#define PSCS_SEMANTICS_STRUCTUREDCLASSIFIERS_CS_OBJECTCS_OBJECTIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "PSCS/PSCS.hpp" 

// model includes
#include "../CS_Object.hpp"

#include "PSCS/Semantics/StructuredClassifiers/impl/StructuredClassifiersFactoryImpl.hpp"
#include "fUML/Semantics/StructuredClassifiers/impl/ObjectImpl.hpp"

//*********************************
namespace PSCS::Semantics::StructuredClassifiers 
{
	class PSCS_API CS_ObjectImpl : virtual public fUML::Semantics::StructuredClassifiers::ObjectImpl, virtual public CS_Object 
	{
		public: 
			CS_ObjectImpl(const CS_ObjectImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			CS_ObjectImpl& operator=(CS_ObjectImpl const&); 

		protected:
			friend class PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactoryImpl;
			CS_ObjectImpl();
			virtual std::shared_ptr<CS_Object> getThisCS_ObjectPtr() const;
			virtual void setThisCS_ObjectPtr(std::weak_ptr<CS_Object> thisCS_ObjectPtr);


		public:
			//destructor
			virtual ~CS_ObjectImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual bool checkAllParents(std::shared_ptr<uml::Classifier> type,std::shared_ptr<uml::Classifier> classifier) ;
			virtual bool contains(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> object) ;
			virtual bool directlyContains(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> object) ;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> dispatchIn(std::shared_ptr<uml::Operation> operation,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint) ;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> dispatchIn(std::shared_ptr<uml::Operation> operation,std::shared_ptr<uml::Port> onPort) ;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> dispatchOut(std::shared_ptr<uml::Operation> operation,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint) ;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> dispatchOut(std::shared_ptr<uml::Operation> operation,std::shared_ptr<uml::Port> onPort) ;
			virtual std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object> > getDirectContainers() ;
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> getFeatureValue(std::shared_ptr<uml::StructuralFeature> feature) ;
			virtual PSCS::Semantics::StructuredClassifiers::CS_LinkKind getLinkKind(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link> link,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint) ;
			virtual std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link> > getLinks(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint) ;
			virtual bool hasValueForAFeature(std::shared_ptr<fUML::Semantics::Values::Value> value) ;
			virtual bool isDescendant(std::shared_ptr<uml::Interface> contract,std::shared_ptr<uml::Interface> interface_) ;
			virtual bool isOperationProvided(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference,std::shared_ptr<uml::Operation> operation) ;
			virtual bool isOperationRequired(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference,std::shared_ptr<uml::Operation> operation) ;
			virtual bool realizesInterface(std::shared_ptr<uml::Class> type,std::shared_ptr<uml::Interface> interface_) ;
			virtual std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference> > selectTargetsForDispatching(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link> link,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint,uml::ConnectorKind connectorKind,std::shared_ptr<uml::Operation> operation,bool toInternal) ;
			virtual std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference> > selectTargetsForSending(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link> link,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint,uml::ConnectorKind connectorKind,bool toInternal) ;
			virtual void sendIn(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> eventOccurrence,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint) ;
			virtual void sendIn(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> eventOccurrence,std::shared_ptr<uml::Port> onPort) ;
			virtual void sendOut(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> eventOccurrence,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint) ;
			virtual void sendOut(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> eventOccurrence,std::shared_ptr<uml::Port> onPort) ;
			virtual void setFeatureValue(std::shared_ptr<uml::StructuralFeature> feature,std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values,int position) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			
			//*********************************
			// Union Reference Getters
			//*********************************
			
			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<CS_Object> m_thisCS_ObjectPtr;
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_STRUCTUREDCLASSIFIERS_CS_OBJECTCS_OBJECTIMPL_HPP */
