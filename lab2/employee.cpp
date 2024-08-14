#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <ctime>

using namespace std;

struct Employee {
    int employeeID;
    double salary;

    // Constructor
    Employee(int id, double sal) : employeeID(id), salary(sal) {}
};

// Partition function for Quick Sort (based on salary)
int partition(vector<Employee> &employees, int low, int high) {
    double pivot = employees[high].salary;  // Pivot is now based on salary
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (employees[j].salary < pivot) {  // Compare based on salary
            i++;
            swap(employees[i], employees[j]);
        }
    }
    swap(employees[i + 1], employees[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(vector<Employee> &employees, int low, int high) {
    if (low < high) {
        int pi = partition(employees, low, high);
        quickSort(employees, low, pi - 1);
        quickSort(employees, pi + 1, high);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {  // Check if the file name is provided
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    vector<Employee> employees;
    ifstream inputFile(argv[1]);  // Use the file name provided as argument

    if (!inputFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        int id;
        double salary;
        ss >> id >> salary;
        employees.emplace_back(id, salary);
    }

    inputFile.close();

    // Timing the sorting
    clock_t start = clock();
    quickSort(employees, 0, employees.size() - 1);
    clock_t end = clock();
    double time_taken = double(end - start) / CLOCKS_PER_SEC;

    // Output the sorted list
    cout << "Sorted Employee Records by Salary:\n";
    for (const auto &e : employees) {
        cout << "ID: " << e.employeeID << ", Salary: $" << e.salary << endl;
    }

    cout << "Time taken to sort: " << time_taken << " seconds\n";
    return 0;
}
