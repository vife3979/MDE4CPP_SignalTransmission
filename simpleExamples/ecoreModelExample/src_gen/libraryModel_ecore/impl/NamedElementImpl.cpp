#include "libraryModel_ecore/impl/NamedElementImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "libraryModel_ecore/impl/LibraryModel_ecorePackageImpl.hpp"

//Forward declaration includes


using namespace libraryModel_ecore;

//*********************************
// Constructor / Destructor
//*********************************
NamedElementImpl::NamedElementImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References

	//Init references
}

NamedElementImpl::~NamedElementImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete NamedElement "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




NamedElementImpl::NamedElementImpl(const NamedElementImpl & obj):NamedElementImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy NamedElement "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_Name = obj.getName();

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  NamedElementImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new NamedElementImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> NamedElementImpl::eStaticClass() const
{
	return LibraryModel_ecorePackageImpl::eInstance()->getNamedElement_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void NamedElementImpl::setName(std::string _Name)
{
	m_Name = _Name;
} 

std::string NamedElementImpl::getName() const 
{
	return m_Name;
}

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<ecore::EObject> NamedElementImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any NamedElementImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case LibraryModel_ecorePackage::NAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //30
	}
	return boost::any();
}

void NamedElementImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case LibraryModel_ecorePackage::NAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _Name = boost::any_cast<std::string>(newValue);
			setName(_Name); //30
			break;
		}
	}
}
