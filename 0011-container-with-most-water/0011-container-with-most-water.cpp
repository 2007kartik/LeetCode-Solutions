class Solution {
public:
    int maxArea(vector<int>& height) {

        int sz = height.size();
        int i  = 0;
        int j  = sz-1;
        int maxi  =INT_MIN;
        while(i<j){
            int min_val = min(height[i] , height[j]);
            maxi = max(maxi , min_val*(j - i));
            if(height[i]>height[j]) j--;
            else if(height[i]<height[j]) i++;
            else{
                i++;
                j--;
            }


         }

         return maxi;
        
    }
};