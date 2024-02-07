#include "pch.h"
#include "Utilities.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <memory>
#include <iostream>

using namespace std;


/// <summary>
		/// Get the contents of the text file as a string vector.
		/// </summary>
		/// <param name="fileName"></param>
		/// <returns></returns>
std::vector<string> GetDataFile(string fileName)
{
	std::vector<string> lines;

	// Go to the base level of the assignments folder.
	filesystem::path cwd = filesystem::current_path().parent_path().parent_path();

	std::string fn = cwd.string() + "\\" + fileName;
	ifstream inputFile;
	inputFile.open(fn, ios_base::in);

	if (inputFile.is_open())
	{
		string currentLine;
		while (inputFile.good())
		{
			getline(inputFile, currentLine);
			lines.push_back(currentLine);
		}

	}

	return lines;

}


int getTestArray(std::vector<string> lines, int lineNumber, int nums[])
{
	if (lineNumber >= lines.size())
		return -1;

	std::string str = lines[lineNumber];
	char stringBuffer[BUFSIZE];

	strcpy_s(stringBuffer, sizeof(stringBuffer), str.c_str());
	int cntNums = ConvertDelimitedIntsToArray(stringBuffer, nums);
	return cntNums;
}

int getTestArrayDoubles(std::vector<string> lines, int lineNumber, double nums[])
{
	if (lineNumber >= lines.size())
		return -1;

	std::string str = lines[lineNumber];
	char stringBuffer[BUFSIZE];

	strcpy_s(stringBuffer, sizeof(stringBuffer), str.c_str());
	int cntNums = ConvertDelimitedDoublesToArray(stringBuffer, nums);
	return cntNums;
}

std::vector<std::string> getNamesAsVector(std::vector<std::string> lines, int lineNumber) {
	if (lineNumber >= lines.size())
		return std::vector<std::string>();

	std::string str = lines[lineNumber];
	char stringBuffer[BUFSIZE];

	strcpy_s(stringBuffer, sizeof(stringBuffer), str.c_str());
	std::vector<std::string> tabnames = ConvertDelimitedStringsToArray(stringBuffer);
	return tabnames;
}

int getNamesInArray(std::vector<std::string> lines, int lineNumber, char names[20][64]) {
	if (lineNumber >= lines.size())
		return -1;

	std::string str = lines[lineNumber];
	char stringBuffer[BUFSIZE];

	strcpy_s(stringBuffer, sizeof(stringBuffer), str.c_str());
	std::vector<std::string> tabnames = ConvertDelimitedStringsToArray(stringBuffer);

	const int NAMESIZE = 64;
	for (size_t i = 0; i < tabnames.size(); i++)
	{
		strcpy_s(names[i], NAMESIZE, tabnames[i].c_str());
	}

}

/// <summary>
/// Split a string and convert it to an array of integers.
/// This is the C++ implementation of the .NET String.Split method.
/// 
/// Convert the delimited list of integers as numbers into an array of integers.
/// The method splits a string on the delimiter, using the C++ method, strtok_s,
/// so that the first word is returned as the char string which is referred to by the p pointer. 
/// 
/// The conversion from a string to an integer is done with the atoi method.
/// 
/// Microsoft documentation on strtok_s is below.
/// See: https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/strtok-s-strtok-s-l-wcstok-s-wcstok-s-l-mbstok-s-mbstok-s-l
/// 
/// MS documentation on atoi is below.
/// https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/atoi-atoi-l-wtoi-wtoi-l?view=msvc-170
/// </summary>
/// <param name="input">The series of numbers stored in a delimited string</param>
/// <param name="nums">The array used to store the ints in the string</param>
/// <returns>Number of ints in string</returns>
/// 
int ConvertDelimitedIntsToArray(char* input, int nums[])
{
	// Get the first token (or number in this case)
	char* next_token = NULL;
	char* token = strtok_s(input, ",", &next_token);
	int countOfTokens = 0;
	if (token != NULL)
	{
		int temp = atoi(token);
		nums[countOfTokens++] = temp;
	}

	// Get the remaining numbers from the remainder of the string.
	// The null input tells the method to keep working with the original input
	// rather than a new string.
	while (token != NULL) {
		token = strtok_s(NULL, ", ", &next_token);
		if (token != NULL)
		{
			int temp = atoi(token);
			nums[countOfTokens++] = temp;
		}
	}
	return countOfTokens;
}

int ConvertDelimitedDoublesToArray(char* input, double nums[])
{
	// Get the first token (or number in this case)
	char* next_token = NULL;
	char* token = strtok_s(input, ",", &next_token);
	int countOfTokens = 0;
	if (token != NULL)
	{
		double temp = atof(token);
		nums[countOfTokens++] = temp;
	}

	// Get the remaining numbers from the remainder of the string.
	// The null input tells the method to keep working with the original input
	// rather than a new string.
	while (token != NULL) {
		token = strtok_s(NULL, ", ", &next_token);
		if (token != NULL)
		{
			double temp = atof(token);
			nums[countOfTokens++] = temp;
		}
	}
	return countOfTokens;
}


std::vector<std::string> ConvertDelimitedStringsToArray(char* input)
{
	std::vector<string> delimitedTokens;
	// Get the first token (or number in this case)
	char* next_token = NULL;
	char* token = strtok_s(input, "\t",
		&next_token);
	if (token != NULL)
	{
		delimitedTokens.push_back(token);
	}

	// Get the remaining numbers from the remainder of the string.
	// The null input tells the method to keep working with the original input
	// rather than a new string.
	while (token != NULL) {
		token = strtok_s(NULL, "\t", &next_token);
		if (token != NULL)
		{
			delimitedTokens.push_back(token);
		}
	}
	return delimitedTokens;
}