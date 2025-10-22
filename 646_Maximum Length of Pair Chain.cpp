// You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.

// A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.

// Return the length longest chain which can be formed.

// You do not need to use up all the given intervals. You can select pairs in any order.

 

// Example 1:

// Input: pairs = [[1,2],[2,3],[3,4]]
// Output: 2
// Explanation: The longest chain is [1,2] -> [3,4].
// Example 2:

// Input: pairs = [[1,2],[7,8],[4,5]]
// Output: 3
// Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].
 

// Constraints:

// n == pairs.length
// 1 <= n <= 1000
// -1000 <= lefti < righti <= 1000

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int dp[1001][1001];

    int solve(vector<vector<int>>& pairs, int i, int p) {
        if (i >= n) {
            return 0;
        }
        if (p != -1 && dp[i][p] != -1) {
            return dp[i][p];
        }
        int take = 0;
        if (p == -1 || pairs[p][1] < pairs[i][0]) {
            take = 1 + solve(pairs, i + 1, i);
        }
        int skip = solve(pairs, i + 1, p);
        if (p != -1)
            dp[i][p] = max(take, skip);
        return max(take, skip);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        n = pairs.size();
        sort(begin(pairs), end(pairs));
        memset(dp, -1, sizeof(dp));
        return solve(pairs, 0, -1);
    }
};


class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        int masLis = 1;
        sort(begin(pairs), end(pairs));
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[j][1] < pairs[i][0]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    masLis = max(masLis, dp[i]);
                }
            }
        }
        return masLis;
    }
};

