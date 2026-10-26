class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {

        int sz = nums.size();
        vector<int> ans(sz , -1);
        int div = 2*k+1;
        if((k*2+1)>sz) return ans;

        long long preSum = 0;
        long long suffSum = 0;
        int idx = 0;
        while(idx<=k){
            preSum += nums[idx];
            idx++;
        }
        while(idx<=2*k){
            suffSum += nums[idx];
            idx++;
        }
        ans[k] = (preSum+suffSum)/div;

        for(int i = k+1;i<sz-k;i++){
            preSum -= nums[i-k-1];
            suffSum += nums[i+k];
            int avg = (preSum+suffSum)/div;
            ans[i] = avg;
        }



        return ans;
    }
};