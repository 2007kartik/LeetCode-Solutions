class Solution {
public:
    vector<vector<bool>> dp;
    int countSubstrings(string s) {
        int sz = s.size();
        dp.assign(sz, vector<bool>(sz, false));
        int counter = 0;

        for (int L = 1; L <= sz; L++) {

            for (int i = 0; i + L - 1 < sz; i++) {
                int j = i + L - 1;
                if (i == j)
                    dp[i][j] = true;
                else if (i + 1 == j)
                    dp[i][j] = (s[i] == s[j]);
                else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }

                if (dp[i][j] == true)
                    counter++;
            }
        }

        return counter;
    }
};