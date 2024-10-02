#include <iostream>
#include <vector>

int scalarMultiplications = 0;
int scalarAdditions = 0;

// Function to add two matrices
std::vector<std::vector<int>> add(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int n = A.size();
    std::vector<std::vector<int>> result(n, std::vector<int>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] + B[i][j];
            scalarAdditions++;
        }
    }
    return result;
}

// Function to subtract two matrices
std::vector<std::vector<int>> subtract(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int n = A.size();
    std::vector<std::vector<int>> result(n, std::vector<int>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] - B[i][j];
            scalarAdditions++;
        }
    }
    return result;
}

// Recursive function to multiply two matrices using Strassen's Algorithm
std::vector<std::vector<int>> strassen(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int n = A.size();
    if (n == 1) {
        // Base case: Single element multiplication
        scalarMultiplications++;
        return {{A[0][0] * B[0][0]}};
    }

    int newSize = n / 2;
    std::vector<std::vector<int>> A11(newSize, std::vector<int>(newSize));
    std::vector<std::vector<int>> A12(newSize, std::vector<int>(newSize));
    std::vector<std::vector<int>> A21(newSize, std::vector<int>(newSize));
    std::vector<std::vector<int>> A22(newSize, std::vector<int>(newSize));
    
    std::vector<std::vector<int>> B11(newSize, std::vector<int>(newSize));
    std::vector<std::vector<int>> B12(newSize, std::vector<int>(newSize));
    std::vector<std::vector<int>> B21(newSize, std::vector<int>(newSize));
    std::vector<std::vector<int>> B22(newSize, std::vector<int>(newSize));

    // Divide the matrices into 4 submatrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Strassen's Algorithm equations
    auto M1 = strassen(add(A11, A22), add(B11, B22)); // (A11 + A22) * (B11 + B22)
    auto M2 = strassen(add(A21, A22), B11);           // (A21 + A22) * B11
    auto M3 = strassen(A11, subtract(B12, B22));      // A11 * (B12 - B22)
    auto M4 = strassen(A22, subtract(B21, B11));      // A22 * (B21 - B11)
    auto M5 = strassen(add(A11, A12), B22);           // (A11 + A12) * B22
    auto M6 = strassen(subtract(A21, A11), add(B11, B12)); // (A21 - A11) * (B11 + B12)
    auto M7 = strassen(subtract(A12, A22), add(B21, B22)); // (A12 - A22) * (B21 + B22)

    // Combine the submatrices into the result matrix C
    auto C11 = add(subtract(add(M1, M4), M5), M7); // C11 = M1 + M4 - M5 + M7
    auto C12 = add(M3, M5);                        // C12 = M3 + M5
    auto C21 = add(M2, M4);                        // C21 = M2 + M4
    auto C22 = add(subtract(add(M1, M3), M2), M6); // C22 = M1 + M3 - M2 + M6

    // Combine results into one matrix
    std::vector<std::vector<int>> C(n, std::vector<int>(n));
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }

    return C;
}

int main() {
    int n = 4; // Matrix size, must be a power of 2
    std::vector<std::vector<int>> A = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    
    std::vector<std::vector<int>> B = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    auto C = strassen(A, B);

    // Output the resulting matrix C
    std::cout << "Resultant Matrix C:" << std::endl;
    for (const auto& row : C) {
        for (int elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    // Output the total number of scalar multiplications and additions
    std::cout << "Total scalar multiplications: " << scalarMultiplications << std::endl;
    std::cout << "Total scalar additions: " << scalarAdditions << std::endl;

    return 0;
}
