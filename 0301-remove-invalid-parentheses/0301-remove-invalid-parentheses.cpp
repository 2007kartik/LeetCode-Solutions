class Solution {
public:
    vector<string> ans;
    unordered_set<string> st;
    void solve(int idx , int open  , int rcnt , string &s , string &tar){
        if(idx==s.size()){
            if(rcnt==0 && open ==0){
                if(!st.count(tar)){
                    st.insert(tar);
                    ans.push_back(tar);
                }
            }
            return ;
        }

        if(s[idx]=='('|| s[idx]==')'){
            //skip para
            if(rcnt>0){
                solve(idx+1 , open , rcnt-1 , s , tar);
            }
            if(s[idx]=='('){
                tar.push_back('(');
                solve(idx+1 , open+1 , rcnt , s , tar);
                tar.pop_back();
            }
            else if(s[idx]==')'){
                if(open>0){
                     tar.push_back(')');
                    solve(idx+1 , open -1  , rcnt , s, tar);
                    tar.pop_back();
                }
            }
        }
        else{
             tar.push_back(s[idx]);
            solve(idx+1 , open , rcnt ,s , tar);
            tar.pop_back();
        }
        

    }
    vector<string> removeInvalidParentheses(string s) {

        int para_to_del = 0;
        int bal = 0;
        for(char ch : s){
            if(ch=='('){
                bal++;
            }
            else if(ch==')'){
                if(bal>0) bal--;
                else{
                    para_to_del++;
                }
            }
        }

        para_to_del += bal;
        string tar = "";
        solve(0 , 0 , para_to_del , s , tar);
        return ans;

        
         


        
    }
};