class Solution {
public:
    bool isPathCrossing(string path) {

        set<pair<int , int>> st;
        int ns = 0 , ew =0;

        st.insert({0,0});

        for(char ch : path){
            if(ch=='N') ns++;
            else if(ch=='S') ns--;
            else if(ch=='E') ew++;
            else ew--;


            if(st.count({ns , ew})) return true;
            st.insert({ns , ew});
        }

        return false;
      
    }
};