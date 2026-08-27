class Solution {
public:
    int binSearch(int l, int r, vector<int>& nums, int target){
        if(l > r){
            return -1;
        }
        int mid = l + (r-l)/2;

        if(nums[mid] == target){
            return mid;
        }

        return (nums[mid] < target) ? 
            (binSearch(mid+1, r, nums, target)) : 
            (binSearch(l, mid-1, nums, target));
    }
    int search(vector<int>& nums, int target) {
        return binSearch(0, nums.size()-1, nums, target);
    }
};
