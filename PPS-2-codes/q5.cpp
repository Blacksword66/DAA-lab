#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int findMaxNonContiguousSum(int A[], int low, int high, vector<int>& result) {
    if (low == high) {
        if(A[low]>0){
          result.push_back(A[low]);
          return A[low];
        }    
        else{
          return 0;
        }
    }
    vector<int> leftResult, rightResult;
    int mid = (low + high) / 2;
    int leftMax = findMaxNonContiguousSum(A, low, mid, leftResult);
    int rightMax = findMaxNonContiguousSum(A, mid + 1, high, rightResult);

    result.insert(result.end(), leftResult.begin(), leftResult.end());
    result.insert(result.end(), rightResult.begin(), rightResult.end());
    return leftMax + rightMax;
}
int main() {
    int A[6] = {1, -1, 2, 3, -5, 8};
    int n = 6;
    vector<int> resultVect;
    int result = findMaxNonContiguousSum(A, 0, n - 1, resultVect);

    cout << "Maximum non-contiguous subarray sum: " << result<< endl;
    cout << "Elements contributing to the maximum sum: ";
    for (int val : resultVect) {
        cout << val << " ";
    }
    cout<<endl;
    return 0;
}
