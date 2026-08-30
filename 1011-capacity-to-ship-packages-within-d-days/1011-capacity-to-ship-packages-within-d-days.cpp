class Solution {
public:
    int req_days(vector<int> &w , int cap){
        int load = 0; int days =1;
        for(int i  = 0;i<w.size();i++){
            if(load+w[i]>cap){
                days++;
                load = w[i];
            }
            else load += w[i];
        }
        return days;

    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int low = *max_element(weights.begin() , weights.end());
        int high = 0;
        for(int i  = 0;i<weights.size();i++){
            high += weights[i];
        }

        while(low<=high){
            int mid = low+(high-low)/2;

            int no_of_days = req_days(weights , mid);

            if(no_of_days<=days){
                high = mid - 1;
            }
            else low  = mid +1;

        }

        return low;

    }
};