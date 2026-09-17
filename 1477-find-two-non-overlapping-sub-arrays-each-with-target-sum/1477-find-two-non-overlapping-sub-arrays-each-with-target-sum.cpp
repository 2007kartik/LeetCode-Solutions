class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();
        int result = INT_MAX;
        int bestMin = INT_MAX;
        vector<int> minLenTillIdx(n , INT_MAX);
        int i  =0;
        int j  = 0;

        long long curr_sum = 0;

        while(j<n){
            curr_sum += arr[j];
            while(curr_sum>target){
                curr_sum -= arr[i];
                i++;
            }
            if(curr_sum==target){
                int len = j-i+1;
                if(i>0 && minLenTillIdx[i-1]!=INT_MAX){
                    result = min(result  , len +minLenTillIdx[i-1] );
                }
                bestMin = min(bestMin , len);
               

            }
             minLenTillIdx[j] = bestMin;
            j++;
        }

        return result==INT_MAX ? -1 : result ;
        
    }
};