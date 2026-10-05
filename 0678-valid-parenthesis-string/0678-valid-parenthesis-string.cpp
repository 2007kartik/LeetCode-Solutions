class Solution {
public:
    vector<vector<int>> dp;
    bool solve(int idx , int bal , int sz  , string &str){
        if(bal<0) return false;
        if(idx==str.size()){
            return bal==0;
        }
        if(dp[idx][bal]!=-1) return dp[idx][bal];
        bool ans = false;
        if(str[idx]=='('){
            ans = solve(idx+1 , bal+1 , sz , str);
        }
        else if(str[idx]==')'){
            ans = solve(idx+1 , bal-1 , sz , str);
        }
        //now here *
        else{
            bool open = solve(idx+1 , bal+1 , sz , str);
            bool close = solve(idx+1 , bal-1 ,sz , str);
            bool empty = solve(idx+1 , bal , sz , str);
            
            ans = open||close||empty;
        }
        return dp[idx][bal]  = ans;
    }
    bool checkValidString(string s) {

        int sz = s.size();
        dp.assign(sz , vector<int>(sz ,-1));
       return solve(0 , 0 , sz , s);
        
        
    }
};