
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n), newAdj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> last(26, -1);
        vector<int> newParent(n, -1);

        // First DFS: Find nearest ancestor with same character
        function<void(int)> dfs1 = [&](int node) {
            int ch = s[node] - 'a';
            int prev = last[ch];

            if (prev != -1)
                newParent[node] = prev;
            else
                newParent[node] = parent[node];

            last[ch] = node;

            for (int child : adj[node]) {
                dfs1(child);
            }

            last[ch] = prev;
        };

        dfs1(0);

        // Build modified tree
        for (int i = 1; i < n; i++) {
            newAdj[newParent[i]].push_back(i);
        }

        vector<int> ans(n, 0);

        // Second DFS: Calculate subtree sizes
        function<int(int)> dfs2 = [&](int node) {
            int size = 1;

            for (int child : newAdj[node]) {
                size += dfs2(child);
            }

            return ans[node] = size;
        };

        dfs2(0);

        return ans;
    }
};
