#include <iostream>
using namespace std;

int main() {
	int count = 1;
	int array2D[3][4];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			array2D[i][j] = count;
			count++;
		}
	}
	cout << *array2D[0] << "\t" << array2D[0] << endl;
	cout << *array2D[1] << "\t" << array2D[1] << endl;
	cout << *array2D[2] << "\t" << array2D[2] << endl;
}

//////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main() {
	int count = 1;
	int* array2D[3];

	for (int i = 0; i < 3; i++) {
		array2D[i] = new int[4];
		for (int j = 0; j < 4; j++) {
			array2D[i][j] = count;
			count++;
		}
	}
	for (int i = 0; i < 3; i++) delete[]array2D[i];
}

//////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main() {
	int count = 1;
	int** array2D;
	array2D = new int* [3];

	for (int i = 0; i < 3; i++) {
		array2D[i] = new int[4];
		for (int j = 0; j < 4; j++) {
			array2D[i][j] = count;
			count++;
		}
	}
	for (int i = 0; i < 3; i++) delete[]array2D[i];
	delete[] array2D;
}