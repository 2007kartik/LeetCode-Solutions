class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0) return true;
        int sz = flowerbed.size();
        for(int i  = 0;i<sz;i++){
           bool left = (i==0 || flowerbed[i-1]==0);
           bool right =(i==sz-1 || flowerbed[i+1]==0);
           if(flowerbed[i]==0 && left && right){
            flowerbed[i] = 1;
            n--;
            if(n==0) return true;
           }
            
        }
        return false;
        
    }
};