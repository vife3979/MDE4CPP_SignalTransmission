#include "StandardProfile/impl/LibraryImpl.hpp"

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
LibraryImpl::LibraryImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_MESSAGE(std::cout<<"Library is created..."<<std::endl;)
	//***********************************
}


LibraryImpl::~LibraryImpl()
{
	DEBUG_MESSAGE(std::cout<<"Library is destroyed..."<<std::endl;)
}

LibraryImpl::LibraryImpl(const LibraryImpl & obj):LibraryImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  LibraryImpl::copy() const
{
	std::shared_ptr<LibraryImpl> element(new LibraryImpl());
	*element=(*this);
	element->setThisLibraryPtr(element);
	return element;
}

LibraryImpl& LibraryImpl::operator=(const LibraryImpl & obj)
{
	//call overloaded =Operator for each base class
	FileImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Library "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)
	m_base_Artifact = obj.getBase_Artifact();

	//clone attributes with containment (deep copy)

	return *this;
}


std::shared_ptr<uml::Class> LibraryImpl::getMetaClass() const
{
	return StandardProfilePackageImpl::eInstance()->get_StandardProfile_Library();
}

void LibraryImpl::instantiate()
{   
	FileImpl::instantiate();
	
}

void LibraryImpl::destroy()
{	

	//Erase properties
	//deleting property base_Artifact
	m_base_Artifact.reset();
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void LibraryImpl::setBase_Artifact(std::weak_ptr<uml::Artifact> _base_Artifact)
{
	m_base_Artifact = _base_Artifact;
	
}
std::weak_ptr<uml::Artifact> LibraryImpl::getBase_Artifact() const 
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
std::shared_ptr<Any> LibraryImpl::get(std::shared_ptr<uml::Property> _property) const
{
	std::string qualifiedName = _property->getQualifiedName();
	return this->get(qualifiedName);
}

std::shared_ptr<Any> LibraryImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->get(uID);
}

std::shared_ptr<Any> LibraryImpl::get(unsigned long _uID) const
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::LIBRARY_ATTRIBUTE_BASE_ARTIFACT:
			return eAny(this->getBase_Artifact(), uml::umlPackage::ARTIFACT_CLASS, false);
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
void LibraryImpl::set(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->set(qualifiedName, value);
}

void LibraryImpl::set(std::string _qualifiedName, std::shared_ptr<Any> value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->set(uID, value);
}

void LibraryImpl::set(unsigned long _uID, std::shared_ptr<Any> value)
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::LIBRARY_ATTRIBUTE_BASE_ARTIFACT:
		{
			if(value->isContainer())
			{
				std::shared_ptr<Bag<uml::Artifact>> container = value->get<std::shared_ptr<Bag<uml::Artifact>>>();
				if(container)
				{
					if(!(container->empty()))
					{
						// If a non-empty container is passed, the property will be set to the first value of the container
						this->setBase_Artifact(container->at(0));
					}
				}
			}
			else
			{
				this->setBase_Artifact(value->get<std::shared_ptr<uml::Artifact>>());
			}
			return;
		}
	}

	//Call set() for base class File
	StandardProfile::FileImpl::set(_uID, value);
}

//Add
void LibraryImpl::add(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->set(qualifiedName, value);
}

void LibraryImpl::add(std::string _qualifiedName, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->set(uID, value);
}

void LibraryImpl::add(unsigned long _uID, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	//Call set() for base class File
	StandardProfile::FileImpl::add(_uID, value);
}

//Unset
void LibraryImpl::unset(std::shared_ptr<uml::Property> _property)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->unset(qualifiedName);
}

void LibraryImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->unset(uID);
}

void LibraryImpl::unset(unsigned long _uID)
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::LIBRARY_ATTRIBUTE_BASE_ARTIFACT:
		{
			m_base_Artifact.reset();
			return;
		}
	}

	//Call unset() for base class File
	StandardProfile::FileImpl::unset(_uID);
}

//*********************************
// Operation Invoction
//*********************************
//Invoke
std::shared_ptr<Any> LibraryImpl::invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> _arguments)
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

std::shared_ptr<Any> LibraryImpl::invoke(std::string _qualifiedName, std::shared_ptr<Bag<Any>> _arguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invoke(uID, _arguments);
}

std::shared_ptr<Any> LibraryImpl::invoke(unsigned long _uID, std::shared_ptr<Bag<Any>> _arguments)
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

std::shared_ptr<Library> LibraryImpl::getThisLibraryPtr()
{
	return m_thisLibraryPtr.lock();
}
void LibraryImpl::setThisLibraryPtr(std::weak_ptr<Library> thisLibraryPtr)
{
	m_thisLibraryPtr = thisLibraryPtr;
	setThisFilePtr(thisLibraryPtr);
}
