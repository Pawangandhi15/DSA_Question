// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

// Example 1:

// Input: text1 = "abcde", text2 = "ace"
// Output: 3
// Explanation: The longest common subsequence is "ace" and its length is 3.
// Example 2:

// Input: text1 = "abc", text2 = "abc"
// Output: 3
// Explanation: The longest common subsequence is "abc" and its length is 3.
// Example 3:

// Input: text1 = "abc", text2 = "def"
// Output: 0
// Explanation: There is no such common subsequence, so the result is 0.

// Constraints:

// 1 <= text1.length, text2.length <= 1000
// text1 and text2 consist of only lowercase English characters.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int m, n;
    int dp[1001][1001];
    int solve(string &s1, string &s2, int i, int j)
    {
        if (i >= m || j >= n)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (s1[i] == s2[j])
        {
            return dp[i][j] = 1 + solve(s1, s2, i + 1, j + 1);
        }
        else
        {
            return dp[i][j] = max(solve(s1, s2, i + 1, j), solve(s1, s2, i, j + 1));
        }
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        m = text1.length();
        n = text2.length();
        memset(dp, -1, sizeof(dp));
        return solve(text1, text2, 0, 0);
    }
};

class Solution
{
public:
    int longestCommonSubsequence(string s1, string s2)
    {
        int m = s1.length();
        int n = s2.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int row = 0; row < m + 1; row++)
        {
            dp[row][0] = 0;
        }
        for (int col = 0; col < n + 1; col++)
        {
            dp[0][col] = 0;
        }
        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};
