class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        map<int, int> mp;
        for (int x : nums) {
            mp[x]++;
        }
        int miss = 0;
        int dup = 0;
        int k = 1;
          for (auto& it : mp) {
            if (it.second > 1) {
                dup = it.first;
                break;
            }
        }

        for (auto& it : mp) {
            if (it.first != k) {
                miss = k;
                break;
            }
            k++;
        }

          if (miss == 0 && k <= nums.size()) {
            miss = k;
        }

        return {dup, miss};
    }
};