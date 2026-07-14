class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        

        vector<vector<int>> ans;
       
        for(int i = 0;i<numRows;i++){
            vector<int> row(i+1);

            row[0] = 1;
            for(int j = 1;j<=i;j++){
                 if(j==i){
                    row[i] = 1;
                    break;
                 } 
                row[j] = ans[i-1][j-1] + ans[i-1][j];
               
            }            
            ans.push_back(row);
        }
        return ans;
    }
};