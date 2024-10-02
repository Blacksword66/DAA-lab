#include <iostream>
#include <vector>
using namespace std;

int fiba(int n, vector<int>& dp) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (n == 3) return 2;
    
    if (dp[n] != -1) return dp[n];
    
    dp[n] = fiba(n-1, dp) + fiba(n-2, dp) + fiba(n-3, dp);
    return dp[n];
}

int main() {
    int n;
    cin>>n;
    vector<int> dp(n+1, -1);
    cout << "fiba(" << n << "): " << fiba(n, dp) << endl;
    return 0;
}
