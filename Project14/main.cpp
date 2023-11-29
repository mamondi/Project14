#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

struct Fraction {
    int num;
    int denom;
};

void simplifyFraction(Fraction& frac) {
    int commonDivisor = gcd(abs(frac.num), frac.denom);
    frac.num /= commonDivisor;
    frac.denom /= commonDivisor;
}

Fraction toProperFraction(int wholePart, const Fraction& frac) {
    Fraction properFrac;
    properFrac.num = wholePart * frac.denom + frac.num;
    properFrac.denom = frac.denom;
    simplifyFraction(properFrac);
    return properFrac;
}

Fraction addFractions(const Fraction& frac1, const Fraction& frac2) {
    Fraction result;
    result.num = frac1.num * frac2.denom + frac2.num * frac1.denom;
    result.denom = frac1.denom * frac2.denom;
    simplifyFraction(result);
    return result;
}

Fraction subtractFractions(const Fraction& frac1, const Fraction& frac2) {
    Fraction result;
    result.num = frac1.num * frac2.denom - frac2.num * frac1.denom;
    result.denom = frac1.denom * frac2.denom;
    simplifyFraction(result);
    return result;
}

Fraction multiplyFractions(const Fraction& frac1, const Fraction& frac2) {
    Fraction result;
    result.num = frac1.num * frac2.num;
    result.denom = frac1.denom * frac2.denom;
    simplifyFraction(result);
    return result;
}

Fraction divideFractions(const Fraction& frac1, const Fraction& frac2) {
    Fraction result;
    result.num = frac1.num * frac2.denom;
    result.denom = frac1.denom * frac2.num;
    simplifyFraction(result);
    return result;
}

void printFraction(const Fraction& frac) {
    cout << frac.num << '/' << frac.denom;
}

int main() {
    Fraction frac1 = { 3, 4 };
    Fraction frac2 = { 2, 5 };

    Fraction sum = addFractions(frac1, frac2);
    Fraction diff = subtractFractions(frac1, frac2);
    Fraction product = multiplyFractions(frac1, frac2);
    Fraction quotient = divideFractions(frac1, frac2);

    cout << "Frac1: ";
    printFraction(frac1);
    cout << endl;

    cout << "Frac2: ";
    printFraction(frac2);
    cout << endl;

    cout << "Sum: ";
    printFraction(sum);
    cout << endl;

    cout << "Diff: ";
    printFraction(diff);
    cout << endl;

    cout << "Product: ";
    printFraction(product);
    cout << endl;

    cout << "Quotient: ";
    printFraction(quotient);
    cout << endl;

    return 0;
}