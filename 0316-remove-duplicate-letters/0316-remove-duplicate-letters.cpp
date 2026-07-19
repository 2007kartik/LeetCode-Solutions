class Solution {
public:
    string removeDuplicateLetters(string s) {
          stack<char> st;
        unordered_map<char , int > mp;
        //take a last occurrences of each chars
        for(int i = 0;i<s.size();i++){
            mp[s[i]] = i; 
        }

        vector<bool> visited(26 , false);
        

        for(int i = 0;i<s.size();i++){

            char ch = s[i];

            if(visited[ch-'a']) continue;

            //remove larger character
            while(!st.empty() && st.top()>ch && mp[st.top()]>i){
                visited[st.top()-'a'] = false;
                st.pop();
            }

            st.push(ch);
            visited[ch-'a'] = true;
            
        }


        string ans = "";
        while(!st.empty()){
            char ch = st.top();
            st.pop();
            ans +=ch;
        }
        reverse(ans.begin() , ans.end());
        return ans;

        
        
    }
};