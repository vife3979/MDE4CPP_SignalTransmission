//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIVITIES_OBJECTTOKENOBJECTTOKENIMPL_HPP
#define FUML_SEMANTICS_ACTIVITIES_OBJECTTOKENOBJECTTOKENIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../ObjectToken.hpp"

#include "fUML/Semantics/Activities/impl/ActivitiesFactoryImpl.hpp"
#include "fUML/Semantics/Activities/impl/TokenImpl.hpp"

//*********************************
namespace fUML::Semantics::Activities 
{
	class FUML_API ObjectTokenImpl : virtual public TokenImpl, virtual public ObjectToken 
	{
		public: 
			ObjectTokenImpl(const ObjectTokenImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ObjectTokenImpl& operator=(ObjectTokenImpl const&); 

		protected:
			friend class fUML::Semantics::Activities::ActivitiesFactoryImpl;
			ObjectTokenImpl();
			virtual std::shared_ptr<fUML::Semantics::Activities::ObjectToken> getThisObjectTokenPtr() const;
			virtual void setThisObjectTokenPtr(std::weak_ptr<fUML::Semantics::Activities::ObjectToken> thisObjectTokenPtr);

			//Additional constructors for the containments back reference
			ObjectTokenImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivation> par_holder);

		public:
			//destructor
			virtual ~ObjectTokenImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<fUML::Semantics::Activities::Token> _copy() ;
			virtual bool equals(const std::shared_ptr<fUML::Semantics::Activities::Token>& other) ;
			virtual bool isControl() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual std::shared_ptr<Any> getValue() const ;
			virtual void setValue (const std::shared_ptr<Any>& _value);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			
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
			std::weak_ptr<fUML::Semantics::Activities::ObjectToken> m_thisObjectTokenPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIES_OBJECTTOKENOBJECTTOKENIMPL_HPP */
