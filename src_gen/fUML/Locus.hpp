//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_LOCUS_HPP
#define FUML_LOCUS_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

#define ACTIVITY_DEBUG_ON

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

#include <string>
#include <map>
#include <vector>
#include "SubsetUnion.hpp"
#include "boost/shared_ptr.hpp"
#include "boost/any.hpp"

//*********************************
// generated Includes

//Forward Declaration for used types
namespace uml 
{
	class Class;
}

namespace uml 
{
	class Classifier;
}

namespace fUML 
{
	class ExecutionFactory;
}

namespace fUML 
{
	class Executor;
}

namespace fUML 
{
	class ExtensionalValue;
}

namespace fUML 
{
	class Object;
}

// base class includes

// enum includes

#include "EObject.hpp"

//*********************************
namespace fUML 
{
	/*!
	 */
	class Locus : virtual public ecore::EObject 
	{
		public:
 			Locus(const Locus &) {}
			Locus& operator=(Locus const&) = delete;
	
		protected:
			Locus(){}

		public:
			virtual ecore::EObject* copy() const = 0;

			//destructor
			virtual ~Locus() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual bool conforms(std::shared_ptr<uml::Classifier>  type,std::shared_ptr<uml::Classifier>  classifier)  = 0;
			
			/*!
			 */ 
			virtual void assignExecutor(std::shared_ptr<fUML::Executor>  executor)  = 0;
			
			/*!
			 */ 
			virtual void assignFactory(std::shared_ptr<fUML::ExecutionFactory>  factory)  = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<Bag<fUML::ExtensionalValue> > retrieveExtent(std::shared_ptr<uml::Classifier>  classifier)  = 0;
			
			/*!
			 */ 
			virtual void add(std::shared_ptr<fUML::ExtensionalValue>  value)  = 0;
			
			/*!
			 */ 
			virtual void remove(std::shared_ptr<fUML::ExtensionalValue>  value)  = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Object> instantiate(std::shared_ptr<uml::Class>  type)  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<fUML::Executor > getExecutor() const = 0;
			
			/*!
			 */
			virtual void setExecutor(std::shared_ptr<fUML::Executor> _executor_executor) = 0;
			/*!
			 */
			virtual std::shared_ptr<fUML::ExecutionFactory > getFactory() const = 0;
			
			/*!
			 */
			virtual void setFactory(std::shared_ptr<fUML::ExecutionFactory> _factory_factory) = 0;
			/*!
			 */
			virtual std::shared_ptr< Bag<fUML::ExtensionalValue> > getExtensionalValues() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 */
			std::shared_ptr<fUML::Executor > m_executor;
			/*!
			 */
			std::shared_ptr<fUML::ExecutionFactory > m_factory;
			/*!
			 */
			std::shared_ptr< Bag<fUML::ExtensionalValue> > m_extensionalValues;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			 
	};

}
#endif /* end of include guard: FUML_LOCUS_HPP */

