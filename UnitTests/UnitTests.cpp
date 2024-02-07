#include "pch.h"
#include "CppUnitTest.h"

#include <string>
#include "..\ConsPointersFunctions\FunctionExercises.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTests
{
	std::wstring createErrorMessage(int, int);

	TEST_CLASS(UnitTests)
	{
	public:
		
		
		TEST_METHOD(TestSum)
		{
			int a = 211, b = 303;
			int result = Sum(a, b);
			int expected = a + b;

			Assert::AreEqual<int>(expected, result, createErrorMessage(expected, result).c_str());

		}
		TEST_METHOD(TestSwap)
		{
			int a = 211, b = 303, xb = 211, xa = 303;
			Swap(a, b);
			

			Assert::AreEqual<int>(a, xa, createErrorMessage(a, xa).c_str());
			Assert::AreEqual<int>(b, xb, createErrorMessage(b, xb).c_str());

		}
		//Swap(int& a, int& b);
		TEST_METHOD(TestMethod1)
		{

			int result = PowerOf(3, 2);
			int expected  = 9;

			Assert::AreEqual<int>(expected, result, createErrorMessage(expected, result).c_str());

		}
	};

	std::wstring createErrorMessage(int expected, int received)
	{
		std::string sample = "Expected " + std::to_string(expected) + ", Received: " + std::to_string(received);
		std::wstring wsample = std::wstring(sample.begin(), sample.end());
		return wsample;
	}
}
