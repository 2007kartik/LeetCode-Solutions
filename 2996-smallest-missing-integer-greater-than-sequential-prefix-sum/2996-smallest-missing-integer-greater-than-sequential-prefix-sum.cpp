class Solution {
public:
    int missingInteger(vector<int>& nums) {

        int val = 0;
        val  = nums[0];
        set<int> st(nums.begin() , nums.end());     
        for(int i  = 1;i<nums.size();i++){
                if(nums[i]==nums[i-1]+1){
                    val += nums[i];
                }
                else break;
        }

        while(st.count(val)){
            val++;
        }
        return val;
        
    }
};