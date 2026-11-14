class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {

        int mini = INT_MAX;

        for(int i  = 0;i<nums.size();i++){
            int sum = 0;
            for(int j  = i;j<nums.size();j++){
                sum += nums[j];
                int len  = j - i+1;
                if(sum>0 && len>=l && len<=r ){
                    mini = min(mini , sum);
                }
                if(len>r) break;
            }
        }

        return mini==INT_MAX?-1:mini;
        
    }
};