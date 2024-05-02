#include <iostream>
#include <vector>
#include <cmath>
#include <map>

// Function to factorize the number and store the prime factors
std::vector<int> prime_factors(int num) {
    std::vector<int> factors;
    while (num % 2 == 0) {
        factors.push_back(2);
        num /= 2;
    }
    for (int i = 3; i <= sqrt(num); i += 2) {
        while (num % i == 0) {
            factors.push_back(i);
            num /= i;
        }
    }
    if (num > 2) factors.push_back(num);
    return factors;
}

// Function to process the numbers and return the number of iterations
int process_numbers(std::vector<int>& numbers) {
    std::map<int, int> factor_count;
    int iterations = 0;
    int sum = 0;

    // Initial factorization and counting
    for (int num : numbers) {
        std::vector<int> factors = prime_factors(abs(num));
        for (int factor : factors) {
            if (factor_count[factor] == 0) {
                sum += factor;
                factor_count[factor] = 1;
            }
        }
    }

    // Iterating until we have a single unique prime
    while (factor_count.size() > 1) {
        int new_sum = 0;
        factor_count.clear();
        std::vector<int> factors = prime_factors(sum);
        for (int factor : factors) {
            if (factor_count[factor] == 0) {
                new_sum += factor;
                factor_count[factor] = 1;
            }
        }
        sum = new_sum;
        iterations++;
    }

    return iterations;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> numbers(n);

    for (int i = 0; i < n; i++) {
        std::cin >> numbers[i];
    }

    int result = process_numbers(numbers);
    std::cout << result + 1 << std::endl;

    return 0;
}
