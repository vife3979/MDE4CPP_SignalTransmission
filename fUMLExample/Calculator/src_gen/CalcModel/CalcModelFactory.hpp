//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef CALCMODEL_FACTORY_HPP
#define CALCMODEL_FACTORY_HPP

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif
#include <iostream>
#include <memory>
#include "abstractDataTypes/SubsetUnion.hpp"


#include "uml/Factory.hpp"

namespace CalcModel 
{
	class CheckIfPrime;
	class PrimeChecker;
	class CalcModelPackage;
	class CalcModelFactory;
}

namespace CalcModel
{
	class CalcModelFactory : virtual public uml::Factory 
	{ 
		protected:
			//protected default construcotr
			CalcModelFactory(){}

			//Singleton Instance and Getter
			
			private:
				static std::shared_ptr<CalcModelFactory> instance;
			public:
				static std::shared_ptr<CalcModelFactory> eInstance();

			//Creator functions
			virtual std::shared_ptr<uml::Element> create(std::string _className) = 0;


			virtual std::shared_ptr<CalcModel::CheckIfPrime> createCheckIfPrime() = 0;
			
			virtual std::shared_ptr<CalcModel::PrimeChecker> createPrimeChecker() = 0;
			
			

			//Package
			virtual std::shared_ptr<CalcModelPackage> getCalcModelPackage() = 0;
	};
}
#endif /* end of include guard: CALCMODEL_FACTORY_HPP */
