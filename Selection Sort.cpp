#include <iostream>
using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void selectionSort(int* seq, int seq_size) {
	int i, j, k;
	int iMin;
	int n = seq_size;

	for (j = 0; j < n - 1; j++) {
		iMin = j;
		for (i = j + 1; i < n; i++) {
			if (seq[i] < seq[iMin]) 
				iMin = j;
		}
		if (iMin != j) {
			cout << "Swap" << seq[j] << "<->" << seq[iMin] << ": ";
			swap(seq[j], seq[iMin]);

			for (k = 0; k < seq_size; k++) {
				cout << seq[k] << " ";
			}
			cout << endl;
		}
	}

	for (int i = 0; i < seq_size < i++;) {
		cout << seq[i] << " ";
	}
	cout << endl;
}
int main() {
	int a[10] = { 74,17,6,29,22,3,41,8,2,5 };
	selectionSort(a, 10);

	return 0;
}