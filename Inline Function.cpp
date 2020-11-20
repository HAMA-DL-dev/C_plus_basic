// Non-inline function
#include <iostream>
using namespace std;

int add2(int n1, int n2) {
	int out = 0;
	out = n1 + n2;
	return out;
}

int main() {
	int result = 0;
	result = add2(3, 5);
	cout << "The result is " << result << endl;
}

// Inline function
#include <iostream>
using namespace std;

inline int add2(int n1,int n2) {
	int out = 0;
	out = n1 + n2;
	return out;
}

int main() {
	int result = 0;
	result = add2(3, 5);
	cout << "The result is " << result << endl;
}
 
