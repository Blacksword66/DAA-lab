#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper function to generate all subsequences
void generateSubsequences(const string &str, vector<string> &subseqs) {
    int n = str.size();
    for (int i = 0; i < (1 << n); ++i) {
        string subseq;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) subseq.push_back(str[j]);
        }
        subseqs.push_back(subseq);
    }
}

// Function to find the longest common subsequence
string longestCommonSubsequence(const string &X, const string &Y) {
    vector<string> subseqX, subseqY;
    generateSubsequences(X, subseqX);
    generateSubsequences(Y, subseqY);

    string lcs;
    for (const string &sx : subseqX) {
        for (const string &sy : subseqY) {
            if (sx == sy && sx.size() > lcs.size()) {
                lcs = sx;
            }
        }
    }
    return lcs;
}

int main() {
    string X = "ABCBDAB", Y = "BDCAB";
    string lcs = longestCommonSubsequence(X, Y);
    cout << "Longest Common Subsequence: " << lcs << endl;
    return 0;
}

