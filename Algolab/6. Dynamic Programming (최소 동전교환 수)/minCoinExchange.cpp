#include <iostream>

using namespace std;

void coinExchange(int coins[], int numDiffCoins, int change, int coinsUsed[])
{
	int cents, j;

	// coinsUsed = C
	coinsUsed[0] = 0;

	// Bottom-Up
	for (cents = 1; cents <= change; cents++)
	{
		int minCoins;

		minCoins = cents;
		for (j = 0; j < numDiffCoins; j++)
		{
			if (coins[j] > cents)
				continue;
			if (coinsUsed[cents - coins[j]] + 1 < minCoins)
				minCoins = coinsUsed[cents - coins[j]] + 1;
		}

		coinsUsed[cents] = minCoins;
	}
}

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int change;
		cin >> change;

		int numDiffCoins;
		cin >> numDiffCoins;

		int *coins = new int[numDiffCoins];
		int *coinsUsed = new int[change + 1];
		for (int j = 0; j < numDiffCoins; j++)
			cin >> coins[j];

		coinExchange(coins, numDiffCoins, change, coinsUsed);
		cout << coinsUsed[change] << endl;

		delete coins;
		delete coinsUsed;
	}

	return 0;
}
