class Solution {
public:
    int sumCounts(vector<int>& nums) {

        int sz = nums.size();
        int sum = 0;
        for(int i  = 0;i<sz;i++){
            unordered_set<int> st;
            for(int j  = i;j<sz;j++){
                st.insert(nums[j]);
                int val  = st.size();
                sum += val*val;
            }          
        }
        return sum;
    }
};