#include <iostream>
#include <sstream>
#include <string>

bool isVowel(char symbol) {
	switch (symbol) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'y':
			return true;
		default:
			return false;
	}
}

bool balanceVowelAndConsonant( \
		std::string str \
) {
	long balance = 0L;
	for (char ch : str)
		balance += isVowel(ch) ? 1L : -1L;
	return balance == 0;
}

int main() {
	std::string str;
	std::getline(std::cin, str);
	for (std::stringstream sstr(str); !sstr.eof();) {
		sstr >> str;
		if (balanceVowelAndConsonant(str)) std::cout << str << ' ';
	}
	std::cout << std::endl;
	return 0;
}
