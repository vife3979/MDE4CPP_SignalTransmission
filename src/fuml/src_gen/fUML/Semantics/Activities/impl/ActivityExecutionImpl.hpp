//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIVITIES_ACTIVITYEXECUTIONACTIVITYEXECUTIONIMPL_HPP
#define FUML_SEMANTICS_ACTIVITIES_ACTIVITYEXECUTIONACTIVITYEXECUTIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../ActivityExecution.hpp"

#include "fUML/Semantics/Activities/impl/ActivitiesFactoryImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/ExecutionImpl.hpp"

//*********************************
namespace fUML::Semantics::Activities 
{
	class ActivityExecutionImpl :virtual public fUML::Semantics::CommonBehavior::ExecutionImpl, virtual public ActivityExecution 
	{
		public: 
			ActivityExecutionImpl(const ActivityExecutionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			ActivityExecutionImpl& operator=(ActivityExecutionImpl const&) = delete;

		protected:
			friend class fUML::Semantics::Activities::ActivitiesFactoryImpl;
			ActivityExecutionImpl();
			virtual std::shared_ptr<ActivityExecution> getThisActivityExecutionPtr() const;
			virtual void setThisActivityExecutionPtr(std::weak_ptr<ActivityExecution> thisActivityExecutionPtr);



		public:
			//destructor
			virtual ~ActivityExecutionImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual void execute() ;
			
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Semantics::Values::Value> new_() ;
			
			/*!
			 */ 
			virtual void terminate() ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > getActivationGroup() const ;
			
			/*!
			 */
			virtual void setActivationGroup(std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> _activationGroup_activationGroup) ;
							
			
			//*********************************
			// Union Getter
			//*********************************
			 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************

			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<ActivityExecution> m_thisActivityExecutionPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIES_ACTIVITYEXECUTIONACTIVITYEXECUTIONIMPL_HPP */
