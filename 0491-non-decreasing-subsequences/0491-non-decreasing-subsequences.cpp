class Solution {
public:
    vector<vector<int>> ans;

    void solve(int ind , vector<int> &path ,int n , vector<int> &nums){
        if(path.size()>=2){
            ans.push_back(path);
            
        }
        set<int> used;

        for(int i  = ind;i<n;i++){
            if(used.count(nums[i])){
                continue;
            }
            used.insert(nums[i]);
            if(path.empty()|| nums[i]>=path.back()){
                path.push_back(nums[i]);
            
            
            solve(i+1 , path  , n , nums);
            path.pop_back();
            }

        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>path;

        solve(0 , path , nums.size() , nums);
        return ans;
        
    }
};