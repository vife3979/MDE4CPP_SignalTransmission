//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef LIBRARYMODEL_ECORE_LIBRARYMODELLIBRARYMODELIMPL_HPP
#define LIBRARYMODEL_ECORE_LIBRARYMODELLIBRARYMODELIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../LibraryModel.hpp"


#include "ecore/impl/EObjectImpl.hpp"

//*********************************
namespace libraryModel_ecore 
{
	class LibraryModelImpl :virtual public ecore::EObjectImpl,
virtual public LibraryModel 
	{
		public: 
			LibraryModelImpl(const LibraryModelImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			LibraryModelImpl& operator=(LibraryModelImpl const&) = delete;

		protected:
			friend class LibraryModel_ecoreFactoryImpl;
			LibraryModelImpl();
			virtual std::shared_ptr<LibraryModel> getThisLibraryModelPtr();
			virtual void setThisLibraryModelPtr(std::weak_ptr<LibraryModel> thisLibraryModelPtr);



		public:
			//destructor
			virtual ~LibraryModelImpl();
			
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
			virtual std::shared_ptr<Bag<libraryModel_ecore::Author>> getAuthors() const ;
			
			/*!
			 */
			virtual std::shared_ptr<Bag<libraryModel_ecore::Book>> getBook() const ;
			
							
			
			//*********************************
			// Union Getter
			//*********************************
			 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************

			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interface::XLoadHandler> loadHandler, std::shared_ptr<libraryModel_ecore::LibraryModel_ecoreFactory> modelFactory);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual boost::any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, boost::any newValue) ;

		private:
			std::weak_ptr<LibraryModel> m_thisLibraryModelPtr;
	};
}
#endif /* end of include guard: LIBRARYMODEL_ECORE_LIBRARYMODELLIBRARYMODELIMPL_HPP */
