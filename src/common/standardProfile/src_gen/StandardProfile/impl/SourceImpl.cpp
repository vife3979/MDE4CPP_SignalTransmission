#include "StandardProfile/impl/SourceImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
#endif

#include <iostream>


#include "abstractDataTypes/SubsetUnion.hpp"
#include "util/util.hpp"
#include "uml/UMLAny.hpp"
#include "uml/UMLContainerAny.hpp"
#include "uml/Property.hpp"
#include "uml/Operation.hpp"
#include "uml/Parameter.hpp"
#include "StandardProfile/StandardProfileFactory.hpp"
#include "StandardProfile/impl/StandardProfilePackageImpl.hpp"
#include "uml/Stereotype.hpp"

//Types included from attributes, operation parameters, imports and composite owner classes
#include "uml/umlPackage.hpp"
#include "uml/Artifact.hpp"

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
SourceImpl::SourceImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_INFO("Instance of 'Source' is created.")
	//***********************************
}


SourceImpl::~SourceImpl()
{
	DEBUG_INFO("Instance of 'Source' is destroyed.")
}

SourceImpl::SourceImpl(const SourceImpl & obj):SourceImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  SourceImpl::copy() const
{
	std::shared_ptr<SourceImpl> element(new SourceImpl());
	*element=(*this);
	element->setThisSourcePtr(element);
	return element;
}

SourceImpl& SourceImpl::operator=(const SourceImpl & obj)
{
	//call overloaded =Operator for each base class
	FileImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Source "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)
	m_base_Artifact = obj.getBase_Artifact();

	//clone attributes with containment (deep copy)

	return *this;
}


std::shared_ptr<uml::Class> SourceImpl::getMetaClass() const
{
	return StandardProfilePackageImpl::eInstance()->get_StandardProfile_Source();
}

void SourceImpl::instantiate()
{   
	FileImpl::instantiate();
	
}

void SourceImpl::destroy()
{	

	//Erase properties
	//deleting property base_Artifact
	m_base_Artifact.reset();
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void SourceImpl::setBase_Artifact(std::weak_ptr<uml::Artifact> _base_Artifact)
{
	m_base_Artifact = _base_Artifact;
	
}
std::weak_ptr<uml::Artifact> SourceImpl::getBase_Artifact() const 
{

	return m_base_Artifact;
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
std::shared_ptr<Any> SourceImpl::get(std::shared_ptr<uml::Property> _property) const
{
	std::string qualifiedName = _property->getQualifiedName();
	return this->get(qualifiedName);
}

std::shared_ptr<Any> SourceImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->get(uID);
}

std::shared_ptr<Any> SourceImpl::get(unsigned long _uID) const
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::SOURCE_ATTRIBUTE_BASE_ARTIFACT:
			return eUMLAny(this->getBase_Artifact().lock(), uml::umlPackage::ARTIFACT_CLASS);
	}

	std::shared_ptr<Any> result;
	//Call get() for base class File
	result = StandardProfile::FileImpl::get(_uID);
	if (result != nullptr)
	{
		return result;
	}
	return result;
}

//Set
void SourceImpl::set(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->set(qualifiedName, value);
}

void SourceImpl::set(std::string _qualifiedName, std::shared_ptr<Any> value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->set(uID, value);
}

void SourceImpl::set(unsigned long _uID, std::shared_ptr<Any> value)
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::SOURCE_ATTRIBUTE_BASE_ARTIFACT:
		{
			std::shared_ptr<uml::UMLAny> umlAny = std::dynamic_pointer_cast<uml::UMLAny>(value);
			if(umlAny)
			{
				try
				{
					std::shared_ptr<uml::Element> element = umlAny->getAsElement();
					std::shared_ptr<uml::Artifact> _base_Artifact = std::dynamic_pointer_cast<uml::Artifact>(umlAny);
					if(_base_Artifact)
					{
						setBase_Artifact(_base_Artifact);
					}			
					else
					{
						throw "Invalid argument";
					}		
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'uml::UMLAny' for property 'base_Artifact'. Failed to set property!")
					return;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'uml::UMLAny' for property 'base_Artifact'. Failed to set property!")
				return;
			}
		break;
		}
	}
	//Call set() for base class File
	StandardProfile::FileImpl::set(_uID, value);
}

//Add
void SourceImpl::add(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->add(qualifiedName, value);
}

void SourceImpl::add(std::string _qualifiedName, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->add(uID, value);
}

void SourceImpl::add(unsigned long _uID, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	//Call set() for base class File
	StandardProfile::FileImpl::add(_uID, value, insertAt);
}

//Unset
void SourceImpl::unset(std::shared_ptr<uml::Property> _property)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->unset(qualifiedName);
}

void SourceImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->unset(uID);
}

void SourceImpl::unset(unsigned long _uID)
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::SOURCE_ATTRIBUTE_BASE_ARTIFACT:
		{
			m_base_Artifact.reset();
			return;
		}
	}

	//Call unset() for base class File
	StandardProfile::FileImpl::unset(_uID);
}

//Remove
void SourceImpl::remove(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->remove(qualifiedName, value);
}

void SourceImpl::remove(std::string _qualifiedName, std::shared_ptr<Any> value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->remove(uID, value);
}

void SourceImpl::remove(unsigned long _uID, std::shared_ptr<Any> value)
{
	//Call set() for base class File
	StandardProfile::FileImpl::remove(_uID, value);
}

//*********************************
// Operation Invoction
//*********************************
//Invoke
std::shared_ptr<Any> SourceImpl::invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> _arguments)
{
	std::shared_ptr<Any> result;
	//Call invoke() for base class File
	result = StandardProfile::FileImpl::invoke(_operation, _arguments);
	if (result != nullptr)
	{
		return result;
	}
	return result;

	/* Currently not functioning. TODO: Clarifiy how this should work in the future
	std::string qualifiedName = _operation->getQualifiedName();

	for(unsigned int i = 0; i < _operation->getOwnedParameter()->size(); i++)
	{
		qualifiedName += "_" + _operation->getOwnedParameter()->at(i)->getType()->getName();
	}

	return this->invoke(qualifiedName, _arguments);
	*/
}

std::shared_ptr<Any> SourceImpl::invoke(std::string _qualifiedName, std::shared_ptr<Bag<Any>> _arguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invoke(uID, _arguments);
}

std::shared_ptr<Any> SourceImpl::invoke(unsigned long _uID, std::shared_ptr<Bag<Any>> _arguments)
{
	std::shared_ptr<Any> result;
	//Call invoke() for base class File
	result = StandardProfile::FileImpl::invoke(_uID, _arguments);
	if (result != nullptr)
	{
		return result;
	}
	return result;
}

std::shared_ptr<Source> SourceImpl::getThisSourcePtr()
{
	return m_thisSourcePtr.lock();
}
void SourceImpl::setThisSourcePtr(std::weak_ptr<Source> thisSourcePtr)
{
	m_thisSourcePtr = thisSourcePtr;
	setThisFilePtr(thisSourcePtr);
}
