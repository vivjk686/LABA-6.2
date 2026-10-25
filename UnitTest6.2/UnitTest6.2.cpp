#include "pch.h"
#include "CppUnitTest.h"

#define UNIT_TESTING
#include "../LABA-6.2/LABA-6.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest62
{
    TEST_CLASS(UnitTest62)
    {
    public:
        TEST_METHOD(TestMaxMin_StandardArray)
        {
            int arr[] = { 10, -5, 23, 4, -18, 50, 0 };
            int maxVal = arr[0];
            int minVal = arr[0];
            MaxMin(arr, 7, 1, maxVal, minVal);
            Assert::AreEqual(50, maxVal);
            Assert::AreEqual(-18, minVal);
        }

        TEST_METHOD(TestMax_HelperFunction)
        {
            int arr[] = { 10, -5, 23, 4, -18, 50, 0 };
            int maxVal = Max(arr, 7, 1, arr[0]);
            Assert::AreEqual(50, maxVal);
        }

        TEST_METHOD(TestMin_HelperFunction)
        {
            int arr[] = { 10, -5, 23, 4, -18, 50, 0 };
            int minVal = Min(arr, 7, 1, arr[0]);
            Assert::AreEqual(-18, minVal);
        }

        TEST_METHOD(TestMaxAtStart_MinAtEnd)
        {
            int arr[] = { 100, 50, 20, 0, -10, -50 };
            int maxVal = arr[0];
            int minVal = arr[0];
            MaxMin(arr, 6, 1, maxVal, minVal);
            Assert::AreEqual(100, maxVal);
            Assert::AreEqual(-50, minVal);
        }

        TEST_METHOD(TestMinAtStart_MaxAtEnd)
        {
            int arr[] = { -70, -30, 0, 15, 85 };
            int maxVal = arr[0];
            int minVal = arr[0];
            MaxMin(arr, 5, 1, maxVal, minVal);
            Assert::AreEqual(85, maxVal);
            Assert::AreEqual(-70, minVal);
        }

        TEST_METHOD(TestSingleElement)
        {
            int arr[] = { 42 };
            int maxVal = arr[0];
            int minVal = arr[0];
            MaxMin(arr, 1, 1, maxVal, minVal);
            Assert::AreEqual(42, maxVal);
            Assert::AreEqual(42, minVal);
            Assert::AreEqual(42, Max(arr, 1, 1, arr[0]));
            Assert::AreEqual(42, Min(arr, 1, 1, arr[0]));
        }

        TEST_METHOD(TestAllNegative)
        {
            int arr[] = { -15, -2, -88, -4, -30 };
            int maxVal = arr[0];
            int minVal = arr[0];
            MaxMin(arr, 5, 1, maxVal, minVal);
            Assert::AreEqual(-2, maxVal);
            Assert::AreEqual(-88, minVal);
        }

        TEST_METHOD(TestDuplicateMaxMin)
        {
            int arr[] = { 5, 50, 5, 50, 5 };
            int maxVal = arr[0];
            int minVal = arr[0];
            MaxMin(arr, 5, 1, maxVal, minVal);
            Assert::AreEqual(50, maxVal);
            Assert::AreEqual(5, minVal);
        }
    };
}
