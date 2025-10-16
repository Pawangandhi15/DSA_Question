// Given an array nums of n integers, your task is to find the maximum value of k for which there exist two adjacent subarrays of length k each, such that both subarrays are strictly increasing. Specifically, check if there are two subarrays of length k starting at indices a and b (a < b), where:

// Both subarrays nums[a..a + k - 1] and nums[b..b + k - 1] are strictly increasing.
// The subarrays must be adjacent, meaning b = a + k.
// Return the maximum possible value of k.

// A subarray is a contiguous non-empty sequence of elements within an array.

 

// Example 1:

// Input: nums = [2,5,7,8,9,2,3,4,3,1]

// Output: 3

// Explanation:

// The subarray starting at index 2 is [7, 8, 9], which is strictly increasing.
// The subarray starting at index 5 is [2, 3, 4], which is also strictly increasing.
// These two subarrays are adjacent, and 3 is the maximum possible value of k for which two such adjacent strictly increasing subarrays exist.
// Example 2:

// Input: nums = [1,2,3,4,4,4,4,5,6,7]

// Output: 2

// Explanation:

// The subarray starting at index 0 is [1, 2], which is strictly increasing.
// The subarray starting at index 2 is [3, 4], which is also strictly increasing.
// These two subarrays are adjacent, and 2 is the maximum possible value of k for which two such adjacent strictly increasing subarrays exist.



// brute force

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums, vector<int>& increasing, int k) {
        int n = nums.size();
        for (int i = k; i <= n - k; i++) {
            if (increasing[i] >= k && increasing[i + k] >= k) {
                return true;
            }
        }
        return false;
    }

    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        int low = 1;
        int high = n / 2;
        vector<int> increasing(n + 1, 1);

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                increasing[i + 1] += increasing[i];
            } else {
                increasing[i + 1] = 1;
            }
        }

        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(nums, increasing, mid)) {
                ans = max(ans, mid);
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    cout << "Enter number of elements: ";
    int n;
    cin >> n;

    cout << "Enter elements: ";
    nums.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = sol.maxIncreasingSubarrays(nums);
    cout << "Maximum k with two increasing subarrays of length k: " << result << endl;

    return 0;
}


// optimal approach

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int prevCount = 0;
        int currCount = 1;
        int maxi = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                currCount++;
            } else {
                prevCount = currCount;
                currCount = 1;
            }
            maxi = max(maxi, min(prevCount, currCount));
            maxi = max(maxi, currCount / 2);
        }

        return maxi;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    cout << "Enter number of elements: ";
    int n;
    cin >> n;

    cout << "Enter elements: ";
    nums.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = sol.maxIncreasingSubarrays(nums);
    cout << "Maximum k with two increasing subarrays of length k: " << result << endl;

    return 0;
}
