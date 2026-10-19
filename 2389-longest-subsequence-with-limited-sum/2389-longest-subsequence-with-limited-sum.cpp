class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {

        sort(nums.begin(), nums.end());
        int sz = nums.size();
        vector<int> pref(sz);
        pref[0] = nums[0];
        for (int i = 1; i < sz; i++) {
            pref[i] = pref[i - 1] + nums[i];
        }
        // now the prefix sum array is created

        vector<int> res;
        for (int x : queries) {
            auto it = lower_bound(pref.begin(), pref.end(), x);
            int idx = it - pref.begin();
            if (it == pref.end()) {
                res.push_back(sz);
            } else {
                if (pref[idx] > x) {
                    idx--;
                }
                res.push_back(idx + 1);
            }
        }
        return res;
    }
};