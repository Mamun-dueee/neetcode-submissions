class Solution {
public:
    int cal_time(vector<int>& piles, int m){
        int time = 0; 
        for(int i = 0; i < piles.size(); i++){
            if(piles[i]%m == 0){
                time += piles[i]/m;

            }
            else{
                time += (piles[i]/m) + 1; 
            }
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_right = 0;
        for(int b : piles){
            max_right = max(max_right, b);
        }
        int left = 1, right = max_right; // 1 <= K <= max_right
        while(left+1 < right){
            int mid = left + (right-left)/2;
            int time = cal_time(piles, mid);
            if(time == h){
                right = mid;
            }
            else if(time < h){
                right = mid;
            }
            else{
                left = mid;
            }
        }
        if(cal_time(piles, left) <= h){
            return left;
        }
        else{
            return right;
        }

        
    }
};
