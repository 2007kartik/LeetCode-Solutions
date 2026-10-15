class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int , int> mp;
        for(int num : arr){
            mp[num]++;
        }
        //sort the negative number with the abs values diff in asc order
        sort(arr.begin() , arr.end() ,[](int a , int b){
            return abs(a)< abs(b);
        });

        for(int num : arr){
            int twice = 2*num;
            if(mp[num]==0) continue;
            if(mp[twice]==0) return false;
            mp[num]--;
            mp[twice]--;
        }
        return true;
    }
};