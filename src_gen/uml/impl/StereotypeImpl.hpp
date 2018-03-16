//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_STEREOTYPESTEREOTYPEIMPL_HPP
#define UML_STEREOTYPESTEREOTYPEIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../Stereotype.hpp"

#include "uml/impl/ClassImpl.hpp"

//*********************************
namespace uml 
{
	class StereotypeImpl :virtual public ClassImpl, virtual public Stereotype 
	{
		public: 
			StereotypeImpl(const StereotypeImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			StereotypeImpl& operator=(StereotypeImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			StereotypeImpl();
			virtual std::shared_ptr<Stereotype> getThisStereotypePtr();
			virtual void setThisStereotypePtr(std::weak_ptr<Stereotype> thisStereotypePtr);

			//Additional constructors for the containments back reference
			StereotypeImpl(std::weak_ptr<uml::Namespace > par_namespace);


			//Additional constructors for the containments back reference
			StereotypeImpl(std::weak_ptr<uml::Element > par_owner);


			//Additional constructors for the containments back reference
			StereotypeImpl(std::weak_ptr<uml::Package > par_Package, const int reference_id);


			//Additional constructors for the containments back reference
			StereotypeImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter);


			//Additional constructors for the containments back reference




		public:
			//destructor
			virtual ~StereotypeImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 Where a stereotype’s property is an association end for an association other than a kind of extension, and the other end is not a stereotype, the other end must be owned by the association itself.
			ownedAttribute
			->select(association->notEmpty() and not association.oclIsKindOf(Extension) and not type.oclIsKindOf(Stereotype))
			->forAll(opposite.owner = association) */ 
			virtual bool associationEndOwnership(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 If a Stereotype extends more than one metaclass, the multiplicity of the corresponding base-properties shall be [0..1]. At any point in time, only one of these base-properties can contain a metaclass instance during runtime. */ 
			virtual bool base_property_multiplicity_multiple_extension(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 If a Stereotype extends only one metaclass, the multiplicity of the corresponding base-property shall be 1..1. */ 
			virtual bool base_property_multiplicity_single_extension(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 The upper bound of base-properties is exactly 1. */ 
			virtual bool base_property_upper_bound(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 Stereotypes may only participate in binary associations.
			ownedAttribute.association->forAll(memberEnd->size()=2) */ 
			virtual bool binaryAssociationsOnly(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 The query containingProfile returns the closest profile directly or indirectly containing this stereotype.
			result = (self.namespace.oclAsType(Package).containingProfile())
			<p>From package UML::Packages.</p> */ 
			virtual std::shared_ptr<uml::Profile> containingProfile()  ;
			
			/*!
			 Creates a(n) (required) extension of the specified metaclass with this stereotype. */ 
			virtual std::shared_ptr<uml::Extension> createExtension(std::shared_ptr<uml::Class>  metaclass,bool isRequired)  ;
			
			/*!
			 Creates an icon with the specified location for this stereotype. */ 
			virtual std::shared_ptr<uml::Image> createIcon(std::string location)  ;
			
			/*!
			 Creates an icon with the specified format and content for this stereotype. */ 
			virtual std::shared_ptr<uml::Image> createIcon(std::string format,std::string content)  ;
			
			/*!
			 A Stereotype may only generalize or specialize another Stereotype.
			allParents()->forAll(oclIsKindOf(Stereotype)) 
			and Classifier.allInstances()->forAll(c | c.allParents()->exists(oclIsKindOf(Stereotype)) implies c.oclIsKindOf(Stereotype)) */ 
			virtual bool generalize(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 Retrieves all the metaclasses extended by this stereotype, including the metaclasses extended by its superstereotypes. */ 
			virtual std::shared_ptr<Bag<uml::Class> > getAllExtendedMetaclasses()  ;
			
			/*!
			 Retrieves the current definition (Ecore representation) of this stereotype. */ 
			virtual std::shared_ptr<ecore::EClass> getDefinition()  ;
			
			/*!
			 Retrieves the metaclasses extended by this stereotype. */ 
			virtual std::shared_ptr<Bag<uml::Class> > getExtendedMetaclasses()  ;
			
			/*!
			 Retrieves the localized keyword for this stereotype. */ 
			virtual std::string getKeyword()  ;
			
			/*!
			 Retrieves the keyword for this stereotype, localized if indicated. */ 
			virtual std::string getKeyword(bool localize)  ;
			
			
			
			/*!
			 Stereotype names should not clash with keyword names for the extended model element. */ 
			virtual bool name_not_clash(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 Stereotype can change the graphical appearance of the extended model element by using attached icons. When this association is not null, it references the location of the icon content to be displayed within diagrams presenting the extended model elements.
			<p>From package UML::Packages.</p> */
			virtual std::shared_ptr<Subset<uml::Image, uml::Element>> getIcon() const ;
			
			/*!
			 The profile that directly or indirectly contains this stereotype.
			<p>From package UML::Packages.</p> */
			virtual std::shared_ptr<uml::Profile > getProfile() const ;
			
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 All of the Properties that are direct (i.e., not inherited or imported) attributes of the Classifier.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> getAttribute() const ;/*!
			 Specifies each Feature directly defined in the classifier. Note that there may be members of the Classifier that are of the type Feature but are not included, e.g., inherited features.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> getFeature() const ;/*!
			 A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::NamedElement>> getMember() const ;/*!
			 Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Namespace > getNamespace() const ;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			 A collection of NamedElements owned by the Namespace.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> getOwnedMember() const ;/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Element > getOwner() const ;/*!
			 The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const ;/*!
			 The roles that instances may play in this StructuredClassifier.
			<p>From package UML::StructuredClassifiers.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::ConnectableElement, uml::NamedElement>> getRole() const ; 
			 
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
			std::weak_ptr<Stereotype> m_thisStereotypePtr;
	};
}
#endif /* end of include guard: UML_STEREOTYPESTEREOTYPEIMPL_HPP */
