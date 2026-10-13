class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        long long left = 0;
        long long right = 0;
        long long sz = nums.size();

        for(int x  = 0;x<sz;x++){
            if(nums[x]<0){
                nums[x] =  nums[x]* (-1);

            }
        }

      //  for(int x  :nums) cout<< x <<" ";

     //   for(int x : nums)

        sort(nums.begin() , nums.end() , greater<int>());
                for(int x  :nums) cout<< x <<" ";

        long long div = 0;
        if(sz%2==0) div = sz/2;
        else div = (sz/2)+1;
        for(long long i  = 0;i<div;i++){
            left += nums[i] *  nums[i];
        }
        long long j = div;
        for(long long k  = j ;k<sz;k++){
            right += nums[k] * nums[k];
        }

        return left - right;
        
    }
};