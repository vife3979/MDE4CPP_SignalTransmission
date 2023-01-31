//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_UNLIMITEDNATURALFUNCTIONS__GLOBALFUNCTIONS_HPP
#define FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_UNLIMITEDNATURALFUNCTIONS__GLOBALFUNCTIONS_HPP

#include <memory>

class Any;
template<class T> class Bag;

namespace uml
{
	class OpaqueBehavior;
}

namespace FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions
{
	std::shared_ptr<Any> invoke(std::shared_ptr<uml::OpaqueBehavior>, std::shared_ptr<Bag<Any>>, std::shared_ptr<Bag<Any>>);
}

namespace FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions
{
	std::string ToString(const int x);
	bool greaterOrEqual(const int x, const int y);
	int ToUnlimitedNatural(const std::string x);
	bool lessThan(const int x, const int y);
	int Min(const int x, const int y);
	int Max(const int x, const int y);
	bool greaterThan(const int x, const int y);
	int ToInteger(const int x);
	bool lessOrEqual(const int x, const int y);
}

#endif /* end of include guard: FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_UNLIMITEDNATURALFUNCTIONS__GLOBALFUNCTIONS_HPP */
