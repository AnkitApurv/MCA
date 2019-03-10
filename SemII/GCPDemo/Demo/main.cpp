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

	compute::cpuCompute(a, b, c);
	io::writeArray(c, "cpu.json");
	//io::displaySum(a, b, c);

	compute::gpuCompute(a, b, c);
	io::writeArray(c, "gpu.json");
	//io::displaySum(a, b, c);

	delete a, b, c;
	char wait;
	cin >> wait;
	return 0;
}