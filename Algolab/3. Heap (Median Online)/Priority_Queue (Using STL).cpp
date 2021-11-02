#include <iostream>
#include <functional>
#include <ctime>
#include <queue>

using namespace std;

int main() {
	int t, n, m;
	cin >> t;

	for(int i = 0; i < t; i++) {
		cin >> n;

		int median = 0;
		priority_queue<int, vector<int>, less<int>> MaxHeap;
		priority_queue<int, vector<int>, greater<int>> MinHeap;
		for(int j = 0; j < n; j++) {
			cin >> m;

			if(MaxHeap.size() == 0 && MinHeap.size() == 0)
				MinHeap.push(m);
			else if(MaxHeap.size() == MinHeap.size()) {
				if(m >= MinHeap.top())
					MinHeap.push(m);
				else if(m < MinHeap.top())
					MaxHeap.push(m);
			}
			else if(MaxHeap.size() < MinHeap.size()) {
				if(m >= MinHeap.top()) {
					int x = MinHeap.top();
					MinHeap.pop();
					MaxHeap.push(x);
					MinHeap.push(m);
				}
				else if(m <= MinHeap.top())
					MaxHeap.push(m);
			}
			else if(MaxHeap.size() > MinHeap.size()) {
				if(m >= MaxHeap.top())
					MinHeap.push(m);
				else if(m <= MaxHeap.top()) {
					int x = MaxHeap.top();
					MaxHeap.pop();
					MinHeap.push(x);
					MaxHeap.push(m);
				}
			}

			if(MaxHeap.size() == MinHeap.size())
				median += (MaxHeap.top() + MinHeap.top())/2;
			else if(MaxHeap.size() > MinHeap.size())
				median += MaxHeap.top();
			else
				median += MinHeap.top();		
		}
		cout << (median%10) << endl;
	}

	return 0;
}	
