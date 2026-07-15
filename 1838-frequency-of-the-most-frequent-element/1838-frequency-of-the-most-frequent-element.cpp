class Solution {
public:

    int bSearch(int target_idx , int k , vector<int>&nums , vector<long> &ps){

        int l = 0;
        int r = target_idx;

        int best_idx = target_idx;

        while(l<=r){
            int mid = l+(r-l)/2;
            long count = target_idx - mid+1;

            long  windowSum =count*nums[target_idx];
            long curr_sum = ps[target_idx] - ps[mid]+nums[mid]; 

            long ops = windowSum - curr_sum;
            if(ops>k){
                l =mid+1;
            }
            else{
                best_idx = mid;
                r = mid-1;
            }
        }

        return target_idx - best_idx +1;

    }

    int maxFrequency(vector<int>& nums, int k) {

        int n = nums.size();
        int result = 0;
        sort(nums.begin() , nums.end());

        //prefix sum to calculate the current window sum;

        vector<long> prefsum(n);
        prefsum[0] = nums[0];
        for(int i = 1;i<n;i++){
            prefsum[i] = prefsum[i-1]+nums[i];
        }

        for(int i =0;i<n;i++){

            int freq = bSearch(i , k , nums , prefsum);
            result = max(freq , result);
        }
        return result;
    }
};