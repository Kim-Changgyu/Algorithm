#include <iostream>

using namespace std;

void Hanoi(int n, int a, int b, int c) {
	if (n > 0) {
		Hanoi(n-1, a, c, b);
		cout << "Move disk from " << a << " to " << c << endl;
		Hanoi(n-1, b, a, c);
	}
}

int main() {
	int numDisks;
	cin >> numDisks;

	Hanoi(numDisks, 1, 2, 3);
}
