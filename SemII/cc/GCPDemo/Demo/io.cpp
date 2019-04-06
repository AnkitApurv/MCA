#include <iostream>	//cout
#include <fstream>	//readArray(), writeArray()
#include <string>	//string
#include <iomanip>	//setprecision()
#include <chrono>	//getComputeTime()
#include "io.h"		//impl

using namespace std;
namespace io {
	void createInput(int* a, int* b) {
		for (int i = 0; i < arraySize; i++) {
			a[i] = rand() % 1000;	//random number between 0 to 999
			b[i] = rand() % 1000;
		}
		return;
	}
	void writeOps(std::string fileName, int a[], int b[], int c[], std::string ops) {
		ofstream w(fileName, ios::out | ios::trunc);
		w << "index" << "\t\t" << "a[]" << "\t" << ops << "\t" << "b[]" << "\t" << "=" << "\t" << "c[]" << "\n";
		for(int i = 0; i < arraySize; i++)
			w << (i+1) << "\t\t" << a[i] << "\t" << "\t\t" << "\t" << b[i] << "\t" << "=" << "\t" << c[i] << "\n";
		w << "\n" << endl;
		w.close();
		return;
	}

	double getComputeTime(std::chrono::steady_clock::time_point beginExecution, std::chrono::steady_clock::time_point endExecution) {
		//https://www.geeksforgeeks.org/measure-execution-time-with-high-precision-in-c-c/
		long long t = chrono::duration_cast<chrono::nanoseconds>(endExecution - beginExecution).count();
		double timeTaken = t * 1e-9; //to seconds, 10^9 nanoseconds = 1 second.
		return timeTaken;
	}
}