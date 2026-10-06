class Solution {
public:
    void dfs(int source ,vector<vector<int>>& rooms ,vector<int> &vis ){
        vis[source] =1;
        for(auto it  : rooms[source]){
            if(!vis[it]){
                dfs(it , rooms , vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int n = rooms.size();
        vector<int> vis(n ,0);

        dfs(0 , rooms , vis);

        for(auto it  : vis){
            if(it==0) return false;
        }
        return true;
        
    }
};