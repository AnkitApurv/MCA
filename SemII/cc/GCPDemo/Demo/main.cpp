#include <iostream>	//cout
#include <string>	//string
#include <CL/cl.hpp>
#include <fstream>
#include "io.h"
#include "cpu.h"
#include "gpu.h"

using namespace std;

int main(void) {
	int* a = new int[io::arraySize];
	int* b = new int[io::arraySize];
	int* c = new int[io::arraySize];
	int* g = new int[io::arraySize];
	io::createInput(a, b);

	double cpuTimeTaken = compute::cpuCompute(a, b, c);
	double gpuTimeTaken = compute::gpuCompute(a, b, g);
	double timesFaster = cpuTimeTaken / gpuTimeTaken;
	cout << "GPU is " << timesFaster << " times faster than CPU\n";

	char saveResult;
	cout << "Write computations to file (Y/N) : ";
	cin >> saveResult;
	if (saveResult == 'Y' || saveResult == 'y') {
		io::writeOps("cpu.txt", a, b, c, "mas");
		io::writeOps("gpu.txt", a, b, g, "mas");
	}

	cout << "Write result to file (Y/N) : ";
	cin >> saveResult;
	if (saveResult == 'Y' || saveResult == 'y') {
		ofstream w("DemoResult.txt", ios::out | ios::trunc);
		w << "CPU Compute time(seconds) : " << cpuTimeTaken << endl;
		w << "GPU Compute time(seconds) : " << gpuTimeTaken << endl;
		w << "GPU is " << timesFaster << " times faster than CPU\n";
		w.close();
	}

	delete a, b, c, g;
	char wait;
	cout << "\nExit...";
	cin >> wait;
	return 0;
}