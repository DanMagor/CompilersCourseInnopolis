#pragma once


#include <unordered_set>
#include <unordered_map>
#include <string>

class InputReader 
{

public:
	std::unordered_set<std::string> readKeywords(std::string);
	std::unordered_set<std::string> readSpecialSymbols(std::string);
	std::unordered_map<std::string,std::string> readOperators(std::string);
	std::unordered_map<std::string, std::string> readDelimeters(std::string);
	std::string readProgramCode(std::string);
};



	




	
