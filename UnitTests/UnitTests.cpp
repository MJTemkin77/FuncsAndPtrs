#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>

#include <string>
#include "..\ConsPointersFunctions\FunctionExercises.h"
#include "..\ConsPointersFunctions\PointersExercises.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTests
{
	template <typename T>
	std::wstring createErrorMessage(T expected, T received);

	TEST_CLASS(FunctionsTests)
	{
	public:
		
		
		TEST_METHOD(TestSum)
		{
			int a = 3, b = 12;
			int result = Sum(a, b);
			int expected = a + b;

			Assert::AreEqual<int>(expected, result, createErrorMessage<int>(expected, result).c_str());

		}
		TEST_METHOD(TestSwap)
		{
			int a = 3, b = 12, xb = a, xa = b;
			Swap(a, b);
			

			Assert::AreEqual<int>(a, xa, createErrorMessage<int>(a, xa).c_str());
			Assert::AreEqual<int>(b, xb, createErrorMessage<int>(b, xb).c_str());

		}

		TEST_METHOD(TestSumItems_V1)
		{
			double prices[] = { 7.5, 10.50, 21, 3.25, 51 };
			int len = sizeof(prices) / sizeof(double);
			double result = SumItems(prices, len);
			double expected = 93.25;
			double diff = abs(expected - result);

			Assert::IsFalse(diff > .01, createErrorMessage<double>(expected, result).c_str());

		}
		
		TEST_METHOD(TestSumItems_V2)
		{
			double prices[] = { 7.5, 10.50, 21, 3.25, 51 };
			double discount = .1;
			double threshold = 25;
			int len = sizeof(prices) / sizeof(double);

			double result = SumItems(prices, len, discount);
			double expected = 83.925;
			double diff = abs(expected - result);


			Assert::IsFalse(diff > .01, createErrorMessage<double>(expected, result).c_str());

		}

		TEST_METHOD(TestSumItems_V3)
		{
			double prices[] = { 7.5, 10.50, 21, 3.25, 51 };
			double discount = .1;
			double threshold = 25;
			int len = sizeof(prices) / sizeof(double);

			double result = SumItems(prices, len, discount, true);
			double expected = 74.60;
			double diff = abs(expected - result);
			Assert::IsFalse(diff > .01, createErrorMessage<double>(expected, result).c_str());

		}

		TEST_METHOD(TestPowerOf)
		{

			int result = PowerOf(2, 3);
			int expected  = 8;

			Assert::AreEqual<int>(expected, result, createErrorMessage<int>(expected, result).c_str());

		}
	};


	TEST_CLASS(PointersTests) {
public:


	TEST_METHOD(TestSwapPtrs)
	{
		int a = 3, b = 12, xb = a, xa = b;

		// Assign the addresses of a and p to pointer to int variables.
		int* pa = &a;
		int* pb = &b;

		SwapPtrs(pa, pb);

		Assert::AreEqual<int>(a, xb, createErrorMessage<int>(a, xb).c_str());
		Assert::AreEqual<int>(b, xa, createErrorMessage<int>(b, xa).c_str());

	}

	TEST_METHOD(TestDistanceBetweenPointers)
	{

		int nums[] = { 10, 20, 30, 40, 50, 60, 70 };
		int result =
		DistanceBetweenPointers(&nums[2], &nums[5]);
		int expected = 4;

		Assert::AreEqual<int>(expected, result, createErrorMessage<int>(expected, result).c_str());

	}
	};

	template <typename T>
	std::wstring createErrorMessage(T expected, T received)
	{
		std::string sample = "Expected " + std::to_string(expected) + ", Received: " + std::to_string(received);
		std::wstring wsample = std::wstring(sample.begin(), sample.end());
		return wsample;
	}


}
