#include "fUML/Semantics/Actions/impl/LinkActionActivationImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_MESSAGE(a) /**/
#else
	#define DEBUG_MESSAGE(a) a
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
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Actions/ActionsFactory.hpp"
#include "uml/UmlFactory.hpp"
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"


#include "uml/Action.hpp"
#include "fUML/Semantics/Actions/ActionActivation.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "uml/Association.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/StructuredClassifiers/Link.hpp"
#include "uml/LinkEndData.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"

//Factories an Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
LinkActionActivationImpl::LinkActionActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

LinkActionActivationImpl::~LinkActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LinkActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
LinkActionActivationImpl::LinkActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:LinkActionActivationImpl()
{
	m_group = par_group;
}

LinkActionActivationImpl::LinkActionActivationImpl(const LinkActionActivationImpl & obj): LinkActionActivationImpl()
{
	*this = obj;
}

LinkActionActivationImpl& LinkActionActivationImpl::operator=(const LinkActionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	ActionActivationImpl::operator=(obj);
	LinkActionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LinkActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> LinkActionActivationImpl::copy() const
{
	std::shared_ptr<LinkActionActivationImpl> element(new LinkActionActivationImpl());
	*element =(*this);
	element->setThisLinkActionActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> LinkActionActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getLinkActionActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool LinkActionActivationImpl::endMatchesEndData(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Link> link,std::shared_ptr<uml::LinkEndData> endData)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Association> LinkActionActivationImpl::getAssociation()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LinkActionActivationImpl::linkMatchesEndData(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Link> link,std::shared_ptr<Bag<uml::LinkEndData>> endDataList)
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
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> LinkActionActivationImpl::getPinActivation() const
{
	if(m_pinActivation == nullptr)
	{
		/*Union*/
		m_pinActivation.reset(new Union<fUML::Semantics::Actions::PinActivation>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_pinActivation - Union<fUML::Semantics::Actions::PinActivation>()" << std::endl;
		#endif
		
		
	}
	return m_pinActivation;
}




std::shared_ptr<LinkActionActivation> LinkActionActivationImpl::getThisLinkActionActivationPtr() const
{
	return m_thisLinkActionActivationPtr.lock();
}
void LinkActionActivationImpl::setThisLinkActionActivationPtr(std::weak_ptr<LinkActionActivation> thisLinkActionActivationPtr)
{
	m_thisLinkActionActivationPtr = thisLinkActionActivationPtr;
	setThisActionActivationPtr(thisLinkActionActivationPtr);
}
std::shared_ptr<ecore::EObject> LinkActionActivationImpl::eContainer() const
{
	if(auto wp = m_group.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any LinkActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ActionActivationImpl::eGet(featureID, resolve, coreType);
}
bool LinkActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ActionActivationImpl::internalEIsSet(featureID);
}
bool LinkActionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return ActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any LinkActionActivationImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 6959
		case ActionsPackage::LINKACTIONACTIVATION_OPERATION_ENDMATCHESENDDATA_LINK_LINKENDDATA:
		{
			//Retrieve input parameter 'link'
			//parameter 0
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Link> incoming_param_link;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_link_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_link = (*incoming_param_link_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::StructuredClassifiers::Link> >();
			//Retrieve input parameter 'endData'
			//parameter 1
			std::shared_ptr<uml::LinkEndData> incoming_param_endData;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_endData_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_endData = (*incoming_param_endData_arguments_citer)->get()->get<std::shared_ptr<uml::LinkEndData> >();
			result = eAny(this->endMatchesEndData(incoming_param_link,incoming_param_endData));
			break;
		}
		
		// 6960
		case ActionsPackage::LINKACTIONACTIVATION_OPERATION_GETASSOCIATION:
		{
			result = eAny(this->getAssociation());
			break;
		}
		
		// 6958
		case ActionsPackage::LINKACTIONACTIVATION_OPERATION_LINKMATCHESENDDATA_LINK_LINKENDDATA:
		{
			//Retrieve input parameter 'link'
			//parameter 0
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Link> incoming_param_link;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_link_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_link = (*incoming_param_link_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::StructuredClassifiers::Link> >();
			//Retrieve input parameter 'endDataList'
			//parameter 1
			std::shared_ptr<Bag<uml::LinkEndData>> incoming_param_endDataList;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_endDataList_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_endDataList = (*incoming_param_endDataList_arguments_citer)->get()->get<std::shared_ptr<Bag<uml::LinkEndData>> >();
			result = eAny(this->linkMatchesEndData(incoming_param_link,incoming_param_endDataList));
			break;
		}

		default:
		{
			// call superTypes
			result = ActionActivationImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

//*********************************
// Persistence Functions
//*********************************
void LinkActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get fUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void LinkActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void LinkActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ActionActivationImpl::loadNode(nodeName, loadHandler);
}

void LinkActionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ActionActivationImpl::resolveReferences(featureID, references);
}

void LinkActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void LinkActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

