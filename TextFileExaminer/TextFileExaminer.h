#pragma once

#include<string>
#include<iostream>
#include<fstream>

class TextFileExaminer
{
public:
	static int countWords(std::string file);
	static bool containsString(std::string file, std::string str);
	static bool containsChar(std::string file, char chr);
private:
	static bool openFile(std::string str, std::ifstream &fileStream);
};