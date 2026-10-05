class Solution {
public:
    int scoreOfParentheses(string s) {
        int sum = 0;
        int depth = 0;
        for(int i = 0 ;i< s.size();i++){
            if(s[i]=='('){
                depth++;
            }
            else{
                if(s[i-1]=='('){
                    int val = 1;
                    for(int j = 0;j<depth-1;j++){
                        val *=2;
                    }
                    sum += val;
                }
                depth--;

            }
        }
        return sum;
    }
};