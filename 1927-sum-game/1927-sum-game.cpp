class Solution {
public:
    bool sumGame(string num) {
        int sz = num.size();
       int left_sum = 0;
       int right_sum = 0;
       int leftQ = 0;
       int rightQ = 0;

       for(int i  = 0;i<sz/2;i++){
            if(num[i]=='?'){
                leftQ++;
                continue;
            }
            left_sum += num[i]-'0';
       }
       for(int i  = sz/2;i<sz;i++){
            if(num[i]=='?'){
                rightQ++;
                continue;
            }
            right_sum += num[i]-'0';
       }

       if((leftQ+rightQ)%2==1) return true;
       return (left_sum-right_sum) != 9*(rightQ-leftQ)/2;
    }
};