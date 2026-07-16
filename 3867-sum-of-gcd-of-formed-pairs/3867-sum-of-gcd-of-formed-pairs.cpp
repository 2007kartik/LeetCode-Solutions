class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }

        return a;
    }
    long long gcdSum(vector<int>& nums) {

        int sz = nums.size();
        int preSum = 0;
        vector<int> GCD(sz);
        preSum = nums[0];
        GCD[0] = nums[0];
        for (int i = 1; i < sz; i++) {

            preSum = max(preSum, nums[i]);
            GCD[i] = gcd(nums[i], preSum);
        }

        // sort
        sort(GCD.begin(), GCD.end());

        int n = GCD.size();
        long long sum = 0;
        int i = 0;
        int j = GCD.size() - 1;
        while (i < j) {
            sum += gcd(GCD[i], GCD[j]);
            i++;
            j--;
        }

        return sum;
    }
};