// You are given an array of words where each word consists of lowercase English letters.

// wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

// For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
// A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

// Return the length of the longest possible word chain with words chosen from the given list of words.

 

// Example 1:

// Input: words = ["a","b","ba","bca","bda","bdca"]
// Output: 4
// Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
// Example 2:

// Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
// Output: 5
// Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
// Example 3:

// Input: words = ["abcd","dbqca"]
// Output: 1
// Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
// ["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
 

// Constraints:

// 1 <= words.length <= 1000
// 1 <= words[i].length <= 16
// words[i] only consists of lowercase English letters.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int dp[1001][1001];

    bool isPrec(string& prev_word, string& curr_word) {
        int M = prev_word.length();
        int N = curr_word.length();

        if (M >= N || N - M != 1) {
            return false;
        }

        int i = 0, j = 0;
        while (i < M && j < N) {
            if (prev_word[i] == curr_word[j])
                i++;

            j++;
        }

        return i == M;
    }

    static bool myfunction(string& word1, string& word2) {
        return word1.length() < word2.length();
    }

    int solve(vector<string>& nums, int i, int p) {
        if (i == n) {
            return 0;
        }
        
        if (p != -1 && dp[i][p] != -1) {
            return dp[i][p];
        }
        
        int take = 0;
        if (p == -1 || isPrec(nums[p], nums[i])) {
            take = 1 + solve(nums, i + 1, i);
        }
        
        int skip = solve(nums, i + 1, p);
        
        if (p != -1)
            dp[i][p] = max(take, skip);
        
        return max(take, skip);
    }

    int longestStrChain(vector<string>& words) {
        n = words.size();
        sort(begin(words), end(words), myfunction);
        memset(dp, -1, sizeof(dp));
        
        return solve(words, 0, -1);
    }
}; 





class Solution {
public:
    int n;
    static bool myfunction(string& word1, string& word2) {
        return word1.length() < word2.length();
    }

    bool isPrec(string& prev_word, string& curr_word) {
        int M = prev_word.length();
        int N = curr_word.length();

        if (M >= N || N - M != 1) {
            return false;
        }

        int i = 0, j = 0;
        while (i < M && j < N) {
            if (prev_word[i] == curr_word[j])
                i++;

            j++;
        }

        return i == M;
    }

    int longestStrChain(vector<string>& words) {
        n = words.size();
        sort(begin(words), end(words), myfunction);
        vector<int> dp(n,1);

        int maxl=1;

        for(int i = 0 ;i<n;i++){
            for(int j =0;j<i;j++){
                if (isPrec(words[j], words[i])){
                    dp[i] =  max (dp[i], dp[j]+1);
                    maxl = max(dp[i], maxl) ;
                }
            }
        }
        return maxl;
    }
};
