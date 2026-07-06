class Solution {
public:
    int maxJump(vector<int>& stones) {

        int sz = stones.size();

        int ans = stones[1] - stones[0];
        for(int i =2;i<sz;i++){
            ans = max(ans , stones[i]-stones[i-2]);
        }
        return ans;
    }
};