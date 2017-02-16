//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_ACTIVITYEDGEINSTANCEACTIVITYEDGEINSTANCEIMPL_HPP
#define FUML_ACTIVITYEDGEINSTANCEACTIVITYEDGEINSTANCEIMPL_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

//*********************************
// generated Includes

//Model includes
#include "../ActivityEdgeInstance.hpp"


#include "impl/EObjectImpl.hpp"

 #include "FUMLFactory.hpp"

//*********************************
namespace fUML 
{
	class ActivityEdgeInstanceImpl :virtual public ecore::EObjectImpl,
virtual public ActivityEdgeInstance
	{
		public: 
			ActivityEdgeInstanceImpl(const ActivityEdgeInstanceImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			ActivityEdgeInstanceImpl& operator=(ActivityEdgeInstanceImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			ActivityEdgeInstanceImpl();

		public:
			//destructor
			virtual ~ActivityEdgeInstanceImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual void sendOffer(std::vector<fUML::Token * > *  tokens)  ;
			
			/*!
			 */ 
			virtual int countOfferedValue()  ;
			
			/*!
			 */ 
			virtual std::vector<fUML::Token * > *  takeOfferedTokens()  ;
			
			/*!
			 */ 
			virtual std::vector<fUML::Token * > *  takeOfferedTokens(int maxCount)  ;
			
			/*!
			 */ 
			virtual std::vector<fUML::Token * > *  getOfferedTokens()  ;
			
			/*!
			 */ 
			virtual bool hasOffer()  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual uml::ActivityEdge *  getEdge() const ;
			
			/*!
			 */
			virtual void setEdge(uml::ActivityEdge *  _edge) ;
			
			/*!
			 */
			virtual fUML::ActivityNodeActivation *  getSource() const ;
			
			/*!
			 */
			virtual void setSource(fUML::ActivityNodeActivation *  _source) ;
			
			/*!
			 */
			virtual fUML::ActivityNodeActivation *  getTarget() const ;
			
			/*!
			 */
			virtual void setTarget(fUML::ActivityNodeActivation *  _target) ;
			
			/*!
			 */
			virtual std::vector<fUML::Offer * > *  getOffers() const ;
			
			/*!
			 */
			virtual fUML::ActivityNodeActivationGroup *  getGroup() const ;
			
			/*!
			 */
			virtual void setGroup(fUML::ActivityNodeActivationGroup *  _group) ;
			
							
			
			//*********************************
			// Union Getter
			//*********************************
			 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
			
			virtual boost::any eGet(int featureID, bool resolve, bool coreType) const ;
			
		protected:
			virtual ecore::EClass* eStaticClass() const;
	};
}
#endif /* end of include guard: FUML_ACTIVITYEDGEINSTANCEACTIVITYEDGEINSTANCEIMPL_HPP */

