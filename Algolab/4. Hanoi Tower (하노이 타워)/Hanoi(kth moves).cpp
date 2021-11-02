#include <iostream>
#include <cmath>

using namespace std;

int diskCheck(int arr[], int n) {
	int i;
	for(i = 0; i < n; ++i) {
		if(arr[i] == 1)
			return i+1;
	}

	return n;
}

int main() {
	int t, n;
	unsigned long long int k;
	cin >> t;

	for(int i = 0; i < t; ++i) {
		cin >> n >> k;

		int arr[n];
		for(int j = n-1; j >= 0; --j)
			arr[j] = k >> j & 1;

		unsigned long long int kMoves = (k >> diskCheck(arr, n)) + 1;

		// 입력이 64 2^63인 경우 1 3으로 출력되지 않는 오류가 있음 (수정 예정)
		if(n%2 == 1) {
			if(diskCheck(arr, n) % 2 == 1) {
				if(kMoves%3 == 1)
					cout << "1 3" << endl;
				else if(kMoves%3 == 2)
					cout << "3 2" << endl;
				else if(kMoves%3 == 0)
					cout << "2 1" << endl;
			}
			else {
				if(kMoves%3 == 1)
					cout << "1 2" << endl;
				else if(kMoves%3 == 2)
					cout << "2 3" << endl;
				else if(kMoves%3 == 0)
					cout << "3 1" << endl;
			}
		}
		else {
			if(diskCheck(arr, n) % 2 == 1) {
				if(kMoves%3 == 1)
					cout << "1 2" << endl;
				else if(kMoves%3 == 2)
					cout << "2 3" << endl;
				else if(kMoves%3 == 0)
					cout << "3 1" << endl;
			}
			else {
				if(kMoves%3 == 1)
					cout << "1 3" << endl;
				else if(kMoves%3 == 2)
					cout << "3 2" << endl;
				else if(kMoves%3 == 0)
					cout << "2 1" << endl;
			}
		}
	}

	return 0;
}	
