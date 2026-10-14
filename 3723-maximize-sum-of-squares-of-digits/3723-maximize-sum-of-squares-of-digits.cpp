class Solution {
public:
    string maxSumOfSquares(int num, int sum) {

        string ans = "";

        while(sum>0){
            
            for(int i  = 9;i>=0;i--){
                if((sum - i)>=0){
                    ans  += to_string(i);
                    sum -= i;
                    break;
                }
                
            }

        }
        cout<<ans;
        if(ans.size()>num) return "";
        else if(ans.size()<num){
            int rem_zero = num - ans.size();
            while(rem_zero>0){
                ans.push_back('0');
                rem_zero--;
            }
        }
        
        return ans;
        
    }
};