
#include "uml/impl/LinkActionImpl.hpp"

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

#include "abstractDataTypes/SubsetUnion.hpp"


#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"


//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"

#include "uml/Action.hpp"
#include "uml/Activity.hpp"
#include "uml/ActivityEdge.hpp"
#include "uml/ActivityGroup.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/ActivityPartition.hpp"
#include "uml/Association.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ExceptionHandler.hpp"
#include "uml/InputPin.hpp"
#include "uml/InterruptibleActivityRegion.hpp"
#include "uml/LinkEndData.hpp"
#include "uml/Namespace.hpp"
#include "uml/OutputPin.hpp"
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
LinkActionImpl::LinkActionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

LinkActionImpl::~LinkActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LinkAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
LinkActionImpl::LinkActionImpl(std::weak_ptr<uml::Activity> par_activity)
:LinkActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
LinkActionImpl::LinkActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:LinkActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
LinkActionImpl::LinkActionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:LinkActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
LinkActionImpl::LinkActionImpl(std::weak_ptr<uml::Element> par_owner)
:LinkActionImpl()
{
	m_owner = par_owner;
}

LinkActionImpl::LinkActionImpl(const LinkActionImpl & obj): LinkActionImpl()
{
	*this = obj;
}

LinkActionImpl& LinkActionImpl::operator=(const LinkActionImpl & obj)
{
	//call overloaded =Operator for each base class
	ActionImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of LinkAction 
	 * which is generated by the compiler (as LinkAction is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//LinkAction::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LinkAction "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'endData'
	std::shared_ptr<Subset<uml::LinkEndData, uml::Element>> endDataList = obj.getEndData();
	if(endDataList)
	{
		/*Subset*/
		m_endData.reset(new Subset<uml::LinkEndData, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_endData - Subset<uml::LinkEndData, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getEndData()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_endData - Subset<uml::LinkEndData, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		

		Bag<uml::LinkEndData>::iterator endDataIter = endDataList->begin();
		Bag<uml::LinkEndData>::iterator endDataEnd = endDataList->end();
		while (endDataIter != endDataEnd) 
		{
			std::shared_ptr<uml::LinkEndData> temp = std::dynamic_pointer_cast<uml::LinkEndData>((*endDataIter)->copy());
			getEndData()->push_back(temp);
			endDataIter++;
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr endData."<< std::endl;)
	}

	//clone reference 'inputValue'
	std::shared_ptr<Subset<uml::InputPin, uml::InputPin>> inputValueList = obj.getInputValue();
	if(inputValueList)
	{
		/*Subset*/
		m_inputValue.reset(new Subset<uml::InputPin, uml::InputPin >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_inputValue - Subset<uml::InputPin, uml::InputPin >()" << std::endl;
		#endif
		
		/*Subset*/
		getInputValue()->initSubset(getInput());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_inputValue - Subset<uml::InputPin, uml::InputPin >(getInput())" << std::endl;
		#endif
		

		Bag<uml::InputPin>::iterator inputValueIter = inputValueList->begin();
		Bag<uml::InputPin>::iterator inputValueEnd = inputValueList->end();
		while (inputValueIter != inputValueEnd) 
		{
			std::shared_ptr<uml::InputPin> temp = std::dynamic_pointer_cast<uml::InputPin>((*inputValueIter)->copy());
			getInputValue()->push_back(temp);
			inputValueIter++;
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr inputValue."<< std::endl;)
	}
	/*Subset*/
	getEndData()->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_endData - Subset<uml::LinkEndData, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	/*Subset*/
	getInputValue()->initSubset(getInput());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_inputValue - Subset<uml::InputPin, uml::InputPin >(getInput())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> LinkActionImpl::copy() const
{
	std::shared_ptr<LinkActionImpl> element(new LinkActionImpl());
	*element =(*this);
	element->setThisLinkActionPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::Association> LinkActionImpl::association()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LinkActionImpl::not_static(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LinkActionImpl::same_association(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LinkActionImpl::same_pins(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference endData */
std::shared_ptr<Subset<uml::LinkEndData, uml::Element>> LinkActionImpl::getEndData() const
{
	if(m_endData == nullptr)
	{
		/*Subset*/
		m_endData.reset(new Subset<uml::LinkEndData, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_endData - Subset<uml::LinkEndData, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getEndData()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_endData - Subset<uml::LinkEndData, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_endData;
}

/* Getter & Setter for reference inputValue */
std::shared_ptr<Subset<uml::InputPin, uml::InputPin>> LinkActionImpl::getInputValue() const
{
	if(m_inputValue == nullptr)
	{
		/*Subset*/
		m_inputValue.reset(new Subset<uml::InputPin, uml::InputPin >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_inputValue - Subset<uml::InputPin, uml::InputPin >()" << std::endl;
		#endif
		
		/*Subset*/
		getInputValue()->initSubset(getInput());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_inputValue - Subset<uml::InputPin, uml::InputPin >(getInput())" << std::endl;
		#endif
		
	}
    return m_inputValue;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup>> LinkActionImpl::getInGroup() const
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

std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> LinkActionImpl::getInput() const
{
	if(m_input == nullptr)
	{
		/*SubsetUnion*/
		m_input.reset(new SubsetUnion<uml::InputPin, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_input - SubsetUnion<uml::InputPin, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getInput()->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_input - SubsetUnion<uml::InputPin, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
	return m_input;
}

std::shared_ptr<Union<uml::Element>> LinkActionImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> LinkActionImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> LinkActionImpl::getRedefinedElement() const
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

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> LinkActionImpl::eContainer() const
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
// Persistence Functions
//*********************************
void LinkActionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void LinkActionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ActionImpl::loadAttributes(loadHandler, attr_list);
}

void LinkActionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("endData") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "LinkEndData";
			}
			loadHandler->handleChildContainer<uml::LinkEndData>(this->getEndData());  

			return; 
		}

		if ( nodeName.compare("inputValue") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "InputPin";
			}
			loadHandler->handleChildContainer<uml::InputPin>(this->getInputValue());  

			return; 
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}
	//load BasePackage Nodes
	ActionImpl::loadNode(nodeName, loadHandler);
}

void LinkActionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ActionImpl::resolveReferences(featureID, references);
}

void LinkActionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActionImpl::saveContent(saveHandler);
	
	ExecutableNodeImpl::saveContent(saveHandler);
	
	ActivityNodeImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void LinkActionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'endData'
		for (std::shared_ptr<uml::LinkEndData> endData : *this->getEndData()) 
		{
			saveHandler->addReference(endData, "endData", endData->eClass() != package->getLinkEndData_Class());
		}

		// Save 'inputValue'
		for (std::shared_ptr<uml::InputPin> inputValue : *this->getInputValue()) 
		{
			saveHandler->addReference(inputValue, "inputValue", inputValue->eClass() != package->getInputPin_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


std::shared_ptr<ecore::EClass> LinkActionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getLinkAction_Class();
}


//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any LinkActionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::LINKACTION_ATTRIBUTE_ENDDATA:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::LinkEndData>::iterator iter = getEndData()->begin();
			Bag<uml::LinkEndData>::iterator end = getEndData()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //13327			
		}
		case uml::umlPackage::LINKACTION_ATTRIBUTE_INPUTVALUE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::InputPin>::iterator iter = getInputValue()->begin();
			Bag<uml::InputPin>::iterator end = getInputValue()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //13328			
		}
	}
	return ActionImpl::eGet(featureID, resolve, coreType);
}

bool LinkActionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::LINKACTION_ATTRIBUTE_ENDDATA:
			return getEndData() != nullptr; //13327
		case uml::umlPackage::LINKACTION_ATTRIBUTE_INPUTVALUE:
			return getInputValue() != nullptr; //13328
	}
	return ActionImpl::internalEIsSet(featureID);
}

bool LinkActionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::LINKACTION_ATTRIBUTE_ENDDATA:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::LinkEndData>> endDataList(new Bag<uml::LinkEndData>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				endDataList->add(std::dynamic_pointer_cast<uml::LinkEndData>(*iter));
				iter++;
			}
			
			Bag<uml::LinkEndData>::iterator iterEndData = getEndData()->begin();
			Bag<uml::LinkEndData>::iterator endEndData = getEndData()->end();
			while (iterEndData != endEndData)
			{
				if (endDataList->find(*iterEndData) == -1)
				{
					getEndData()->erase(*iterEndData);
				}
				iterEndData++;
			}
 
			iterEndData = endDataList->begin();
			endEndData = endDataList->end();
			while (iterEndData != endEndData)
			{
				if (getEndData()->find(*iterEndData) == -1)
				{
					getEndData()->add(*iterEndData);
				}
				iterEndData++;			
			}
			return true;
		}
		case uml::umlPackage::LINKACTION_ATTRIBUTE_INPUTVALUE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::InputPin>> inputValueList(new Bag<uml::InputPin>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				inputValueList->add(std::dynamic_pointer_cast<uml::InputPin>(*iter));
				iter++;
			}
			
			Bag<uml::InputPin>::iterator iterInputValue = getInputValue()->begin();
			Bag<uml::InputPin>::iterator endInputValue = getInputValue()->end();
			while (iterInputValue != endInputValue)
			{
				if (inputValueList->find(*iterInputValue) == -1)
				{
					getInputValue()->erase(*iterInputValue);
				}
				iterInputValue++;
			}
 
			iterInputValue = inputValueList->begin();
			endInputValue = inputValueList->end();
			while (iterInputValue != endInputValue)
			{
				if (getInputValue()->find(*iterInputValue) == -1)
				{
					getInputValue()->add(*iterInputValue);
				}
				iterInputValue++;			
			}
			return true;
		}
	}

	return ActionImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any LinkActionImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 1086747006
		case umlPackage::LINKACTION_OPERATION_ASSOCIATION:
		{
			result = eAny(this->association());
			break;
		}
		
		// 768493780
		case umlPackage::LINKACTION_OPERATION_NOT_STATIC_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->not_static(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 1355951104
		case umlPackage::LINKACTION_OPERATION_SAME_ASSOCIATION_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->same_association(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 1475541173
		case umlPackage::LINKACTION_OPERATION_SAME_PINS_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->same_pins(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = ActionImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}


std::shared_ptr<LinkAction> LinkActionImpl::getThisLinkActionPtr() const
{
	return m_thisLinkActionPtr.lock();
}
void LinkActionImpl::setThisLinkActionPtr(std::weak_ptr<LinkAction> thisLinkActionPtr)
{
	m_thisLinkActionPtr = thisLinkActionPtr;
	setThisActionPtr(thisLinkActionPtr);
}
