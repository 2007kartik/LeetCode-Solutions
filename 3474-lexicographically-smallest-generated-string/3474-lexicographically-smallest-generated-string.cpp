class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int len = n + m - 1;

        string ans(len, 'a');
        vector<bool> fixed(len, false);

        // Handle all T constraints
        for (int i = 0; i < n; i++) {
            if (str1[i] != 'T') continue;

            for (int j = 0; j < m; j++) {
                int p = i + j;

                if (fixed[p] && ans[p] != str2[j])
                    return "";

                ans[p] = str2[j];
                fixed[p] = true;
            }
        }

        // Handle all F constraints
        for (int i = 0; i < n; i++) {
            if (str1[i] != 'F') continue;

            bool same = true;

            for (int j = 0; j < m; j++) {
                if (ans[i + j] != str2[j]) {
                    same = false;
                    break;
                }
            }

            if (!same) continue;

            // Break this match at the rightmost non-fixed position
            int pos = -1;

            for (int j = i + m - 1; j >= i; j--) {
                if (!fixed[j]) {
                    pos = j;
                    break;
                }
            }

            if (pos == -1)
                return "";

            ans[pos] = 'b';
            fixed[pos] = true;
        }

        return ans;
    }
};