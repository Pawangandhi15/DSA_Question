// Given an integer array nums, return the length of the longest strictly increasing subsequence.

 

// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
// Example 2:

// Input: nums = [0,1,0,3,2,3]
// Output: 4
// Example 3:

// Input: nums = [7,7,7,7,7,7,7]
// Output: 1
 

// Constraints:

// 1 <= nums.length <= 2500
// -104 <= nums[i] <= 104

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int dp[2501][2501];

    int solve(vector<int>& nums, int i, int p) {
        if (i >= n) {
            return 0;
        }
        if (p != -1 && dp[i][p] != -1) {
            return dp[i][p];
        }
        int take = 0;
        if (p == -1 || nums[p] < nums[i]) {
            take = 1 + solve(nums, i + 1, i);
        }
        int skip = solve(nums, i + 1, p);
        if (p != -1)
            dp[i][p] = max(take, skip);
        return max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, -1);
    }
};


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int masLis = 1;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    masLis = max(masLis, dp[i]);
                }
            }
        }
        return masLis;
    }
};
