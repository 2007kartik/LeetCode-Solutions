class NumArray {
public:
vector<int> prefSum;
    NumArray(vector<int>& nums) {
        int sz = nums.size();
        prefSum.resize(sz+1);
        
        prefSum[0] = 0;
        for(int i = 0;i<sz;i++){
            prefSum[i+1] = prefSum[i]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {

        return prefSum[right+1] - prefSum[left];
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */