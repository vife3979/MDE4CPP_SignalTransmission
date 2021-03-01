#include "uml/impl/FlowFinalNodeImpl.hpp"

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
#include "abstractDataTypes/SubsetUnion.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Activity.hpp"
#include "uml/ActivityEdge.hpp"
#include "uml/ActivityGroup.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/ActivityPartition.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/FinalNode.hpp"
#include "uml/InterruptibleActivityRegion.hpp"
#include "uml/Namespace.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuredActivityNode.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
FlowFinalNodeImpl::FlowFinalNodeImpl()
{	
}

FlowFinalNodeImpl::~FlowFinalNodeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete FlowFinalNode "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
FlowFinalNodeImpl::FlowFinalNodeImpl(std::weak_ptr<uml::Activity> par_activity)
:FlowFinalNodeImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
FlowFinalNodeImpl::FlowFinalNodeImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:FlowFinalNodeImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
FlowFinalNodeImpl::FlowFinalNodeImpl(std::weak_ptr<uml::Namespace> par_namespace)
:FlowFinalNodeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
FlowFinalNodeImpl::FlowFinalNodeImpl(std::weak_ptr<uml::Element> par_owner)
:FlowFinalNodeImpl()
{
	m_owner = par_owner;
}

FlowFinalNodeImpl::FlowFinalNodeImpl(const FlowFinalNodeImpl & obj): FlowFinalNodeImpl()
{
	*this = obj;
}

FlowFinalNodeImpl& FlowFinalNodeImpl::operator=(const FlowFinalNodeImpl & obj)
{
	//call overloaded =Operator for each base class
	FinalNodeImpl::operator=(obj);
	FlowFinalNode::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy FlowFinalNode "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)

	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> FlowFinalNodeImpl::copy() const
{
	std::shared_ptr<FlowFinalNodeImpl> element(new FlowFinalNodeImpl());
	*element =(*this);
	element->setThisFlowFinalNodePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> FlowFinalNodeImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getFlowFinalNode_Class();
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

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup>> FlowFinalNodeImpl::getInGroup() const
{
	if(m_inGroup == nullptr)
	{
		/*Union*/
		m_inGroup.reset(new Union<uml::ActivityGroup>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_inGroup - Union<uml::ActivityGroup>()" << std::endl;
		#endif
		
		
	}
	return m_inGroup;
}

std::shared_ptr<Union<uml::Element>> FlowFinalNodeImpl::getOwnedElement() const
{
	if(m_ownedElement == nullptr)
	{
		/*Union*/
		m_ownedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_ownedElement - Union<uml::Element>()" << std::endl;
		#endif
		
		
	}
	return m_ownedElement;
}

std::weak_ptr<uml::Element> FlowFinalNodeImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> FlowFinalNodeImpl::getRedefinedElement() const
{
	if(m_redefinedElement == nullptr)
	{
		/*Union*/
		m_redefinedElement.reset(new Union<uml::RedefinableElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinedElement - Union<uml::RedefinableElement>()" << std::endl;
		#endif
		
		
	}
	return m_redefinedElement;
}




std::shared_ptr<FlowFinalNode> FlowFinalNodeImpl::getThisFlowFinalNodePtr() const
{
	return m_thisFlowFinalNodePtr.lock();
}
void FlowFinalNodeImpl::setThisFlowFinalNodePtr(std::weak_ptr<FlowFinalNode> thisFlowFinalNodePtr)
{
	m_thisFlowFinalNodePtr = thisFlowFinalNodePtr;
	setThisFinalNodePtr(thisFlowFinalNodePtr);
}
std::shared_ptr<ecore::EObject> FlowFinalNodeImpl::eContainer() const
{
	if(auto wp = m_activity.lock())
	{
		return wp;
	}

	if(auto wp = m_inStructuredNode.lock())
	{
		return wp;
	}

	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any FlowFinalNodeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return FinalNodeImpl::eGet(featureID, resolve, coreType);
}
bool FlowFinalNodeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return FinalNodeImpl::internalEIsSet(featureID);
}
bool FlowFinalNodeImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return FinalNodeImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void FlowFinalNodeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get umlFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void FlowFinalNodeImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	FinalNodeImpl::loadAttributes(loadHandler, attr_list);
}

void FlowFinalNodeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	FinalNodeImpl::loadNode(nodeName, loadHandler);
}

void FlowFinalNodeImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	FinalNodeImpl::resolveReferences(featureID, references);
}

void FlowFinalNodeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	FinalNodeImpl::saveContent(saveHandler);
	
	ControlNodeImpl::saveContent(saveHandler);
	
	ActivityNodeImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
	
}

void FlowFinalNodeImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

