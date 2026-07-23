class Solution {
public:

 bool solve(int i, int j, int k, vector<int>& nums, int sz) {

        
        for (int t = i; t < i + k - 1; t++) {
            if (nums[t] >= nums[t + 1])
                return false;
        }

       
        for (int t = j; t < j + k - 1; t++) {
            if (nums[t] >= nums[t + 1])
                return false;
        }

        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int sz = nums.size();

        for(int i =0;i+2*k<=sz;i++){

            if(solve(i , i+k  , k , nums , sz)) return true;

        }
        return false;
    }
};