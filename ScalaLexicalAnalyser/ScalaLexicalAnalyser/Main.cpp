#pragma once

#include <unordered_set>
#include <iostream>
#include "inputReader.h"
#include "LexicalAnalyzer.h"

using namespace std;

const string KEYWORDS_FILE_NAME = "..\\keywords.txt";
const string INPUT_CODE_FILE_NAME = "..\\input_code.txt";

unordered_set<string> keywords;



	
	int main() {

		
		InputReader inputReader = InputReader();
		keywords = inputReader.readKeywords(KEYWORDS_FILE_NAME);
		string programCode = inputReader.readProgramCode(INPUT_CODE_FILE_NAME);
		LexicalAnalyzer lexicalAnalyzer = LexicalAnalyzer(keywords);
		lexicalAnalyzer.analyzeCode(programCode);

		
		
		
		cin.get();
		return 0;

	}

	void parseCode() {

	}



