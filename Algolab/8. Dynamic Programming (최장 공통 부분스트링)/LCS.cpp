#include <iostream>

#define MAX_LENGTH 101
#define MAX(a, b) ((a>b)? a: b)

using namespace std;

int L[MAX_LENGTH][MAX_LENGTH];

int LCS(string a, string b, int m, int n) {
	for(int i = 0; i <= m; i++)
		L[i][0] = 0;
	for(int i = 0; i <= n; i++)
		L[0][i] = 0;

	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(a[i-1] == b[j-1])
				L[i][j] = L[i-1][j-1] + 1;
			else
				L[i][j] = MAX(L[i][j-1], L[i-1][j]);
		}
	}

	return L[m][n];
}

int main() {
	int t;
	cin >> t;

	string a, b;
	for(int i = 0; i < t; i++) {
		cin >> a >> b;
	
		cout << LCS(a, b, a.length(), b.length()) << endl;

	}

	return 0;
}
