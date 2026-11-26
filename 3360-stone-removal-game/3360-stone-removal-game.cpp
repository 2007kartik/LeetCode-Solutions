
class Solution {
public:
    bool canAliceWin(int n) {
        int miinus = 10;
        bool check = false;

        while (n >= miinus) {
            n -= miinus;
            miinus--;
            check = !check;
        }

        return check;
    }
};
