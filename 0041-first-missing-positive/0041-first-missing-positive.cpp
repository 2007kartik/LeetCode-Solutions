class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int n = nums.size();
        for(int i=0;i<n;){
            long long correctIdx = 0LL+nums[i] - 1;
           if(nums[i]>0 && nums[i]<=n && nums[i]!=nums[correctIdx]){
            swap(nums[i] , nums[correctIdx]);
           }
           else{
            i++;
           }
           
        }

        for(int i = 0;i<nums.size();i++){
            //check no at correct position
            if(nums[i]!=i+1) return i+1;
        }
        return n+1;
    }
};