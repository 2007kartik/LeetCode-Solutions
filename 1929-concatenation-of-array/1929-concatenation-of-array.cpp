class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {

        int sz = nums.size();
        vector<int> ans;

        for(int i = 0;i<sz;i++){
            ans.push_back(nums[i]);
        }
         for(int i = 0;i<sz;i++){
            ans.push_back(nums[i]);
        }

        return ans;

        
    }
};