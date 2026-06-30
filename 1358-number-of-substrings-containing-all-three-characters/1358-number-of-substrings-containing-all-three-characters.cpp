class Solution {
public:
    int numberOfSubstrings(string s) {

        int sz = s.size();
        int total = 0;

        for(int i = 0;i<sz;i++){
            int countA = 0;
            int countB = 0;
            int countC = 0;
            for(int j = i;j<sz;j++){
                if(s[j]=='a'&&countA==0){
                    countA++;                   
                }
                else if(s[j]=='b'&&countB==0){
                    countB++;
                }
                else if(s[j]=='c'&&countC==0){
                    countC++;
                }

                if(countA+countB+countC==3){
                    
                        total += sz-j;
                        break;
                    
                }

            }
        }

        return total;
        
    }
};