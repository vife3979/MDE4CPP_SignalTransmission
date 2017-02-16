//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_ACTIVITYNODEACTIVATIONGROUP_HPP
#define FUML_ACTIVITYNODEACTIVATIONGROUP_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

#include <string>
#include <map>
#include <vector>
#include "boost/any.hpp"

//*********************************
// generated Includes

//Forward Declaration for used types
namespace uml 
{
	class ActivityEdge;
}

namespace fUML 
{
	class ActivityEdgeInstance;
}

namespace fUML 
{
	class ActivityExecution;
}

namespace uml 
{
	class ActivityNode;
}

namespace fUML 
{
	class ActivityNodeActivation;
}

namespace fUML 
{
	class ActivityParameterNodeActivation;
}

namespace fUML 
{
	class StructuredActivityNodeActivation;
}

// base class includes

// enum includes

#include "EObject.hpp"

//*********************************
namespace fUML 
{
	/*!
	 */
	class ActivityNodeActivationGroup : virtual public ecore::EObject 
	{
		public:
 			ActivityNodeActivationGroup(const ActivityNodeActivationGroup &) {}
			ActivityNodeActivationGroup& operator=(ActivityNodeActivationGroup const&) = delete;
	
		protected:
			ActivityNodeActivationGroup(){}

		public:
			virtual ecore::EObject* copy() const = 0;

			//destructor
			virtual ~ActivityNodeActivationGroup() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual void run(std::vector<fUML::ActivityNodeActivation * > *  activations)  = 0;
			
			/*!
			 */ 
			virtual bool checkIncomingEdges(std::vector<fUML::ActivityEdgeInstance * > *  incomingEdges,std::vector<fUML::ActivityNodeActivation * > *  activations)  = 0;
			
			/*!
			 */ 
			virtual void activate(std::vector<uml::ActivityNode * > *  nodes,std::vector<uml::ActivityEdge * > *  edges)  = 0;
			
			/*!
			 */ 
			virtual void runNodes(std::vector<uml::ActivityNode * > *  nodes)  = 0;
			
			/*!
			 */ 
			virtual void terminateAll()  = 0;
			
			/*!
			 */ 
			virtual void createNodeActivations(std::vector<uml::ActivityNode * > *  nodes)  = 0;
			
			/*!
			 */ 
			virtual fUML::ActivityNodeActivation *  createNodeActivation(uml::ActivityNode *  node)  = 0;
			
			/*!
			 */ 
			virtual void addNodeActivation(fUML::ActivityNodeActivation *  activation)  = 0;
			
			/*!
			 */ 
			virtual fUML::ActivityNodeActivation *  getNodeActivation(uml::ActivityNode *  node)  = 0;
			
			/*!
			 */ 
			virtual void createEdgeInstance(std::vector<uml::ActivityEdge * > *  edges)  = 0;
			
			/*!
			 */ 
			virtual void addEdgeInstance(fUML::ActivityEdgeInstance *  instance)  = 0;
			
			/*!
			 */ 
			virtual fUML::ActivityExecution *  retrieveActivityExecution()  = 0;
			
			/*!
			 */ 
			virtual std::vector<fUML::ActivityParameterNodeActivation * > *  getOutputParameterNodeActivations()  = 0;
			
			/*!
			 */ 
			virtual void resume(fUML::ActivityNodeActivation *  activation)  = 0;
			
			/*!
			 */ 
			virtual void suspend(fUML::ActivityNodeActivation *  activation)  = 0;
			
			/*!
			 */ 
			virtual bool isSuspended()  = 0;
			
			/*!
			 */ 
			virtual bool hasSourceFor(fUML::ActivityEdgeInstance *  edgeInstance)  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::vector<fUML::ActivityEdgeInstance * > *  getEdgeInstances() const = 0;
			
			/*!
			 */
			virtual std::vector<fUML::ActivityNodeActivation * > *  getNodeActivations() const = 0;
			
			/*!
			 */
			virtual fUML::ActivityExecution *  getActivityExecution() const = 0;
			
			/*!
			 */
			virtual void setActivityExecution(fUML::ActivityExecution *  _activityExecution) = 0;
			
			/*!
			 */
			virtual fUML::StructuredActivityNodeActivation *  getContainingNodeActivation() const = 0;
			
			/*!
			 */
			virtual void setContainingNodeActivation(fUML::StructuredActivityNodeActivation *  _containingNodeActivation) = 0;
			
			/*!
			 */
			virtual std::vector<fUML::ActivityNodeActivation * > *  getSuspendedActivations() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 */
			std::vector<fUML::ActivityEdgeInstance * > *  m_edgeInstances =  nullptr ;
			/*!
			 */
			std::vector<fUML::ActivityNodeActivation * > *  m_nodeActivations =  nullptr ;
			/*!
			 */
			fUML::ActivityExecution *  m_activityExecution =  nullptr ;
			/*!
			 */
			fUML::StructuredActivityNodeActivation *  m_containingNodeActivation =  nullptr ;
			/*!
			 */
			std::vector<fUML::ActivityNodeActivation * > *  m_suspendedActivations =  nullptr ;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			 
	};

}
#endif /* end of include guard: FUML_ACTIVITYNODEACTIVATIONGROUP_HPP */

