//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef CALCMODEL_PRIMECHECKER_FBDIVIDES_EXECUTION_HPP
#define CALCMODEL_PRIMECHECKER_FBDIVIDES_EXECUTION_HPP

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif
#include <iostream>
#include <memory>
#include "abstractDataTypes/SubsetUnion.hpp"


#include "fUML/impl/OpaqueBehaviorExecutionImpl.hpp"
#include "abstractDataTypes/SubsetUnion.hpp" 


namespace CalcModel 
{
	class FbDividesExecution : public fUML::OpaqueBehaviorExecutionImpl 
	{
		public:
		    //constructor
		    FbDividesExecution(const FbDividesExecution &obj);
		    FbDividesExecution();
		    //destructor
		    virtual ~FbDividesExecution();
		
		    virtual void doBody(std::shared_ptr<Bag<fUML::ParameterValue> > inputParameters, std::shared_ptr<Bag<fUML::ParameterValue> > outputParameters);
		    virtual std::shared_ptr<ecore::EObject> copy() const;
	};
}
#endif /* end of include guard: CALCMODEL_PRIMECHECKER_FBDIVIDES_EXECUTION_HPP */
