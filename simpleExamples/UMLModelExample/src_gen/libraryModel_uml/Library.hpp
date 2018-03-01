//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef LIBRARYMODEL_UML_LIBRARY__HPP
#define LIBRARYMODEL_UML_LIBRARY__HPP

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif
#include <iostream>
#include <memory>
#include "abstractDataTypes/SubsetUnion.hpp"


#include <map>
#include <string>
#include <vector>

#include "boost/any.hpp"
#include "boost/shared_ptr.hpp"

//Forward Declaration for used types
namespace LibraryModel_uml 
{
	class Author;
}

namespace LibraryModel_uml 
{
	class Book;
}


// base class includes

#include "uml/Class.hpp"

// enum includes

//*********************************

namespace LibraryModel_uml
{
	class Library : virtual public uml::Class 
	{
		private:    
			Library(const Library& that) = delete;

		protected:
			Library(){}

		public:
			//destructor
			virtual ~Library() {}

			//*********************************
			// Getter Setter
			//*********************************
			virtual std::shared_ptr<Bag<LibraryModel_uml::Author>> getAuthors() const  = 0;
			
			virtual std::shared_ptr<Bag<LibraryModel_uml::Book>> getBooks() const  = 0;
			
			
			
			//*********************************
			// Operations
			//*********************************
			
			
		protected:
			//*********************************
			// Members
			//*********************************
			std::shared_ptr<Bag<LibraryModel_uml::Author>> m_authors;
			std::shared_ptr<Bag<LibraryModel_uml::Book>> m_books;
			
	
	};
}
#endif /* end of include guard: LIBRARYMODEL_UML_LIBRARY__HPP */
