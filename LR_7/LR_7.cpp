#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Elgamal.h"

using namespace std;

int main()
{
    srand(time(NULL));

    int p = 1; 
    int g = 1; 


    int a = rand() % (p - 1) + 1; 
    int b = static_cast<int>(pow(g, a)) % p;

    string message = "Hello, ElGamal!";
    int k = rand() % (p - 1) + 1; 
    int r = static_cast<int>(pow(g, k)) % p;

    int hashValue = hashFunction(message);
    int s = (hashValue - a * r) * modInverse(k, p - 1) % (p - 1);

    int y = modInverse(b, p);
    int u1 = (hashValue * modInverse(s, p - 1)) % (p - 1);
    int u2 = (r * modInverse(s, p - 1)) % (p - 1);
    int v = static_cast<int>(pow(g, u1) * pow(y, u2)) % p;

    if (v == r) {
        cout << "Підпис вірний!\n";
    }
    else {
        cout << "Підпис невірний!\n";
    }

    return 0;
}
