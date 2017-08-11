#include "AcceptEventActionEventAccepterImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

//Forward declaration includes
#include "AcceptEventActionActivation.hpp"

#include "EventAccepter.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
AcceptEventActionEventAccepterImpl::AcceptEventActionEventAccepterImpl()
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

AcceptEventActionEventAccepterImpl::~AcceptEventActionEventAccepterImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete AcceptEventActionEventAccepter "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

AcceptEventActionEventAccepterImpl::AcceptEventActionEventAccepterImpl(const AcceptEventActionEventAccepterImpl & obj):AcceptEventActionEventAccepterImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy AcceptEventActionEventAccepter "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_actionActivation  = obj.getActionActivation();


    
	//Clone references with containment (deep copy)



}

ecore::EObject *  AcceptEventActionEventAccepterImpl::copy() const
{
	return new AcceptEventActionEventAccepterImpl(*this);
}

std::shared_ptr<ecore::EClass> AcceptEventActionEventAccepterImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getAcceptEventActionEventAccepter();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::shared_ptr<fUML::AcceptEventActionActivation > AcceptEventActionEventAccepterImpl::getActionActivation() const
{
//assert(m_actionActivation);
    return m_actionActivation;
}
void AcceptEventActionEventAccepterImpl::setActionActivation(std::shared_ptr<fUML::AcceptEventActionActivation> _actionActivation)
{
    m_actionActivation = _actionActivation;
}

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any AcceptEventActionEventAccepterImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ACCEPTEVENTACTIONEVENTACCEPTER_ACTIONACTIVATION:
			return getActionActivation(); //1110
	}
	return boost::any();
}
