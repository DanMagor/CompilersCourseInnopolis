#pragma once
#include <unordered_set>
#include <unordered_map>
#include<string>
#include <iostream>

class LexicalAnalyzer
{
public:
	

	std::string analyzeCode();
	std::string analyzeCode(std::string _codeText, char _currentChar, int _index);
	std::unordered_set<std::string> keywords;
	std::unordered_set<std::string> specialSymbols;
	std::unordered_map<std::string, std::string> operatorsMap;
	std::unordered_map<std::string, std::string> delimetersMap;
	std::string _codeText;

	LexicalAnalyzer(std::string codeText, std::unordered_set<std::string> keywords= {}, 
		std::unordered_set<std::string>specialSymbols = {},
		std::unordered_map<std::string, std::string> operatorsMap= {},
		std::unordered_map<std::string, std::string> delimetersMap = {});
	~LexicalAnalyzer();
private:
	
	bool isOperator();
	bool isOperator(std::unordered_map<std::string,std::string> operatorsMap, char _currentChar);
	bool isComment();
	bool isComment(std::string _codeText, int _index);
	bool isIdentifyer();
	bool isIdentifyer(std::string _codeText, char _currentChar, int _index);
	bool isNumber();
	bool isNumber(std::string _codeText, char _currentChar, int _index);
	bool isDelimeter();
	bool isDelimeter(std::unordered_map<std::string,std::string> delimetersMap, char _currentChar);
	bool isQuotes();
	bool isQuotes(char _currentChar);

	std::string parseComment();
	std::string parseComment(std::string _codeText, char _currentChar, int _index);
	std::string parseOperator();
	std::string parseOperator(std::string _codeText, char _currentChar, int _index, 
		std::unordered_map <std::string, std::string> operatorsMap);
	std::string parseIdentifyer();
	std::string parseIdentifyer(std::string _codeText, char _currentChar, int _index,
		std::unordered_set<std::string> keywords);
	std::string parseNumber();
	std::string parseNumber(std::string _codeText, char _currentChar, int _index);
	std::string parseDelimeter();
	std::string parseDelimeter(std::string _codeText, char _currentChar, int _index,
		std::unordered_map<std::string, std::string> delimetersMap);
	std::string parseQuotes();
	std::string parseQuotes(std::string _codeText, char _currentChar, int _index);

	char _currentChar;
	unsigned int _index;
};

