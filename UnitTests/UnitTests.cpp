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
		
		TEST_METHOD(TestMethod1)
		{

			int result = PowerOf(9, 2);
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
