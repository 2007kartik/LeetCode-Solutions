class Solution {
public:
    int missingInteger(vector<int>& nums) {

        if(nums.size()==1){
            return nums[0]+1;
        }
        else if(nums.size()==0){
            return 0;
        }

        int val = 0;
        int k  = 1;

        int maxi = 0;
        int maxi_k = 0;
        val = nums[0];
        set<int> st(nums.begin() , nums.end());


        for(int i  = 1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                k++;
                val += nums[i];
            }
            else break;
            // else{

            //     if(maxi_k <= k && val > maxi){
            //           maxi = max(maxi , val);
            //           maxi_k = max(maxi_k , k);
            //     }

            //     k = 1;
            //     val = nums[i];
              
            // }

        }
        // if(maxi==0 && maxi_k==0){
        //     maxi = val;
        //     maxi_k = k;
        // }

    //    for(int i  = 0;i<nums.size();i++){
    //     if(st.count(val)){
    //         val++;
    //     }
    //     else return val;
    //    }
    //     return -1;
    while(st.count(val)){
        val++;
    }
    return val;
    }
};