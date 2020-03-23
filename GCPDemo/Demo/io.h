#pragma once

#include <chrono>
#include <string>	//string

namespace io {
	const int workGroupSize = 64;
	const int arraySize = workGroupSize * 1000000;
	/*void readArray(int* arr, std::string fileName);
	void writeArray(int* arr, std::string fileName);
	void createInput(std::string fileA, std::string fileB);
	*/
	void createInput(int* a, int* b);
	void writeOps(std::string fileName, int a[], int b[], int c[], std::string ops);
	double getComputeTime(std::chrono::steady_clock::time_point beginExecution, std::chrono::steady_clock::time_point endExecution);
}