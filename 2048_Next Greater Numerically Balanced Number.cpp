// An integer x is numerically balanced if for every digit d in the number x, there are exactly d occurrences of that digit in x.

// Given an integer n, return the smallest numerically balanced number strictly greater than n.

// Example 1:

// Input: n = 1
// Output: 22
// Explanation:
// 22 is numerically balanced since:
// - The digit 2 occurs 2 times.
// It is also the smallest numerically balanced number strictly greater than 1.
// Example 2:

// Input: n = 1000
// Output: 1333
// Explanation:
// 1333 is numerically balanced since:
// - The digit 1 occurs 1 time.
// - The digit 3 occurs 3 times.
// It is also the smallest numerically balanced number strictly greater than 1000.
// Note that 1022 cannot be the answer because 0 appeared more than 0 times.
// Example 3:

// Input: n = 3000
// Output: 3133
// Explanation:
// 3133 is numerically balanced since:
// - The digit 1 occurs 1 time.
// - The digit 3 occurs 3 times.
// It is also the smallest numerically balanced number strictly greater than 3000.

// Constraints:

// 0 <= n <= 106

#include <bits/stdc++.h>
using namespace std;

// Brute Force

class Solution
{
public:
    bool check(int i)
    {
        string s = to_string(i);
        vector<int> count(10, 0);
        for (char c : s)
        {
            count[c - '0']++;
            if (c == '0')
            {
                return false;
            }
        }

        for (int i = 1; i <= 9; i++)
        {
            if (count[i] > 0 && i != count[i])
            {
                return false;
            }
        }
        return true;
    }
    int nextBeautifulNumber(int n)
    {
        const int maxval = 1224444;
        for (int i = n + 1; i < maxval + 1; i++)
        {
            if (check(i))
            {
                return i;
            }
        }
        return -1;
    }
};

// recursion way...

class Solution
{
public:
    set<int> balanced;
    bool flag = true;

    void solve(set<string> &v, string s, int digit)
    {
        if (s.size() > 7 || digit > 7)
        {
            return;
        }

        if (s.size() > 0)
        {
            v.insert(s);
        }
        // Take
        string temp = s;
        for (int i = 1; i <= digit; i++)
        {
            temp += (digit + '0');
        }
        solve(v, temp, digit + 1);

        // skip
        solve(v, s, digit + 1);
    }
    void precompute()
    {
        set<string> v;
        solve(v, "", 1);
        for (string s : v)
        {
            string val = s;
            balanced.insert(stoi(s));
            while (next_permutation(val.begin(), val.end()))
            {
                balanced.insert(stoi(val));
            }
        }
    }
    int nextBeautifulNumber(int n)
    {
        if (flag)
        {
            precompute();
            flag = false;
        }
        auto it = balanced.upper_bound(n);
        return *it;
    }
};