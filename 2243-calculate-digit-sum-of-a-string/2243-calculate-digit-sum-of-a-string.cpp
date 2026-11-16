class Solution {
public:
    string digitSum(string s, int k) {
        
     
    //    if(s.size()>k) return s;
        
        while(s.size()>k){
         
         
           string str = "";
           int sz = s.size();
            int i = 0;
            for(i = 0;i<s.size();i = i+k){
                    int sum = 0;
                  
                    for(int j = i;j<min(i+k , sz);j++){
                        sum += s[j]-'0';
                    }
                    str += to_string(sum);
            }
           
           
            s = str;
        }

        return s;
    }
};