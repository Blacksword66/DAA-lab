#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int oneTableLCS(const string &X, const string &Y) {
    int m = X.size(), n = Y.size();
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= m; ++i) {
        int prev = 0;
        for (int j = 1; j <= n; ++j) {
            int temp = dp[j];
            if (X[i - 1] == Y[j - 1])
                dp[j] = prev + 1;
            else
                dp[j] = max(dp[j], dp[j - 1]);
            prev = temp;
        }
    }
    return dp[n];
}

int main() {
    string X = "ABCBDAB", Y = "BDCAB";
    int lcsLength = oneTableLCS(X, Y);
    cout << "Length of LCS (One Table DP): " << lcsLength << endl;
    return 0;
}

