#include "StandardProfile/impl/RefineImpl.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include <iostream>


#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "util/util.hpp"
#include "uml/Property.hpp"
#include "uml/Operation.hpp"
#include "uml/Parameter.hpp"
#include "StandardProfile/StandardProfileFactory.hpp"
#include "StandardProfile/impl/StandardProfilePackageImpl.hpp"
#include "uml/Stereotype.hpp"

//Types included from attributes, operation parameters, imports and composite owner classes
#include "uml/umlPackage.hpp"
#include "uml/Abstraction.hpp"

//Packges and Factories included from types of attributes, operation parameters, imports and composite owner classes
#include "uml/umlFactory.hpp"
#include "uml/impl/umlPackageImpl.hpp"

//Packages of included Enumerations


//Includes from InstanceValues (if required)

//Includes from Ports typed by interfaces (if required)

//Includes from roles of ConnectorEnds (if required)

using namespace StandardProfile;

//*********************************
// Constructor / Destructor
//*********************************
RefineImpl::RefineImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_MESSAGE(std::cout<<"Refine is created..."<<std::endl;)
	//***********************************
}


RefineImpl::~RefineImpl()
{
	DEBUG_MESSAGE(std::cout<<"Refine is destroyed..."<<std::endl;)
}

RefineImpl::RefineImpl(const RefineImpl & obj):RefineImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  RefineImpl::copy() const
{
	std::shared_ptr<RefineImpl> element(new RefineImpl());
	*element=(*this);
	element->setThisRefinePtr(element);
	return element;
}

RefineImpl& RefineImpl::operator=(const RefineImpl & obj)
{
	//call overloaded =Operator for each base class
	uml::StereotypeImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Refine "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)
	m_base_Abstraction = obj.getBase_Abstraction();

	//clone attributes with containment (deep copy)

	return *this;
}


std::shared_ptr<uml::Class> RefineImpl::getMetaClass() const
{
	return StandardProfilePackageImpl::eInstance()->get_StandardProfile_Refine();
}

void RefineImpl::instantiate()
{   
	
}

void RefineImpl::destroy()
{	

	//Erase properties
	//deleting property base_Abstraction
	m_base_Abstraction.reset();
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void RefineImpl::setBase_Abstraction(std::weak_ptr<uml::Abstraction> _base_Abstraction)
{
	m_base_Abstraction = _base_Abstraction;
	
}
std::weak_ptr<uml::Abstraction> RefineImpl::getBase_Abstraction() const 
{

	return m_base_Abstraction;
}

//*********************************
// Union Getter
//*********************************



//*********************************
// Operations
//*********************************

//*********************************
// Structural Feature Getter/Setter
//*********************************
//Get
std::shared_ptr<Any> RefineImpl::get(std::shared_ptr<uml::Property> _property) const
{
	std::string qualifiedName = _property->getQualifiedName();
	return this->get(qualifiedName);
}

std::shared_ptr<Any> RefineImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->get(uID);
}

std::shared_ptr<Any> RefineImpl::get(unsigned long _uID) const
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::REFINE_ATTRIBUTE_BASE_ABSTRACTION:
			return eAny(this->getBase_Abstraction(), uml::umlPackage::ABSTRACTION_CLASS, false);
	}

	return eAny(nullptr, -1, false);
}

//Set
void RefineImpl::set(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->set(qualifiedName, value);
}

void RefineImpl::set(std::string _qualifiedName, std::shared_ptr<Any> value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->set(uID, value);
}

void RefineImpl::set(unsigned long _uID, std::shared_ptr<Any> value)
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::REFINE_ATTRIBUTE_BASE_ABSTRACTION:
		{
			if(value->isContainer())
			{
				std::shared_ptr<Bag<uml::Abstraction>> container = value->get<std::shared_ptr<Bag<uml::Abstraction>>>();
				if(container)
				{
					if(!(container->empty()))
					{
						// If a non-empty container is passed, the property will be set to the first value of the container
						this->setBase_Abstraction(container->at(0));
					}
				}
			}
			else
			{
				this->setBase_Abstraction(value->get<std::shared_ptr<uml::Abstraction>>());
			}
			return;
		}
	}

}

//Add
void RefineImpl::add(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->set(qualifiedName, value);
}

void RefineImpl::add(std::string _qualifiedName, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->set(uID, value);
}

void RefineImpl::add(unsigned long _uID, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
}

//Unset
void RefineImpl::unset(std::shared_ptr<uml::Property> _property)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->unset(qualifiedName);
}

void RefineImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->unset(uID);
}

void RefineImpl::unset(unsigned long _uID)
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::REFINE_ATTRIBUTE_BASE_ABSTRACTION:
		{
			m_base_Abstraction.reset();
			return;
		}
	}

}

//*********************************
// Operation Invoction
//*********************************
//Invoke
std::shared_ptr<Any> RefineImpl::invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> _arguments)
{
	return eAny(nullptr, -1, false);

	/* Currently not functioning. TODO: Clarifiy how this should work in the future
	std::string qualifiedName = _operation->getQualifiedName();

	for(unsigned int i = 0; i < _operation->getOwnedParameter()->size(); i++)
	{
		qualifiedName += "_" + _operation->getOwnedParameter()->at(i)->getType()->getName();
	}

	return this->invoke(qualifiedName, _arguments);
	*/
}

std::shared_ptr<Any> RefineImpl::invoke(std::string _qualifiedName, std::shared_ptr<Bag<Any>> _arguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invoke(uID, _arguments);
}

std::shared_ptr<Any> RefineImpl::invoke(unsigned long _uID, std::shared_ptr<Bag<Any>> _arguments)
{
	return eAny(nullptr, -1, false);
}

std::shared_ptr<Refine> RefineImpl::getThisRefinePtr()
{
	return m_thisRefinePtr.lock();
}
void RefineImpl::setThisRefinePtr(std::weak_ptr<Refine> thisRefinePtr)
{
	m_thisRefinePtr = thisRefinePtr;
	setThisStereotypePtr(thisRefinePtr);
}
