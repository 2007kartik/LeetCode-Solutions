class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {

        if(source ==target) return 0;
        unordered_map<int , vector<int>> mp;
      
        // mp[stops] = idxes
        for(int i  = 0;i<routes.size();i++){
           for(auto &stop : routes[i]){
                mp[stop].push_back(i);
           }
        }

        vector<bool> vis(routes.size()+1 , false);
        queue<pair<int , int>> q;

       
        for(auto route : mp[source]){
            q.push({route , 1});
            vis[route] = true;
        }


     
        while(!q.empty()){
            int route = q.front().first;
            int cnt = q.front().second;
            q.pop();

            for(auto &stop : routes[route]){

                if(stop==target){
                    return cnt;
                }
                for(auto nextRoute : mp[stop]){
                    if(!vis[nextRoute]){
                        vis[nextRoute]  = true;
                        q.push({nextRoute , cnt+1});
                    }
                }

            }
        }

        return -1;
        
    }
};