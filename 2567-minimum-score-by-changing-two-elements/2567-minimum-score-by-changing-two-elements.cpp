class Solution {
public:
    int minimizeSum(vector<int>& nums) {

        sort(nums.begin() , nums.end());
        int sz = nums.size();
        int maxi1 = nums[sz-1] - nums[2];

        int maxi2 = nums[sz-3] - nums[0];

        int maxi3 = nums[sz-2] - nums[1];

        return min({maxi1 , maxi2 , maxi3});

        
        
    }
};