class Solution {
public:
    int sz;
    vector<vector<int>> t = vector<vector<int>>(301, vector<int>(5001, -1));
    int solve(int index, int amount, vector<int>& coins) {

        if (amount == 0)
            return 1;

        if (index == sz)
            return 0;

        if (t[index][amount] != -1)
            return t[index][amount];

        if (amount < coins[index])
            return t[index][amount] = solve(index + 1, amount, coins);

        int take = solve(index, amount - coins[index], coins);
        int skip = solve(index + 1, amount, coins);

        return t[index][amount] = take + skip;
    }

    int change(int amount, vector<int>& coins) {
        sz = coins.size();
        return solve(0, amount, coins);
    }
};