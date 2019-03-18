#pragma once

#include <chrono>
#include <string>	//string

namespace io {
	const int arraySize = 100000;
	void readArray(int* arr, std::string fileName);
	void writeArray(int* arr, std::string fileName);
	void createInput(std::string fileA, std::string fileB);
	void writeSum(std::string fileName, int a[], int b[], int c[]);
	double getComputeTime(std::chrono::steady_clock::time_point beginExecution, std::chrono::steady_clock::time_point endExecution);
}