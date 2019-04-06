#pragma once

#include <chrono>	//std::chrono::steady_clock::time_point
#include <string>	//string

namespace io {
	const int workGroupSize = 64;
	const int arraySize = workGroupSize * 1000000;

	void createInput(int* a, int* b);
	void writeOps(std::string fileName, int a[], int b[], int c[], std::string ops);
	double getComputeTime(std::chrono::steady_clock::time_point beginExecution, std::chrono::steady_clock::time_point endExecution);
}