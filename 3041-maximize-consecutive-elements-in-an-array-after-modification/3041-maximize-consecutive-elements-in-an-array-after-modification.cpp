class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> dp;
        int ans = 0;

        for (int x : nums) {

            int take1 = dp[x - 1] + 1;
            int take2 = dp[x] + 1;

            dp[x] = max(dp[x], take1);
            dp[x + 1] = max(dp[x + 1], take2);

            ans = max({ans, dp[x], dp[x + 1]});
        }

        return ans;
    }
};