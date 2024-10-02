#include <iostream>
#include <vector>
using namespace std;

int rodCuttingBruteForce(int n, vector<int>& price) {
    if (n == 0) return 0;

    int maxRevenue = 0;
    for (int i = 1; i <= n; i++) {
        maxRevenue = max(maxRevenue, price[i - 1] + rodCuttingBruteForce(n - i, price));
    }
    return maxRevenue;
}

int main() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int n;
    cout<<"Enter length of rod :";
    cin>>n;
    cout << "Maximum revenue: " << rodCuttingBruteForce(n, price) << endl;
    return 0;
}
