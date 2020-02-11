//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_REFINE_REFINEIMPL_HPP
#define STANDARDPROFILE_REFINE_REFINEIMPL_HPP

#include <functional>

//Model includes
#include "../Refine.hpp"
#include "uml/impl/StereotypeImpl.hpp"
#include "uml/Property.hpp"

class AnyObject;
typedef std::shared_ptr<AnyObject> Any;

namespace uml
{
	class Property;
}

//*********************************
namespace StandardProfile
{
	class RefineImpl : virtual public uml::StereotypeImpl, virtual public Refine
	{
		public: 
			RefineImpl(const RefineImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			RefineImpl& operator=(RefineImpl const&) = delete;

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
			virtual void setBase_Abstraction (std::weak_ptr<uml::Abstraction> _base_Abstraction);
			

		protected:
			virtual std::shared_ptr<uml::Class> getMetaClass();

		public:
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
			virtual Any get(std::shared_ptr<uml::Property> _property) const ;
			virtual void set(std::shared_ptr<uml::Property> _property, Any value) ;
			virtual void unset(std::shared_ptr<uml::Property> _property) ;
			
		
		private:
			std::weak_ptr<Refine> m_thisRefinePtr;
			std::map<std::string,std::function<Any()>> m_getterMap;
			std::map<std::string,std::function<void(Any)>> m_setterMap;
			std::map<std::string,std::function<void()>> m_unsetterMap;
	};
}
#endif /* end of include guard: STANDARDPROFILE_REFINE_REFINEIMPL_HPP */
