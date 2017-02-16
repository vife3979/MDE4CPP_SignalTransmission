#include "WriteStructuralFeatureActionActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
WriteStructuralFeatureActionActivationImpl::WriteStructuralFeatureActionActivationImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

WriteStructuralFeatureActionActivationImpl::~WriteStructuralFeatureActionActivationImpl()
{
	
}

WriteStructuralFeatureActionActivationImpl::WriteStructuralFeatureActionActivationImpl(const WriteStructuralFeatureActionActivationImpl & obj)
{
	//create copy of all Attributes
	m_firing = obj.isFiring();
	m_running = obj.isRunning();

	//copy references with now containment
	
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

ecore::EObject *  WriteStructuralFeatureActionActivationImpl::copy() const
{
	return new WriteStructuralFeatureActionActivationImpl(*this);
}

ecore::EClass* WriteStructuralFeatureActionActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getWriteStructuralFeatureActionActivation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
int WriteStructuralFeatureActionActivationImpl::position(fUML::Value *  value,std::vector<fUML::Value * > *  list,int startAt) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any WriteStructuralFeatureActionActivationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ACTIONACTIVATION_FIRING:
			return isFiring(); //1017
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
			return getGroup(); //1013
		case FUMLPackage::ACTIVITYNODEACTIVATION_HELDTOKENS:
			return getHeldTokens(); //1012
		case FUMLPackage::ACTIVITYNODEACTIVATION_INCOMINGEDGES:
			return getIncomingEdges(); //1011
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
			return getNode(); //1014
		case FUMLPackage::ACTIVITYNODEACTIVATION_OUTGOINGEDGES:
			return getOutgoingEdges(); //1010
		case FUMLPackage::ACTIONACTIVATION_PINACTIVATION:
			return getPinActivation(); //1016
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
			return isRunning(); //1015
	}
	return boost::any();
}
