//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_DEPLOYEDARTIFACTDEPLOYEDARTIFACTIMPL_HPP
#define UML_DEPLOYEDARTIFACTDEPLOYEDARTIFACTIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../DeployedArtifact.hpp"

#include "uml/impl/NamedElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API DeployedArtifactImpl : virtual public NamedElementImpl, virtual public DeployedArtifact 
	{
		public: 
			DeployedArtifactImpl(const DeployedArtifactImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			DeployedArtifactImpl& operator=(DeployedArtifactImpl const&); 

		protected:
			friend class umlFactoryImpl;
			DeployedArtifactImpl();
			virtual std::shared_ptr<DeployedArtifact> getThisDeployedArtifactPtr() const;
			virtual void setThisDeployedArtifactPtr(std::weak_ptr<DeployedArtifact> thisDeployedArtifactPtr);

			//Additional constructors for the containments back reference
			DeployedArtifactImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			DeployedArtifactImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~DeployedArtifactImpl();
			
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
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;
			/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const ;
			
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
			std::weak_ptr<DeployedArtifact> m_thisDeployedArtifactPtr;
	};
}
#endif /* end of include guard: UML_DEPLOYEDARTIFACTDEPLOYEDARTIFACTIMPL_HPP */
