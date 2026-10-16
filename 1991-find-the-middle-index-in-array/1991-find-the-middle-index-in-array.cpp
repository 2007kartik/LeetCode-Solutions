class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
         int sz = nums.size();
        vector<int> pref(sz+1 , 0);
        vector<int> suff(sz+1 , 0);
        pref[0] = nums[0];
        suff[sz-1] = nums[sz-1];

        for(int i =1;i<sz;i++){
            pref[i] = pref[i-1]+nums[i];
        }
        for(int i = sz-2;i>=0;i--){
            suff[i] = suff[i+1]+nums[i];
        }

        for(int i  = 0;i<sz;i++){
            if(pref[i]==suff[i]) return i;
        }
        return -1;
        
    }
};