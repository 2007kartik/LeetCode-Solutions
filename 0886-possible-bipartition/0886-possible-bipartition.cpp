class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        vector<int> color(n + 1, -1);

        vector<vector<int>> adj(n+1);
        for(auto it : dislikes){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

      for(int start = 1;start<=n;start++){
        if(color[start]!=-1) continue;
        color[start] = 0;
        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : adj[node]) {
                if (color[it] == -1) {
                    color[it] = !color[node];
                    q.push(it);
                } else if (color[it] == color[node])
                    return false;
            }
        }
      }

        return true;
    }
    };