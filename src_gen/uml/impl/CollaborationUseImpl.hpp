//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_COLLABORATIONUSECOLLABORATIONUSEIMPL_HPP
#define UML_COLLABORATIONUSECOLLABORATIONUSEIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../CollaborationUse.hpp"

#include "uml/impl/NamedElementImpl.hpp"

//*********************************
namespace uml 
{
	class CollaborationUseImpl :virtual public NamedElementImpl, virtual public CollaborationUse 
	{
		public: 
			CollaborationUseImpl(const CollaborationUseImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			CollaborationUseImpl& operator=(CollaborationUseImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			CollaborationUseImpl();
			virtual std::shared_ptr<CollaborationUse> getThisCollaborationUsePtr();
			virtual void setThisCollaborationUsePtr(std::weak_ptr<CollaborationUse> thisCollaborationUsePtr);

			//Additional constructors for the containments back reference
			CollaborationUseImpl(std::weak_ptr<uml::Namespace > par_namespace);


			//Additional constructors for the containments back reference
			CollaborationUseImpl(std::weak_ptr<uml::Element > par_owner);




		public:
			//destructor
			virtual ~CollaborationUseImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 All the client elements of a roleBinding are in one Classifier and all supplier elements of a roleBinding are in one Collaboration.
			roleBinding->collect(client)->forAll(ne1, ne2 |
			  ne1.oclIsKindOf(ConnectableElement) and ne2.oclIsKindOf(ConnectableElement) and
			    let ce1 : ConnectableElement = ne1.oclAsType(ConnectableElement), ce2 : ConnectableElement = ne2.oclAsType(ConnectableElement) in
			      ce1.structuredClassifier = ce2.structuredClassifier)
			and
			  roleBinding->collect(supplier)->forAll(ne1, ne2 |
			  ne1.oclIsKindOf(ConnectableElement) and ne2.oclIsKindOf(ConnectableElement) and
			    let ce1 : ConnectableElement = ne1.oclAsType(ConnectableElement), ce2 : ConnectableElement = ne2.oclAsType(ConnectableElement) in
			      ce1.collaboration = ce2.collaboration) */ 
			virtual bool client_elements(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 Connectors in a Collaboration typing a CollaborationUse must have corresponding Connectors between elements bound in the context Classifier, and these corresponding Connectors must have the same or more general type than the Collaboration Connectors.
			type.ownedConnector->forAll(connector |
			  let rolesConnectedInCollab : Set(ConnectableElement) = connector.end.role->asSet(),
			        relevantBindings : Set(Dependency) = roleBinding->select(rb | rb.supplier->intersection(rolesConnectedInCollab)->notEmpty()),
			        boundRoles : Set(ConnectableElement) = relevantBindings->collect(client.oclAsType(ConnectableElement))->asSet(),
			        contextClassifier : StructuredClassifier = boundRoles->any(true).structuredClassifier->any(true) in
			          contextClassifier.ownedConnector->exists( correspondingConnector | 
			              correspondingConnector.end.role->forAll( role | boundRoles->includes(role) )
			              and (connector.type->notEmpty() and correspondingConnector.type->notEmpty()) implies connector.type->forAll(conformsTo(correspondingConnector.type)) )
			) */ 
			virtual bool connectors(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 Every collaborationRole in the Collaboration is bound within the CollaborationUse.
			type.collaborationRole->forAll(role | roleBinding->exists(rb | rb.supplier->includes(role))) */ 
			virtual bool every_role(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 A mapping between features of the Collaboration and features of the owning Classifier. This mapping indicates which ConnectableElement of the Classifier plays which role(s) in the Collaboration. A ConnectableElement may be bound to multiple roles in the same CollaborationUse (that is, it may play multiple roles).
			<p>From package UML::StructuredClassifiers.</p> */
			virtual std::shared_ptr<Subset<uml::Dependency, uml::Element>> getRoleBinding() const ;
			
			/*!
			 The Collaboration which is used in this CollaborationUse. The Collaboration defines the cooperation between its roles which are mapped to ConnectableElements relating to the Classifier owning the CollaborationUse.
			<p>From package UML::StructuredClassifiers.</p> */
			virtual std::shared_ptr<uml::Collaboration > getType() const ;
			
			/*!
			 The Collaboration which is used in this CollaborationUse. The Collaboration defines the cooperation between its roles which are mapped to ConnectableElements relating to the Classifier owning the CollaborationUse.
			<p>From package UML::StructuredClassifiers.</p> */
			virtual void setType(std::shared_ptr<uml::Collaboration> _type_type) ;
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Element > getOwner() const ; 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************

			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interface::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual boost::any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, boost::any newValue) ;

		private:
			std::weak_ptr<CollaborationUse> m_thisCollaborationUsePtr;
	};
}
#endif /* end of include guard: UML_COLLABORATIONUSECOLLABORATIONUSEIMPL_HPP */
