class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1000000007;
        int n = s.size();

        vector<int> digit;
        vector<int> pos;

        //Store non-zero digits and their positions
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                digit.push_back(s[i] - '0');
                pos.push_back(i);
            }
        }

        int k = digit.size();

        //prefix sum of digits
        vector<long long> prefSum(k + 1, 0);

        //prefix concatenated number
        vector<long long> prefNum(k + 1, 0);

        //powers of 10
        vector<long long> pow10(k + 1, 1);

        for (int i = 1; i <= k; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        for (int i = 0; i < k; i++) {
            prefSum[i + 1] = prefSum[i] + digit[i];
            prefNum[i + 1] = (prefNum[i] * 10 + digit[i]) % MOD;
        }

        //first non-zero digit index >= i
        vector<int> first(n, -1);
        int p = 0;
        for (int i = 0; i < n; i++) {
            while (p < k && pos[p] < i)
                p++;
            if (p < k)
                first[i] = p;
        }

        //last non-zero digit index <= i
        vector<int> last(n, -1);
        p = k - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (p >= 0 && pos[p] > i)
                p--;
            if (p >= 0)
                last[i] = p;
        }

        vector<int> ans;

        for (auto &q : queries) {

            int l = first[q[0]];
            int r = last[q[1]];

            if (l == -1 || r == -1 || l > r) {
                ans.push_back(0);
                continue;
            }

            int len = r - l + 1;

            long long x =
                (prefNum[r + 1] -
                 prefNum[l] * pow10[len] % MOD +
                 MOD) % MOD;

            long long sum = prefSum[r + 1] - prefSum[l];

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};

//TLE
//class Solution {
// public:
//     vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

//         vector<int> ans;
//         int mod = 1000000007;
//         for(auto it : queries){
//             string str = s.substr(it[0], it[1] - it[0] + 1);
//             long long num =0;
//             int sum = 0;

//             for(char ch : str){
//                 if(ch!='0'){
//                     num = (num*10 + (ch -'0'))%mod;
//                     sum +=ch-'0';
//                 }
//             }          
//             ans.push_back((num*sum)%mod);
//         }
//         return ans;
//     }
// };


