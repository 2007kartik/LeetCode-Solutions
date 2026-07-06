class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        int sz = intervals.size();

        int covered = 0;

        for (int i = 0; i < sz; i++) {
            bool iscovered = false;
            for(int j = 0;j<sz;j++ ){
                if(i==j) continue;
                if(intervals[j][0]<=intervals[i][0]&&
                    intervals[i][1]<=intervals[j][1]){
                        iscovered = true;
                        break;
                    }
            }
            if(iscovered) covered++;
        }
        return sz - covered;
        ;
    }
};