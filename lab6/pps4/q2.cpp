#include <iostream>
#include <algorithm>
using namespace std;

int recursiveLCS(const string &X, const string &Y, int m, int n) {
    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
        return 1 + recursiveLCS(X, Y, m - 1, n - 1);
    else
        return max(recursiveLCS(X, Y, m, n - 1), recursiveLCS(X, Y, m - 1, n));
}

int main() {
    string X = "ABCBDAB", Y = "BDCAB";
    int lcsLength = recursiveLCS(X, Y, X.size(), Y.size());
    cout << "Length of LCS (Recursive): " << lcsLength << endl;
    return 0;
}

