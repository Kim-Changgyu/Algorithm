#include <iostream>
#include <climits>

using namespace std;

int minMatrixMult(int n, int d[]) {
	int M[n+1][n+1];
	
	for(int i = 1; i <= n; i++)
		M[i][i] = 0;

	int j, min;
	for(int diagonal = 1; diagonal < n; diagonal++) {
		for(int i = 1; i <= n-diagonal; i++) {
			j = i + diagonal;
			min = INT_MAX;

			for(int k = i; k < j; k++) {
				int cnt = M[i][k]+M[k+1][j] + (d[i-1]*d[k]*d[j]);
				if(cnt < min)
					min = cnt;
			}

			M[i][j] = min;
		}
	}

	return M[1][n];
}

int main() {
	int t;
	cin >> t;

	for(int i = 0; i < t; i++) {
		int n;
		cin >> n;

		int* d = new int[n+1];
		for(int i = 0; i <= n; i++)
			cin >> d[i];

		cout << minMatrixMult(n, d) << endl;

		delete d;
	}

	return 0;
}
