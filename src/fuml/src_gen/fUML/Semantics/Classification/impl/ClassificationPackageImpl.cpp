#include "fUML/Semantics/Classification/impl/ClassificationPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//metamodel factory
#include "fUML/Semantics/Classification/ClassificationFactory.hpp"

//depending model packages
#include "fUML/fUMLPackage.hpp"

using namespace fUML::Semantics::Classification;

bool ClassificationPackageImpl::isInited = false;

ClassificationPackageImpl::ClassificationPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( ClassificationFactory::eInstance()));
}

ClassificationPackageImpl::~ClassificationPackageImpl()
{
}

ClassificationPackage* ClassificationPackageImpl::create()
{
	if (isInited)
	{
		return ClassificationPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    ClassificationPackageImpl * metaModelPackage = new ClassificationPackageImpl();
    return metaModelPackage;
}

void ClassificationPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}




