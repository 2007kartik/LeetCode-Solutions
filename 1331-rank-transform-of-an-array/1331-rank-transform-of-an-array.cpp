class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        vector<int> temp = arr;
        unordered_map<int , int> mp;    
        sort(temp.begin() , temp.end());

        int rank = 1;
        for(int i = 0;i<temp.size();i++){
            if(mp.count(temp[i]))continue;
            mp[temp[i]] = rank;
            rank++;
        }

        vector<int> ans;
        for(int num : arr){            
            ans.push_back(mp[num]);            
        }
        return ans;        
    }
};