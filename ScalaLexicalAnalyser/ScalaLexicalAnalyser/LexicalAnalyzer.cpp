#include "LexicalAnalyzer.h"






const char digits[] = { '1','2','3','4','5','6','7','8','9','0' };



void LexicalAnalyzer::analyzeCode(std::string codeText)
{
	
	int currentIndex = 0;
	char currentChar = codeText[currentIndex];
	std::string buffer;
	while(currentIndex < (int)codeText.length())
	{
		currentChar = codeText[currentIndex];
		if (isalpha(currentChar)) {
			buffer += currentChar;
		}
		else if (!buffer.empty()){
			if (keywords.find(buffer) != keywords.end()) {
				std::cout << buffer << ": is keyword\n";
			}
			buffer.clear();
		}
		currentIndex++;
		

	}
	
}

LexicalAnalyzer::LexicalAnalyzer(std::unordered_set<std::string> keywords)
{
	LexicalAnalyzer::keywords = keywords;
}

LexicalAnalyzer::~LexicalAnalyzer()
{
}


