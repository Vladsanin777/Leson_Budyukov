#include <iostream>

unsigned short N{ 30 };

int main() {
	srand(time(0L));
	short* arr{ new short[N] }, \
		* const arrEnd{ arr + N }, \
		count{ 0 }, countQuare{ 0 };
	for (short* arrPtr{ arr }; arrPtr != arrEnd; arrPtr++) {
		*arrPtr = rand() % 23 - 2;
		std::cout << *arrPtr << ' ';
		if (*arrPtr < 0) {
			if (count > 7)
				countQuare++;
			count = 0;
		}
		else count++;
	}
	delete[] arr;
	if (count > 7) countQuare++;
	std::cout << '\n' << countQuare << std::endl;
}