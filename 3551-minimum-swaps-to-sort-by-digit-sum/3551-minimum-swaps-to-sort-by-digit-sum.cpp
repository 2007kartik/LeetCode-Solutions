#include<tuple>;
class Solution {
public:
    int get_digit_sum(int num) {
        int sum = 0;
        while (num > 0) {
            int lst = num % 10;
            sum += lst;
            num /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {

        int sz = nums.size();

        vector<int> digitSum;
        vector<tuple<int, int, int>> arr;
        int i  = 0;
        for (int num : nums) {
            int original = num;
            arr.push_back({get_digit_sum(num), num, i++});
        }

        sort(arr.begin(), arr.end());
        vector<int > mapped(sz);
        for (int i = 0; i < sz; i++) {
            int originalIdx = get<2>(arr[i]);

            mapped[originalIdx] = i;
        }

        vector<bool> visited(sz, false);
        int cycles = 0;

        for (int i = 0; i < sz; i++) {
            if (visited[i])
                continue;

            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = mapped[j];
            }

            cycles++;
        }

        return sz - cycles;
    }
};