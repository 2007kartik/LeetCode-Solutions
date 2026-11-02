class Solution {
public:
    vector<int> dp;
    int solve(int idx , vector<int>&sv  , int sz){
        if(idx>=sz) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int curr_sum = 0;
        int max_diff = -INT_MAX;
        for(int x = idx ; x<min(idx +3 , sz);x++){
            curr_sum += sv[x];
            int diff = curr_sum - solve(x+1 , sv , sz);
            max_diff = max(max_diff , diff);
        }

        return dp[idx] = max_diff;
    }
    string stoneGameIII(vector<int>& sv) {

        int sz = sv.size();
        dp.resize(sz , -1);
    
        int res = solve(0 , sv , sz);
        if(res==0) return "Tie";
        else if(res>0) return "Alice";
        return "Bob";
        
    }
};