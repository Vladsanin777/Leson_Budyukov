#include <iostream>

bool isBalanced(const char * const str, const char * const end, int balance = 0) {
    if (*str == '(')
        balance++;
    else if (*str == ')') 
        balance--;
    if (balance < 0)
        return false;
    if (str > end)
        return balance == 0;
    else return isBalanced(str + 1, end, balance);
}

int main() {
	size_t count = 100;
	char* const str = new char[count] {0};
	std::cin.getline(str, 100);
	std::cout << isBalanced(str, str + count - 1) << std::endl;
	delete[] str;
}
