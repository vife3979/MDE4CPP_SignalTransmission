//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_PROPERTYPROPERTYIMPL_HPP
#define UML_PROPERTYPROPERTYIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../Property.hpp"

#include "uml/impl/ConnectableElementImpl.hpp"
#include "uml/impl/DeploymentTargetImpl.hpp"
#include "uml/impl/StructuralFeatureImpl.hpp"

//*********************************
namespace uml 
{
	class PropertyImpl :virtual public ConnectableElementImpl, virtual public DeploymentTargetImpl, virtual public StructuralFeatureImpl, virtual public Property 
	{
		public: 
			PropertyImpl(const PropertyImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			PropertyImpl& operator=(PropertyImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			PropertyImpl();
			virtual std::shared_ptr<Property> getThisPropertyPtr();
			virtual void setThisPropertyPtr(std::weak_ptr<Property> thisPropertyPtr);

			//Additional constructors for the containments back reference
			PropertyImpl(std::weak_ptr<uml::Property > par_associationEnd);


			//Additional constructors for the containments back reference
			PropertyImpl(std::weak_ptr<uml::Class > par_class);


			//Additional constructors for the containments back reference
			PropertyImpl(std::weak_ptr<uml::DataType > par_datatype);


			//Additional constructors for the containments back reference
			PropertyImpl(std::weak_ptr<uml::Interface > par_interface);


			//Additional constructors for the containments back reference
			PropertyImpl(std::weak_ptr<uml::Namespace > par_namespace);


			//Additional constructors for the containments back reference
			PropertyImpl(std::weak_ptr<uml::Element > par_owner);


			//Additional constructors for the containments back reference
			PropertyImpl(std::weak_ptr<uml::Association > par_owningAssociation);


			//Additional constructors for the containments back reference
			PropertyImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter);




		public:
			//destructor
			virtual ~PropertyImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 A binding of a PropertyTemplateParameter representing an attribute must be to an attribute.
			(self.isAttribute()
			and (templateParameterSubstitution->notEmpty())
			implies (templateParameterSubstitution->forAll(ts |
			    ts.formal.oclIsKindOf(Property)
			    and ts.formal.oclAsType(Property).isAttribute()))) */ 
			virtual bool binding_to_attribute(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 A Property can be a DeploymentTarget if it is a kind of Node and functions as a part in the internal structure of an encompassing Node.
			deployment->notEmpty() implies owner.oclIsKindOf(Node) and Node.allInstances()->exists(n | n.part->exists(p | p = self)) */ 
			virtual bool deployment_target(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 A derived union is derived.
			isDerivedUnion implies isDerived */ 
			virtual bool derived_union_is_derived(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 A derived union is read only.
			isDerivedUnion implies isReadOnly */ 
			virtual bool derived_union_is_read_only(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			
			
			/*!
			 Retrieves the other end of the (binary) association in which this property is a member end. */ 
			virtual std::shared_ptr<uml::Property> getOtherEnd()  ;
			
			/*!
			 The query isAttribute() is true if the Property is defined as an attribute of some Classifier.
			result = (not classifier->isEmpty())
			<p>From package UML::Classification.</p> */ 
			virtual bool isAttribute()  ;
			
			/*!
			 The value of isComposite is true only if aggregation is composite.
			result = (aggregation = AggregationKind::composite)
			<p>From package UML::Classification.</p> */ 
			virtual bool isComposite()  ;
			
			/*!
			 The query isNavigable() indicates whether it is possible to navigate across the property.
			result = (not classifier->isEmpty() or association.navigableOwnedEnd->includes(self))
			<p>From package UML::Classification.</p> */ 
			virtual bool isNavigable()  ;
			
			/*!
			 */ 
			virtual bool isSetDefault()  ;
			
			/*!
			 A multiplicity on the composing end of a composite aggregation must not have an upper bound greater than 1.
			isComposite and association <> null implies opposite.upperBound() <= 1 */ 
			virtual bool multiplicity_of_composite(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 All qualified Properties must be Association ends
			qualifier->notEmpty() implies association->notEmpty() */ 
			virtual bool qualified_is_association_end(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 A redefined Property must be inherited from a more general Classifier.
			(redefinedProperty->notEmpty()) implies
			  (redefinitionContext->notEmpty() and
			      redefinedProperty->forAll(rp|
			        ((redefinitionContext->collect(fc|
			          fc.allParents()))->asSet())->collect(c| c.allFeatures())->asSet()->includes(rp))) */ 
			virtual bool redefined_property_inherited(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 Sets the default value for this property to the specified Boolean value. */ 
			virtual void setBooleanDefaultValue(bool value)  ;
			
			/*!
			 Sets the default value for this property to the specified integer value. */ 
			virtual void setIntegerDefaultValue(int value)  ;
			
			/*!
			 Sets the navigability of this property as indicated. */ 
			virtual void setIsNavigable(bool isNavigable)  ;
			
			/*!
			 Sets the default value for this property to the null value. */ 
			virtual void setNullDefaultValue()  ;
			
			/*!
			 Sets the default value for this property to the specified real value. */ 
			virtual void setRealDefaultValue(double value)  ;
			
			/*!
			 Sets the default value for this property to the specified string value. */ 
			virtual void setStringDefaultValue(std::string value)  ;
			
			/*!
			 Sets the default value for this property to the specified unlimited natural value. */ 
			virtual void setUnlimitedNaturalDefaultValue(int value)  ;
			
			/*!
			 A Property may not subset a Property with the same name.
			subsettedProperty->forAll(sp | sp.name <> name) */ 
			virtual bool subsetted_property_names(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 The query subsettingContext() gives the context for subsetting a Property. It consists, in the case of an attribute, of the corresponding Classifier, and in the case of an association end, all of the Classifiers at the other ends.
			result = (if association <> null
			then association.memberEnd->excluding(self)->collect(type)->asSet()
			else 
			  if classifier<>null
			  then classifier->asSet()
			  else Set{} 
			  endif
			endif)
			<p>From package UML::Classification.</p> */ 
			virtual std::shared_ptr<Bag<uml::Type> > subsettingContext()  ;
			
			/*!
			 Subsetting may only occur when the context of the subsetting property conforms to the context of the subsetted property.
			subsettedProperty->notEmpty() implies
			  (subsettingContext()->notEmpty() and subsettingContext()->forAll (sc |
			    subsettedProperty->forAll(sp |
			      sp.subsettingContext()->exists(c | sc.conformsTo(c))))) */ 
			virtual bool subsetting_context_conforms(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 A subsetting Property may strengthen the type of the subsetted Property, and its upper bound may be less.
			subsettedProperty->forAll(sp |
			  self.type.conformsTo(sp.type) and
			    ((self.upperBound()->notEmpty() and sp.upperBound()->notEmpty()) implies
			      self.upperBound() <= sp.upperBound() )) */ 
			virtual bool subsetting_rules(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 If a Property is a classifier-owned end of a binary Association, its owner must be the type of the opposite end.
			(opposite->notEmpty() and owningAssociation->isEmpty()) implies classifier = opposite.type */ 
			virtual bool type_of_opposite_end(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 */ 
			virtual void unsetDefault()  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 Specifies the kind of aggregation that applies to the Property.
			<p>From package UML::Classification.</p> */ 
			virtual AggregationKind getAggregation() const ;
			
			/*!
			 Specifies the kind of aggregation that applies to the Property.
			<p>From package UML::Classification.</p> */ 
			virtual void setAggregation (AggregationKind _aggregation); 
			
			/*!
			 */ 
			virtual std::string getDefault() const ;
			
			/*!
			 */ 
			virtual void setDefault (std::string _default); 
			
			/*!
			 If isComposite is true, the object containing the attribute is a container for the object or value contained in the attribute. This is a derived value, indicating whether the aggregation of the Property is composite or not.
			<p>From package UML::Classification.</p> */ 
			virtual bool getIsComposite() const ;
			
			/*!
			 If isComposite is true, the object containing the attribute is a container for the object or value contained in the attribute. This is a derived value, indicating whether the aggregation of the Property is composite or not.
			<p>From package UML::Classification.</p> */ 
			virtual void setIsComposite (bool _isComposite); 
			
			/*!
			 Specifies whether the Property is derived, i.e., whether its value or values can be computed from other information.
			<p>From package UML::Classification.</p> */ 
			virtual bool getIsDerived() const ;
			
			/*!
			 Specifies whether the Property is derived, i.e., whether its value or values can be computed from other information.
			<p>From package UML::Classification.</p> */ 
			virtual void setIsDerived (bool _isDerived); 
			
			/*!
			 Specifies whether the property is derived as the union of all of the Properties that are constrained to subset it.
			<p>From package UML::Classification.</p> */ 
			virtual bool getIsDerivedUnion() const ;
			
			/*!
			 Specifies whether the property is derived as the union of all of the Properties that are constrained to subset it.
			<p>From package UML::Classification.</p> */ 
			virtual void setIsDerivedUnion (bool _isDerivedUnion); 
			
			/*!
			 True indicates this property can be used to uniquely identify an instance of the containing Class.
			<p>From package UML::Classification.</p> */ 
			virtual bool getIsID() const ;
			
			/*!
			 True indicates this property can be used to uniquely identify an instance of the containing Class.
			<p>From package UML::Classification.</p> */ 
			virtual void setIsID (bool _isID); 
			
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 The Association of which this Property is a member, if any.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<uml::Association > getAssociation() const ;
			
			/*!
			 The Association of which this Property is a member, if any.
			<p>From package UML::Classification.</p> */
			virtual void setAssociation(std::shared_ptr<uml::Association> _association_association) ;
			/*!
			 Designates the optional association end that owns a qualifier attribute.
			<p>From package UML::Classification.</p> */
			virtual std::weak_ptr<uml::Property > getAssociationEnd() const ;
			
			/*!
			 Designates the optional association end that owns a qualifier attribute.
			<p>From package UML::Classification.</p> */
			virtual void setAssociationEnd(std::shared_ptr<uml::Property> _associationEnd_associationEnd) ;
			/*!
			 The Class that owns this Property, if any.
			<p>From package UML::Classification.</p> */
			virtual std::weak_ptr<uml::Class > getClass() const ;
			
			/*!
			 The Class that owns this Property, if any.
			<p>From package UML::Classification.</p> */
			virtual void setClass(std::shared_ptr<uml::Class> _class_class) ;
			/*!
			 The DataType that owns this Property, if any.
			<p>From package UML::Classification.</p> */
			virtual std::weak_ptr<uml::DataType > getDatatype() const ;
			
			/*!
			 The DataType that owns this Property, if any.
			<p>From package UML::Classification.</p> */
			virtual void setDatatype(std::shared_ptr<uml::DataType> _datatype_datatype) ;
			/*!
			 A ValueSpecification that is evaluated to give a default value for the Property when an instance of the owning Classifier is instantiated.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<uml::ValueSpecification > getDefaultValue() const ;
			
			/*!
			 A ValueSpecification that is evaluated to give a default value for the Property when an instance of the owning Classifier is instantiated.
			<p>From package UML::Classification.</p> */
			virtual void setDefaultValue(std::shared_ptr<uml::ValueSpecification> _defaultValue_defaultValue) ;
			/*!
			 The Interface that owns this Property, if any.
			<p>From package UML::Classification.</p> */
			virtual std::weak_ptr<uml::Interface > getInterface() const ;
			
			/*!
			 The Interface that owns this Property, if any.
			<p>From package UML::Classification.</p> */
			virtual void setInterface(std::shared_ptr<uml::Interface> _interface_interface) ;
			/*!
			 In the case where the Property is one end of a binary association this gives the other end.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<uml::Property > getOpposite() const ;
			
			/*!
			 In the case where the Property is one end of a binary association this gives the other end.
			<p>From package UML::Classification.</p> */
			virtual void setOpposite(std::shared_ptr<uml::Property> _opposite_opposite) ;
			/*!
			 The owning association of this property, if any.
			<p>From package UML::Classification.</p> */
			virtual std::weak_ptr<uml::Association > getOwningAssociation() const ;
			
			/*!
			 The owning association of this property, if any.
			<p>From package UML::Classification.</p> */
			virtual void setOwningAssociation(std::shared_ptr<uml::Association> _owningAssociation_owningAssociation) ;
			/*!
			 An optional list of ordered qualifier attributes for the end.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<Subset<uml::Property, uml::Element>> getQualifier() const ;
			
			/*!
			 The properties that are redefined by this property, if any.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::Property, uml::RedefinableElement>> getRedefinedProperty() const ;
			
			/*!
			 The properties of which this Property is constrained to be a subset, if any.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<Bag<uml::Property>> getSubsettedProperty() const ;
			
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 The Classifiers that have this Feature as a feature.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<Union<uml::Classifier>> getFeaturingClassifier() const ;/*!
			 Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Namespace > getNamespace() const ;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Element > getOwner() const ;/*!
			 The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const ;/*!
			 The contexts that this element may be redefined from.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<Union<uml::Classifier>> getRedefinitionContext() const ; 
			 
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
			std::weak_ptr<Property> m_thisPropertyPtr;
	};
}
#endif /* end of include guard: UML_PROPERTYPROPERTYIMPL_HPP */
