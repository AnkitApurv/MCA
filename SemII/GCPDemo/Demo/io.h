#pragma once

#include <string>	//string

namespace io {
	const int arraySize = 10000;
	void readArray(int* arr, std::string fileName);
	void writeArray(int* arr, std::string fileName);
	void createInput(std::string fileA, std::string fileB);
	void displaySum(int a[], int b[], int c[]);
}