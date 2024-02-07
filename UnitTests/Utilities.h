#pragma once
#include <string>
#include <vector>

std::vector<std::string> GetDataFile(std::string);
const int BUFSIZE = 256 * 4;


int ConvertDelimitedIntsToArray(char* input, int nums[]);
int ConvertDelimitedDoublesToArray(char* input, double nums[]);
std::vector<std::string> ConvertDelimitedStringsToArray(char* input);
int getTestArray(std::vector<std::string>, int, int[]);
int getTestArrayDoubles(std::vector<std::string>, int, double[]);
int getNamesInArray(std::vector<std::string>, int, char[20][64]);
std::vector<std::string> getNamesAsVector(std::vector<std::string> lines, int lineNumber);
