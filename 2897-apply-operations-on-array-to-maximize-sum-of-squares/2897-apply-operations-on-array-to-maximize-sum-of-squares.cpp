
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        int cnt[31] = {0};

        // Count set bits at every position
        for (int num : nums) {
            for (int bit = 0; bit < 31; bit++) {
                if ((num >> bit) & 1) {
                    cnt[bit]++;
                }
            }
        }

        long long ans = 0;

        // Construct k maximum numbers greedily
        for (int i = 0; i < k; i++) {
            long long x = 0;

            for (int bit = 0; bit < 31; bit++) {
                if (cnt[bit] > 0) {
                    x |= (1LL << bit);
                    cnt[bit]--;
                }
            }

            ans = (ans + x * x) % MOD;
        }

        return (int)ans;
    }
};
