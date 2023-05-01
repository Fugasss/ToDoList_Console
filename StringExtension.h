#pragma once
#include <vector>
#include <algorithm> 
#include <cctype>
#include <locale>

using namespace std;

static inline void splitString(const string input, const int splitLength, const char rowSeparator, vector<string>* splitted)
{
	int len = input.length();
	const int splitLenWithSeparators = splitLength - 1;

	int rows = len / (splitLenWithSeparators);
	int lastRowLen = len % (splitLenWithSeparators);

	for (int i = 0; i <= rows; i++)
	{
		int substrLen = ( rows == i  ? lastRowLen : splitLenWithSeparators);
		
		splitted->push_back( input.substr(i * splitLenWithSeparators, substrLen) + rowSeparator);
	}
}



// trim from start (in place)
static inline void ltrim(std::string& s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
		return !std::isspace(ch);
		}));
}

// trim from end (in place)
static inline void rtrim(std::string& s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
		return !std::isspace(ch);
		}).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string& s) {
	rtrim(s);
	ltrim(s);
}