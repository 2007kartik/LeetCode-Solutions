class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size()==1) return false;
        if(s.size()%2==1) return false;
        int lf = 0;

        for(int i  =0;i<s.size();i++){
            if(s[i]=='('){
                lf++;
            }
            else if(locked[i]=='0') lf++;
            else lf--;
        

        if(lf<0) return false;}
        
        int rt = 0;

        for(int i= s.size()-1;i>=0;i--){
            if(s[i]==')') rt++;
            else if(locked[i]=='0') rt++;
            else rt--;
        
        if(rt<0) return false;}


        return true;
    }
};