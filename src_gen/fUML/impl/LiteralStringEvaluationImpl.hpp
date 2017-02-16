//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_LITERALSTRINGEVALUATIONLITERALSTRINGEVALUATIONIMPL_HPP
#define FUML_LITERALSTRINGEVALUATIONLITERALSTRINGEVALUATIONIMPL_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

//*********************************
// generated Includes

//Model includes
#include "../LiteralStringEvaluation.hpp"

#include "impl/LiteralEvaluationImpl.hpp"

#include "FUMLFactory.hpp"
#include "LiteralString.hpp"

//*********************************
namespace fUML 
{
	class LiteralStringEvaluationImpl :virtual public LiteralEvaluationImpl, virtual public LiteralStringEvaluation
	{
		public: 
			LiteralStringEvaluationImpl(const LiteralStringEvaluationImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			LiteralStringEvaluationImpl& operator=(LiteralStringEvaluationImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			LiteralStringEvaluationImpl();

		public:
			//destructor
			virtual ~LiteralStringEvaluationImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual fUML::Value *  evaluate()  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
							
			
			//*********************************
			// Union Getter
			//*********************************
			 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
			
			virtual boost::any eGet(int featureID, bool resolve, bool coreType) const ;
			
		protected:
			virtual ecore::EClass* eStaticClass() const;
	};
}
#endif /* end of include guard: FUML_LITERALSTRINGEVALUATIONLITERALSTRINGEVALUATIONIMPL_HPP */

