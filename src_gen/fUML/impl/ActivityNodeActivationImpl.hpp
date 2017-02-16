//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_ACTIVITYNODEACTIVATIONACTIVITYNODEACTIVATIONIMPL_HPP
#define FUML_ACTIVITYNODEACTIVATIONACTIVITYNODEACTIVATIONIMPL_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

//*********************************
// generated Includes

//Model includes
#include "../ActivityNodeActivation.hpp"

#include "impl/SemanticVisitorImpl.hpp"

#include "ActivityNode.hpp"

#include "Class.hpp"
#include "ActivityNodeActivation.hpp"

#include "EClass.hpp"

//*********************************
namespace fUML 
{
	class ActivityNodeActivationImpl :virtual public SemanticVisitorImpl, virtual public ActivityNodeActivation
	{
		public: 
			ActivityNodeActivationImpl(const ActivityNodeActivationImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			ActivityNodeActivationImpl& operator=(ActivityNodeActivationImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			ActivityNodeActivationImpl();

		public:
			//destructor
			virtual ~ActivityNodeActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual void run()  ;
			
			/*!
			 */ 
			virtual void recieveOffer()  ;
			
			/*!
			 */ 
			virtual std::vector<fUML::Token * > *  takeOfferedTokens()  ;
			
			/*!
			 */ 
			virtual void fire(std::vector<fUML::Token * > *  incomingTokens)  ;
			
			/*!
			 */ 
			virtual void sendOffers(std::vector<fUML::Token * > *  tokens)  ;
			
			/*!
			 */ 
			virtual void terminate()  ;
			
			/*!
			 */ 
			virtual bool isReady()  ;
			
			/*!
			 */ 
			virtual bool getRunning()  ;
			
			/*!
			 */ 
			virtual void addOutgoingEdge(fUML::ActivityEdgeInstance *  edge)  ;
			
			/*!
			 */ 
			virtual void addIncomingEdge(fUML::ActivityEdgeInstance *  edge)  ;
			
			/*!
			 */ 
			virtual void createNodeActivations()  ;
			
			/*!
			 */ 
			virtual void createEdgeInstances()  ;
			
			/*!
			 */ 
			virtual bool isSourceFor(fUML::ActivityEdgeInstance *  edgeInstances)  ;
			
			/*!
			 */ 
			virtual fUML::ActivityExecution *  getActivityExecution()  ;
			
			/*!
			 */ 
			virtual fUML::Object *  getExecutionContext()  ;
			
			/*!
			 */ 
			virtual fUML::Locus *  getExecutionLocus()  ;
			
			/*!
			 */ 
			virtual fUML::ActivityNodeActivation *  getNodeActivation(uml::ActivityNode *  node)  ;
			
			/*!
			 */ 
			virtual void addToken(fUML::Token *  token)  ;
			
			/*!
			 */ 
			virtual int removeToken(fUML::Token *  token)  ;
			
			/*!
			 */ 
			virtual void addTokens(std::vector<fUML::Token * > *  tokens)  ;
			
			/*!
			 */ 
			virtual std::vector<fUML::Token * > *  takeTokens()  ;
			
			/*!
			 */ 
			virtual void clearTokens()  ;
			
			/*!
			 */ 
			virtual std::vector<fUML::Token * > *  getTokens()  ;
			
			/*!
			 */ 
			virtual void suspend()  ;
			
			/*!
			 */ 
			virtual void resume()  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 */ 
			virtual bool isRunning() const ;
			
			/*!
			 */ 
			virtual void setRunning (bool _running); 
			
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::vector<fUML::ActivityEdgeInstance * > *  getOutgoingEdges() const ;
			
			/*!
			 */
			virtual std::vector<fUML::ActivityEdgeInstance * > *  getIncomingEdges() const ;
			
			/*!
			 */
			virtual std::vector<fUML::Token * > *  getHeldTokens() const ;
			
			/*!
			 */
			virtual fUML::ActivityNodeActivationGroup *  getGroup() const ;
			
			/*!
			 */
			virtual void setGroup(fUML::ActivityNodeActivationGroup *  _group) ;
			
			/*!
			 */
			virtual uml::ActivityNode *  getNode() const ;
			
			/*!
			 */
			virtual void setNode(uml::ActivityNode *  _node) ;
			
							
			
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
#endif /* end of include guard: FUML_ACTIVITYNODEACTIVATIONACTIVITYNODEACTIVATIONIMPL_HPP */

