class Solution {
public:

    bool isPalindrome(string &s, int i, int j,
                      vector<vector<int>>& dp) {

        // Base case
        if(i >= j)
            return true;

        // Already calculated
        if(dp[i][j] != -1)
            return dp[i][j];

        // First and last characters don't match
        if(s[i] != s[j])
            return dp[i][j] = false;

        // Check inside substring
        return dp[i][j] = isPalindrome(s, i + 1, j - 1, dp);
    }


    string longestPalindrome(string s) {

        int n = s.size();

        vector<vector<int>> dp(
            n,
            vector<int>(n, -1)
        );

        int start = 0;
        int maxLen = 1;

        // Generate every substring
        for(int i = 0; i < n; i++) {

            for(int j = i; j < n; j++) {

                if(isPalindrome(s, i, j, dp)) {

                    int len = j - i + 1;

                    if(len > maxLen) {
                        maxLen = len;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};