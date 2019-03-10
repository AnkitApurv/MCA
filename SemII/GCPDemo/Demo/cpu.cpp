#include <iostream> //cin, cout
#include <iomanip>	//setprecision()
#include <chrono>	//timer

#include "cpu.h"
#include "io.h"

using namespace std;

namespace compute {
	void cpuCompute(int a[], int b[], int c[]) {
		//vector addition
		auto beginExecution = chrono::high_resolution_clock::now();
		for (int i = 0; i < io::arraySize; i++)
			c[i] = a[i] + b[i];
		auto endExecution = chrono::high_resolution_clock::now();

		//https://www.geeksforgeeks.org/measure-execution-time-with-high-precision-in-c-c/
		double timeTaken = chrono::duration_cast<chrono::nanoseconds>(endExecution - beginExecution).count();
		timeTaken *= 1e-9; //to seconds, 10^9 nanoseconds = 1 second.
		cout << "CPU Compute time (seconds) : " << fixed << timeTaken << setprecision(9) << endl;

		return;
	}
}