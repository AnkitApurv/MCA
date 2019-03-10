#include <cstdlib>	//rand()
#include <iostream>	//cout
#include <fstream>
using namespace std;

int main(void) {
	const int k = 10000;
	int a[k], b[k], i, g[k], h[k];

	for (i = 0; i < k; i++) {
		a[i] = rand() % 1000;	//random number between 0 to 999
		b[i] = rand() % 1000;
	}
	ofstream fa("a.json", ios::binary | ios::out | ios::trunc);
	fa.seekp(ios::beg);
	fa.write((char*)&a, sizeof(a));
	fa.close();

	ofstream fb("b.json", ios::binary | ios::out | ios::trunc);
	fb.seekp(ios::beg);
	fb.write((char*)&b, sizeof(b));
	fb.close();

	ifstream fg("a.json", ios::binary | ios::in);
	fg.seekg(ios::beg);
	fg.read((char*)&g, sizeof(g));
	fg.close();

	ifstream fh("b.json", ios::binary | ios::in);
	fh.seekg(ios::beg);
	fh.read((char*)&h, sizeof(h));
	fh.close();
	/*
	cout << "\n\n\n" << "a,g" <<"\n";
	for (i = 0; i < k; i++)
		cout << a[i] << "\t" << g[i] << "\n";
	cout << "\n\n\n" << "b,h" << "\n";
	for (i = 0; i < k; i++)
		cout << b[i] << "\t" << h[i] << "\n";*/
	bool success = true;
	for (i = 0; i < k; i++)
		if (a[i] != g[i] || b[i] != h[i])
			success = false;
	cout << success;
	char wait;
	cin >> wait;
	return 0;
}