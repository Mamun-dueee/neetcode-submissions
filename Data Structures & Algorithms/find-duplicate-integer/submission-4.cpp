class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int t = 0, h = 0; // t = tortoise, h = hare
        do{
            t = nums[t];
            h = nums[nums[h]];
        }while(t != h);

        int tt = 0;
        while(t != tt){
            t = nums[t];
            tt = nums[tt];
        }
        return t; 
        
    }
};
