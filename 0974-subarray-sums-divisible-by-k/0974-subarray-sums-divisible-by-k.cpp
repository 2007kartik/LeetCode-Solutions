class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

       int count = 0;
       unordered_map<int , int> mp;
       mp[0] = 1;
       int preSum = 0;

       for(int num  : nums){
            preSum += num;
            int rem = preSum%k;
            if(rem<0){
                rem += k;
            }
            if(mp.count(rem)){
                count += mp[rem];
            }
            mp[rem]++;
       }

       return count;
    }
};