// Given an m x n matrix, return all elements of the matrix in spiral order.

// Example 1:

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]
// Example 2:

// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0, down = m - 1;
        int left = 0, right = n - 1;
        int dir = 0; // 0:→, 1:↓, 2:←, 3:↑

        vector<int> res;

        while (top <= down && left <= right)
        {
            if (dir == 0)
            {
                // left → right
                for (int i = left; i <= right; i++)
                {
                    res.push_back(matrix[top][i]);
                }
                top++;
            }
            else if (dir == 1)
            {
                // top → bottom
                for (int i = top; i <= down; i++)
                {
                    res.push_back(matrix[i][right]);
                }
                right--;
            }
            else if (dir == 2)
            {
                // right → left
                for (int i = right; i >= left; i--)
                {
                    res.push_back(matrix[down][i]);
                }
                down--;
            }
            else if (dir == 3)
            {
                // bottom → top
                for (int i = down; i >= top; i--)
                {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
            dir = (dir + 1) % 4; // move to next direction
        }

        return res;
    }
};
