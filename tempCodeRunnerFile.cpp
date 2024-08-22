#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int longestSequenceDP(const vector<string>& tiles) {
    unordered_map<char, unordered_map<char, int>> dp;

    int maxLength = 0;

    for (const string& tile : tiles) {
        char start = tile[0];
        char end = tile[1];

        dp[start][end] = max(dp[start][end], dp[start][start] + 1);

        maxLength = max(maxLength, dp[start][end]);
    }

    return maxLength;
}

int main() {
    vector<string> test1 = {"RG", "RG", "RG"};
    vector<string> test2 = {"RG", "GR", "RG", "GR"};

    cout << "Test Case 1: " << longestSequenceDP(test1) << endl; // Expected: 1
    cout << "Test Case 2: " << longestSequenceDP(test2) << endl; // Expected: 4

    return 0;
}
