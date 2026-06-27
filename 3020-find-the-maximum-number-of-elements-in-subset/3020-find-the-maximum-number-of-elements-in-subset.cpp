class Solution {
public:
    int maximumLength(vector<int>& nums) {

        unordered_map<long long  , int > freq;

        for(int num : nums){
            freq[num]++;
        }
        int ans = 1;
        //case of 1
        if(freq.count(1)){
            if(freq[1]%2==0) ans = max(ans , freq[1]-1);
            else ans = max(ans , freq[1]);
        }

        for(auto &[x , cnt] : freq){
            if(x==1) continue;
            long long curr = x;
            int len = 0;
            while(freq.count(curr)&& freq[curr]>=2){
                len += 2;
                //overflow cnd
                if(curr>1000000000LL/curr) break;
                curr *= curr;
            }

            if(freq.count(curr)&& freq[curr]==1){
                len++;
            }
            else len--;

            ans = max(ans , len);
        }
        return ans;
    }
};