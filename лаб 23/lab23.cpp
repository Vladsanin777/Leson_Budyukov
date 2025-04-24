#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <ctime>
using ushort = unsigned short;
const size_t countRows{ 10UL }, countCols{ 5UL };
template<typename T>
void action(void);
int main(void) {
	action<ushort>();
	action<float>();
	return 0;
}
template<typename T>
void action(void) {
	srand(time(0L));
	T numberC{(T)0}, numberX{(T)0};
	std::cout << "Input number C: ";
	std::cin >> numberC;
	std::cout << "Input number X: ";
	std::cin >> numberX;

	size_t* const rowsWithC{ new size_t[countRows] {0UL} };
	size_t* rowsWithCPtr{ rowsWithC };
	T**const matrix{ new T * [countRows] };
	T**const rowMatrixEnd{ matrix + countRows };
	T* colMatrixEnd{ 0UL };
	for (T** rowMatrix{ matrix };
		rowMatrix != rowMatrixEnd;
		rowMatrix++
		) {
		*rowMatrix = new T[countCols];
		colMatrixEnd = *rowMatrix + countCols;
		for (T* elementMatrix{ *rowMatrix };
			elementMatrix != colMatrixEnd;
			elementMatrix++
			) {
			*elementMatrix = rand() / (T)rand() ;
			if (*elementMatrix == numberC) {
				size_t temp{ (size_t)(rowMatrix-matrix) };
				//std::cout << temp << std::endl;
				if (rowsWithCPtr == rowsWithC \
					||*rowsWithCPtr != temp) {
					*(rowsWithCPtr++) = temp;
				}
			}
			std::cout << *elementMatrix << '\t';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	if (rowsWithCPtr == rowsWithC) {
		T nearestX{ matrix[0][0] }, \
			distinction{ (T)(std::max(nearestX, numberX) \
			- std::min(nearestX, numberX)) };

		for (T** rowMatrix{ matrix };
			rowMatrix != rowMatrixEnd;
			rowMatrix++
			) {
			T* elementMatrix{ *rowMatrix };
			T* const elementMatrixConst{ *rowMatrix };
			colMatrixEnd = elementMatrixConst + countCols;
			for (; elementMatrix != colMatrixEnd;
				elementMatrix++
				) {
				size_t tempDistinction{ 0 };
				if ((tempDistinction = (T)(std::max(*elementMatrix, numberX) - \
					std::min(*elementMatrix, numberX))) < \
					distinction) {
					distinction = tempDistinction;
					nearestX = *elementMatrix;
				}
			}
			delete[] elementMatrixConst;
		}
		std::cout << nearestX << std::endl;
		delete[] matrix;
		return;
	}
	size_t* rowsWithCEnd{ rowsWithCPtr };
	for (rowsWithCPtr = rowsWithC;
		rowsWithCPtr != rowsWithCEnd;
		rowsWithCPtr++) {
		for (T* rowsMatrix{ *(matrix + *rowsWithCPtr) }, \
			* rowsMatrixEnd{ rowsMatrix + countCols };
			rowsMatrix != rowsMatrixEnd; rowsMatrix++) {
			*rowsMatrix *= numberX;
		}
	}
	for (T** rowMatrix{ matrix };
		rowMatrix != rowMatrixEnd;
		rowMatrix++
		) {
		T* elementMatrix{ *rowMatrix };
		colMatrixEnd = elementMatrix + countCols;
		for (; elementMatrix != colMatrixEnd;
			elementMatrix++
			) std::cout << std::setprecision(4) << std::fixed << *elementMatrix << '\t';
		std::cout << std::endl;
		T* const elementMatrixConst{ *rowMatrix };
		delete[] elementMatrixConst;
	}
	delete[] matrix;
}