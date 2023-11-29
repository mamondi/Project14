#include <iostream>
#include <Windows.h>
using namespace std;

struct Complex {
    double real;
    double imaginary;
};

Complex addComplex(const Complex& c1, const Complex& c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imaginary = c1.imaginary + c2.imaginary;
    return result;
}

Complex subtractComplex(const Complex& c1, const Complex& c2) {
    Complex result;
    result.real = c1.real - c2.real;
    result.imaginary = c1.imaginary - c2.imaginary;
    return result;
}

Complex multiplyComplex(const Complex& c1, const Complex& c2) {
    Complex result;
    result.real = c1.real * c2.real - c1.imaginary * c2.imaginary;
    result.imaginary = c1.real * c2.imaginary + c1.imaginary * c2.real;
    return result;
}

Complex divideComplex(const Complex& c1, const Complex& c2) {
    Complex result;
    double denominator = c2.real * c2.real + c2.imaginary * c2.imaginary;
    result.real = (c1.real * c2.real + c1.imaginary * c2.imaginary) / denominator;
    result.imaginary = (c1.imaginary * c2.real - c1.real * c2.imaginary) / denominator;
    return result;
}

void printComplex(const Complex& c) {
    cout << c.real << " + " << c.imaginary << "i";
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
        
    Complex complex1 = { 3.0, 4.0 };
    Complex complex2 = { 1.0, 2.0 };

    Complex sum = addComplex(complex1, complex2);
    cout << "Сума: ";
    printComplex(sum);
    cout << endl;

    Complex difference = subtractComplex(complex1, complex2);
    cout << "Різниця: ";
    printComplex(difference);
    cout << endl;

    Complex product = multiplyComplex(complex1, complex2);
    cout << "Добуток: ";
    printComplex(product);
    cout << endl;

    Complex quotient = divideComplex(complex1, complex2);
    cout << "Частка: ";
    printComplex(quotient);
    cout << endl;

    return 0;
}