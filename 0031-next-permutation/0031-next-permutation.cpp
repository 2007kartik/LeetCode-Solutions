class Solution {
public:
    int check(vector<int> &nums , int idx , int sz , int target ){
        sort(nums.begin()+idx , nums.end());    
        for(int i = idx;i<sz;i++){
            if(nums[i]>target){
                return i;
            }
        }
        return sz-1;
    }
    void nextPermutation(vector<int>& nums) {
        int sz = nums.size();

        for(int i = sz-1;i>=0;i--){
            if(i>0 && nums[i-1]<nums[i]){
                int val_to_swap = nums[i-1];
                int idx2 = check(nums , i , sz , val_to_swap);
                swap(nums[i-1] , nums[idx2]);
                sort(nums.begin()+i , nums.end());

                break;
            }
            if(i==0){
                sort(nums.begin() , nums.end());
            }
        }
        
    }
};