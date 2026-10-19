class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin() , points.end());
        int ans = 0;
        int prevSP = points[0][0];
        int prevEP = points[0][1];
        for(int i = 1;i<points.size();i++){
            int currSP = points[i][0];
            int currEP = points[i][1];
            if(currSP>prevEP)//means no overlap
            {
                prevSP = currSP;
                prevEP = currEP;
                ans++;
            }
            else//means overlap
            {
                prevSP = max(currSP , prevSP);
                prevEP = min(currEP , prevEP);
            }
        }

        return ans+1;
        
    }
};