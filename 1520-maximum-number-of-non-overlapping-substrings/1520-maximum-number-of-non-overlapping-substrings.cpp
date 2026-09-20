class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {

        int n = s.size();
        vector<pair<int , int>> intervals;
        vector<int> first(26 ,-1);
        vector<int> last(26 , -1);

        //get the first and last occurrence of each chars
        for(int  i = 0;i<n;i++){
            int idx = s[i] - 'a';
            if(first[idx]==-1){
                first[idx] = i;
            }
            last[idx] = i;
        }

        //check the L to R window is valid or not

        for(int i  = 0;i< 26;i++){
            if(first[i]==-1) continue;
            int L = first[i];
            int R = last[i];

            bool valid = true;

            for(int j = L;j<=R;j++){
                int idx = s[j] - 'a';
                if(first[idx]<L) {
                    valid = false;
                    break;
                }
                R = max(R , last[idx]);
            }

            if(valid){
                intervals.push_back({L , R});
            }
        }

        //sort the intervals at right end

        sort(intervals.begin() , intervals.end() , 
            [](auto &a , auto &b){
                return a.second<b.second;
            });

            int preEnd = -1;

            vector<string> ans;

            for(auto it : intervals){
                if(it.first > preEnd){
                    ans.push_back(s.substr(it.first , it.second - it.first +1)); 
                    preEnd = it.second;
                }
            }
            return ans;
        
    }
};