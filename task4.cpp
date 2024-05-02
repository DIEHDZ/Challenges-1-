#include <iostream>
#include <vector>

// Function to sort the array - using bubble sort 
void sortArray(std::vector<int>& arr) {
    int size = arr.size();
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to remove duplicates from the array after sorting
void removeDuplicates(std::vector<int>& arr) {
    int size = arr.size();
    int j = 0;

    for (int i = 0; i < size - 1; ++i) {
        if (arr[i] != arr[i + 1]) {
            arr[j++] = arr[i];
        }
    }
    arr[j++] = arr[size - 1];

    // Resize the vector to remove the undefined elements
    arr.resize(j);
}

int main() {
    int n, val;
    std::vector<int> arr;

    // Read the number of elements
    std::cin >> n;

    // Read the elements into the array
    for(int i = 0; i < n; ++i) {
        std::cin >> val;
        arr.push_back(val);
    }

    // Sort the array
    sortArray(arr);

    // Remove duplicates from the array
    removeDuplicates(arr);

    // Output the sorted array without duplicates
    for(int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}
