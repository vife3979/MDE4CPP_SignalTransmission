//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef SUBSETUNIONBENCHMARKDEPTHPACKAGE_HPP
#define SUBSETUNIONBENCHMARKDEPTHPACKAGE_HPP

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

#include "EPackage.hpp"
#include "EcoreFactory.hpp"

namespace subsetUnionBenchmarkDepth 
{	class Container;
	class Container_Level1;
	class Container_Level10;
	class Container_Level2;
	class Container_Level3;
	class Container_Level4;
	class Container_Level5;
	class Container_Level6;
	class Container_Level7;
	class Container_Level8;
	class Container_Level9;
	class Element;
	class Element_Level1;
	class Element_Level10;
	class Element_Level2;
	class Element_Level3;
	class Element_Level4;
	class Element_Level5;
	class Element_Level6;
	class Element_Level7;
	class Element_Level8;
	class Element_Level9;
	class ExampleModel;
	class SubsetUnionBenchmarkDepthPackage;
}

namespace subsetUnionBenchmarkDepth 
{
	/*!
	The Metamodel Package for the subsetUnionBenchmarkDepth metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	/*!
	 */
	class SubsetUnionBenchmarkDepthPackage : virtual public ecore::EPackage 
	{
		private:    
			SubsetUnionBenchmarkDepthPackage(SubsetUnionBenchmarkDepthPackage const&) = delete;
			SubsetUnionBenchmarkDepthPackage& operator=(SubsetUnionBenchmarkDepthPackage const&) = delete;

		protected:
			SubsetUnionBenchmarkDepthPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			// Begin Class Container
			//Class and Feature IDs 
			static const int CONTAINER = 1;
			static const int CONTAINER_FEATURE_COUNT = 2;
			static const int CONTAINER_OPERATION_COUNT = 0;
			static const int CONTAINER_NAME = 11;
			
			static const int CONTAINER_UNION = 10;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getContainer() const = 0;
			virtual std::shared_ptr<ecore::EAttribute> getContainer_Name() const = 0;
			
			virtual std::shared_ptr<ecore::EReference> getContainer_Union() const = 0;
			
			
			// End Class Container


			// Begin Class Container_Level1
			//Class and Feature IDs 
			static const int CONTAINER_LEVEL1 = 4;
			static const int CONTAINER_LEVEL1_FEATURE_COUNT = 3;
			static const int CONTAINER_LEVEL1_OPERATION_COUNT = 0;
			
			static const int CONTAINER_LEVEL1_SUBSET1 = 42;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getContainer_Level1() const = 0;
			
			virtual std::shared_ptr<ecore::EReference> getContainer_Level1_Subset1() const = 0;
			
			
			// End Class Container_Level1


			// Begin Class Container_Level10
			//Class and Feature IDs 
			static const int CONTAINER_LEVEL10 = 22;
			static const int CONTAINER_LEVEL10_FEATURE_COUNT = 12;
			static const int CONTAINER_LEVEL10_OPERATION_COUNT = 0;
			
			static const int CONTAINER_LEVEL10_SUBSET10 = 2211;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getContainer_Level10() const = 0;
			
			virtual std::shared_ptr<ecore::EReference> getContainer_Level10_Subset10() const = 0;
			
			
			// End Class Container_Level10


			// Begin Class Container_Level2
			//Class and Feature IDs 
			static const int CONTAINER_LEVEL2 = 6;
			static const int CONTAINER_LEVEL2_FEATURE_COUNT = 4;
			static const int CONTAINER_LEVEL2_OPERATION_COUNT = 0;
			
			static const int CONTAINER_LEVEL2_SUBSET2 = 63;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getContainer_Level2() const = 0;
			
			virtual std::shared_ptr<ecore::EReference> getContainer_Level2_Subset2() const = 0;
			
			
			// End Class Container_Level2


			// Begin Class Container_Level3
			//Class and Feature IDs 
			static const int CONTAINER_LEVEL3 = 8;
			static const int CONTAINER_LEVEL3_FEATURE_COUNT = 5;
			static const int CONTAINER_LEVEL3_OPERATION_COUNT = 0;
			
			static const int CONTAINER_LEVEL3_SUBSET3 = 84;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getContainer_Level3() const = 0;
			
			virtual std::shared_ptr<ecore::EReference> getContainer_Level3_Subset3() const = 0;
			
			
			// End Class Container_Level3


			// Begin Class Container_Level4
			//Class and Feature IDs 
			static const int CONTAINER_LEVEL4 = 10;
			static const int CONTAINER_LEVEL4_FEATURE_COUNT = 6;
			static const int CONTAINER_LEVEL4_OPERATION_COUNT = 0;
			
			static const int CONTAINER_LEVEL4_SUBSET4 = 105;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getContainer_Level4() const = 0;
			
			virtual std::shared_ptr<ecore::EReference> getContainer_Level4_Subset4() const = 0;
			
			
			// End Class Container_Level4


			// Begin Class Container_Level5
			//Class and Feature IDs 
			static const int CONTAINER_LEVEL5 = 11;
			static const int CONTAINER_LEVEL5_FEATURE_COUNT = 7;
			static const int CONTAINER_LEVEL5_OPERATION_COUNT = 0;
			
			static const int CONTAINER_LEVEL5_SUBSET5 = 116;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getContainer_Level5() const = 0;
			
			virtual std::shared_ptr<ecore::EReference> getContainer_Level5_Subset5() const = 0;
			
			
			// End Class Container_Level5


			// Begin Class Container_Level6
			//Class and Feature IDs 
			static const int CONTAINER_LEVEL6 = 14;
			static const int CONTAINER_LEVEL6_FEATURE_COUNT = 8;
			static const int CONTAINER_LEVEL6_OPERATION_COUNT = 0;
			
			static const int CONTAINER_LEVEL6_SUBSET6 = 147;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getContainer_Level6() const = 0;
			
			virtual std::shared_ptr<ecore::EReference> getContainer_Level6_Subset6() const = 0;
			
			
			// End Class Container_Level6


			// Begin Class Container_Level7
			//Class and Feature IDs 
			static const int CONTAINER_LEVEL7 = 16;
			static const int CONTAINER_LEVEL7_FEATURE_COUNT = 9;
			static const int CONTAINER_LEVEL7_OPERATION_COUNT = 0;
			
			static const int CONTAINER_LEVEL7_SUBSET7 = 168;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getContainer_Level7() const = 0;
			
			virtual std::shared_ptr<ecore::EReference> getContainer_Level7_Subset7() const = 0;
			
			
			// End Class Container_Level7


			// Begin Class Container_Level8
			//Class and Feature IDs 
			static const int CONTAINER_LEVEL8 = 17;
			static const int CONTAINER_LEVEL8_FEATURE_COUNT = 10;
			static const int CONTAINER_LEVEL8_OPERATION_COUNT = 0;
			
			static const int CONTAINER_LEVEL8_SUBSET8 = 179;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getContainer_Level8() const = 0;
			
			virtual std::shared_ptr<ecore::EReference> getContainer_Level8_Subset8() const = 0;
			
			
			// End Class Container_Level8


			// Begin Class Container_Level9
			//Class and Feature IDs 
			static const int CONTAINER_LEVEL9 = 20;
			static const int CONTAINER_LEVEL9_FEATURE_COUNT = 11;
			static const int CONTAINER_LEVEL9_OPERATION_COUNT = 0;
			
			static const int CONTAINER_LEVEL9_SUBSET9 = 2010;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getContainer_Level9() const = 0;
			
			virtual std::shared_ptr<ecore::EReference> getContainer_Level9_Subset9() const = 0;
			
			
			// End Class Container_Level9


			// Begin Class Element
			//Class and Feature IDs 
			static const int ELEMENT = 2;
			static const int ELEMENT_FEATURE_COUNT = 1;
			static const int ELEMENT_OPERATION_COUNT = 0;
			static const int ELEMENT_NAME = 20;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getElement() const = 0;
			virtual std::shared_ptr<ecore::EAttribute> getElement_Name() const = 0;
			
			
			
			// End Class Element


			// Begin Class Element_Level1
			//Class and Feature IDs 
			static const int ELEMENT_LEVEL1 = 3;
			static const int ELEMENT_LEVEL1_FEATURE_COUNT = 1;
			static const int ELEMENT_LEVEL1_OPERATION_COUNT = 0;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getElement_Level1() const = 0;
			
			
			
			// End Class Element_Level1


			// Begin Class Element_Level10
			//Class and Feature IDs 
			static const int ELEMENT_LEVEL10 = 21;
			static const int ELEMENT_LEVEL10_FEATURE_COUNT = 1;
			static const int ELEMENT_LEVEL10_OPERATION_COUNT = 0;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getElement_Level10() const = 0;
			
			
			
			// End Class Element_Level10


			// Begin Class Element_Level2
			//Class and Feature IDs 
			static const int ELEMENT_LEVEL2 = 5;
			static const int ELEMENT_LEVEL2_FEATURE_COUNT = 1;
			static const int ELEMENT_LEVEL2_OPERATION_COUNT = 0;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getElement_Level2() const = 0;
			
			
			
			// End Class Element_Level2


			// Begin Class Element_Level3
			//Class and Feature IDs 
			static const int ELEMENT_LEVEL3 = 7;
			static const int ELEMENT_LEVEL3_FEATURE_COUNT = 1;
			static const int ELEMENT_LEVEL3_OPERATION_COUNT = 0;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getElement_Level3() const = 0;
			
			
			
			// End Class Element_Level3


			// Begin Class Element_Level4
			//Class and Feature IDs 
			static const int ELEMENT_LEVEL4 = 9;
			static const int ELEMENT_LEVEL4_FEATURE_COUNT = 1;
			static const int ELEMENT_LEVEL4_OPERATION_COUNT = 0;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getElement_Level4() const = 0;
			
			
			
			// End Class Element_Level4


			// Begin Class Element_Level5
			//Class and Feature IDs 
			static const int ELEMENT_LEVEL5 = 12;
			static const int ELEMENT_LEVEL5_FEATURE_COUNT = 1;
			static const int ELEMENT_LEVEL5_OPERATION_COUNT = 0;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getElement_Level5() const = 0;
			
			
			
			// End Class Element_Level5


			// Begin Class Element_Level6
			//Class and Feature IDs 
			static const int ELEMENT_LEVEL6 = 13;
			static const int ELEMENT_LEVEL6_FEATURE_COUNT = 1;
			static const int ELEMENT_LEVEL6_OPERATION_COUNT = 0;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getElement_Level6() const = 0;
			
			
			
			// End Class Element_Level6


			// Begin Class Element_Level7
			//Class and Feature IDs 
			static const int ELEMENT_LEVEL7 = 15;
			static const int ELEMENT_LEVEL7_FEATURE_COUNT = 1;
			static const int ELEMENT_LEVEL7_OPERATION_COUNT = 0;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getElement_Level7() const = 0;
			
			
			
			// End Class Element_Level7


			// Begin Class Element_Level8
			//Class and Feature IDs 
			static const int ELEMENT_LEVEL8 = 18;
			static const int ELEMENT_LEVEL8_FEATURE_COUNT = 1;
			static const int ELEMENT_LEVEL8_OPERATION_COUNT = 0;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getElement_Level8() const = 0;
			
			
			
			// End Class Element_Level8


			// Begin Class Element_Level9
			//Class and Feature IDs 
			static const int ELEMENT_LEVEL9 = 19;
			static const int ELEMENT_LEVEL9_FEATURE_COUNT = 1;
			static const int ELEMENT_LEVEL9_OPERATION_COUNT = 0;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getElement_Level9() const = 0;
			
			
			
			// End Class Element_Level9


			// Begin Class ExampleModel
			//Class and Feature IDs 
			static const int EXAMPLEMODEL = 0;
			static const int EXAMPLEMODEL_FEATURE_COUNT = 1;
			static const int EXAMPLEMODEL_OPERATION_COUNT = 0;
			
			static const int EXAMPLEMODEL_CONTAINER = 00;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getExampleModel() const = 0;
			
			virtual std::shared_ptr<ecore::EReference> getExampleModel_Container() const = 0;
			
			
			// End Class ExampleModel

			
			

			//Singleton Instance and Getter
			private:
				static std::shared_ptr<SubsetUnionBenchmarkDepthPackage> instance;
			public:
				static std::shared_ptr<SubsetUnionBenchmarkDepthPackage> eInstance();
	};
}
#endif /* end of include guard: SUBSETUNIONBENCHMARKDEPTHPACKAGE_HPP */

