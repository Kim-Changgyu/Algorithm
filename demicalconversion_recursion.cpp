#include <iostream>
#include <string>

using namespace std;

static string baseTable = "0123456789abcdef";

void baseconversion(int n, int base) {
	if (n >= base)
		baseconversion(n/base, base);

	cout << baseTable[n%base];
}

int main() {
	int n, base;
	cin >> n >> base;

	baseconversion(n, base);
}
