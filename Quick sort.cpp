#include <iostream>
using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void quicksort(int* seq, int left, int right) {
	if (left < right) {
		int i = left, j = right + 1;
		int pivot = seq[left];

		do {
			do i++; while (seq[i] < pivot);
			do j--; while (seq[j] > pivot);
			if (i < j) {
				cout << "Swap" << seq[i] << "<->" << seq[j] << " : ";
				swap(seq[i], seq[j]);

				for (int k = 0; k < 10; k++) {
					cout << seq[k] << " ";
				}
				cout << endl;
			}
			
		} while (i < j);
		cout << "Swap" << seq[i] << "<->" << seq[j] << " : ";
		swap(seq[i], seq[j]);

		for (int k = 0; k < 10; k++) {
			cout << seq[k] << " ";
		}
		cout << endl;

		quicksort(seq, left, j - 1);
		quicksort(seq, j + 1, right);
	}
	
}

int main() {
	int array[10] = { 25,5,37,1,61,11,59,15,48,19 };
	for (int i = 0; i < 10; i++) {
		cout << array[i] << " ";
	}
	cout << endl;

	quicksort(array, 0, 9);

	return 0;
}