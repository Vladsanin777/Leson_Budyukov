#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>

char ifMoreTwoSameSymbols(std::string str) {
	unsigned char index = str.length();
	char symbols[26] = { 0 };
	while (--index != 255)
		symbols[tolower(str[index]) - 'a']++;
	index = 26;
	while (--index != 255)
		if (symbols[index] > 2)
			return 0;
	return 1;
}
int main()
{
	std::string s;
	std::getline(std::cin, s);
	std::stringstream streamWord(s);
	std::string word, ans = "";

	while (streamWord >> word)
		if (ifMoreTwoSameSymbols(word))
			ans += word + " ";


	std::cout << ans;
}