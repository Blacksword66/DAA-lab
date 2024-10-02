#include <iostream>
#include <vector>
using namespace std;

int rodCuttingMemoized(const vector<int>& price, int n, vector<int>& memo) {
    if (n == 0)
        return 0;
    
    if (memo[n] != -1)
        return memo[n];
    
    int maxRevenue = 0;
    for (int i = 1; i <= n; ++i) {
        maxRevenue = max(maxRevenue, price[i - 1] + rodCuttingMemoized(price, n - i, memo));
    }
    
    memo[n] = maxRevenue;
    return memo[n];
}

int main() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int n = 10;
    vector<int> memo(n + 1, -1);
    cout << "Maximum Revenue (Memoized): " << rodCuttingMemoized(price, n, memo) << endl;
    return 0;
}
