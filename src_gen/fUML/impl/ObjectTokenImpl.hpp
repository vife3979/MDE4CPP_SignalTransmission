//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_OBJECTTOKENOBJECTTOKENIMPL_HPP
#define FUML_OBJECTTOKENOBJECTTOKENIMPL_HPP

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

//*********************************
// generated Includes

//Model includes
#include "../ObjectToken.hpp"

#include "impl/TokenImpl.hpp"

#include "SubsetUnion.hpp"

 #include "FUMLFactory.hpp"


//*********************************
namespace fUML 
{
	class ObjectTokenImpl :virtual public TokenImpl, virtual public ObjectToken 
	{
		public: 
			ObjectTokenImpl(const ObjectTokenImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			ObjectTokenImpl& operator=(ObjectTokenImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			ObjectTokenImpl();

		public:
			//destructor
			virtual ~ObjectTokenImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual bool equals(std::shared_ptr<fUML::Token>  other)  ;
			
			/*!
			 */ 
			virtual bool isControl()  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<fUML::Value > getValue() const ;
			
			/*!
			 */
			virtual void setValue(std::shared_ptr<fUML::Value> _value_value) ;
							
			
			//*********************************
			// Union Getter
			//*********************************
			 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
			
			virtual boost::any eGet(int featureID, bool resolve, bool coreType) const ;
			
		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
	};
}
#endif /* end of include guard: FUML_OBJECTTOKENOBJECTTOKENIMPL_HPP */

