class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<int>result;
        for(int ball =0 ; ball < col;ball++){
            int r = 0;
            int c = ball;
            bool check = false;
            while(r<row && c<col){
                if(grid[r][c]==1){
                    if(c==col-1 || grid[r][c+1]==-1 ) {
                        check  = true;
                        break;
                    }
                     c++;
                }
               
                else{//-1 here
                    if(c==0 || grid[r][c-1]==1){
                        check  = true;
                        break;
                    }
                     c--;
                }
               r++;
            }

            if(check){
                result.push_back(-1);
            }
            else{
                result.push_back(c);
            }

        }

        return result;
    }
};