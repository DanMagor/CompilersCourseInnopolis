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

std::unordered_set<std::string> InputReader::readSpecialSymbols(std::string fileName)
{
	std::ifstream fileStream;
	std::string temp_specialSymbol;
	std::unordered_set<std::string> specialSymbolsSet;

	fileStream.open(fileName);

	while (std::getline(fileStream, temp_specialSymbol))
	{
		specialSymbolsSet.insert(temp_specialSymbol);
	}

	return specialSymbolsSet;
}

std::unordered_map<std::string, std::string> InputReader::readOperators(std::string fileName)
{
	std::ifstream fileStream;
	std::unordered_map<std::string,std::string> operatorsMap;

	fileStream.open(fileName);
	std::string temp;
	while (fileStream>>temp)
	{	
		std::string key = temp;
		fileStream >> temp;
		std::string value = temp;
		operatorsMap.insert(std::pair<std::string,std::string>(key,value));
	}

	return operatorsMap;
}

std::unordered_map<std::string, std::string> InputReader::readDelimeters(std::string fileName)
{
	std::ifstream fileStream;
	std::unordered_map<std::string, std::string> delimetersMap;

	fileStream.open(fileName);
	std::string temp;
	while (fileStream >> temp)
	{
		std::string key = temp;
		fileStream >> temp;
		std::string value = temp;
		delimetersMap.insert(std::pair<std::string, std::string>(key, value));
	}

	return delimetersMap;
}

std::string InputReader::readProgramCode(std::string fileName)
{
	std::ifstream fileStream;
	fileStream.open(fileName);
	return std::string((std::istreambuf_iterator<char>(fileStream)), (std::istreambuf_iterator<char>()));
	
	
}
