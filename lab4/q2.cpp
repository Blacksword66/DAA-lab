#include <iostream>
#include <vector>
#include <algorithm> // For swap function

// Partition function for quickselect
int partition(std::vector<int>& arr, int left, int right, int pivotIndex) {
    int pivotValue = arr[pivotIndex];
    std::swap(arr[pivotIndex], arr[right]); // Move pivot to end
    int storeIndex = left;

    for (int i = left; i < right; i++) {
        if (arr[i] < pivotValue) {
            std::swap(arr[i], arr[storeIndex]);
            storeIndex++;
        }
    }

    std::swap(arr[storeIndex], arr[right]); // Move pivot to its final place
    return storeIndex;
}

// Quickselect function to find the k-th smallest element
int quickSelect(std::vector<int>& arr, int left, int right, int k) {
    if (left == right) {
        return arr[left]; // If the list contains only one element, return it
    }

    // Select a pivotIndex between left and right
    int pivotIndex = left + (right - left) / 2; // Middle as pivot
    pivotIndex = partition(arr, left, right, pivotIndex);

    // The pivot is in its final sorted position
    if (k == pivotIndex) {
        return arr[k];
    } else if (k < pivotIndex) {
        return quickSelect(arr, left, pivotIndex - 1, k);
    } else {
        return quickSelect(arr, pivotIndex + 1, right, k);
    }
}

int main() {
    std::vector<int> arr = {1, 7, 8, 4, 3};
    int k = 4; // We are looking for the 4th smallest element
    
    // Adjust k to be zero-indexed
    int kthSmallest = quickSelect(arr, 0, arr.size() - 1, k - 1);
    
    std::cout << "The " << k << "th smallest element is: " << kthSmallest << std::endl;

    return 0;
}
