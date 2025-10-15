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
