#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> // For std::is_sorted

using namespace std;

// Function to perform binary search and count steps
bool binarySearch(const vector<int>& ids, int target, int& steps) {
    int left = 0;
    int right = ids.size() - 1;
    steps = 0;

    while (left <= right) {
        steps++; // Increment step count for each comparison
        int mid = left + (right - left) / 2;
        if (ids[mid] == target) {
            return true;
        } else if (ids[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <filename> <id_to_search>" << endl;
        return 1;
    }

    const char* filename = argv[1];
    int idToSearch = atoi(argv[2]);

    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return 1;
    }

    vector<int> ids;
    int id;

    while (file >> id) {
        ids.push_back(id);
    }
    file.close();

    // Ensure the IDs are sorted
    if (!is_sorted(ids.begin(), ids.end())) {
        cerr << "IDs in the file are not sorted. Please provide a sorted file." << endl;
        return 1;
    }

    int steps;
    bool found = binarySearch(ids, idToSearch, steps);
    if (found) {
        cout << "ID " << idToSearch << " found in the list." << endl;
    } else {
        cout << "ID " << idToSearch << " not found in the list." << endl;
    }
    cout << "Number of steps taken: " << steps << endl;

    return 0;
}
