
#include "fUML/Semantics/Values/impl/EvaluationImpl.hpp"
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
#include <stdexcept>


#include "abstractDataTypes/AnyEObject.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/Loci/SemanticVisitor.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "uml/ValueSpecification.hpp"
//Factories and Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::Values;

//*********************************
// Constructor / Destructor
//*********************************
EvaluationImpl::EvaluationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

EvaluationImpl::~EvaluationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Evaluation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


EvaluationImpl::EvaluationImpl(const EvaluationImpl & obj): EvaluationImpl()
{
	*this = obj;
}

EvaluationImpl& EvaluationImpl::operator=(const EvaluationImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Loci::SemanticVisitorImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Evaluation 
	 * which is generated by the compiler (as Evaluation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Evaluation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Evaluation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_locus  = obj.getLocus();
	m_specification  = obj.getSpecification();
	//Clone references with containment (deep copy)
	return *this;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Values::Value> EvaluationImpl::evaluate()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference locus */
std::shared_ptr<fUML::Semantics::Loci::Locus> EvaluationImpl::getLocus() const
{
    return m_locus;
}
void EvaluationImpl::setLocus(std::shared_ptr<fUML::Semantics::Loci::Locus> _locus)
{
    m_locus = _locus;
	
}

/* Getter & Setter for reference specification */
std::shared_ptr<uml::ValueSpecification> EvaluationImpl::getSpecification() const
{
    return m_specification;
}
void EvaluationImpl::setSpecification(std::shared_ptr<uml::ValueSpecification> _specification)
{
    m_specification = _specification;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> EvaluationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void EvaluationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void EvaluationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("locus");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("locus")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("specification");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("specification")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	fUML::Semantics::Loci::SemanticVisitorImpl::loadAttributes(loadHandler, attr_list);
}

void EvaluationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Loci::SemanticVisitorImpl::loadNode(nodeName, loadHandler);
}

void EvaluationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Values::ValuesPackage::EVALUATION_ATTRIBUTE_LOCUS:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::Loci::Locus> _locus = std::dynamic_pointer_cast<fUML::Semantics::Loci::Locus>( references.front() );
				setLocus(_locus);
			}
			
			return;
		}

		case fUML::Semantics::Values::ValuesPackage::EVALUATION_ATTRIBUTE_SPECIFICATION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ValueSpecification> _specification = std::dynamic_pointer_cast<uml::ValueSpecification>( references.front() );
				setSpecification(_specification);
			}
			
			return;
		}
	}
	fUML::Semantics::Loci::SemanticVisitorImpl::resolveReferences(featureID, references);
}

void EvaluationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void EvaluationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Values::ValuesPackage> package = fUML::Semantics::Values::ValuesPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getLocus(), "locus", getLocus()->eClass() != fUML::Semantics::Loci::LociPackage::eInstance()->getLocus_Class()); 
		saveHandler->addReference(this->getSpecification(), "specification", getSpecification()->eClass() != uml::umlPackage::eInstance()->getValueSpecification_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> EvaluationImpl::eStaticClass() const
{
	return fUML::Semantics::Values::ValuesPackage::eInstance()->getEvaluation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any EvaluationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Values::ValuesPackage::EVALUATION_ATTRIBUTE_LOCUS:
			return eAny(getLocus(),fUML::Semantics::Loci::LociPackage::LOCUS_CLASS,false); //421
		case fUML::Semantics::Values::ValuesPackage::EVALUATION_ATTRIBUTE_SPECIFICATION:
			return eAny(getSpecification(),uml::umlPackage::VALUESPECIFICATION_CLASS,false); //420
	}
	return fUML::Semantics::Loci::SemanticVisitorImpl::eGet(featureID, resolve, coreType);
}

bool EvaluationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Values::ValuesPackage::EVALUATION_ATTRIBUTE_LOCUS:
			return getLocus() != nullptr; //421
		case fUML::Semantics::Values::ValuesPackage::EVALUATION_ATTRIBUTE_SPECIFICATION:
			return getSpecification() != nullptr; //420
	}
	return fUML::Semantics::Loci::SemanticVisitorImpl::internalEIsSet(featureID);
}

bool EvaluationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Values::ValuesPackage::EVALUATION_ATTRIBUTE_LOCUS:
		{
			// CAST Any to fUML::Semantics::Loci::Locus
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::Loci::Locus> _locus = std::dynamic_pointer_cast<fUML::Semantics::Loci::Locus>(_temp);
			setLocus(_locus); //421
			return true;
		}
		case fUML::Semantics::Values::ValuesPackage::EVALUATION_ATTRIBUTE_SPECIFICATION:
		{
			// CAST Any to uml::ValueSpecification
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ValueSpecification> _specification = std::dynamic_pointer_cast<uml::ValueSpecification>(_temp);
			setSpecification(_specification); //420
			return true;
		}
	}

	return fUML::Semantics::Loci::SemanticVisitorImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any EvaluationImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Values::Evaluation::evaluate() : fUML::Semantics::Values::Value: 3829887513
		case ValuesPackage::EVALUATION_OPERATION_EVALUATE:
		{
			result = eAnyObject(this->evaluate(), fUML::Semantics::Values::ValuesPackage::VALUE_CLASS);
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::Semantics::Loci::SemanticVisitorImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Values::Evaluation> EvaluationImpl::getThisEvaluationPtr() const
{
	return m_thisEvaluationPtr.lock();
}
void EvaluationImpl::setThisEvaluationPtr(std::weak_ptr<fUML::Semantics::Values::Evaluation> thisEvaluationPtr)
{
	m_thisEvaluationPtr = thisEvaluationPtr;
	setThisSemanticVisitorPtr(thisEvaluationPtr);
}


