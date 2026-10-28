class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int sz = intervals.size();
        sort(intervals.begin() , intervals.end());
        int end = intervals[0][1];
        int cnt = 0;
        for(int i  =1  ; i<sz;i++){
            if(intervals[i][0]<end){
                cnt++;
                end = min(intervals[i][1] , end);
            }
            else{
                end = intervals[i][1];
            }
        }

        return cnt;
        
    }
};