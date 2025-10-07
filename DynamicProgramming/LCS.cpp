// Problem: Given two strings s1 and s2, find the length of the longest common subsequence (LCS).
// Concept: Dynamic Programming (Recursion → Memoization → Tabulation)

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// Recursive Solution
// ---------------------------
int lcsRec(string s1, string s2, int m, int n) {
    if (m == 0 || n == 0)
        return 0;

    if (s1[m - 1] == s2[n - 1])
        return 1 + lcsRec(s1, s2, m - 1, n - 1);
    else
        return max(lcsRec(s1, s2, m - 1, n), lcsRec(s1, s2, m, n - 1));
}

// ---------------------------
// Memoization (Top-Down DP)
// ---------------------------
int memo[1001][1001];

int lcsMem(string s1, string s2, int m, int n) {
    if (m == 0 || n == 0)
        return 0;

    if (memo[m][n] != -1)
        return memo[m][n];

    if (s1[m - 1] == s2[n - 1])
        return memo[m][n] = 1 + lcsMem(s1, s2, m - 1, n - 1);
    else
        return memo[m][n] = max(lcsMem(s1, s2, m - 1, n), lcsMem(s1, s2, m, n - 1));
}

// ---------------------------
// Tabulation (Bottom-Up DP)
// ---------------------------
int lcsTab(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // dp[i][j] = length of LCS of s1[0..i-1] and s2[0..j-1]
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n];
}

// ---------------------------
// Main Function
// ---------------------------
int main() {
    string s1, s2;
    cout << "Enter two strings: ";
    cin >> s1 >> s2;

    memset(memo, -1, sizeof(memo));

    cout << "LCS (Recursion): " << lcsRec(s1, s2, s1.size(), s2.size()) << endl;
    cout << "LCS (Memoization): " << lcsMem(s1, s2, s1.size(), s2.size()) << endl;
    cout << "LCS (Tabulation): " << lcsTab(s1, s2) << endl;

    return 0;
}
