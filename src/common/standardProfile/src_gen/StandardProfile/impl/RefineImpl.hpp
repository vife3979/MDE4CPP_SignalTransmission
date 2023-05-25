//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_REFINE_REFINEIMPL_HPP
#define STANDARDPROFILE_REFINE_REFINEIMPL_HPP

//Model includes
#include "../Refine.hpp"
#include "uml/impl/StereotypeImpl.hpp"

class Any;

namespace uml
{
	class Property;
	class Operation;
	class OpaqueBehavior;
}

//*********************************
namespace StandardProfile
{
	class RefineImpl : virtual public uml::StereotypeImpl, virtual public Refine
	{
		public: 
			RefineImpl(const RefineImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;  
			RefineImpl& operator=(RefineImpl const&);

		protected:
			friend class StandardProfileFactoryImpl;
			//constructor
			RefineImpl();
			virtual std::shared_ptr<Refine> getThisRefinePtr();
			virtual void setThisRefinePtr(std::weak_ptr<Refine> thisRefinePtr);


		public:

			//destructor
			virtual ~RefineImpl();

			//*********************************
			// Operations
			//*********************************
			//*********************************
			// Attributes Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Abstraction> getBase_Abstraction() const ;
			virtual void setBase_Abstraction(std::weak_ptr<uml::Abstraction> _base_Abstraction);
			
			
			
			//*********************************
			// Union Getter
			//*********************************
			

		protected:
			virtual std::shared_ptr<uml::Class> getMetaClass() const;
			virtual void instantiate();
			virtual void destroy();

		public:
			//**************************************
			// StructuralFeature Getter & Setter
			//**************************************
			//Get
			virtual std::shared_ptr<Any> get(const std::shared_ptr<uml::Property>& _property) const ;
			virtual std::shared_ptr<Any> get(std::string _qualifiedName) const ;
			virtual std::shared_ptr<Any> get(unsigned long _uID) const ;
			//Set
			virtual void set(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value) ;
			virtual void set(std::string _qualifiedName, const std::shared_ptr<Any>& value) ;
			virtual void set(unsigned long _uID, const std::shared_ptr<Any>& value) ;
			//Add
			virtual void add(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int insertAt = -1) ;
			virtual void add(std::string _qualifiedName, const std::shared_ptr<Any>& value, int insertAt = -1) ;
			virtual void add(unsigned long _uID, const std::shared_ptr<Any>& value, int insertAt = -1) ;
			//Unset
			virtual void unset(const std::shared_ptr<uml::Property>& _property) ;
			virtual void unset(std::string _qualifiedName) ;
			virtual void unset(unsigned long _uID) ;
			//Remove
			virtual void remove(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value) ;
			virtual void remove(std::string _qualifiedName, const std::shared_ptr<Any>& value) ;
			virtual void remove(unsigned long _uID, const std::shared_ptr<Any>& value) ;
		
			//**************************************
			// Operation & OpaqueBehavior Invocation
			//**************************************
			//Operation invocation
			virtual std::shared_ptr<Any> invoke(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments) ;
			virtual std::shared_ptr<Any> invoke(std::string _qualifiedName, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments) ;
			virtual std::shared_ptr<Any> invoke(unsigned long _uID, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments) ;
			
			//OpaqueBehavior invocation
			virtual std::shared_ptr<Any> invoke(const std::shared_ptr<uml::OpaqueBehavior>& _opaqueBehavior, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments) ;

		private:
			std::weak_ptr<Refine> m_thisRefinePtr;
	};
}
#endif /* end of include guard: STANDARDPROFILE_REFINE_REFINEIMPL_HPP */
