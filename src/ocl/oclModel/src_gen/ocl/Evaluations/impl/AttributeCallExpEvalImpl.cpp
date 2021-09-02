
#include "ocl/Evaluations/impl/AttributeCallExpEvalImpl.hpp"

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
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"


//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Values/ValuesFactory.hpp"
#include "ocl/Evaluations/EvaluationsFactory.hpp"
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "ocl/Expressions/ExpressionsFactory.hpp"

#include "ocl/Evaluations/EvalEnvironment.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "ocl/Evaluations/ModelPropertyCallExpEval.hpp"
#include "ocl/Evaluations/OclExpEval.hpp"
#include "ocl/Expressions/OclExpression.hpp"
#include "fUML/Semantics/SimpleClassifiers/StringValue.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "uml/ValueSpecification.hpp"

//Factories an Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Evaluations/EvaluationsPackage.hpp"
#include "ocl/Expressions/ExpressionsPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ocl::Evaluations;

//*********************************
// Constructor / Destructor
//*********************************
AttributeCallExpEvalImpl::AttributeCallExpEvalImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

AttributeCallExpEvalImpl::~AttributeCallExpEvalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete AttributeCallExpEval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


AttributeCallExpEvalImpl::AttributeCallExpEvalImpl(const AttributeCallExpEvalImpl & obj): AttributeCallExpEvalImpl()
{
	*this = obj;
}

AttributeCallExpEvalImpl& AttributeCallExpEvalImpl::operator=(const AttributeCallExpEvalImpl & obj)
{
	//call overloaded =Operator for each base class
	ModelPropertyCallExpEvalImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of AttributeCallExpEval 
	 * which is generated by the compiler (as AttributeCallExpEval is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//AttributeCallExpEval::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy AttributeCallExpEval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_referredAttribute  = obj.getReferredAttribute();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> AttributeCallExpEvalImpl::copy() const
{
	std::shared_ptr<AttributeCallExpEvalImpl> element(new AttributeCallExpEvalImpl());
	*element =(*this);
	element->setThisAttributeCallExpEvalPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference referredAttribute */
std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> AttributeCallExpEvalImpl::getReferredAttribute() const
{
    return m_referredAttribute;
}
void AttributeCallExpEvalImpl::setReferredAttribute(std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> _referredAttribute)
{
    m_referredAttribute = _referredAttribute;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> AttributeCallExpEvalImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void AttributeCallExpEvalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get oclFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void AttributeCallExpEvalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("referredAttribute");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("referredAttribute")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ModelPropertyCallExpEvalImpl::loadAttributes(loadHandler, attr_list);
}

void AttributeCallExpEvalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ModelPropertyCallExpEvalImpl::loadNode(nodeName, loadHandler);
}

void AttributeCallExpEvalImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::ATTRIBUTECALLEXPEVAL_ATTRIBUTE_REFERREDATTRIBUTE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> _referredAttribute = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StringValue>( references.front() );
				setReferredAttribute(_referredAttribute);
			}
			
			return;
		}
	}
	ModelPropertyCallExpEvalImpl::resolveReferences(featureID, references);
}

void AttributeCallExpEvalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ModelPropertyCallExpEvalImpl::saveContent(saveHandler);
	
	PropertyCallExpEvalImpl::saveContent(saveHandler);
	
	OclExpEvalImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::EvaluationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void AttributeCallExpEvalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Evaluations::EvaluationsPackage> package = ocl::Evaluations::EvaluationsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getReferredAttribute(), "referredAttribute", getReferredAttribute()->eClass() != fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getStringValue_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


std::shared_ptr<ecore::EClass> AttributeCallExpEvalImpl::eStaticClass() const
{
	return ocl::Evaluations::EvaluationsPackage::eInstance()->getAttributeCallExpEval_Class();
}


//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any AttributeCallExpEvalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::ATTRIBUTECALLEXPEVAL_ATTRIBUTE_REFERREDATTRIBUTE:
			{
				std::shared_ptr<ecore::EObject> returnValue=getReferredAttribute();
				return eAny(returnValue); //57
			}
	}
	return ModelPropertyCallExpEvalImpl::eGet(featureID, resolve, coreType);
}

bool AttributeCallExpEvalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::ATTRIBUTECALLEXPEVAL_ATTRIBUTE_REFERREDATTRIBUTE:
			return getReferredAttribute() != nullptr; //57
	}
	return ModelPropertyCallExpEvalImpl::internalEIsSet(featureID);
}

bool AttributeCallExpEvalImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::ATTRIBUTECALLEXPEVAL_ATTRIBUTE_REFERREDATTRIBUTE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> _referredAttribute = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StringValue>(_temp);
			setReferredAttribute(_referredAttribute); //57
			return true;
		}
	}

	return ModelPropertyCallExpEvalImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any AttributeCallExpEvalImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ModelPropertyCallExpEvalImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}


std::shared_ptr<AttributeCallExpEval> AttributeCallExpEvalImpl::getThisAttributeCallExpEvalPtr() const
{
	return m_thisAttributeCallExpEvalPtr.lock();
}
void AttributeCallExpEvalImpl::setThisAttributeCallExpEvalPtr(std::weak_ptr<AttributeCallExpEval> thisAttributeCallExpEvalPtr)
{
	m_thisAttributeCallExpEvalPtr = thisAttributeCallExpEvalPtr;
	setThisModelPropertyCallExpEvalPtr(thisAttributeCallExpEvalPtr);
}
