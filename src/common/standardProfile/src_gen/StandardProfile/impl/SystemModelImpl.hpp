//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_SYSTEMMODEL_SYSTEMMODELIMPL_HPP
#define STANDARDPROFILE_SYSTEMMODEL_SYSTEMMODELIMPL_HPP

//Model includes
#include "../SystemModel.hpp"
#include "uml/impl/StereotypeImpl.hpp"

class Any;

namespace uml
{
	class Property;
	class Operation;
}

//*********************************
namespace StandardProfile
{
	class SystemModelImpl : virtual public uml::StereotypeImpl, virtual public SystemModel
	{
		public: 
			SystemModelImpl(const SystemModelImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;  
			SystemModelImpl& operator=(SystemModelImpl const&);

		protected:
			friend class StandardProfileFactoryImpl;
			//constructor
			SystemModelImpl();
			virtual std::shared_ptr<SystemModel> getThisSystemModelPtr();
			virtual void setThisSystemModelPtr(std::weak_ptr<SystemModel> thisSystemModelPtr);


		public:

			//destructor
			virtual ~SystemModelImpl();

			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Model> getBase_Model() const ;
			virtual void setBase_Model(std::weak_ptr<uml::Model> _base_Model);
			
			
			
			//*********************************
			// Union Getter
			//*********************************
			

		protected:
			virtual std::shared_ptr<uml::Class> getMetaClass() const;
			virtual void instantiate();
			virtual void destroy();

		public:
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
			//Get
			virtual std::shared_ptr<Any> get(std::shared_ptr<uml::Property> _property) const ;
			virtual std::shared_ptr<Any> get(std::string _qualifiedName) const ;
			virtual std::shared_ptr<Any> get(unsigned long _uID) const ;
			//Set
			virtual void set(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value) ;
			virtual void set(std::string _qualifiedName, std::shared_ptr<Any> value) ;
			virtual void set(unsigned long _uID, std::shared_ptr<Any> value) ;
			//Add
			virtual void add(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value, int insertAt = -1) ;
			virtual void add(std::string _qualifiedName, std::shared_ptr<Any> value, int insertAt = -1) ;
			virtual void add(unsigned long _uID, std::shared_ptr<Any> value, int insertAt = -1) ;
			//Unset
			virtual void unset(std::shared_ptr<uml::Property> _property) ;
			virtual void unset(std::string _qualifiedName) ;
			virtual void unset(unsigned long _uID) ;
		
			//*********************************
			// Operation Invocation
			//*********************************
			//Invoke
			virtual std::shared_ptr<Any> invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> _arguments) ;
			virtual std::shared_ptr<Any> invoke(std::string _qualifiedName, std::shared_ptr<Bag<Any>> _arguments) ;
			virtual std::shared_ptr<Any> invoke(unsigned long _uID, std::shared_ptr<Bag<Any>> _arguments) ;

		private:
			std::weak_ptr<SystemModel> m_thisSystemModelPtr;
	};
}
#endif /* end of include guard: STANDARDPROFILE_SYSTEMMODEL_SYSTEMMODELIMPL_HPP */
