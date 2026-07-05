class Solution {
public:
    int fib(int n) {

        //use of prev and prev2 variables and make job done
        if(n==0||n==1) return n;
        int prev = 1 , prev2 = 0;
        int curr;
        for(int i = 2;i<=n;i++){
            curr = prev+prev2;
            prev2 = prev;
            prev = curr;
        }

        return curr;
        
    }
};