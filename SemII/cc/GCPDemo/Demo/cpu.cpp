#include <chrono>	//timer
#include "cpu.h"	//impl
#include "io.h"		//getComputeTime()

using namespace std;

namespace compute {
//#pragma optimize( "", off )
	double cpuCompute(int a[], int b[], int c[]) {
		//vector addition
		std::chrono::steady_clock::time_point beginExecution = chrono::high_resolution_clock::now();
		for (int globalIndex = 0; globalIndex < io::arraySize; globalIndex++) {
			c[globalIndex] = a[globalIndex] * b[globalIndex];
			c[globalIndex] += a[globalIndex] + b[globalIndex];
			c[globalIndex] += a[globalIndex] - b[globalIndex];
			//c[globalIndex] = c[globalIndex] % b[globalIndex];
		}
		std::chrono::steady_clock::time_point endExecution = chrono::high_resolution_clock::now();
		double timeTaken = io::getComputeTime(beginExecution, endExecution);
		return timeTaken;
	}
//#pragma optimize( "", on )
}