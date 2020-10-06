#include <iostream>
using namespace std;

class Complex {
private:


public:
    int re, img;

    Complex(int re, int img) : re(re), img(img) {
        re = 0;
        img = 0;

    }
    Complex(const Complex& c) { re = c.re, img = c.img; }
    Complex operator+(const Complex& c) const;
    Complex operator*(const Complex& c) const;
};



Complex Complex::operator+(const Complex& c) const {

    Complex result = Complex(re + c.re, img + c.img);
    return result;
}

Complex Complex::operator*(const Complex& c) const {
    Complex result = Complex(re * c.re - img * c.img, re * c.img + img * c.re);
    return result;

}


int main() {
    cout << "The initial value is 0+j0" << endl;

    Complex a(2, 4);
    Complex b(3, 5);

    Complex sum = a + b;
    Complex mul = a * b;

    cout << "the sum of two num : " << sum.re << "+" << "j" << sum.img << endl;
    cout << "the multiplication of two num : " << mul.re << "+" << "j" << mul.img << endl;
}