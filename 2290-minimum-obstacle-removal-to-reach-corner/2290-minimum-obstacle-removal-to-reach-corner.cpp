class Solution {
public:
    using p = pair<int, pair<int, int>>;
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    bool isValid(int r, int c, int row, int col) {
        return r >= 0 && r < row && c >= 0 && c < col;
    }

    int minimumObstacles(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        priority_queue<p, vector<p>, greater<p>> pq;
        vector<vector<int>> dis(row , vector<int>(col , INT_MAX));

        pq.push({0, {0, 0}});
        dis[0][0] =1;

        while (!pq.empty()) {
            int obs_cnt = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            
            if(obs_cnt > dis[r][c]) continue;
            if (r == row - 1 && c == col - 1) {
                return obs_cnt;
            }
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];


                if (!isValid(nr, nc, row, col))
                    continue;
                int newObs_cnt = obs_cnt+grid[nr][nc];
                if(newObs_cnt< dis[nr][nc]){
                    dis[nr][nc] = newObs_cnt;
                    pq.push({newObs_cnt , {nr , nc}});
                }
            }
        }

        return -1;
    }
};