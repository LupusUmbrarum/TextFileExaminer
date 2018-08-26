#include "TextFileExaminer.h"

#define clearScreen system("CLS")
#define pause system("pause")

template<class T> void print(T t)
{
	std::cout << t;
}

template<class T> void println(T t)
{
	std::cout << t << std::endl;
}

void upperString(std::string &str)
{
	int count = 0;
	int strLen = str.length();

	while (count < strLen)
	{
		str[count] = toupper(str[count]);
		count++;
	}
}

void performAction(int val)
{
	switch (val)
	{
	case 1:
	{
		clearScreen;
		println("Enter the full path of the text file you want to examine");

		std::string path;
		std::cin >> path;

		int value = TextFileExaminer::countWords(path);

		if (value == -1)
		{
			println("Could not open file");
			break;
		}

		print("The file has ");
		print(value);
		println(" words in it.");

		break;
	}
	case 2:
	{
		clearScreen;
		println("Enter the full path of the text file you want to examine");

		std::string path;
		std::cin >> path;

		println("Enter the word or pattern you want to search for");

		std::string pattern;
		std::cin >> pattern;

		bool value = TextFileExaminer::containsString(path, pattern);

		if (!value)
		{
			println("Could not open file or file does not contain pattern");
			break;
		}

		println("The file contains the pattern");

		break;
	}
	case -1:
	{
		println("failed");
	}
	}
}

int safeStringToInteger(std::string str)
{
	int value = -1;
	try
	{
		value = std::stoi(str);
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << "Could not convert from string to integer" << std::endl;
	}
	return value;
}

int main()
{
	TextFileExaminer textf;
	std::string str;

	while (true)
	{
		std::cout << "Enter the number of the action you want to take\nor enter 'exit' to quit\n(1) Count words in file\n(2) See if file contains word" << std::endl;

		std::cin >> str;

		upperString(str);

		if (str == "EXIT")
		{
			break;
		}

		performAction(safeStringToInteger(str));

		pause;
		clearScreen;
	}

	return 0;
}