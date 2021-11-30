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
				mat[x][y] = INT_MAX;
		
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

		vector<pair<int, int>> F;

		int vnear = -1;
		int nearest[n+1] = {-1};
		int distance[n+1] = {-1};
		for(int j = 2; j <= n; j++) {
			nearest[j] = 1;
			distance[j] = mat[1][j];
		}

		for(int j = 0; j < n-1; j++) {
			int min = INT_MAX;
			for(int k = 2; k <= n; k++) {
				if(distance[k] >= 0 && distance[k] < min) {
					min = distance[k];
					vnear = k;
				}
			}
			
			pair<int, int> p;
			p.first = vnear;
			p.second = nearest[vnear];
			F.push_back(p);

			distance[vnear] = -1;
		
			for(int k = 2; k <= n; k++) {
				if(mat[k][vnear] < distance[k]) {
					distance[k] = mat[k][vnear];
					nearest[k] = vnear;
				}
			}
		}

		int result = 0;
		for(int j = 0; j < F.size(); j++)
			result += mat[F[j].first][F[j].second];

		cout << result << endl;
	}

	return 0;
}
