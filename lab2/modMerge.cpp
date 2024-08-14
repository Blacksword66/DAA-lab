#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class MergeSortMetrics {
public:
    int comparisons = 0;
    int recursive_calls = 0;
    int right_directly_placed = 0;
    int left_directly_placed = 0;
};

// Merge function to merge two sorted halves and count metrics
void merge(vector<string>& arr, int left, int mid, int right, MergeSortMetrics& metrics) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    vector<string> L(n1);
    vector<string> R(n2);
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        metrics.comparisons++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
            metrics.left_directly_placed++;
        } else {
            arr[k++] = R[j++];
            metrics.right_directly_placed++;
        }
    }
    
    while (i < n1) {
        arr[k++] = L[i++];
        metrics.left_directly_placed++;
    }
    
    while (j < n2) {
        arr[k++] = R[j++];
        metrics.right_directly_placed++;
    }
}

// Recursive Merge Sort function
void mergeSort(vector<string>& arr, int left, int right, MergeSortMetrics& metrics) {
    metrics.recursive_calls++;
    
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid, metrics);
        mergeSort(arr, mid + 1, right, metrics);
        merge(arr, left, mid, right, metrics);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    string filename = argv[1];
    ifstream infile(filename);

    if (!infile) {
        cerr << "Error opening file: " << filename << endl;
        return 1;
    }

    vector<string> arr;
    string line;
    
    while (getline(infile, line)) {
        arr.push_back(line);
    }
    
    infile.close();

    MergeSortMetrics metrics;

    cout << "Original array:\n";
    for (const auto& word : arr) {
        cout << word << " ";
    }
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1, metrics);

    cout << "Sorted array:\n";
    for (const auto& word : arr) {
        cout << word << " ";
    }
    cout << endl;

    cout << "Total comparisons: " << metrics.comparisons << endl;
    cout << "Total recursive calls: " << metrics.recursive_calls << endl;
    cout << "Right directly placed: " << metrics.right_directly_placed << endl;
    cout << "Left directly placed: " << metrics.left_directly_placed << endl;

    return 0;
}
