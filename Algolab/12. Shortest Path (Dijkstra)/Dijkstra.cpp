#include <iostream>
#include <climits>
#include <vector>
#include <utility>

using namespace std;

int main() {
	int t;
	cin >> t;

	for(int i = 0; i < t; i++) {
		int n;
		cin >> n;

		int mat[n+1][n+1];
		for(int x = 0; x <= n; x++)
			for(int y = 0; y <= n; y++)
				mat[x][y] = 10000;
		
		for(int j = 0; j < n; j++) {
			int k, m;
			cin >> k >> m;

			for(int l = 0; l < m; l++) {
				int v, w;
				cin >> v >> w;

				mat[k][v] = w;
			}
		}

		for(int j = 0; j <= n; j++)
			mat[j][j] = 0;

		int vnear;
		int touch[n+1];
		int length[n+1];
		for(int j = 0; j <= n; j++) {
			touch[j] = 1;
			length[j] = mat[1][j];
		}

		for(int j = 0; j < n-1; j++) {
			int min = 10000;
			for(int k = 2; k <= n; k++) {
				if(length[k] >= 0 && length[k] < min) {
					min = length[k];
					vnear = k;
				}
			}

			for(int k = 2; k <= n; k++) {
				if(length[vnear] + mat[vnear][k] < length[k]) {
					length[k] = length[vnear] + mat[vnear][k];
					touch[k] = vnear;
				}
			}
			
			length[vnear] *= -1;
		}

		for(int j = 1; j <= n; j++)
			length[j] *= -1;

		int result = 0;
		for(int j = 2; j <= n; j++) {
			result += length[j] - length[touch[j]];
		}
		cout << result << endl;
	}

	return 0;
}
