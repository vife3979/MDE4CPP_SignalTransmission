#include "AcceptEventActionActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
AcceptEventActionActivationImpl::AcceptEventActionActivationImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
}

AcceptEventActionActivationImpl::~AcceptEventActionActivationImpl()
{
	
}

AcceptEventActionActivationImpl::AcceptEventActionActivationImpl(const AcceptEventActionActivationImpl & obj)
{
	//create copy of all Attributes
	m_firing = obj.isFiring();
	m_running = obj.isRunning();
	m_waiting = obj.isWaiting();

	//copy references with now containment
	
	m_eventAccepter  = obj.getEventAccepter();

	m_group  = obj.getGroup();

	std::vector<fUML::ActivityEdgeInstance * > *  _incomingEdges = obj.getIncomingEdges();
	this->getIncomingEdges()->insert(this->getIncomingEdges()->end(), _incomingEdges->begin(), _incomingEdges->end());

	m_node  = obj.getNode();

	std::vector<fUML::ActivityEdgeInstance * > *  _outgoingEdges = obj.getOutgoingEdges();
	this->getOutgoingEdges()->insert(this->getOutgoingEdges()->end(), _outgoingEdges->begin(), _outgoingEdges->end());

	std::vector<fUML::PinActivation * > *  _pinActivation = obj.getPinActivation();
	this->getPinActivation()->insert(this->getPinActivation()->end(), _pinActivation->begin(), _pinActivation->end());


	//clone containt lists
	for(fUML::Token * 	_heldTokens : *obj.getHeldTokens())
	{
		this->getHeldTokens()->push_back(dynamic_cast<fUML::Token * >(_heldTokens->copy()));
	}
}

ecore::EObject *  AcceptEventActionActivationImpl::copy() const
{
	return new AcceptEventActionActivationImpl(*this);
}

ecore::EClass* AcceptEventActionActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getAcceptEventActionActivation();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void AcceptEventActionActivationImpl::setWaiting (bool _waiting)
{
	m_waiting = _waiting;
} 

bool AcceptEventActionActivationImpl::isWaiting() const 
{
	return m_waiting;
}

//*********************************
// Operations
//*********************************
void AcceptEventActionActivationImpl::accept(fUML::SignalInstance *  signalInstance) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool AcceptEventActionActivationImpl::match(fUML::SignalInstance *  signalInstance) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
fUML::AcceptEventActionEventAccepter *  AcceptEventActionActivationImpl::getEventAccepter() const
{
	
	return m_eventAccepter;
}
void AcceptEventActionActivationImpl::setEventAccepter(fUML::AcceptEventActionEventAccepter *  _eventAccepter)
{
	m_eventAccepter = _eventAccepter;
}

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any AcceptEventActionActivationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ACCEPTEVENTACTIONACTIVATION_EVENTACCEPTER:
			return getEventAccepter(); //1098
		case FUMLPackage::ACTIONACTIVATION_FIRING:
			return isFiring(); //1097
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
			return getGroup(); //1093
		case FUMLPackage::ACTIVITYNODEACTIVATION_HELDTOKENS:
			return getHeldTokens(); //1092
		case FUMLPackage::ACTIVITYNODEACTIVATION_INCOMINGEDGES:
			return getIncomingEdges(); //1091
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
			return getNode(); //1094
		case FUMLPackage::ACTIVITYNODEACTIVATION_OUTGOINGEDGES:
			return getOutgoingEdges(); //1090
		case FUMLPackage::ACTIONACTIVATION_PINACTIVATION:
			return getPinActivation(); //1096
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
			return isRunning(); //1095
		case FUMLPackage::ACCEPTEVENTACTIONACTIVATION_WAITING:
			return isWaiting(); //1099
	}
	return boost::any();
}
