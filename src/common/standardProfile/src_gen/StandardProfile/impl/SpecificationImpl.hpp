//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_SPECIFICATION_SPECIFICATIONIMPL_HPP
#define STANDARDPROFILE_SPECIFICATION_SPECIFICATIONIMPL_HPP

//Model includes
#include "../Specification.hpp"
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
	class SpecificationImpl : virtual public uml::StereotypeImpl, virtual public Specification
	{
		public: 
			SpecificationImpl(const SpecificationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;  
			SpecificationImpl& operator=(SpecificationImpl const&);

		protected:
			friend class StandardProfileFactoryImpl;
			//constructor
			SpecificationImpl();
			virtual std::shared_ptr<Specification> getThisSpecificationPtr();
			virtual void setThisSpecificationPtr(std::weak_ptr<Specification> thisSpecificationPtr);


		public:

			//destructor
			virtual ~SpecificationImpl();

			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Classifier> getBase_Classifier() const ;
			virtual void setBase_Classifier(std::weak_ptr<uml::Classifier> _base_Classifier);
			
			
			
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
			std::weak_ptr<Specification> m_thisSpecificationPtr;
	};
}
#endif /* end of include guard: STANDARDPROFILE_SPECIFICATION_SPECIFICATIONIMPL_HPP */
