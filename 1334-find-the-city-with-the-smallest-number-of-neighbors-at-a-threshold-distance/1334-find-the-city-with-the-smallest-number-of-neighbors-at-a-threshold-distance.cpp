class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        //create a adjlist
        vector<vector<pair<int,int>>> adjlist(n);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adjlist[u].push_back({v,wt});
            adjlist[v].push_back({u,wt});

        }

        int mincount = INT_MAX;
        int ans = -1;

        for(int scr =0;scr<n;scr++){

            //dijstra algo needs , distance array and min heap
            vector<int> dist(n , INT_MAX);

            priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int,int>>> pq;
            pq.push({0 , scr});
            dist[scr] =0;
            while(!pq.empty()){
                int d = pq.top().first;
                int node = pq.top().second;
                pq.pop();
                //ignore the outed entry in the pq
                if(d>dist[node]) continue;
                if(d>distanceThreshold) continue;

                for(auto it : adjlist[node]){

                    int next = it.first;
                    int wt = it.second;

                    if(d + wt < dist[next]){
                        dist[next] = wt+d;
                        pq.push({dist[next] , next});
                    }
                }
            }

            int cnt = 0;
            for(int i  = 0;i<n;i++){
                if(i!=scr && dist[i]<=distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<=mincount){
                mincount = cnt;
                ans = scr;
            }

        }
        return ans;
        
    }
};