#include <iostream>

using namespace std;

int HoareSwapCnt = 0;
int HoareCompareCnt = 0;
int LomutoSwapCnt = 0;
int LomutoCompareCnt = 0;

void swap(int arr[], int a, int b) {
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

int HoarePartition(int arr[], int low, int high) {
	int pivot = arr[low];
	int i = low-1;
	int j = high+1;

	while(true) {
		do {
			HoareCompareCnt++;
		} while(arr[++i] < pivot);
		do {
			HoareCompareCnt++;
		} while(arr[--j] > pivot);

		if(i < j) {
			swap(arr, i, j);
			HoareSwapCnt++;
		}
		else
			return j;
	}
}

void HoareQuickSort(int arr[], int low, int high) {
	if(low >= high)
		return;

	int pivotPos = HoarePartition(arr, low, high);
	HoareQuickSort(arr, low, pivotPos);
	HoareQuickSort(arr, pivotPos+1, high);
}

int LomutoPartition(int arr[], int low, int high) {
	int pivot = arr[low];
	int j = low;

	for(int i = low+1; i <= high; i++) {
		LomutoCompareCnt++;
		if(arr[i] < pivot) {
			j++;
			swap(arr, i, j);
			LomutoSwapCnt++;
		}
	}

	int pivotPos = j;
	swap(arr, low, pivotPos);
	LomutoSwapCnt++;

	return pivotPos;
}

void LomutoQuickSort(int arr[], int low, int high) {
	int pivotPos;

	if(high > low) {
		pivotPos = LomutoPartition(arr, low, high);
		LomutoQuickSort(arr, low, pivotPos-1);
		LomutoQuickSort(arr, pivotPos+1, high);
	}
}

int main() {
	int t;
	cin >> t;

	for(int i = 0; i < t; i++) {
		int n;
		cin >> n;

		HoareSwapCnt = HoareCompareCnt = LomutoSwapCnt = LomutoCompareCnt = 0;

		int LomutoArr[n], HoareArr[n];
		for(int j = 0; j < n; j++) {
			int x;
			cin >> x;

			HoareArr[j] = LomutoArr[j] = x;
		}
		
		HoareQuickSort(HoareArr, 0, n-1);
		LomutoQuickSort(LomutoArr, 0, n-1);
		
		cout << HoareSwapCnt << " " << LomutoSwapCnt << " " << HoareCompareCnt << " " << LomutoCompareCnt << endl;
	}

	return 0;
}
