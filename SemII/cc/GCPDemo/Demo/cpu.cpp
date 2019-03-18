#include <iostream> //cin, cout
#include <iomanip>	//setprecision()
#include <chrono>	//timer

#include "cpu.h"
#include "io.h"

using namespace std;

namespace compute {
#pragma optimize( "", off )
	double cpuCompute(int a[], int b[], int c[]) {
		//vector addition
		std::chrono::steady_clock::time_point beginExecution = chrono::high_resolution_clock::now();
		for (int i = 0; i < io::arraySize; i++)
			c[i] = a[i] + b[i];
		std::chrono::steady_clock::time_point endExecution = chrono::high_resolution_clock::now();
		std::cout << "CPU ";
		double timeTaken = io::getComputeTime(beginExecution, endExecution);
		return timeTaken;
	}
#pragma optimize( "", on )
}