class Solution {
public:
    int solve(int num , vector<int>&dp){
        if(num==0) return 1;
        if(num<0) return 0;

        if(dp[num]!=-1) return dp[num];

        int left = solve(num-1 , dp);
        int right = solve(num-2 , dp);

        return dp[num] =  left + right;
    }
    int climbStairs(int n) {

        vector<int> dp(n+1 , -1);
        return solve(n , dp);
        
    }
};