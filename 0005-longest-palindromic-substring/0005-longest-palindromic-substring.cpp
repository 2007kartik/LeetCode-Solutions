class Solution {
public:
    string longestPalindrome(string s) {
        
        int start = 0;
        int maxLen = 0;

        int n = s.size();
        for(int i =0;i<n;i++){
            //for odd length palindromic substring
            int left = i;
            int right  = i;
            while(left>=0 && right<n && s[left]==s[right]){
                if(maxLen<right-left+1){
                    maxLen = right-left+1;
                    start = left;
                }
                left--;
                right++;
            }

            //for even lenght palindromic substring
             left = i;
             right = i+1;
            while(left >= 0  && right < n && s[left]==s[right]){
                if(maxLen<right-left +1){
                    maxLen = right - left +1;
                    start   = left;
                }
                left--;
                right++;
            }
        }

        return s.substr(start , maxLen);
        
    }
};