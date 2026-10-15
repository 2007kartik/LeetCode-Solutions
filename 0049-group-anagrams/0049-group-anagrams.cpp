class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<int> freq(26 ,0);
        unordered_map<string , vector<string>> mp;

        int sz = strs.size();

        for(int i  = 0;i< sz;i++){
            string str = strs[i];
            for(char ch : str){
                freq[ch - 'a']++;
            }
            string key = "";
            for(int k = 0;k<freq.size();k++){
                if(freq[k]>0){
                    while(freq[k]>0){
                        key += k + 'a';
                        freq[k]--;
                    }
                   
                }
            }
            mp[key].push_back(str);
            freq.assign(26 ,0);

        }
        vector<vector<string>> ans;
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
        
    }
};