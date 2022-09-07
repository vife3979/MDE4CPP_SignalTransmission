//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef UML4CPPPROFILE_NONEXECUTABLE_NONEXECUTABLEIMPL_HPP
#define UML4CPPPROFILE_NONEXECUTABLE_NONEXECUTABLEIMPL_HPP

//Model includes
#include "../NonExecutable.hpp"
#include "uml/impl/StereotypeImpl.hpp"

class Any;

namespace uml
{
	class Property;
	class Operation;
}

//*********************************
namespace UML4CPPProfile
{
	class NonExecutableImpl : virtual public uml::StereotypeImpl, virtual public NonExecutable
	{
		public: 
			NonExecutableImpl(const NonExecutableImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;  
			NonExecutableImpl& operator=(NonExecutableImpl const&);

		protected:
			friend class UML4CPPProfileFactoryImpl;
			//constructor
			NonExecutableImpl();
			virtual std::shared_ptr<NonExecutable> getThisNonExecutablePtr();
			virtual void setThisNonExecutablePtr(std::weak_ptr<NonExecutable> thisNonExecutablePtr);


		public:

			//destructor
			virtual ~NonExecutableImpl();

			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::NamedElement> getBase_NamedElement() const ;
			virtual void setBase_NamedElement(std::weak_ptr<uml::NamedElement> _base_NamedElement);
			
			
			
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
			std::weak_ptr<NonExecutable> m_thisNonExecutablePtr;
	};
}
#endif /* end of include guard: UML4CPPPROFILE_NONEXECUTABLE_NONEXECUTABLEIMPL_HPP */
