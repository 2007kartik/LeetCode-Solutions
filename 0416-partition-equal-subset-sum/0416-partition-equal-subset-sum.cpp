class Solution {
public:
    //its a previous question where i have to find subset with equal sum as target
    //in addition with this prob , 
    //calculate tot_sum  , if its odd then false  , if even then pass tot_sum/2 as target 
    //if one partition found  , second partiion will also be form with the equal sum
    bool solve(int idx, int sum, int target, vector<int> &arr, int n,
               vector<vector<int>>& dp) {
         if (sum == target)
            return true;
        if (sum > target)
            return false;
        if (idx ==n)
            return false;
        if (dp[idx][sum] != -1)
            return dp[idx][sum];

        bool left = solve(idx + 1, sum + arr[idx], target, arr, n, dp);
        bool right = solve(idx + 1, sum, target, arr, n, dp);

        return dp[idx][sum] = left || right;
    }
    bool canPartition(vector<int>& nums) {

        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        if (sum % 2 == 1)
            return false;
        int sz = nums.size();
        vector<vector<int>>dp(sz , vector<int>((sum/2+1) ,-1));


        return solve(0,0, sum/2 , nums , sz , dp);
    }
};