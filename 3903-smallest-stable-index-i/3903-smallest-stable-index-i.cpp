class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int stable = INT_MAX;
        int largest = INT_MIN;

        int pos = -1;

        for (int i = 0; i < nums.size(); i++) {

            largest = max(largest, nums[i]);

            int mini = INT_MAX;

            for (int j = i; j < nums.size(); j++) {

                mini = min(mini, nums[j]);
            }

            int sub = largest - mini;

            if (sub<=k) {

                return i;
            }
        }
        return -1;

    }
};