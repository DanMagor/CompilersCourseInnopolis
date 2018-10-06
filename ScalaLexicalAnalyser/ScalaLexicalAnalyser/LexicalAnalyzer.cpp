#include "LexicalAnalyzer.h"







std::string LexicalAnalyzer::analyzeCode()
{

	_index = 0;
	std::string buffer;
	std::string resultString;
	_currentChar = _codeText[_index];


	while (_currentChar != '\0') {
		if (_currentChar != ' ') {
			if (_currentChar == '/') {
				if (isComment())
				{
					resultString += parseComment() + "\n";
				}
				else
				{
					std::cout << "else" << std::endl;
					resultString += parseOperator() + "\n";
				}
			}
			else if (isOperator()) {
				resultString += parseOperator() + "\n";
			}
			else if (isIdentifyer()) {
				resultString += parseIdentifyer() + "\n";
			}
			else if (isNumber()) {
				resultString += parseNumber() + "\n";
			}
			else if (isDelimeter()) {
				resultString += parseDelimeter() + "\n";
			}
			else if (isQuotes()) {
				resultString += parseQuotes() + "\n";
			}
			else
			{
				resultString += _currentChar;
				resultString += " : Invalid Token\n";
				_index++;
			}

		}

		if (_codeText[_index] == '\n' || _codeText[_index] == ' ')
		{
			_index++;
		}
		_currentChar = _codeText[_index];
	}
		return resultString;

}



std::string LexicalAnalyzer::analyzeCode(std::string _codeText, char _currentChar, int _index)
{
	_index = 0;
	std::string buffer;
	std::string resultString;
	_currentChar = _codeText[_index];


	while (_currentChar != '\0') {
		if (_currentChar != ' ') {
			if (_currentChar == '/') {
				if (isComment())
				{
					resultString += parseComment() + "\n";
				}
				else
				{
					std::cout << "else" << std::endl;
					resultString += parseOperator() + "\n";
				}
			}
			else if (isOperator()) {
				resultString += parseOperator() + "\n";
			}
			else if (isIdentifyer()) {
				resultString += parseIdentifyer() + "\n";
			}
			else if (isNumber()) {
				resultString += parseNumber() + "\n";
			}
			else if (isDelimeter()) {
				resultString += parseDelimeter() + "\n";
			}
			else if (isQuotes()) {
				resultString += parseQuotes() + "\n";
			}
			else
			{
				resultString += _currentChar;
				resultString += " : Invalid Token\n";
				_index++;
			}

		}

		if (_codeText[_index] == '\n' || _codeText[_index] == ' ')
		{
			_index++;
		}
		_currentChar = _codeText[_index];
	}
	return resultString;

}




	

	LexicalAnalyzer::LexicalAnalyzer(std::string codeText,
	std::unordered_set<std::string> keywords, std::unordered_set<std::string> specialSymbols,
	std::unordered_map<std::string, std::string> operatorsMap,
	std::unordered_map<std::string, std::string> delimetersMap)
{
	LexicalAnalyzer::delimetersMap = delimetersMap;
	LexicalAnalyzer::operatorsMap = operatorsMap;
	LexicalAnalyzer::_codeText = codeText;
	LexicalAnalyzer::keywords = keywords;
	LexicalAnalyzer::specialSymbols = specialSymbols;
}

LexicalAnalyzer::~LexicalAnalyzer()
{
}

bool LexicalAnalyzer::isOperator()
{
	std::string buffer(1, _currentChar);
	if (operatorsMap.find(buffer)==operatorsMap.end())
		return false;
	return true;
}

bool LexicalAnalyzer::isOperator(std::unordered_map<std::string, std::string>, char _currentChar)
{
	std::string buffer(1, _currentChar);
	if (operatorsMap.find(buffer) == operatorsMap.end())
		return false;
	return true;
}


bool LexicalAnalyzer::isComment()
{
	
	if (_index + 1 < _codeText.length() && _codeText[_index + 1] == '/') {
		return true;
	}
	else if (_index + 1 < _codeText.length() && _codeText[_index + 1] == '*') {
		return true;
	}
	else
		return false;
}

bool LexicalAnalyzer::isComment(std::string _codeText, int _index)
{
	if (_index + 1 < _codeText.length() && _codeText[_index + 1] == '/') {
		return true;
	}
	else if (_index + 1 < _codeText.length() && _codeText[_index + 1] == '*') {
		return true;
	}
	else
		return false;
}

bool LexicalAnalyzer::isIdentifyer()
{

	_currentChar = _codeText[_index];
	if (_currentChar == '_' || isalpha(_currentChar)) {
		return true;
	}
	return false;
}

bool LexicalAnalyzer::isIdentifyer(std::string _codeText, char _currentChar, int _index)
{

	_currentChar = _codeText[_index];
	if (_currentChar == '_' || isalpha(_currentChar)) {
		return true;
	}
	return false;
}

bool LexicalAnalyzer::isNumber()
{
	if (isalnum(_currentChar)) return true;
	if (_index + 1 < _codeText.length() && _currentChar == '.' && isalnum(_codeText[_index + 1]))
		return true;
	return false;
}

bool LexicalAnalyzer::isNumber(std::string _codeText, char _currentChar, int _index)
{
	if (isalnum(_currentChar)) return true;
	if (_index + 1 < _codeText.length() && _currentChar == '.' && isalnum(_codeText[_index + 1]))
		return true;
	return false;
}

bool LexicalAnalyzer::isDelimeter()
{
	std::string buffer(1, _currentChar);
	if (delimetersMap.find(buffer) == delimetersMap.end())
		return false;
	return true;
}

bool LexicalAnalyzer::isDelimeter(std::unordered_map<std::string,std::string> delimetersMap, char _currentChar)
{
	std::string buffer(1, _currentChar);
	if (delimetersMap.find(buffer) == delimetersMap.end())
		return false;
	return true;
}

bool LexicalAnalyzer::isQuotes()
{
	if (_currentChar == '"' || _currentChar == '\'')
		return true;
	return false;
}

bool LexicalAnalyzer::isQuotes(char _currentChar)
{
	if (_currentChar == '"' || _currentChar == '\'')
		return true;
	return false;
}

std::string LexicalAnalyzer::parseComment()
{

	std::string buffer = "";
	_currentChar = _codeText[_index];

	if (_index + 1 < _codeText.length() && _codeText[_index + 1] == '/') {
		buffer = "/";
		_index++;
		_currentChar = _codeText[_index];
		while (_currentChar != '\n') {
			buffer += _currentChar;
			_index++;
			_currentChar = _codeText[_index];
		}
		_index++;
	}
	else if (_index + 1 < _codeText.length() && _codeText[_index + 1] == '*') {
		buffer = "/";
		_index++;
		_currentChar = _codeText[_index];
		while (_index + 1 < _codeText.length() && !(_currentChar == '*' && _codeText[_index + 1] == '/')) {
			buffer += _currentChar;
			_index++;
			_currentChar = _codeText[_index];
		}
		buffer += _currentChar;
		_index++;
		buffer += _codeText[_index];
		_index++;

	}

	buffer += " : Comment Tokken";

	return buffer;
}

std::string LexicalAnalyzer::parseComment(std::string _codeText, char _currentChar, int _index)
{
	std::string buffer = "";
	_currentChar = _codeText[_index];

	if (_index + 1 < _codeText.length() && _codeText[_index + 1] == '/') {
		buffer = "/";
		_index++;
		_currentChar = _codeText[_index];
		while (_currentChar != '\n') {
			buffer += _currentChar;
			_index++;
			_currentChar = _codeText[_index];
		}
		_index++;
	}
	else if (_index + 1 < _codeText.length() && _codeText[_index + 1] == '*') {
		buffer = "/";
		_index++;
		_currentChar = _codeText[_index];
		while (_index + 1 < _codeText.length() && !(_currentChar == '*' && _codeText[_index + 1] == '/')) {
			buffer += _currentChar;
			_index++;
			_currentChar = _codeText[_index];
		}
		buffer += _currentChar;
		_index++;
		buffer += _codeText[_index];
		_index++;

	}

	buffer += " : Comment Tokken";

	return buffer;
}

std::string LexicalAnalyzer::parseOperator()
{
	std::string buffer;
	buffer += _currentChar;
	if (_index + 1 < _codeText.length() && (_codeText[_index+1] == ' ' 
		|| isalpha(_codeText[_index + 1]) || isdigit(_codeText[_index + 1])
		|| _codeText[_index+1]=='\n' || _codeText[_index+1]=='_'
		|| _codeText[_index + 1] == '\0'))
	{
		buffer += " : " + operatorsMap.at(buffer) + " Token";
		_index++;
	}
	else if(_index + 1 < _codeText.length())
	{
		_index++;
		buffer += _codeText[_index];
		if (operatorsMap.find(buffer) == operatorsMap.end())
		{
			while (_index + 1 < _codeText.length() && _codeText[_index] != ' ' && _codeText[_index] != '\n') {
				_index++;
				_currentChar = _codeText[_index];
				buffer += _currentChar;
				_index++;
				
			}
			buffer += ": Invalid Token";
		}
		else
		{
			buffer += " : " + operatorsMap.at(buffer)+" Token";
			_index++;
		}
	}
	else if (_currentChar = '/') {
		buffer += " : " + operatorsMap.at(buffer) + " Token";
		_index++;
	}
	return buffer;
}

std::string LexicalAnalyzer::parseOperator(std::string _codeText, char _currentChar, int _index,
	std::unordered_map <std::string, std::string> operatorsMap)
{
	std::string buffer;
	buffer += _currentChar;
	if (_index + 1 < _codeText.length() && (_codeText[_index + 1] == ' '
		|| isalpha(_codeText[_index + 1]) || isdigit(_codeText[_index + 1])
		|| _codeText[_index + 1] == '\n' || _codeText[_index + 1] == '_'
		|| _codeText[_index + 1] == '\0'))
	{
		buffer += " : " + operatorsMap.at(buffer) + " Token";
		_index++;
	}
	else if (_index + 1 < _codeText.length())
	{
		_index++;
		buffer += _codeText[_index];
		if (operatorsMap.find(buffer) == operatorsMap.end())
		{
			while (_index + 1 < _codeText.length() && _codeText[_index] != ' ' && _codeText[_index] != '\n') {
				_index++;
				_currentChar = _codeText[_index];
				buffer += _currentChar;
				_index++;

			}
			buffer += ": Invalid Token";
		}
		else
		{
			buffer += " : " + operatorsMap.at(buffer) + " Token";
			_index++;
		}
	}
	else if (_currentChar = '/') {
		buffer += " : " + operatorsMap.at(buffer) + " Token";
		_index++;
	}
	return buffer;
}

std::string LexicalAnalyzer::parseIdentifyer()
{
	std::string buffer;
	while (_index < _codeText.length() && (isalpha(_currentChar) || isalnum(_currentChar) || _currentChar == '_'))
	{
		_currentChar = _codeText[_index];
		buffer += _currentChar;
		_index++;
		if (_index < _codeText.length()) {
			_currentChar = _codeText[_index];
		}
	}
	if(keywords.find(buffer)==keywords.end())
	{
		buffer += ": Identifyer Token";
	}
	else
	{
		buffer += ": Keyword";
	}
	
	return buffer;
}

std::string LexicalAnalyzer::parseIdentifyer(std::string _codeText, char _currentChar, int _index, 
	std::unordered_set<std::string> keywords)
{
	std::string buffer;
	while (_index < _codeText.length() && (isalpha(_currentChar) || isalnum(_currentChar) || _currentChar == '_'))
	{
		_currentChar = _codeText[_index];
		buffer += _currentChar;
		_index++;
		if (_index < _codeText.length()) {
			_currentChar = _codeText[_index];
		}
	}
	if (keywords.find(buffer) == keywords.end())
	{
		buffer += ": Identifyer Token";
	}
	else
	{
		buffer += ": Keyword";
	}

	return buffer;
}

std::string LexicalAnalyzer::parseNumber()
{
	std::string buffer;
	if (_currentChar == '.') {
		buffer = _currentChar;
		_index++;
	}
	bool hasPoint = false;
	while (isalnum(_codeText[_index]) || (_codeText[_index]=='.' && !hasPoint)) 
	{
		if (_currentChar == '.') hasPoint = true;
		_currentChar = _codeText[_index];
		buffer += _currentChar;
		_index++;

	}
	buffer += ": Number Token";
	return buffer;
	
}

std::string LexicalAnalyzer::parseNumber(std::string _codeText, char _currentChar, int _index)
{
	std::string buffer;
	if (_currentChar == '.') {
		buffer = _currentChar;
		_index++;
	}
	bool hasPoint = false;
	while (isalnum(_codeText[_index]) || (_codeText[_index] == '.' && !hasPoint))
	{
		if (_currentChar == '.') hasPoint = true;
		_currentChar = _codeText[_index];
		buffer += _currentChar;
		_index++;

	}
	buffer += ": Number Token";
	return buffer;

}

std::string LexicalAnalyzer::parseDelimeter()
{
	std::string buffer(1, _currentChar);
	buffer+= " : " + delimetersMap.at(buffer) + " Delimeter Token";
	_index++;
	return buffer;
}

std::string LexicalAnalyzer::parseDelimeter(std::string _codeText, char _currentChar, int _index,
	std::unordered_map<std::string,std::string> delimetersMap)
{
	std::string buffer(1, _currentChar);
	buffer += " : " + delimetersMap.at(buffer) + " Delimeter Token";
	_index++;
	return buffer;
}

std::string LexicalAnalyzer::parseQuotes()
{
	std::string buffer;
	char quote = _currentChar;
	while (_index + 1 < _codeText.length() && _codeText[_index + 1] != quote)
	{
		_currentChar = _codeText[_index];
		buffer += _currentChar;
		_index++;
	}
	if (_index + 1 < _codeText.length() && _codeText[_index+1]==quote) 
	{
		_currentChar = _codeText[_index];
		buffer += _currentChar;
		_index++;
		_currentChar = _codeText[_index];
		buffer += _currentChar;
		buffer+= " :  Quote Token";
		_index++;
	}
	else 
	{
		buffer += _currentChar;
		buffer += " : Invalid Token";
		//_index++ should be
	}
	return buffer;
}

std::string LexicalAnalyzer::parseQuotes(std::string _codeText, char _currentChar, int _index)
{
	std::string buffer;
	char quote = _currentChar;
	while (_index + 1 < _codeText.length() && _codeText[_index + 1] != quote)
	{
		_currentChar = _codeText[_index];
		buffer += _currentChar;
		_index++;
	}
	if (_index + 1 < _codeText.length() && _codeText[_index + 1] == quote)
	{
		_currentChar = _codeText[_index];
		buffer += _currentChar;
		_index++;
		_currentChar = _codeText[_index];
		buffer += _currentChar;
		buffer += " :  Quote Token";
		_index++;
	}
	else
	{
		buffer += _currentChar;
		buffer += " : Invalid Token";
	}
	return buffer;
}



