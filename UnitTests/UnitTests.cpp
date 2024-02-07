#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>

#include <string>
#include <vector>
#include "..\ConsPointersFunctions\FunctionExercises.h"
#include "..\ConsPointersFunctions\PointersExercises.h"
#include "Utilities.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTests
{
	template <typename T>
	std::wstring createErrorMessage(T expected, T received);

	TEST_CLASS(FunctionsTests)
	{

		string dataFile;
		const static int MAX_LEN = 20;
		const static int BUFSIZE = 160;

	public:
		TEST_METHOD_INITIALIZE(InitMethods)
		{
			dataFile = "dataFile.txt";
		}


		
		
		TEST_METHOD(TestSum)
		{
			std::vector<string> lines = GetDataFile(dataFile);
			if (lines.size() == 0)
			{
				Assert::Fail(L"No lines in data file");
			}

			int nums[MAX_LEN] = {};
			int cntNums = getTestArray(lines, 0, nums);

			int a = nums[0], b = nums[1];
			int result = Sum(a, b);
			int expected = nums[2];

			Assert::AreEqual<int>(expected, result, createErrorMessage<int>(expected, result).c_str());

		}
		TEST_METHOD(TestSwap)
		{
			std::vector<string> lines = GetDataFile(dataFile);
			if (lines.size() == 0)
			{
				Assert::Fail(L"No lines in data file");
			}

			int nums[MAX_LEN] = {};
			int cntNums = getTestArray(lines, 1, nums);
			int a = nums[0], b = nums[1], xb = nums[3], xa = nums[2];
			Swap(a, b);
			

			Assert::AreEqual<int>(a, xa, createErrorMessage<int>(a, xa).c_str());
			Assert::AreEqual<int>(b, xb, createErrorMessage<int>(b, xb).c_str());

		}

		TEST_METHOD(TestSumItems_V1)
		{
			std::vector<string> lines = GetDataFile(dataFile);
			if (lines.size() == 0)
			{
				Assert::Fail(L"No lines in data file");
			}

			double prices[MAX_LEN] = {0};
			int cntNums = getTestArrayDoubles(lines, 2, prices);

			double expected = prices[cntNums - 1];
			prices[cntNums - 1] = 0;
			int len = sizeof(prices) / sizeof(double);
			double result = SumItems(prices, len);
			double diff = abs(expected - result);

			Assert::IsFalse(diff > .01, createErrorMessage<double>(expected, result).c_str());

		}
		
		TEST_METHOD(TestSumItems_V2)
		{
			std::vector<string> lines = GetDataFile(dataFile);
			if (lines.size() == 0)
			{
				Assert::Fail(L"No lines in data file");
			}

			double prices[MAX_LEN] = { 0 };
			int cntNums = getTestArrayDoubles(lines, 3, prices);

			double expected = prices[cntNums - 3];
			double discount = prices[cntNums - 2];
			double threshold = prices[cntNums - 1];

			prices[cntNums - 3] = prices[cntNums - 2] = prices[cntNums - 1] = 0;

			int len = sizeof(prices) / sizeof(double);

			double result = SumItems(prices, len, discount);
			
			double diff = abs(expected - result);


			Assert::IsFalse(diff > .01, createErrorMessage<double>(expected, result).c_str());

		}

		TEST_METHOD(TestSumItems_V3)
		{
			std::vector<string> lines = GetDataFile(dataFile);
			if (lines.size() == 0)
			{
				Assert::Fail(L"No lines in data file");
			}

			double prices[MAX_LEN] = { 0 };
			int cntNums = getTestArrayDoubles(lines, 4, prices);

			bool isCash = prices[cntNums - 1];
			double expected = prices[cntNums - 4];
			double discount = prices[cntNums - 3];
			double threshold = prices[cntNums - 2];

			prices[cntNums - 4]=
			prices[cntNums - 3] = prices[cntNums - 2] = prices[cntNums - 1] = 0;
			int len = sizeof(prices) / sizeof(double);

			double result = SumItems(prices, len, discount, isCash);
			double diff = abs(expected - result);
			Assert::IsFalse(diff > .01, createErrorMessage<double>(expected, result).c_str());

		}

		TEST_METHOD(TestPowerOf)
		{
			std::vector<string> lines = GetDataFile(dataFile);
			if (lines.size() == 0)
			{
				Assert::Fail(L"No lines in data file");
			}

			int nums[MAX_LEN] = {};
			int cntNums = getTestArray(lines, 5, nums);

			int _base = nums[0];
			int exponent = nums[1];

			int result = PowerOf(_base, exponent);
			int expected = nums[2];

			Assert::AreEqual<int>(expected, result, createErrorMessage<int>(expected, result).c_str());

		}
	};


	TEST_CLASS(PointersTests) {
public:

	string dataFile;
	const static int MAX_LEN = 20;
	const static int BUFSIZE = 160;

public:
	TEST_METHOD_INITIALIZE(InitMethods)
	{
		dataFile = "dataFile.txt";
	}

	TEST_METHOD(TestSwapPtrs)
	{
		
		std::vector<string> lines = GetDataFile(dataFile);
		if (lines.size() == 0)
		{
			Assert::Fail(L"No lines in data file");
		}

		int nums[MAX_LEN] = {};
		int cntNums = getTestArray(lines, 1, nums);
		int a = nums[0], b = nums[1], xb = nums[3], xa = nums[2];

		// Assign the addresses of a and p to pointer to int variables.
		int* pa = &a;
		int* pb = &b;

		SwapPtrs(pa, pb);

		Assert::AreEqual<int>(a, xb, createErrorMessage<int>(a, xb).c_str());
		Assert::AreEqual<int>(b, xa, createErrorMessage<int>(b, xa).c_str());

	}

	TEST_METHOD(TestDistanceBetweenPointers)
	{
		std::vector<string> lines = GetDataFile(dataFile);
		if (lines.size() == 0)
		{
			Assert::Fail(L"No lines in data file");
		}

		int nums[MAX_LEN] = { 0 };
		int cntNums = getTestArray(lines, 6, nums);

		int expected = nums[cntNums - 3];
		int start = nums[cntNums - 2];
		int end = nums[cntNums - 1];
			
		int result =
		DistanceBetweenPointers(&nums[start], &nums[end]);
		

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
