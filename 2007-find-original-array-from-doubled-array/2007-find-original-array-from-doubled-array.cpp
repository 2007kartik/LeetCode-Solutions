class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {

        int sz = changed.size();
        if (sz % 2 == 1)
            return {};
        unordered_map<int, int> mp;
        for (int num : changed) {
            mp[num]++;
        }

        sort(changed.begin(), changed.end());
        vector<int> ans;

        for (int num : changed) {
            int twice = num * 2;
            if (mp[num] == 0)
                continue;
            else if (!mp.count(twice) || mp[twice] == 0)
                return {};

            else {
                ans.push_back(num);
                mp[num]--;
                mp[twice]--;
            }
        }
        return ans;
    }
};