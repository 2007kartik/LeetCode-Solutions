class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {

        int row = mat.size();
        int col = mat[0].size();

        //right part
        for(int j  = 0;j<col;j++){
            int k  = j;
            int i  = 0;
            vector<int> temp;
        
            for(k = j;k<col;k++){
                if(i<row) temp.push_back(mat[i++][k]);
            }
          //  for(int i  = 0;i<temp.size();i++) cout<< temp[i]<<" ";
            sort(temp.begin() , temp.end());
            i = 0;
            for(int k = j;k<col;k++){
                if(i<row){
                    mat[i][k] = temp[i];
                    i++;
                }
            }
        }
        //left part

         for(int j  = 0;j<row;j++){
            int k  = j;
            int i  = 0;
            vector<int> temp;
        
            for(k = j;k<row;k++){
                if(i<col) temp.push_back(mat[k][i++]);
            }
          //  for(int i  = 0;i<temp.size();i++) cout<< temp[i]<<" ";
            sort(temp.begin() , temp.end());
            i = 0;
            for(int k = j;k<row;k++){
                if(i<col){
                    mat[k][i] = temp[i];
                    i++;
                }
            }

        }



        return mat;
    }
};