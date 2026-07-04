class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {

        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> prefix(r , vector<int>(c,0));

        for(int i=0;i<r;i++){
            long long preSum =0;
            for(int j=0;j<c;j++){
                preSum += grid[i][j];
                prefix[i][j] = preSum;
            }
        }

        for(int i=0;i<c;i++){
            long long preSum =0;
            for(int j=0;j<r;j++){
                preSum += prefix[j][i];
                prefix[j][i] = preSum;
            }
        
        }
            int ans =0;        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(prefix[i][j]<=k) ans++;
            }
        }

        return ans;
    }
};