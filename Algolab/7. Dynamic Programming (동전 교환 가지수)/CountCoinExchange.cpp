#include <iostream>

using namespace std;

int countCoinExchange(int coins[], int numDiffCoins, int change) {
	// Room for k == n == 0 (Row+1, Column+1)
	int N[numDiffCoins+1][change+1] = {0};

	// Base Case (k == 0)
	for(int i = 0; i < numDiffCoins+1; i++)
		N[i][0] = 1;
	// Base Case (n == 0)
	for(int i = 1; i < change+1; i++)
		N[0][i] = 0;
	
	for(int i = 1; i <= numDiffCoins; i++) {
		for(int j = 1; j <= change; j++) {
			if(j-coins[i] < 0)
				N[i][j] = N[i-1][j];
			else
				N[i][j] = N[i-1][j] + N[i][j-coins[i]];
		}
	}

	return N[numDiffCoins][change];
}

int main() {
	int t;
	cin >> t;

	for(int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;

		int* coins = new int[m+1];
		for(int j = 1; j <= m; j++)
			cin >> coins[j];

		cout << countCoinExchange(coins, m, n) << endl;

		delete coins;
	}
	
	return 0;
}
