
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freq(n + 1, 0);

        int minPrice = INT_MAX;

        // Step 1: Count frequency of each factor
        for (auto& item : items) {
            freq[item[0]]++;
            minPrice = min(minPrice, item[1]);
        }

        // Step 2: Calculate the number of free-item opportunities
        vector<int> gain(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                gain[i] += freq[j];
            }
            if (gain[i] > 0) {
                gain[i]--;
            }
        }

        // Step 3: Store profitable purchases
        vector<pair<int, int>> candidates;

        for (auto& item : items) {
            int factor = item[0];
            int price = item[1];

            if (gain[factor] > 0 && price < 2LL * minPrice) {
                candidates.push_back({price, gain[factor]});
            }
        }

        // Step 4: Sort by increasing price
        sort(candidates.begin(), candidates.end());

        // Step 5: Greedily purchase profitable items
        long long ans = 0;
        long long remaining = budget;

        for (auto& [price, count] : candidates) {
            long long buy = min(
                (long long)count,
                remaining / price
            );

            ans += 2LL * buy;
            remaining -= buy * price;
        }

        // Step 6: Purchase cheapest items with remaining budget
        ans += remaining / minPrice;

        return (int)ans;
    }
};
