#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int extendedGCD(int a, int b, int& x, int& y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1;
    int gcd = extendedGCD(b % a, a, x1, y1);

    x = y1 - (b / a) * x1;
    y = x1;

    return gcd;
}

int modInverse(int a, int m) {
    int x, y;
    int gcd = extendedGCD(a, m, x, y);

    if (gcd != 1) {
        std::cerr << "Inverse doesn't exist\n";
        exit(EXIT_FAILURE);
    }

    return (x % m + m) % m;
}

int hashFunction(const string& message) {
    int hash = 0;
    for (char c : message) {
        hash += static_cast<int>(c);
    }
    return hash;
}