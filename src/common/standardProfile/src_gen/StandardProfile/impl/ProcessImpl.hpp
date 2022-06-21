//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_PROCESS_PROCESSIMPL_HPP
#define STANDARDPROFILE_PROCESS_PROCESSIMPL_HPP

//Model includes
#include "../Process.hpp"
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
	class ProcessImpl : virtual public uml::StereotypeImpl, virtual public Process
	{
		public: 
			ProcessImpl(const ProcessImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;  
			ProcessImpl& operator=(ProcessImpl const&);

		protected:
			friend class StandardProfileFactoryImpl;
			//constructor
			ProcessImpl();
			virtual std::shared_ptr<Process> getThisProcessPtr();
			virtual void setThisProcessPtr(std::weak_ptr<Process> thisProcessPtr);


		public:

			//destructor
			virtual ~ProcessImpl();

			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Component> getBase_Component() const ;
			virtual void setBase_Component(std::weak_ptr<uml::Component> _base_Component);
			
			
			
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
			std::weak_ptr<Process> m_thisProcessPtr;
	};
}
#endif /* end of include guard: STANDARDPROFILE_PROCESS_PROCESSIMPL_HPP */
