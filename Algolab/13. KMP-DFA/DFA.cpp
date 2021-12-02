#include <iostream>
#include <cstring>

using namespace std;

#define MAX_SIZE 1000

int main() {
	int t;
	cin >> t;

	for(int _a = 0; _a < t; _a++) {
		int DFA[MAX_SIZE][MAX_SIZE] = {};
		int R = MAX_SIZE;

		char pattern[MAX_SIZE], text[MAX_SIZE];
		cin >> pattern >> text;
		
		// Construct DFA
		int pLength = strlen(pattern);
		DFA[pattern[0]][0] = 1;
		for(int X = 0, j = 1; j <= pLength; j++) {
			for(int c = 0; c < R; c++)
				DFA[c][j] = DFA[c][X];

			DFA[pattern[j]][j] = j+1;
			X = DFA[pattern[j]][X];
		}

		// Counting Non-state 0
		int cnt1 = 0;
		for(int x = 65; x <= 67; x++) {
			for(int y = 0; y <= strlen(pattern); y++) {
				if(DFA[x][y] != 0)
					cnt1++;
			}
		}
		
		// KMP
		int i, j, txtLength;
		txtLength = strlen(text);
		int cnt2 = 0;
		for(i = 0, j = 0; i <= txtLength; i++) {
			j = DFA[text[i]][j];
			if(j == pLength)
				cnt2++;
		}

		cout << cnt1 << " " << cnt2 << endl;
	}

	return 0;
}