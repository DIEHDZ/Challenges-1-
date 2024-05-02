#include <iostream>
#include <unordered_map>

std::unordered_map<int, long long> memo;

long long fibonacci(int n) {

    if (n <= 0) return 0;
    if (n == 1) return 1;
    if (memo.find(n) != memo.end()) return memo[n];
    
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}

int main() {
    int number;
    std::cin >> number;

    long long result = fibonacci(number);
    std::cout << result << std::endl;

    return 0;
}
