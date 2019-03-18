#include <iostream>	//cout
#include <string>	//string

#include "io.h"
#include "cpu.h"
#include "gpu.h"

using namespace std;

int main(void) {
	io::createInput("a.json", "b.json");
	int* a = new int[io::arraySize];
	int* b = new int[io::arraySize];
	int* c = new int[io::arraySize];
	io::readArray(a, "a.json");
	io::readArray(b, "b.json");

	double cpuTimeTaken = compute::cpuCompute(a, b, c);
	io::writeArray(c, "cpu.json");
	io::writeSum("cpu.txt", a, b, c);

	double gpuTimeTaken = compute::gpuCompute(a, b, c);
	io::writeArray(c, "gpu.json");
	io::writeSum("gpu.txt", a, b, c);

	double timesFaster = cpuTimeTaken / gpuTimeTaken;
	cout << "GPU is " << timesFaster << " times faster than CPU\n";

	delete a, b, c;
	char wait;
	cin >> wait;
	return 0;
}