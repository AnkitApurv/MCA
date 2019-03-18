#include <iostream>	//cout
#include <fstream>	//readArray(), writeArray()
#include <string>	//string
#include <iomanip> //setprecision()
#include <ctime>
#include "io.h"

using namespace std;
namespace io {
	void readArray(int* arr, string fileName) {
		ifstream r(fileName, ios::binary | ios::in);
		r.seekg(ios::beg);
		r.read((char*)arr, io::arraySize * sizeof(int));
		r.close();
		return;
	}

	void writeArray(int* arr, string fileName) {
		ofstream w(fileName, ios::binary | ios::out | ios::trunc);
		w.seekp(ios::beg);
		w.write((char*)arr, io::arraySize * sizeof(int));
		w.close();
		return;
	}

	void createInput(string fileA, string fileB) {
		int a[arraySize], b[arraySize];
		for (int i = 0; i < arraySize; i++) {
			a[i] = rand() % 1000;	//random number between 0 to 999
			b[i] = rand() % 1000;
		}
		writeArray(a, fileA);
		writeArray(b, fileB);
		return;
	}

	void writeSum(std::string fileName, int a[], int b[], int c[]) {
		ofstream w(fileName, ios::out | ios::trunc);
		w << "index" << "\t\t" << "a[]" << "\t" << "+" << "\t" << "b[]" << "\t" << "=" << "\t" << "c[]" << "\n";
		for(int i = 0; i < arraySize; i++)
			w << (i+1) << "\t\t" << a[i] << "\t" << "+" << "\t" << b[i] << "\t" << "=" << "\t" << c[i] << "\n";
		w << "\n" << endl;
		return;
	}

	double getComputeTime(std::chrono::steady_clock::time_point beginExecution, std::chrono::steady_clock::time_point endExecution) {
		//https://www.geeksforgeeks.org/measure-execution-time-with-high-precision-in-c-c/
		double timeTaken = chrono::duration_cast<chrono::nanoseconds>(endExecution - beginExecution).count();;
		timeTaken *= 1e-9; //to seconds, 10^9 nanoseconds = 1 second.
		cout << "Compute time (seconds) : " << fixed << timeTaken << setprecision(9) << endl;
		return timeTaken;
	}
}