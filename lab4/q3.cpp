#include <iostream>
#include <vector>
#include <algorithm> // For merge

// Merge function to combine two halves
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp arrays for left and right halves
    std::vector<int> leftArr(n1), rightArr(n2);

    for (int i = 0; i < n1; ++i) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; ++i) {
        rightArr[i] = arr[mid + 1 + i];
    }

    // Merge temp arrays back into the main array
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    // Copy any remaining elements of leftArr and rightArr
    while (i < n1) {
        arr[k++] = leftArr[i++];
    }
    while (j < n2) {
        arr[k++] = rightArr[j++];
    }
}

// Recursive function to perform merge sort on odd-indexed elements
void mergeSortOddIndices(std::vector<int>& oddIndicesArr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort the left and right halves
        mergeSortOddIndices(oddIndicesArr, left, mid);
        mergeSortOddIndices(oddIndicesArr, mid + 1, right);

        // Merge the sorted halves
        merge(oddIndicesArr, left, mid, right);
    }
}

int main() {
    // Input array
    std::vector<int> A = {-1, 2, -2, -5, 4, 0};

    // Extract odd-indexed elements
    std::vector<int> oddIndicesArr;
    for (int i = 1; i < A.size(); i += 2) {
        oddIndicesArr.push_back(A[i]);
    }

    // Perform merge sort on odd-indexed elements
    mergeSortOddIndices(oddIndicesArr, 0, oddIndicesArr.size() - 1);

    // Place the sorted odd-indexed elements back into the original array
    int oddIndex = 0;
    for (int i = 1; i < A.size(); i += 2) {
        A[i] = oddIndicesArr[oddIndex++];
    }

    // Output the modified array
    std::cout << "Array after sorting odd indices: ";
    for (int num : A) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
