class Solution {
public:
    bool canDivide(vector<int>&nums , int maxOp , int mid){
        int op = 0;
        for(int num : nums){

            op += (num-1)/mid;
            if(op>maxOp) return false;
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {

        int low = 1;
        int high = *max_element(nums.begin() , nums.end());
        int ans = high;

        while(low<=high){
            int mid = low +(high- low)/2;

            if(canDivide(nums , maxOperations , mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};