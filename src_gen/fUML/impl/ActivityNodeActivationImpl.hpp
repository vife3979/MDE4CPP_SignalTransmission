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

#define ACTIVITY_DEBUG_ON

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//*********************************
// generated Includes

//Model includes
#include "../ActivityNodeActivation.hpp"

#include "impl/SemanticVisitorImpl.hpp"

#include "SubsetUnion.hpp"

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
			virtual std::shared_ptr<Bag<fUML::Token> > takeOfferedTokens()  ;
			
			/*!
			 */ 
			virtual void fire(std::shared_ptr<Bag<fUML::Token> >  incomingTokens)  ;
			
			/*!
			 */ 
			virtual void sendOffers(std::shared_ptr<Bag<fUML::Token> >  tokens)  ;
			
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
			virtual void addOutgoingEdge(std::shared_ptr<fUML::ActivityEdgeInstance>  edge)  ;
			
			/*!
			 */ 
			virtual void addIncomingEdge(std::shared_ptr<fUML::ActivityEdgeInstance>  edge)  ;
			
			/*!
			 */ 
			virtual void createNodeActivations()  ;
			
			/*!
			 */ 
			virtual void createEdgeInstances()  ;
			
			/*!
			 */ 
			virtual bool isSourceFor(std::shared_ptr<fUML::ActivityEdgeInstance>  edgeInstances)  ;
			
			/*!
			 */ 
			virtual std::shared_ptr<fUML::ActivityExecution> getActivityExecution()  ;
			
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Object> getExecutionContext()  ;
			
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Locus> getExecutionLocus()  ;
			
			/*!
			 */ 
			virtual std::shared_ptr<fUML::ActivityNodeActivation> getNodeActivation(std::shared_ptr<uml::ActivityNode>  node)  ;
			
			/*!
			 */ 
			virtual void addToken(std::shared_ptr<fUML::Token>  token)  ;
			
			/*!
			 */ 
			virtual int removeToken(std::shared_ptr<fUML::Token>  token)  ;
			
			/*!
			 */ 
			virtual void addTokens(std::shared_ptr<Bag<fUML::Token> >  tokens)  ;
			
			/*!
			 */ 
			virtual std::shared_ptr<Bag<fUML::Token> > takeTokens()  ;
			
			/*!
			 */ 
			virtual void clearTokens()  ;
			
			/*!
			 */ 
			virtual std::shared_ptr<Bag<fUML::Token> > getTokens()  ;
			
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
			virtual std::shared_ptr< Bag<fUML::ActivityEdgeInstance> > getOutgoingEdges() const ;
			
			/*!
			 */
			virtual std::shared_ptr< Bag<fUML::ActivityEdgeInstance> > getIncomingEdges() const ;
			
			/*!
			 */
			virtual std::shared_ptr< Bag<fUML::Token> > getHeldTokens() const ;
			
			/*!
			 */
			virtual std::shared_ptr<fUML::ActivityNodeActivationGroup > getGroup() const ;
			
			/*!
			 */
			virtual void setGroup(std::shared_ptr<fUML::ActivityNodeActivationGroup> _group_group) ;
			/*!
			 */
			virtual std::shared_ptr<uml::ActivityNode > getNode() const ;
			
			/*!
			 */
			virtual void setNode(std::shared_ptr<uml::ActivityNode> _node_node) ;
							
			
			//*********************************
			// Union Getter
			//*********************************
			 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
			
			virtual boost::any eGet(int featureID, bool resolve, bool coreType) const ;
			
		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
	};
}
#endif /* end of include guard: FUML_ACTIVITYNODEACTIVATIONACTIVITYNODEACTIVATIONIMPL_HPP */

