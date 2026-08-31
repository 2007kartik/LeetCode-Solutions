class Solution {
public:

    // Checks whether:
    // word[i ... i + m - 1] == str2
    bool isSame(string &word, string &str2, int i, int m) {

        for (int j = 0; j < m; j++) {

            if (word[i + j] != str2[j]) {
                return false;
            }
        }

        return true;
    }


    string generateString(string str1, string str2) {

        int n = str1.length();
        int m = str2.length();

        int N = n + m - 1;

        // Initially all positions are '$'
        string word(N, '$');

        // true means this position can still be changed
        vector<bool> canChange(N, false);


        // ------------------------------------------------
        // STEP 1: Process all 'T'
        // ------------------------------------------------

        for (int i = 0; i < n; i++) {

            if (str1[i] == 'T') {

                int i_ = i;

                for (int j = 0; j < m; j++) {

                    // If already fixed and different -> impossible
                    if (word[i_] != '$' &&
                        word[i_] != str2[j]) {

                        return "";
                    }

                    word[i_] = str2[j];

                    i_++;
                }
            }
        }


        // ------------------------------------------------
        // STEP 2: Fill remaining positions with 'a'
        // ------------------------------------------------

        for (int i = 0; i < N; i++) {

            if (word[i] == '$') {

                word[i] = 'a';

                // This position was not fixed by T,
                // so we are allowed to change it later.
                canChange[i] = true;
            }
        }


        // ------------------------------------------------
        // STEP 3: Process all 'F'
        // ------------------------------------------------

        for (int i = 0; i < n; i++) {

            if (str1[i] == 'F') {

                // If the current substring is already
                // different from str2, F condition is satisfied.

                if (isSame(word, str2, i, m)) {

                    bool changed = false;


                    // We need to make this substring different.
                    //
                    // Start from the RIGHTMOST position because
                    // that gives the lexicographically smallest
                    // possible answer.

                    for (int k = i + m - 1; k >= i; k--) {

                        if (canChange[k] == true) {

                            word[k] = 'b';

                            changed = true;

                            break;
                        }
                    }


                    // Every character of this substring was
                    // fixed by a T condition.
                    //
                    // Therefore we cannot make it different.

                    if (changed == false) {

                        return "";
                    }
                }
            }
        }


        return word;
    }
};