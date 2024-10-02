#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printLCS(const string &X, const string &Y, const vector<vector<int>> &dp) {
    int m = X.size(), n = Y.size();
    string lcs;
    
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs.push_back(X[i - 1]);
            --i; --j;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }
    reverse(lcs.begin(), lcs.end());
    cout << "LCS: " << lcs << endl;
}

int bottomUpLCS(const string &X, const string &Y) {
    int m = X.size(), n = Y.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    printLCS(X, Y, dp);
    return dp[m][n];
}

int main() {
    string X = "ABCBDAB", Y = "BDCAB";
    int lcsLength = bottomUpLCS(X, Y);
    cout << "Length of LCS (Bottom-up DP): " << lcsLength << endl;
    return 0;
}

