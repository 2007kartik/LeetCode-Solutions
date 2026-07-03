class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int tot_sum = nums[0];
        int maxKadane = nums[0];
        int minKadane = nums[0];

        int maxEnd = nums[0];
        int minEnd = nums[0];
        int sz = nums.size();
        for(int i = 1;i<sz;i++){
            tot_sum += nums[i];

            maxEnd = max(nums[i] , maxEnd + nums[i]);
            maxKadane = max(maxKadane , maxEnd);
            minEnd = min(nums[i] , minEnd + nums[i]);
            minKadane = min(minKadane , minEnd);

           



        }
         if(maxKadane <0){
                return maxKadane;
            }

            return max(maxKadane , tot_sum- minKadane);
        
    }
};