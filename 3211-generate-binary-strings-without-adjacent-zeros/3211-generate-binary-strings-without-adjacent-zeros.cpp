class Solution {
public:
    void solve(vector<string> &ans , string str,int n){        
        if(str.size()==n){
            ans.push_back(str);
            return;
        }

        solve(ans , str+"1" , n);
     
       if(str.empty()||str.back()=='1') {
        solve(ans , str+"0" , n);
       }
       
       
        
    }
    vector<string> validStrings(int n) {

        vector<string> ans;
        solve(ans , "",n);
        return ans;
        
    }
};