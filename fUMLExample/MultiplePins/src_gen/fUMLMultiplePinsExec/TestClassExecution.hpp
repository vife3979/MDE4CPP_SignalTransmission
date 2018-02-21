//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef FUMLMULTIPLEPINS_TESTCLASS_EXECUTION_HPP
#define FUMLMULTIPLEPINS_TESTCLASS_EXECUTION_HPP

#include "fUML/impl/ObjectImpl.hpp"

template <class T> 
class Bag;

namespace fUMLMultiplePins
{
	class TestClass;
}

namespace fUMLMultiplePins 
{
	class TestClassExecution : public fUML::ObjectImpl 
	{
		public:
		    //constructors
		    TestClassExecution(TestClassExecution &obj);
		    TestClassExecution(std::shared_ptr<TestClass>);
		    TestClassExecution(std::shared_ptr<Bag<TestClass>>);
		 	TestClassExecution();
		    //destructor
		    virtual ~TestClassExecution();
		
		    virtual std::shared_ptr<ecore::EObject> copy();
			
			std::shared_ptr<TestClass> getUmlValue() const;
			std::shared_ptr<Bag<TestClass>> getUmlValues() const;
			void setUmlValue(std::shared_ptr<TestClass>);
			void setUmlValues(std::shared_ptr<Bag<TestClass>>);;
		
		protected:
			std::shared_ptr<TestClass> m_umlValue = nullptr;
			std::shared_ptr<Bag<TestClass>> m_umlValues = nullptr;
	};
}
#endif /* end of include guard: FUMLMULTIPLEPINS_TESTCLASS_EXECUTION_HPP */
