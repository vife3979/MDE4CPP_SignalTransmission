//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef LIBRARYMODEL_ECORE_BOOK_HPP
#define LIBRARYMODEL_ECORE_BOOK_HPP

#include <list>
#include <memory>
#include <string>


// forward declarations
template<class T> class Bag;



//*********************************
// generated Includes

#include <map>

namespace persistence
{
	namespace interface
	{
		class XLoadHandler; // used for Persistence
		class XSaveHandler; // used for Persistence
	}
}

namespace libraryModel_ecore
{
	class LibraryModel_ecoreFactory;
}

//Forward Declaration for used types
namespace libraryModel_ecore 
{
	class Author;
}

namespace libraryModel_ecore 
{
	class LibraryModel;
}

namespace libraryModel_ecore 
{
	class NamedElement;
}

namespace libraryModel_ecore 
{
	class Picture;
}

// base class includes
#include "libraryModel_ecore/NamedElement.hpp"

// enum includes


//*********************************
namespace libraryModel_ecore 
{
	/*!
	 */
	class Book:virtual public NamedElement
	{
		public:
 			Book(const Book &) {}
			Book& operator=(Book const&) = delete;

		protected:
			Book(){}


			//Additional constructors for the containments back reference

			Book(std::weak_ptr<libraryModel_ecore::LibraryModel > par_library);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Book() {}

			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<Bag<libraryModel_ecore::Author>> getAuthors() const = 0;
			
			/*!
			 */
			virtual std::weak_ptr<libraryModel_ecore::LibraryModel > getLibrary() const = 0;
			
			/*!
			 */
			virtual void setLibrary(std::shared_ptr<libraryModel_ecore::LibraryModel> _library_library) = 0;
			/*!
			 */
			virtual std::shared_ptr<Bag<libraryModel_ecore::Picture>> getPictures() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 */
			std::shared_ptr<Bag<libraryModel_ecore::Author>> m_authors;
			/*!
			 */
			std::weak_ptr<libraryModel_ecore::LibraryModel > m_library;
			/*!
			 */
			std::shared_ptr<Bag<libraryModel_ecore::Picture>> m_pictures;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: LIBRARYMODEL_ECORE_BOOK_HPP */
