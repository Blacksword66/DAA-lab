#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int memoizedLCS(const string &X, const string &Y, int m, int n, vector<vector<int>> &memo) {
    if (m == 0 || n == 0)
        return 0;
    if (memo[m][n] != -1)
        return memo[m][n];
    if (X[m - 1] == Y[n - 1])
        memo[m][n] = 1 + memoizedLCS(X, Y, m - 1, n - 1, memo);
    else
        memo[m][n] = max(memoizedLCS(X, Y, m, n - 1, memo), memoizedLCS(X, Y, m - 1, n, memo));
    return memo[m][n];
}

int main() {
    string X = "ABCBDAB", Y = "BDCAB";
    int m = X.size(), n = Y.size();
    vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
    int lcsLength = memoizedLCS(X, Y, m, n, memo);
    cout << "Length of LCS (Memoized DP): " << lcsLength << endl;
    return 0;
}

