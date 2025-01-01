#include <iostream>
#include <vector>

// Function to find prime factors
std::vector<int> primeFactors(int n) {
    std::vector<int> factors;

    // Divide by 2 until n is odd
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    // Try odd numbers from 3 onwards
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    // If n is a prime number greater than 2
    if (n > 2) {
        factors.push_back(n);
    }

    return factors;
}

int main() {
    int num = 60;
    std::vector<int> factors = primeFactors(num);

    std::cout << "Prime factors of " << num << " are: ";
    for (int factor : factors) {
        std::cout << factor << " ";
    }
    std::cout << std::endl;

    return 0;
}
