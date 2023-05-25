//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EXPRESSIONS_VARDECLARATIONEXPVARDECLARATIONEXPIMPL_HPP
#define OCL_EXPRESSIONS_VARDECLARATIONEXPVARDECLARATIONEXPIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../VarDeclarationExp.hpp"

#include "ocl/Expressions/impl/ExpressionsFactoryImpl.hpp"
#include "ocl/Expressions/impl/OclExpressionImpl.hpp"

//*********************************
namespace ocl::Expressions 
{
	class OCL_API VarDeclarationExpImpl : virtual public OclExpressionImpl, virtual public VarDeclarationExp 
	{
		public: 
			VarDeclarationExpImpl(const VarDeclarationExpImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			VarDeclarationExpImpl& operator=(VarDeclarationExpImpl const&); 

		protected:
			friend class ocl::Expressions::ExpressionsFactoryImpl;
			VarDeclarationExpImpl();
			virtual std::shared_ptr<ocl::Expressions::VarDeclarationExp> getThisVarDeclarationExpPtr() const;
			virtual void setThisVarDeclarationExpPtr(std::weak_ptr<ocl::Expressions::VarDeclarationExp> thisVarDeclarationExpPtr);

			//Additional constructors for the containments back reference
			VarDeclarationExpImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id);
			//Additional constructors for the containments back reference
			VarDeclarationExpImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			VarDeclarationExpImpl(std::weak_ptr<ocl::Expressions::OclExpression> par_initExpression);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			VarDeclarationExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int reference_id);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			VarDeclarationExpImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall);
			//Additional constructors for the containments back reference
			VarDeclarationExpImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			VarDeclarationExpImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression);

		public:
			//destructor
			virtual ~VarDeclarationExpImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual std::string getVarName() const ;
			virtual void setVarName (std::string _varName);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<ocl::Expressions::OclExpression> getAssignedOclExp() const ;
			virtual void setAssignedOclExp(std::shared_ptr<ocl::Expressions::OclExpression>) ;
			virtual std::weak_ptr<ocl::Expressions::OclExpression> getInitExpression() const ;
			virtual void setInitExpression(std::weak_ptr<ocl::Expressions::OclExpression>) ;
			virtual std::shared_ptr<ocl::Expressions::TypeExp> getVarType() const ;
			virtual void setVarType(std::shared_ptr<ocl::Expressions::TypeExp>) ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			
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
			virtual std::shared_ptr<Any> eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, const std::shared_ptr<Any>& newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID,const std::shared_ptr<Bag<Any>>& arguments) ;

		private:
			std::weak_ptr<ocl::Expressions::VarDeclarationExp> m_thisVarDeclarationExpPtr;
	};
}
#endif /* end of include guard: OCL_EXPRESSIONS_VARDECLARATIONEXPVARDECLARATIONEXPIMPL_HPP */
