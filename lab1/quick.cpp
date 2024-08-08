#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function to place the pivot element in its correct position
int partition(vector<int> &elements, int low, int high) {
    int pivot = elements[high];  // Pivot element
    int i = low - 1;  // Index of the smaller element

    for (int j = low; j < high; j++) {
        if (elements[j] <= pivot) {
            i++;
            swap(elements[i], elements[j]);  // Swap if the current element is smaller than or equal to pivot
        }
    }
    swap(elements[i + 1], elements[high]);  // Swap the pivot element with the element at i+1
    return (i + 1);  // Return the partition index
}

// Quick Sort function
void quickSort(vector<int> &elements, int low, int high) {
    if (low < high) {
        int pi = partition(elements, low, high);  // Partitioning index
        quickSort(elements, low, pi - 1);  // Recursively sort the elements before partition
        quickSort(elements, pi + 1, high);  // Recursively sort the elements after partition
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
    quickSort(elements, 0, n - 1);  // Call to Quick Sort
    double time1 = (double)(clock() - tStart);  // Calculate the time taken

    cout << "Time taken is " << time1 << endl;

    /*
    for (int i = 0; i < n; i++) {
        cout << elements[i] << " ";
    }
    cout << endl;
    */
}
