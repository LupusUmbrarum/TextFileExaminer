#include"TextFileExaminer.h"

int TextFileExaminer::countWords(std::string file)
{
	int wordCount = 0, index = 0;

	std::ifstream fileStream;

	if (!openFile(file, fileStream))
	{
		return -1;
	}

	while (std::getline(fileStream, file))
	{
		while (file.length() > 0 && (index = file.find_first_of(" ")) != std::string::npos)
		{
			file = file.substr(index + 1);

			if (file.length() > 0)
			{
				wordCount++;
			}
		}

		wordCount++;
	}

	fileStream.close();

	return wordCount;
}

bool TextFileExaminer::containsString(std::string file, std::string str)
{
	std::ifstream fileStream;
	int index;

	if (!openFile(file, fileStream))
	{
		return false;
	}

	while (std::getline(fileStream, file))
	{
		if (file.find(str) != std::string::npos)
		{
			return true;
		}
	}

	fileStream.close();

	return false;
}

bool TextFileExaminer::containsChar(std::string file, char chr)
{
	return containsString(file, std::string(1, chr));
}

bool TextFileExaminer::openFile(std::string str, std::ifstream &fileStream)
{
	fileStream.open(str);
	
	if (!fileStream)
	{
		return false;
	}

	return true;
}