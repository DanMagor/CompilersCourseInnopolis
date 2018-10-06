#pragma once

#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include "inputReader.h"
#include "LexicalAnalyzer.h"
#include "Main.h"

using namespace std;

const string KEYWORDS_FILE_NAME = "..\\keywords.txt";
const string INPUT_CODE_FILE_NAME = "..\\input_code.txt";
const string SPECIAL_SYMBOL_FILE_NAME = "..\\special_symbols.txt";
const string OPERATORS_SYMBOL_FILE_NAME = "..\\operators.txt";
const string DELIMETERS_SYMBOL_FILE_NAME = "..\\delimeters.txt";
unordered_set<string> keywords, specialSymbols;
unordered_map<string, string> operatorsMap;
unordered_map<string, string> delimetersMap;


	
	int main() {


		
		InputReader inputReader = InputReader();
		keywords = inputReader.readKeywords(KEYWORDS_FILE_NAME);
		specialSymbols = inputReader.readSpecialSymbols(SPECIAL_SYMBOL_FILE_NAME);
		operatorsMap = inputReader.readOperators(OPERATORS_SYMBOL_FILE_NAME);
		delimetersMap = inputReader.readDelimeters(DELIMETERS_SYMBOL_FILE_NAME);

		string programCode = inputReader.readProgramCode(INPUT_CODE_FILE_NAME);
		LexicalAnalyzer lexicalAnalyzer = LexicalAnalyzer(programCode,keywords,
			specialSymbols,operatorsMap, delimetersMap);
		
		string result = lexicalAnalyzer.analyzeCode();
		ofstream outputfile("..\\output.txt");
		if (outputfile.is_open()) 
		{
			outputfile << result;
		}
		return 0;

	}




