#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
public:
	int length;
	int size;
	
	int* arr;

	MaxHeap(int n) {
		length = n;
		size = 0;
		arr = new int[length + 1];
	}
	~MaxHeap() {
		delete[] arr;
	}

	void Push(int n) {
		if(++size <= length) {
			arr[size] = n;
			
			for(int i = size/2; i >= 1; i /= 2)
				Heapify(i);
		}
	}

	void Heapify(int n) {
		int largest;
		int left = n*2;
		int right = n*2 + 1;

		if(left <= size && arr[left] > arr[n])
			largest = left;
		else
			largest = n;

		if(right <= size && arr[right] > arr[largest])
			largest = right;

		if(largest != n) {
			int tmp = arr[largest];
			arr[largest] = arr[n];
			arr[n] = tmp;

			Heapify(largest);
		}
	}

	void Delete() {
		if(size < 1)
			return;

		arr[1] = arr[size];
		
		if(--size > 1)
			Heapify(1);
	}

	int Top() { return arr[1]; }

	void Print() {
		for(int i = 1; i <= size; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
};

class MinHeap {
public:
	int length;
	int size;
	
	int* arr;

	MinHeap(int n) {
		length = n;
		size = 0;
		arr = new int[length + 1];
	}
	~MinHeap() {
		delete[] arr;
	}

	void Push(int n) {
		if(++size <= length) {
			arr[size] = n;
			
			for(int i = size/2; i >= 1; i /= 2)
				Heapify(i);
		}
	}

	void Heapify(int n) {
		int smallest;
		int left = n*2;
		int right = n*2 + 1;

		if(left <= size && arr[left] < arr[n])
			smallest = left;
		else
			smallest = n;

		if(right <= size && arr[right] < arr[smallest])
			smallest = right;

		if(smallest != n) {
			int tmp = arr[smallest];
			arr[smallest] = arr[n];
			arr[n] = tmp;

			Heapify(smallest);
		}
	}

	void Delete() {
		if(size < 1)
			return;

		arr[1] = arr[size];

		if(--size > 1)
			Heapify(1);
	}

	int Top() { return arr[1]; }

	void Print() {
		for(int i = 1; i <= size; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
};

int main() {
	int t, n, m;
	cin >> t;

	for(int i = 0; i < t; i++) {
		cin >> n;

		MaxHeap* max = new MaxHeap(n);
		MinHeap* min = new MinHeap(n);

		unsigned long long int result = 0;
		for(int j = 0; j < n; j++) {
			cin >> m;

			if(max->size == 0 && min->size == 0)		// Initial
				min->Push(m);
			else if(max->size == min->size) {		// x = k, y = k
				if(m >= min->Top())
					min->Push(m);
				else
					max->Push(m);
			}
			else if(max->size < min->size) {		// x = k, y = k+1
				if(m >= min->Top()) {
					max->Push(min->Top());
					min->Delete();
					min->Push(m);
				}
				else
					max->Push(m);
			}
			else if(max->size > min->size) {		// x = k+1, y = k
				if(m >= max->Top())
					min->Push(m);
				else {
					min->Push(max->Top());
					max->Delete();
					max->Push(m);
				}		
			}

			// Add Median
			if(max->size == min->size)
				result += ((max->Top() + min->Top())/2)%10;
			else if(max->size > min->size)
				result += max->Top()%10;
			else
				result += min->Top()%10;
		}

		cout << result%10 << endl;

		delete max;
		delete min;
	}

	return 0;
}
