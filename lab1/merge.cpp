#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

// Function to merge two subarrays
void merge(vector<int> &elements, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays
    vector<int> L(n1), R(n2);

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = elements[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = elements[mid + 1 + j];

    // Merge the temporary arrays back into elements[left..right]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            elements[k] = L[i];
            i++;
        } else {
            elements[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        elements[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        elements[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(vector<int> &elements, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(elements, left, mid);
        mergeSort(elements, mid + 1, right);

        // Merge the sorted halves
        merge(elements, left, mid, right);
    }
}

int main() {
    vector<int> elements;
    int n, ele;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ele;
        elements.push_back(ele);
    }

    clock_t tStart = clock();  // Start time measurement
    mergeSort(elements, 0, n - 1);  // Call to Merge Sort
    double time1 = (double)(clock() - tStart);  // Calculate the time taken

    cout << "Time taken is " << time1 << endl;

    // Uncomment the following lines to print the sorted elements
    /*
    for (int i = 0; i < n; i++) {
        cout << elements[i] << " ";
    }
    cout << endl;
    */
}
