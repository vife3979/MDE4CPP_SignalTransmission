//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_READEXTENTACTIONREADEXTENTACTIONIMPL_HPP
#define UML_READEXTENTACTIONREADEXTENTACTIONIMPL_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//*********************************
// generated Includes

//Model includes
#include "../ReadExtentAction.hpp"

#include "impl/ActionImpl.hpp"

#include "SubsetUnion.hpp"



//*********************************
namespace uml 
{
	class ReadExtentActionImpl :virtual public ActionImpl, virtual public ReadExtentAction 
	{
		public: 
			ReadExtentActionImpl(const ReadExtentActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			ReadExtentActionImpl& operator=(ReadExtentActionImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			ReadExtentActionImpl();

			//Additional constructors for the containments back reference
			ReadExtentActionImpl(std::weak_ptr<uml::Activity > par_activity);


			//Additional constructors for the containments back reference
			ReadExtentActionImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode);


			//Additional constructors for the containments back reference
			ReadExtentActionImpl(std::weak_ptr<uml::Namespace > par_namespace);


			//Additional constructors for the containments back reference
			ReadExtentActionImpl(std::weak_ptr<uml::Element > par_owner);




		public:
			//destructor
			virtual ~ReadExtentActionImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 The multiplicity of the result OutputPin is 0..*.
			result.is(0,*) */ 
			virtual bool multiplicity_of_result(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 The type of the result OutputPin is the classifier.
			result.type = classifier */ 
			virtual bool type_is_classifier(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 The Classifier whose instances are to be retrieved.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<uml::Classifier > getClassifier() const ;
			
			/*!
			 The Classifier whose instances are to be retrieved.
			<p>From package UML::Actions.</p> */
			virtual void setClassifier(std::shared_ptr<uml::Classifier> _classifier_classifier) ;
			/*!
			 The OutputPin on which the Classifier instances are placed.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<uml::OutputPin > getResult() const ;
			
			/*!
			 The OutputPin on which the Classifier instances are placed.
			<p>From package UML::Actions.</p> */
			virtual void setResult(std::shared_ptr<uml::OutputPin> _result_result) ;
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p> */
			virtual std::shared_ptr<Union<uml::ActivityGroup> > getInGroup() const ;/*!
			 The ordered set of OutputPins representing outputs from the Action.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element > > getOutput() const ;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::Element> > getOwnedElement() const ;/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Element > getOwner() const ;/*!
			 The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<Union<uml::RedefinableElement> > getRedefinedElement() const ; 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
			
			virtual boost::any eGet(int featureID, bool resolve, bool coreType) const ;
			
		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
	};
}
#endif /* end of include guard: UML_READEXTENTACTIONREADEXTENTACTIONIMPL_HPP */

