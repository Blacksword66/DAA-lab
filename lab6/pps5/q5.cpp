#include <iostream>
#include <vector>
using namespace std;

int rodCuttingDP(int n, vector<int>& price, vector<int>& dp) {
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];
    
    int maxRevenue = 0;
    for (int i = 1; i <= n; i++) {
        maxRevenue = max(maxRevenue, price[i - 1] + rodCuttingDP(n - i, price, dp));
    }
    dp[n] = maxRevenue;
    return dp[n];
}

int main() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int n;
    cout<<"Enter the length of the rod";
    cin>>n;
    vector<int> dp(n+1, -1);
    cout << "Maximum revenue: " << rodCuttingDP(n, price, dp) << endl;
    return 0;
}
