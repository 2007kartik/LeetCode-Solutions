class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> pre(2*n+1,0);
        pre[n] = 1;
        int cnt = n;

        long long ans = 0;
        long long presum =0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==target){
                presum += pre[cnt];
                cnt++;
                pre[cnt]++;
            }
            else{
                cnt--;
                presum -=pre[cnt];
                pre[cnt]++;
            }
            ans += presum;
        }
        return ans;
    }
};