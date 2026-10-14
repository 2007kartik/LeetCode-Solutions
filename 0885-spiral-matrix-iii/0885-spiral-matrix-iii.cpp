class Solution {
public:
    bool isValid(int r , int c , int rows , int cols){
        return r>=0 && r<rows && c>=0 && c<cols;
    }
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {

        vector<vector<int>> ans;
        int r = rStart;
        int c = cStart;
        ans.push_back({r , c});
        int steps = 1;//for every two directions the step will increase by 1;


        while(ans.size()<rows*cols){

            //east
            for(int i = 0;i<steps;i++){
                c++;
                if(isValid(r , c , rows , cols)){
                    ans.push_back({r , c});
                }
            }
            //south
             for(int i = 0;i<steps;i++){
                r++;
                if(isValid(r , c , rows , cols)){
                    ans.push_back({r , c});
                }
            }
            steps++;

            //west
             for(int i = 0;i<steps;i++){
                c--;
                if(isValid(r , c , rows , cols)){
                    ans.push_back({r , c});
                }
            }
            //north
             for(int i = 0;i<steps;i++){
                r--;
                if(isValid(r , c , rows , cols)){
                    ans.push_back({r , c});
                }
            }
            steps++;
        }
        return ans;
    }
};