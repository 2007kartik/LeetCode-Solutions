class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        vector<int> ans;

        string str = to_string(low);
        int k = str.size();
        int start = str[0]-'0';
        if(start+k>10){
            start =1;
            k = k+1;

        } 
        if(low==high&&low>10) {
             ans.push_back(low);
        }

        while(low<high){

            int temp = 0;
            int t = start;

            for(int i=1;i<=k;i++){
                temp = temp*10 + t;
                t++;
            }

            if(temp<=high&&temp>=low){
                ans.push_back(temp);
            }          

            low = temp;
            start++;
             if(low%10==9){
                 k++;
                start =1;
            }
           // start<9?start++:start =1;
            
        }



        return ans;

        
    }
};