#include "StandardProfile/impl/MetamodelImpl.hpp"

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
#include "uml/Model.hpp"

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
MetamodelImpl::MetamodelImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_MESSAGE(std::cout<<"Metamodel is created..."<<std::endl;)
	//***********************************
}


MetamodelImpl::~MetamodelImpl()
{
	DEBUG_MESSAGE(std::cout<<"Metamodel is destroyed..."<<std::endl;)
}

MetamodelImpl::MetamodelImpl(const MetamodelImpl & obj):MetamodelImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  MetamodelImpl::copy() const
{
	std::shared_ptr<MetamodelImpl> element(new MetamodelImpl());
	*element=(*this);
	element->setThisMetamodelPtr(element);
	return element;
}

MetamodelImpl& MetamodelImpl::operator=(const MetamodelImpl & obj)
{
	//call overloaded =Operator for each base class
	uml::StereotypeImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Metamodel "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)
	m_base_Model = obj.getBase_Model();

	//clone attributes with containment (deep copy)

	return *this;
}


std::shared_ptr<uml::Class> MetamodelImpl::getMetaClass() const
{
	return StandardProfilePackageImpl::eInstance()->get_StandardProfile_Metamodel();
}

void MetamodelImpl::instantiate()
{   
	
}

void MetamodelImpl::destroy()
{	

	//Erase properties
	//deleting property base_Model
	m_base_Model.reset();
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void MetamodelImpl::setBase_Model(std::weak_ptr<uml::Model> _base_Model)
{
	m_base_Model = _base_Model;
	
}
std::weak_ptr<uml::Model> MetamodelImpl::getBase_Model() const 
{

	return m_base_Model;
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
std::shared_ptr<Any> MetamodelImpl::get(std::shared_ptr<uml::Property> _property) const
{
	std::string qualifiedName = _property->getQualifiedName();
	return this->get(qualifiedName);
}

std::shared_ptr<Any> MetamodelImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->get(uID);
}

std::shared_ptr<Any> MetamodelImpl::get(unsigned long _uID) const
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::METAMODEL_ATTRIBUTE_BASE_MODEL:
			return eAny(this->getBase_Model(), uml::umlPackage::MODEL_CLASS, false);
	}

	return eAny(nullptr, -1, false);
}

//Set
void MetamodelImpl::set(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->set(qualifiedName, value);
}

void MetamodelImpl::set(std::string _qualifiedName, std::shared_ptr<Any> value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->set(uID, value);
}

void MetamodelImpl::set(unsigned long _uID, std::shared_ptr<Any> value)
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::METAMODEL_ATTRIBUTE_BASE_MODEL:
		{
			if(value->isContainer())
			{
				std::shared_ptr<Bag<uml::Model>> container = value->get<std::shared_ptr<Bag<uml::Model>>>();
				if(container)
				{
					if(!(container->empty()))
					{
						// If a non-empty container is passed, the property will be set to the first value of the container
						this->setBase_Model(container->at(0));
					}
				}
			}
			else
			{
				this->setBase_Model(value->get<std::shared_ptr<uml::Model>>());
			}
			return;
		}
	}

}

//Add
void MetamodelImpl::add(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->set(qualifiedName, value);
}

void MetamodelImpl::add(std::string _qualifiedName, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->set(uID, value);
}

void MetamodelImpl::add(unsigned long _uID, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
}

//Unset
void MetamodelImpl::unset(std::shared_ptr<uml::Property> _property)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->unset(qualifiedName);
}

void MetamodelImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->unset(uID);
}

void MetamodelImpl::unset(unsigned long _uID)
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::METAMODEL_ATTRIBUTE_BASE_MODEL:
		{
			m_base_Model.reset();
			return;
		}
	}

}

//*********************************
// Operation Invoction
//*********************************
//Invoke
std::shared_ptr<Any> MetamodelImpl::invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> _arguments)
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

std::shared_ptr<Any> MetamodelImpl::invoke(std::string _qualifiedName, std::shared_ptr<Bag<Any>> _arguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invoke(uID, _arguments);
}

std::shared_ptr<Any> MetamodelImpl::invoke(unsigned long _uID, std::shared_ptr<Bag<Any>> _arguments)
{
	return eAny(nullptr, -1, false);
}

std::shared_ptr<Metamodel> MetamodelImpl::getThisMetamodelPtr()
{
	return m_thisMetamodelPtr.lock();
}
void MetamodelImpl::setThisMetamodelPtr(std::weak_ptr<Metamodel> thisMetamodelPtr)
{
	m_thisMetamodelPtr = thisMetamodelPtr;
	setThisStereotypePtr(thisMetamodelPtr);
}
