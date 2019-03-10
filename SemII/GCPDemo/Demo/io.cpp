#include <iostream>	//cout
#include <fstream>	//readArray(), writeArray()
#include <string>	//string

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

	void displaySum(int a[], int b[], int c[]) {
		cout << "a[]" << "\t" << "+" << "\t" << "b[]" << "\t" << "=" << "\t" << "c[]" << "\n";
		for(int i = 0; i < arraySize; i++)
			cout << a[i] << "\t" << "+" << "\t" << b[i] << "\t" << "=" << "\t" << c[i] << "\n";
		cout << "\n\n\n\n" << endl;
		return;
	}
}