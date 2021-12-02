#include <iostream>
#include <vector>

using namespace std;

vector<int> getFail(string pattern) {
	int m = (int)pattern.size();
	int j = 0;
	vector<int> fail(m, 0);

	for(int i = 1; i < m; i++) {
		while(j > 0 && pattern[i] != pattern[j])
			j = fail[j-1];

		if(pattern[i] == pattern[j])
			fail[i] = ++j;
	}
	
	return fail;
}

vector<int> kmp(string text, string pattern) {
	vector<int> ans;
	vector<int> fail = getFail(pattern);
	int n = (int)text.size();
	int m = (int)pattern.size();

	int j = 0;
	for(int i = 0; i < n; i++) {
		while(j > 0 && text[i] != pattern[j])
			j = fail[j-1];
		
		if(text[i] == pattern[j]) {
			if(j == m-1) {
				ans.push_back(i-j);
				j = fail[j];
			}
			else
				j++;
		}
	}

	return ans;
}

int main() {
	int t;
	cin >> t;

	for(int i = 0; i < t; i++) {
		string pattern, text;
		cin >> pattern >> text;

		vector<int> fail = getFail(pattern);
		for(int j = 0; j < fail.size(); j++)
			cout << fail[j] << " ";
		cout << endl;

		vector<int> ans = kmp(text, pattern);
		cout << ans.size() << endl;
	}

	return 0;
}
