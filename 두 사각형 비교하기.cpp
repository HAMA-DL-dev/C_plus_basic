#include <iostream>
using namespace std;

class Rectangle
{
private:
	int i32height, i32width, area;

public:
	Rectangle(int h, int w);
	bool operator<(const Rectangle& s);
};

Rectangle::Rectangle(int h, int w) {
	h = i32height;
	w = i32width;
	area = h * w;
}

bool Rectangle::operator<(const Rectangle& s) {

	if (area < s.area)return true;

	else return false;
}

int main() {

	Rectangle R1(3, 4);
	Rectangle R2(1, 6);

	if (R2 < R1)
		cout << "R1 is bigger than R2" << endl;
	else
		cout << "R1 is smaller than R2 or same" << endl;

	return 0;
}