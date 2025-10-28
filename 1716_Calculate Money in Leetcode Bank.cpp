// Hercy wants to save money for his first car. He puts money in the Leetcode bank every day.

// He starts by putting in $1 on Monday, the first day. Every day from Tuesday to Sunday, he will put in $1 more than the day before. On every subsequent Monday, he will put in $1 more than the previous Monday.

// Given n, return the total amount of money he will have in the Leetcode bank at the end of the nth day.

// Example 1:

// Input: n = 4
// Output: 10
// Explanation: After the 4th day, the total is 1 + 2 + 3 + 4 = 10.
// Example 2:

// Input: n = 10
// Output: 37
// Explanation: After the 10th day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4) = 37. Notice that on the 2nd Monday, Hercy only puts in $2.
// Example 3:

// Input: n = 20
// Output: 96
// Explanation: After the 20th day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4 + 5 + 6 + 7 + 8) + (3 + 4 + 5 + 6 + 7 + 8) = 96.

// Constraints:

// 1 <= n <= 1000

#include <bits/stdc++.h>
using namespace std;

// TC= O(n)

class Solution
{
public:
    int totalMoney(int n)
    {
        int sum = 0;
        int mon_money = 1;
        while (n > 0)
        {
            int money = mon_money;
            for (int i = 1; i <= min(n, 7); i++)
            {
                sum += money;
                money++;
            }
            n = n - 7;
            mon_money++;
        }
        return sum;
    }
};


// TC= O(1)
class Solution
{
public:
    int totalMoney(int n)
    {
        int terms = n / 7; // no of weeks
        int first = 28;
        int last = 28 + (terms - 1) * 7; // AP formnula for last term
        int sum = terms * (first + last) / 2; // sum of nth term in the AP 

        // final week ==> (remaining days)
        int start_money = 1 + terms;
        for (int day = 1; day <= (n % 7); day++) //{0,1,2,3,4,5,6  --> constanst}
        {
            sum += start_money;
            start_money++;
        }
        return sum;
    }
};