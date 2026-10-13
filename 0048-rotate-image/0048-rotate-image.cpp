class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix.size();

        for(int i = 0;i<row;i++){
            
            for(int j = i;j<col;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i  = 0;i<row;i++){
            int j = 0 , k  = col-1;
            while(j<k){
                swap(matrix[i][j] , matrix[i][k]);
                j++;
                k--;
            }
        }


        
    }
};