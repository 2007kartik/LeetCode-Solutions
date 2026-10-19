class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int sz = nums.size();
        vector<long long> pref(sz);
        pref[0] = nums[0];
        for(int i  = 1;i<sz;i++){
            pref[i] = pref[i-1]+nums[i];
        }
        //now the prefix sum array is created 
        unordered_map<int , int>mp;
        int idx = 0;
        int mini = INT_MAX;
        for(int i  = 0;i<sz;i++){
            int k  = i+1;
            int left = pref[i]/k;
            int right =0;
            if(sz-1-i!=0){
             right = (pref[sz-1] - pref[i]) /  (sz-1-i);
            }
            int diff = abs(left - right);
            if(mini>diff){
                mini = diff;
                idx = i;
            }
            
        }
       

        return idx;        
    }
};