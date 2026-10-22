class Solution {
public:
    int kadans_max(vector<int>&nums , int n){
        int sum = nums[0];
        int maxi = nums[0];
        for(int i  = 1;i<n;i++){
            sum  = max(sum + nums[i] , nums[i]);
            maxi = max(maxi , sum);
        }
        return maxi;
    }

    int kadans_min(vector<int> &nums , int n ){
        int sum = nums[0];
        int mini  = nums[0];
       for(int i  = 1;i<n;i++){
            sum  = min(sum + nums[i] , nums[i]);
            mini = min(mini , sum);
        }
        return mini;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int n  = nums.size();
        int sum = accumulate(nums.begin() , nums.end() , 0);

        int maxi_sum = kadans_max(nums , n);
        int min_sum = kadans_min(nums , n);

        int cir_sum  = sum - min_sum;

        if(maxi_sum>0) return max(maxi_sum , cir_sum);
        return maxi_sum;
    }
};