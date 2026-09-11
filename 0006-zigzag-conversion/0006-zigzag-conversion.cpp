class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows==1 || numRows>=s.size()) return s;

        vector<string> rows(numRows);

        int r =0;
        int dir = 1;
        
        for(char ch : s){
            rows[r] += ch;
            if(r==0){
                dir =1;
            }
            else if(r==numRows-1){
                dir = -1;
            }
            r += dir;
        }

        string ans = "";
        for(string ch: rows){
            ans +=ch;
        }
        return ans;
    }
};