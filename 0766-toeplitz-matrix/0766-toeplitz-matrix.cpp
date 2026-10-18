class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        unordered_map<int , vector<int>>mp;
        int row = matrix.size();
        int col  = matrix[0].size();
        for(int i  = 0;i<row;i++){
            for(int j  = 0;j<col;j++){
                mp[i-j].push_back(matrix[i][j]);

            }
        }

        for(auto &it : mp){
            vector<int> v  = it.second;
            for(int i  = 0;i<v.size()-1;i++){
                if(v[i]!=v[i+1]) return false;
            }
        }

        return true;
    }
};