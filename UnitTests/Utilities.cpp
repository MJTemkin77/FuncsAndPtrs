#include "pch.h"
#include "Utilities.h"
#include <filesystem>
#include <fstream>
#include <iostream>

#include <stdlib.h>


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
