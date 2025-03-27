#include <iostream>
#include <set>
template<typename T>
inline T qrt(T number) {
	return number * number;
}

template<typename T>
void calculate(void) {
	T number;
	std::cin >> number;
	std::set<T> arr;
	for (T i = 0; i < number; i++)
		for (T j = 0; j < number; j++)
			arr.insert(qrt(i) + qrt(j));

	auto itSetEnd = arr.end();
	for (auto itSet = arr.begin(); itSet != itSetEnd; itSet++)
		std::cout << *itSet << ' ';
	std::cout << std::endl;
}

int main()
{
	calculate<unsigned short int>();
}