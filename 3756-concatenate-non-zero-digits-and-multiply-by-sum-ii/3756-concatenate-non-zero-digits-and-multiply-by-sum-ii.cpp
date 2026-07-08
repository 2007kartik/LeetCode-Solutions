class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        static const int MOD=1e9+7;
        int n=s.size();

         vector<int>cnt(n+1,0);
         vector<int>digit;
         for(int i=0;i<n;i++){
            cnt[i+1]=cnt[i];
            if(s[i]!='0'){
                digit.push_back(s[i]-'0');
                cnt[i+1]++;
            }
         }
         int m=digit.size();
         vector<long long>pow(m+1,1);
         for(int i=1;i<=m;i++){
            pow[i]=(pow[i-1]*10)%MOD;
         }
         vector<long long>prefstr(m+1,0);
         vector<long long>presum(m+1,0);
         for(int i=1;i<=m;i++){
            prefstr[i]=(prefstr[i-1]*10+digit[i-1])%MOD;
            presum[i]=presum[i-1]+digit[i-1];
         }
         vector<int>ans;
         for(auto &q:queries){
             int l=q[0];
             int r=q[1];

             int R=cnt[r+1]-1;
             int L=cnt[l];
             if(L>R){
                ans.push_back(0);
                continue;
             }
             int len=R-L+1;
             long long x=(prefstr[R+1]-prefstr[L]*pow[len])%MOD;
             if(x<0) x+=MOD;
             long long  sum= presum[R+1]-presum[L];

            ans.push_back((x*sum)%MOD);
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


