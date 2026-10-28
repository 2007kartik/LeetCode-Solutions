class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int sz = intervals.size();
        //sort the intervals in ascending order of ending time
        sort(intervals.begin() , intervals.end() , [](vector<int>&a , vector<int>&b){
            return a[1]<b[1];
        });
        int end = intervals[0][1];
        int cnt = 0;
        for(int i  = 1 ; i < sz;i++){
            if(intervals[i][0]>=end){
                end = intervals[i][1];
            }
            else cnt++;
        }
        return cnt;
    }
};