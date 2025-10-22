// You are given an integer array nums and two integers k and numOperations.

// You must perform an operation numOperations times on nums, where in each operation you:

// Select an index i that was not selected in any previous operations.
// Add an integer in the range [-k, k] to nums[i].
// Return the maximum possible frequency of any element in nums after performing the operations.

 

// Example 1:

// Input: nums = [1,4,5], k = 1, numOperations = 2

// Output: 2

// Explanation:

// We can achieve a maximum frequency of two by:

// Adding 0 to nums[1], after which nums becomes [1, 4, 5].
// Adding -1 to nums[2], after which nums becomes [1, 4, 4].
// Example 2:

// Input: nums = [5,11,20,20], k = 5, numOperations = 1

// Output: 2

// Explanation:

// We can achieve a maximum frequency of two by:

// Adding 0 to nums[1].
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109
// 0 <= k <= 109
// 0 <= numOperations <= nums.length

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        int ans = 0;

        // Step 1: Create frequency array safely
        vector<int> freq(maxi + 2, 0);  // +2 to handle r+1 edge cases
        for (int i : nums)
            freq[i]++;

        // Step 2: Prefix sum for cumulative frequency
        for (int i = 1; i <= maxi; i++)
            freq[i] += freq[i - 1];

        // Step 3: Try each possible current number
        for (int curr = mini; curr <= maxi; curr++) {
            int l = max(mini, curr - k);
            int r = min(maxi, curr + k);

            int f = freq[curr] - (curr > 0 ? freq[curr - 1] : 0);

            int totalInRange = freq[r] - (l > 0 ? freq[l - 1] : 0);

            int possibleExtra = totalInRange - f;

            int extra = min(numOperations, possibleExtra);

            ans = max(ans, f + extra);
        }

        return ans;
    }
};
