//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_TYPE_TYPEIMPL_HPP
#define STANDARDPROFILE_TYPE_TYPEIMPL_HPP

//Model includes
#include "../Type.hpp"
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
	class TypeImpl : virtual public uml::StereotypeImpl, virtual public Type
	{
		public: 
			TypeImpl(const TypeImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;  
			TypeImpl& operator=(TypeImpl const&);

		protected:
			friend class StandardProfileFactoryImpl;
			//constructor
			TypeImpl();
			virtual std::shared_ptr<Type> getThisTypePtr();
			virtual void setThisTypePtr(std::weak_ptr<Type> thisTypePtr);


		public:

			//destructor
			virtual ~TypeImpl();

			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Class> getBase_Class() const ;
			virtual void setBase_Class(std::weak_ptr<uml::Class> _base_Class);
			
			
			
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
			//Remove
			virtual void remove(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value) ;
			virtual void remove(std::string _qualifiedName, std::shared_ptr<Any> value) ;
			virtual void remove(unsigned long _uID, std::shared_ptr<Any> value) ;
		
			//*********************************
			// Operation Invocation
			//*********************************
			//Invoke
			virtual std::shared_ptr<Any> invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> _arguments) ;
			virtual std::shared_ptr<Any> invoke(std::string _qualifiedName, std::shared_ptr<Bag<Any>> _arguments) ;
			virtual std::shared_ptr<Any> invoke(unsigned long _uID, std::shared_ptr<Bag<Any>> _arguments) ;

		private:
			std::weak_ptr<Type> m_thisTypePtr;
	};
}
#endif /* end of include guard: STANDARDPROFILE_TYPE_TYPEIMPL_HPP */
