class Solution {
public:
    string reverseParentheses(string s) {
        int sz = s.size();
        stack<string> st;

        for (int i = 0; i < sz; i++) {

            if (s[i] == ')') {
                string temp = "";
                while (!st.empty() && st.top() != "(") {
                    temp += st.top();
                    st.pop();
                }
                reverse(temp.begin(), temp.end());
                if (!st.empty()) {
                    st.pop();
                }
               
                if (!temp.empty())st.push(temp);

               
            } 
            else {
                string t ;
                t.push_back(s[i]);
                st.push(t);               
            }
        }
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};