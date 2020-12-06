#include <iostream>

using namespace std;

void insert(int* seq, int new_value, int seq_i) {
	while (new_value < seq[seq_i]) {
		seq[seq_i + 1] = seq[seq_i];
		seq_i--;
	}
	seq[ seq_i + 1 ] = new_value;
}

void InsertSort(int* seq, int seq_size) {
	for (int j = 1; j < seq_size; j++) {
		int temp = seq[j];
		insert(seq, temp, j - 1);

		for (int i = 0; i < 6; i++)
			cout << seq[i] << " ";
		cout << endl;
	}
}

int main() {
	int a[6] = { 74.47,6,29.22,3 };
	InsertSort(a, 6);
	return 0;
}