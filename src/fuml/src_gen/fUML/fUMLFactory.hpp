//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUMLFACTORY_HPP
#define FUMLFACTORY_HPP
// namespace macro header include
#include "fUML/fUML.hpp"

#include <map>
#include <memory>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EFactory.hpp"
#include "fUML/fUMLPackage.hpp"

namespace fUML 
{
	class fUMLPackage;
}
namespace fUML::Semantics::Activities
{
	class ActivityNodeActivationGroup;
	class ObjectToken;
}
namespace fUML::Semantics::CommonBehavior
{
	class ParameterValue;
}
namespace fUML::Semantics::SimpleClassifiers
{
	class FeatureValue;
}


namespace fUML::Semantics::Actions
{
	class CallActionActivation;
	class StructuredActivityNodeActivation;
}
namespace fUML::Semantics::CommonBehavior
{
	class ParameterValue;
}
namespace fUML::Semantics::Loci
{
	class Locus;
}
namespace fUML::Semantics::SimpleClassifiers
{
	class FeatureValue;
}




namespace fUML::Semantics::Actions
{
	class CallActionActivation;
}
namespace fUML::Semantics::Activities
{
	class DecisionNodeActivation;
	class ObjectToken;
}
namespace fUML::Semantics::Loci
{
	class Locus;
}
namespace fUML::Semantics::SimpleClassifiers
{
	class FeatureValue;
}
namespace fUML::Semantics::StructuredClassifiers
{
	class Object;
}




namespace fUML::Semantics::Activities
{
	class ObjectToken;
}
namespace fUML::Semantics::CommonBehavior
{
	class ObjectActivation;
	class ParameterValue;
}


namespace fUML::Semantics::Activities
{
	class ObjectToken;
}
namespace fUML::Semantics::CommonBehavior
{
	class ParameterValue;
}
namespace fUML::Semantics::Loci
{
	class Locus;
}
namespace fUML::Semantics::SimpleClassifiers
{
	class FeatureValue;
}


namespace fUML::Semantics::Activities
{
	class ObjectToken;
}
namespace fUML::Semantics::CommonBehavior
{
	class ParameterValue;
}
namespace fUML::Semantics::SimpleClassifiers
{
	class FeatureValue;
}







namespace fUML 
{
	class FUML_API fUMLFactory : virtual public ecore::EFactory 
	{
		private:    
			fUMLFactory(fUMLFactory const&) = delete;
			fUMLFactory& operator=(fUMLFactory const&) = delete;
		protected:
			fUMLFactory(){}
		
			//Singleton Getter
			public:
				static std::shared_ptr<fUMLFactory> eInstance();
		
			//Creator functions
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const = 0;

			
	};
}
#endif /* end of include guard: FUMLFACTORY_HPP */
