class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {

        //create a pair sum array
        // then sort the pair sum array
        //take the left k-1 and right k-1 elements that your min and max and then take diff of them 

        int n  = weights.size();
        int m   = n-1;
        vector<int>pairSum(m , 0);
        for(int i  = 0;i<m;i++){
            pairSum[i] = weights[i] + weights[i+1];
        }
        sort(pairSum.begin() , pairSum.end());

        long long minSum = 0;
        long long maxSum = 0;
        for(int i  = 0;i<k-1;i++){
            minSum += pairSum[i];
            maxSum += pairSum[m-1-i];
        }

        return maxSum-minSum;
    }
};