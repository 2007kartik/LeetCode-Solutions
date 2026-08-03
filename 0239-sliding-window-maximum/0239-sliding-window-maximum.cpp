class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int  , int>> q;
        int sz = nums.size();
        for(int i  = 0;i< sz;i++){
            q.push({nums[i] , i});
            if(i<k-1) continue;
            while(!q.empty()&& q.top().second<=i-k){
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }           
};