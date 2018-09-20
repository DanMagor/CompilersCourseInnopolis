#pragma once
#include <unordered_set>
#include<string>
#include <iostream>

class LexicalAnalyzer
{
public:
	

	void analyzeCode(std::string);
	std::unordered_set<std::string> keywords;

	LexicalAnalyzer(std::unordered_set<std::string> = {});
	~LexicalAnalyzer();
};

