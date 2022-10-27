
#include "fUML/Semantics/Activities/impl/JoinNodeActivationImpl.hpp"
#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//#include "util/ProfileCallCount.hpp"

#include <cassert>
#include <iostream>
#include <sstream>

#include "abstractDataTypes/Bag.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Includes from codegen annotation
#include "fUML/Semantics/Activities/ControlToken.hpp"
#include "uml/ActivityNode.hpp"
//Forward declaration includes
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Activities/ControlNodeActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
//Factories and Package includes
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::Activities;

//*********************************
// Constructor / Destructor
//*********************************
JoinNodeActivationImpl::JoinNodeActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

JoinNodeActivationImpl::~JoinNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete JoinNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
JoinNodeActivationImpl::JoinNodeActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:JoinNodeActivationImpl()
{
	m_group = par_group;
}

JoinNodeActivationImpl::JoinNodeActivationImpl(const JoinNodeActivationImpl & obj): JoinNodeActivationImpl()
{
	*this = obj;
}

JoinNodeActivationImpl& JoinNodeActivationImpl::operator=(const JoinNodeActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	ControlNodeActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of JoinNodeActivation 
	 * which is generated by the compiler (as JoinNodeActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//JoinNodeActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy JoinNodeActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> JoinNodeActivationImpl::copy() const
{
	std::shared_ptr<JoinNodeActivationImpl> element(new JoinNodeActivationImpl());
	*element =(*this);
	element->setThisJoinNodeActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void JoinNodeActivationImpl::fire(std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incomingTokens)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	if (this->getNode() != nullptr)
	{
		DEBUG_INFO("Firing JoinNode '" << this->getNode()->getName() << "'.")
	}

	int controlTokenID = fUML::Semantics::Activities::ActivitiesPackage::CONTROLTOKEN_CLASS;
	std::shared_ptr<Bag<fUML::Semantics::Activities::ControlToken>> controlTokenList(new Bag<fUML::Semantics::Activities::ControlToken>());

	Bag<fUML::Semantics::Activities::Token>::iterator tokenIter = incomingTokens->begin();
	Bag<fUML::Semantics::Activities::Token>::iterator tokenEnd = incomingTokens->end();
	while (tokenIter != tokenEnd)
	{
		if ((*tokenIter)->getMetaElementID() == controlTokenID)
		{
			controlTokenList->push_back(std::dynamic_pointer_cast<fUML::Semantics::Activities::ControlToken>(*tokenIter));
		}
		tokenIter++;
	}

	DEBUG_INFO(std::to_string(controlTokenList->size()) << " control tokens contained within all " << std::to_string(incomingTokens->size()) << " incoming tokens.")
	if (controlTokenList->size() == incomingTokens->size()) // all incoming tokens are ControlToken -> only one token should be offered
	{
		incomingTokens.reset(new Bag<fUML::Semantics::Activities::Token>());
		incomingTokens->push_back(controlTokenList->front());
	}
	else // remove all ControlToken and offer only ObjectToken
	{
		Bag<fUML::Semantics::Activities::Token>::iterator controlIter = incomingTokens->begin();
		Bag<fUML::Semantics::Activities::Token>::iterator controlEnd = incomingTokens->end();
		while (controlIter != controlEnd)
		{
			incomingTokens->erase(*controlIter);
			controlIter++;
		}
	}

	this->sendOffers(incomingTokens);
	//end of body
}

bool JoinNodeActivationImpl::isReady()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		bool ready = true;
	unsigned int i = 0;
	while (ready && i < this->getIncomingEdges()->size()) {
		ready = this->getIncomingEdges()->at(i)->hasOffer();
		i = i + 1;
	}

	return ready;
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> JoinNodeActivationImpl::eContainer() const
{
	if(auto wp = m_group.lock())
	{
		return wp;
	}
	return nullptr;
}

std::shared_ptr<ecore::EClass> JoinNodeActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getJoinNodeActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> JoinNodeActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ControlNodeActivationImpl::eGet(featureID, resolve, coreType);
}

bool JoinNodeActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ControlNodeActivationImpl::internalEIsSet(featureID);
}

bool JoinNodeActivationImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
	}

	return ControlNodeActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> JoinNodeActivationImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Activities::JoinNodeActivation::fire(fUML::Semantics::Activities::Token[*]): 1770507194
		case ActivitiesPackage::JOINNODEACTIVATION_OPERATION_FIRE_TOKEN:
		{
			//Retrieve input parameter 'incomingTokens'
			//parameter 0
			std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incoming_param_incomingTokens;
			Bag<Any>::const_iterator incoming_param_incomingTokens_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>((*incoming_param_incomingTokens_arguments_citer));
				if(ecoreContainerAny)
				{
					try
					{
						std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
				
						if(eObjectList)
						{
							incoming_param_incomingTokens.reset();
							for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
							{
								std::shared_ptr<fUML::Semantics::Activities::Token> _temp = std::dynamic_pointer_cast<fUML::Semantics::Activities::Token>(anEObject);
								incoming_param_incomingTokens->add(_temp);
							}
						}
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreContainerAny' for parameter 'incomingTokens'. Failed to invoke operation 'fire'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreContainerAny' for parameter 'incomingTokens'. Failed to invoke operation 'fire'!")
					return nullptr;
				}
			}
		
			this->fire(incoming_param_incomingTokens);
			break;
		}
		// fUML::Semantics::Activities::JoinNodeActivation::isReady() : bool: 1408588552
		case ActivitiesPackage::JOINNODEACTIVATION_OPERATION_ISREADY:
		{
			result = eAny(this->isReady(), 0, false);
			break;
		}

		default:
		{
			// call superTypes
			result = ControlNodeActivationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Activities::JoinNodeActivation> JoinNodeActivationImpl::getThisJoinNodeActivationPtr() const
{
	return m_thisJoinNodeActivationPtr.lock();
}
void JoinNodeActivationImpl::setThisJoinNodeActivationPtr(std::weak_ptr<fUML::Semantics::Activities::JoinNodeActivation> thisJoinNodeActivationPtr)
{
	m_thisJoinNodeActivationPtr = thisJoinNodeActivationPtr;
	setThisControlNodeActivationPtr(thisJoinNodeActivationPtr);
}


