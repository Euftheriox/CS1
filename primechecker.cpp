#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

bool isPrime(int num, vector<int>& divisors) {
    const vector<int> primeDivisors = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

    if (num <= 31) {
        // Check if num is one of the first 11 prime numbers
        for (int prime : primeDivisors) {
            if (num == prime) {
                return true;
            }
        }
        // Check divisibility by the first 11 prime numbers for numbers less than or equal to 31
        for (int prime : primeDivisors) {
            if (num % prime == 0) {
                divisors.push_back(prime);
            }
        }
        return false;
    }

    // Check divisibility by the first 11 prime numbers for numbers greater than 31
    for (int prime : primeDivisors) {
        if (num % prime == 0) {
            divisors.push_back(prime);
        }
    }

    return divisors.empty();
}

int main() {
    int num;
    vector<int> divisors;

    // Prompt user for input
    cout << "Enter a positive integer between 1 and 1000 (inclusive): ";
    cin >> num;

    // Check if the input is within the valid range
    if (num < 1 || num > 1000) {
        cout << "The number is out of the valid range." << endl;
        return 1;
    }

    // Determine if the number is prime and find divisors if it's not
    if (isPrime(num, divisors)) {
        cout << num << " is a prime number." << endl;
    } else {
        cout << num << " is not a prime number." << endl;
        cout << "It is divisible by: ";
        for (size_t i = 0; i < divisors.size(); ++i) {
            cout << divisors[i];
            if (i < divisors.size() - 1) {
                cout << ", ";
            }
        }
        cout << "." << endl;
    }

    return 0;
}