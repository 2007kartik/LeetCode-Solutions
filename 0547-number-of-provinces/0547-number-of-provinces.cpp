class Solution {
public:
    void solve(int node , vector<int> &vis , vector<vector<int>> &isC , int n){
        vis[node] = 1;

        for(int neighbour = 0;neighbour<n;neighbour++){
            if(!vis[neighbour] && isC[node][neighbour]==1){
                solve(neighbour , vis , isC , n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int cnt = 0;

      
        vector<int> vis(n ,0);

        for(int i = 0;i<n;i++){
            if(!vis[i]){
                solve(i , vis , isConnected , n);
                cnt++;
            }
        }
        return cnt;
        
    }
};