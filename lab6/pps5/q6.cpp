#include <iostream>
#include <vector>
using namespace std;

int rodCuttingBottomUp(int n, vector<int>& price) {
    vector<int> dp(n + 1, 0);  // dp[i] represents the maximum revenue for a rod of length i

    for (int i = 1; i <= n; i++) {
        int maxRevenue = 0;
        for (int j = 1; j <= i; j++) {
            maxRevenue = max(maxRevenue, price[j - 1] + dp[i - j]);
        }
        dp[i] = maxRevenue;
    }
    return dp[n];
}

int main() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int n;
    cout<<"Enter the length of the rod :";
    cin>>n;
    cout << "Maximum revenue: " << rodCuttingBottomUp(n, price) << endl;
    return 0;
}
