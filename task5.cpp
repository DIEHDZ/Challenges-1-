#include <iostream>
#include <vector>

int findIndex(const std::vector<int>& arr, int v) {
    int left = 0;
    int right = arr.size() - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;
        if (arr[mid] == v) {
            return mid; 
        } else if (arr[mid] < v) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // If not found, left will be the position to insert v
    return left; 
}

int main() {
    int n, v;
    std::cin >> n;
    std::vector<int> S(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> S[i];
    }

    std::cin >> v;

    std::cout << findIndex(S, v) << std::endl;

    return 0;
}
