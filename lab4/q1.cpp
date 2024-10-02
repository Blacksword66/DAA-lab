#include <iostream>
#include <string>
#include <algorithm> // For max function

// Recursive function to find the maximum digit using divide and conquer
int findMaxDigit(const std::string &num, int left, int right) {
    // Base case: if there's only one digit, return it as an integer
    if (left == right) {
        return num[left] - '0';
    }

    // Find the middle index
    int mid = (left + right) / 2;

    // Recursively find the maximum digit in the left and right halves
    int maxLeft = findMaxDigit(num, left, mid);
    int maxRight = findMaxDigit(num, mid + 1, right);

    // Return the maximum of the two
    return std::max(maxLeft, maxRight);
}

int main() {
    std::string transactionID;
    
    // Input the transaction ID (large number)
    std::cout << "Enter transaction ID: ";
    std::cin >> transactionID;

    // Find and print the maximum digit in the transaction ID
    int maxDigit = findMaxDigit(transactionID, 0, transactionID.size() - 1);
    std::cout << "Maximum digit in the transaction ID is: " << maxDigit << std::endl;

    return 0;
}
