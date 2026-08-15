class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> freq(26 ,0);
        int l = 0;
        int r = 0;
        int maxi = INT_MIN;

    while(r<s.size()){
            freq[s[r]-'a']++;
            while(freq[s[r]-'a']>2){
                freq[s[l]-'a']--;
                l++;
            }

            maxi = max(maxi , r-l+1);

            r++;
        }

        return maxi;
    }
};