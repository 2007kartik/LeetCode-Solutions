class Solution {
public:
    int minMoves2(vector<int>& nums) {

        sort(nums.begin() , nums.end());
        int middle = nums[nums.size()/2];

        int sum = 0;
        for(int x : nums){
            sum += abs(x - middle);
        }
        return sum;
    }
};