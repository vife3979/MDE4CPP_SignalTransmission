//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_CREATE_CREATEIMPL_HPP
#define STANDARDPROFILE_CREATE_CREATEIMPL_HPP

//Model includes
#include "../Create.hpp"
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
	class CreateImpl : virtual public uml::StereotypeImpl, virtual public Create
	{
		public: 
			CreateImpl(const CreateImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;  
			CreateImpl& operator=(CreateImpl const&);

		protected:
			friend class StandardProfileFactoryImpl;
			//constructor
			CreateImpl();
			virtual std::shared_ptr<Create> getThisCreatePtr();
			virtual void setThisCreatePtr(std::weak_ptr<Create> thisCreatePtr);


		public:

			//destructor
			virtual ~CreateImpl();

			//*********************************
			// Operations
			//*********************************
			//*********************************
			// Attributes Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::BehavioralFeature> getBase_BehavioralFeature() const ;
			virtual void setBase_BehavioralFeature(std::weak_ptr<uml::BehavioralFeature> _base_BehavioralFeature);
			virtual std::weak_ptr<uml::Usage> getBase_Usage() const ;
			virtual void setBase_Usage(std::weak_ptr<uml::Usage> _base_Usage);
			
			
			
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
			std::weak_ptr<Create> m_thisCreatePtr;
	};
}
#endif /* end of include guard: STANDARDPROFILE_CREATE_CREATEIMPL_HPP */
