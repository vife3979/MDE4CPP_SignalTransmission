//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef UML4CPPPROFILE_UML4CPPPACKAGE_UML4CPPPACKAGEIMPL_HPP
#define UML4CPPPROFILE_UML4CPPPACKAGE_UML4CPPPACKAGEIMPL_HPP

//Model includes
#include "../UML4CPPPackage.hpp"
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
	class UML4CPPPackageImpl : virtual public uml::StereotypeImpl, virtual public UML4CPPPackage
	{
		public: 
			UML4CPPPackageImpl(const UML4CPPPackageImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;  
			UML4CPPPackageImpl& operator=(UML4CPPPackageImpl const&);

		protected:
			friend class UML4CPPProfileFactoryImpl;
			//constructor
			UML4CPPPackageImpl();
			virtual std::shared_ptr<UML4CPPPackage> getThisUML4CPPPackagePtr();
			virtual void setThisUML4CPPPackagePtr(std::weak_ptr<UML4CPPPackage> thisUML4CPPPackagePtr);


		public:

			//destructor
			virtual ~UML4CPPPackageImpl();

			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Package> getBase_Package() const ;
			virtual void setBase_Package(std::weak_ptr<uml::Package> _base_Package);
			virtual std::string getEclipseURI() const ;
			virtual void setEclipseURI(std::string _eclipseURI);
			virtual bool isIgnoreNamespace() const ;
			virtual void setIgnoreNamespace(bool _ignoreNamespace);
			virtual bool isPackageOnly() const ;
			virtual void setPackageOnly(bool _packageOnly);
			
			
			
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
			std::weak_ptr<UML4CPPPackage> m_thisUML4CPPPackagePtr;
	};
}
#endif /* end of include guard: UML4CPPPROFILE_UML4CPPPACKAGE_UML4CPPPACKAGEIMPL_HPP */
