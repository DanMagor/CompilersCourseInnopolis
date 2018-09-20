#include "inputReader.h"
#include <fstream>


std::unordered_set<std::string> InputReader::readKeywords(std::string fileName)
{
	std::ifstream fileStream;
	std::string temp_keyword;
	std::unordered_set<std::string> keywordsSet;
	
	fileStream.open(fileName);
	
	while (std::getline(fileStream, temp_keyword)) 
	{
		keywordsSet.insert(temp_keyword);
	}

	return keywordsSet;	
}

std::string InputReader::readProgramCode(std::string fileName)
{
	std::ifstream fileStream;
	fileStream.open(fileName);
	return std::string((std::istreambuf_iterator<char>(fileStream)), (std::istreambuf_iterator<char>()));
	
	
}
