#include "StandardProfile/impl/ServiceImpl.hpp"

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
#include "uml/Component.hpp"

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
ServiceImpl::ServiceImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_MESSAGE(std::cout<<"Service is created..."<<std::endl;)
	//***********************************
}


ServiceImpl::~ServiceImpl()
{
	DEBUG_MESSAGE(std::cout<<"Service is destroyed..."<<std::endl;)
}

ServiceImpl::ServiceImpl(const ServiceImpl & obj):ServiceImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  ServiceImpl::copy() const
{
	std::shared_ptr<ServiceImpl> element(new ServiceImpl());
	*element=(*this);
	element->setThisServicePtr(element);
	return element;
}

ServiceImpl& ServiceImpl::operator=(const ServiceImpl & obj)
{
	//call overloaded =Operator for each base class
	uml::StereotypeImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Service "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)
	m_base_Component = obj.getBase_Component();

	//clone attributes with containment (deep copy)

	return *this;
}


std::shared_ptr<uml::Class> ServiceImpl::getMetaClass() const
{
	return StandardProfilePackageImpl::eInstance()->get_StandardProfile_Service();
}

void ServiceImpl::instantiate()
{   
	
}

void ServiceImpl::destroy()
{	

	//Erase properties
	//deleting property base_Component
	m_base_Component.reset();
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void ServiceImpl::setBase_Component(std::weak_ptr<uml::Component> _base_Component)
{
	m_base_Component = _base_Component;
	
}
std::weak_ptr<uml::Component> ServiceImpl::getBase_Component() const 
{

	return m_base_Component;
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
std::shared_ptr<Any> ServiceImpl::get(std::shared_ptr<uml::Property> _property) const
{
	std::string qualifiedName = _property->getQualifiedName();
	return this->get(qualifiedName);
}

std::shared_ptr<Any> ServiceImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->get(uID);
}

std::shared_ptr<Any> ServiceImpl::get(unsigned long _uID) const
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::SERVICE_ATTRIBUTE_BASE_COMPONENT:
			return eAny(this->getBase_Component(), uml::umlPackage::COMPONENT_CLASS, false);
	}

	return eAny(nullptr, -1, false);
}

//Set
void ServiceImpl::set(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->set(qualifiedName, value);
}

void ServiceImpl::set(std::string _qualifiedName, std::shared_ptr<Any> value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->set(uID, value);
}

void ServiceImpl::set(unsigned long _uID, std::shared_ptr<Any> value)
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::SERVICE_ATTRIBUTE_BASE_COMPONENT:
		{
			if(value->isContainer())
			{
				std::shared_ptr<Bag<uml::Component>> container = value->get<std::shared_ptr<Bag<uml::Component>>>();
				if(container)
				{
					if(!(container->empty()))
					{
						// If a non-empty container is passed, the property will be set to the first value of the container
						this->setBase_Component(container->at(0));
					}
				}
			}
			else
			{
				this->setBase_Component(value->get<std::shared_ptr<uml::Component>>());
			}
			return;
		}
	}

}

//Add
void ServiceImpl::add(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->set(qualifiedName, value);
}

void ServiceImpl::add(std::string _qualifiedName, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->set(uID, value);
}

void ServiceImpl::add(unsigned long _uID, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
}

//Unset
void ServiceImpl::unset(std::shared_ptr<uml::Property> _property)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->unset(qualifiedName);
}

void ServiceImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->unset(uID);
}

void ServiceImpl::unset(unsigned long _uID)
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::SERVICE_ATTRIBUTE_BASE_COMPONENT:
		{
			m_base_Component.reset();
			return;
		}
	}

}

//*********************************
// Operation Invoction
//*********************************
//Invoke
std::shared_ptr<Any> ServiceImpl::invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> _arguments)
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

std::shared_ptr<Any> ServiceImpl::invoke(std::string _qualifiedName, std::shared_ptr<Bag<Any>> _arguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invoke(uID, _arguments);
}

std::shared_ptr<Any> ServiceImpl::invoke(unsigned long _uID, std::shared_ptr<Bag<Any>> _arguments)
{
	return eAny(nullptr, -1, false);
}

std::shared_ptr<Service> ServiceImpl::getThisServicePtr()
{
	return m_thisServicePtr.lock();
}
void ServiceImpl::setThisServicePtr(std::weak_ptr<Service> thisServicePtr)
{
	m_thisServicePtr = thisServicePtr;
	setThisStereotypePtr(thisServicePtr);
}
