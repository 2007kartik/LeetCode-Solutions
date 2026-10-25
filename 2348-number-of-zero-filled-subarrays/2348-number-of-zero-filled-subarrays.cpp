class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {

        int cZero = 0;
        long long cnt = 0;
        for(int i  = 0;i<nums.size();i++){
            if(nums[i]==0){
                cnt +=cZero +1;
                cZero++;
            }
            else{
                cZero = 0;
            }
        }

        return cnt;
        
    }
};