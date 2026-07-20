class Solution {
public:
    void solve(int start, vector<int>&vis ,vector<vector<int>>& rooms ){

        vis[start]=true;
        vector<int>v  = rooms[start];     

        for(int i = 0;i<v.size();i++){
           if(!vis[v[i]]){
            solve(v[i], vis , rooms);
           }    
           
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int sz = rooms.size();

        vector<int>vis(sz , false);

       solve(0, vis , rooms);

       for(int i = 0;i<vis.size();i++){
        if(!vis[i]) return false;
       }
        return true;
        
    }
};