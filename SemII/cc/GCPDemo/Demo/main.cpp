#include <iostream>	//cout, cin
#include <iomanip> //setprecision()
#include <fstream>//writeResult
#include <chrono> //std::chrono::steady_clock::time_point
#include "io.h" //createInput(), writeOps()
#include "cpu.h" //cpuCompute()
#include "gpu.h" //gpuCompute()

using namespace std;

int main(void) {
	int* a = new int[io::arraySize];
	int* b = new int[io::arraySize];
	int* c = new int[io::arraySize];
	int* g = new int[io::arraySize];
	cout << "Generating random inputs.....\n";
	io::createInput(a, b);
	cout << "Inputs generated! Two vectors with " << io::arraySize << " elements.\n\n";
	string ops = "((*) + (+)) + (-)";

	cout << "Beginning compute tests...\nResult, third vector from operation " << ops << "\n\n";
	double cpuTimeTaken = compute::cpuCompute(a, b, c);
	std::chrono::steady_clock::time_point beginExecution = std::chrono::high_resolution_clock::now();
	double gpuTimeTaken = compute::gpuCompute(a, b, g);
	std::chrono::steady_clock::time_point endExecution = std::chrono::high_resolution_clock::now();
	double timesFaster = cpuTimeTaken / gpuTimeTaken;
	double gpuTotalTimeTaken = io::getComputeTime(beginExecution, endExecution);
	cout << "CPU Compute time (seconds) : " << fixed << cpuTimeTaken << setprecision(9) << endl;
	cout << "GPU Compute time (seconds) : " << fixed << gpuTimeTaken << setprecision(9) << endl;
	cout << "GPU Total time (copy to memory, build, run, copy from memory) (seconds) : " << fixed << gpuTotalTimeTaken << setprecision(9) << endl;
	cout << "GPU is " << timesFaster << " times faster than CPU\n";

	char saveResult;
	cout << "\nWrite computations to file (Y/N) : ";
	cin >> saveResult;
	if (saveResult == 'Y' || saveResult == 'y') {
		io::writeOps("cpu.txt", a, b, c, ops);
		io::writeOps("gpu.txt", a, b, g, ops);
	}

	cout << "Write result to file (Y/N) : ";
	cin >> saveResult;
	if (saveResult == 'Y' || saveResult == 'y') {
		ofstream w("DemoResult.txt", ios::out | ios::trunc);
		w << "CPU Compute time(seconds) : " << cpuTimeTaken << endl;
		w << "GPU Compute time(seconds) : " << gpuTimeTaken << endl;
		w << "GPU Total time (copy to memory, build, run, copy from memory) (seconds) : " << fixed << gpuTotalTimeTaken << setprecision(9) << endl;
		w << "GPU is " << timesFaster << " times faster than CPU\n";
		w.close();
	}

	delete a, b, c, g;
	char wait;
	cout << "\nExit(enter any character)...";
	cin >> wait;
	return 0;
}