class Solution {
public:
    vector<string> findWords(vector<string>& words) {

        unordered_set<char> row1 = {'q','w','e','r','t','y','u','i','o','p'};
        unordered_set<char> row2 = {'a','s','d','f','g','h','j','k','l'};
        unordered_set<char> row3 = {'z','x','c','v','b','n','m'};

        vector<string> ans;

        for (string word : words) {

            int row = 0;

            char first = tolower(word[0]);

            if (row1.count(first))
                row = 1;
            else if (row2.count(first))
                row = 2;
            else
                row = 3;

            bool ok = true;

            for (char ch : word) {

                ch = tolower(ch);

                if (row == 1 && !row1.count(ch)) {
                    ok = false;
                    break;
                }

                if (row == 2 && !row2.count(ch)) {
                    ok = false;
                    break;
                }

                if (row == 3 && !row3.count(ch)) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                ans.push_back(word);
        }

        return ans;
    }
};