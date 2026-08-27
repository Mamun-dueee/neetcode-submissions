class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l < r){
            int mid = l+(r-l)/2;
            if(nums[mid] > nums[r]){
                l = mid+1;
            } else{
                r = mid;
            }
        }
        int pivot = l;

        int res = binSearch(nums, target, 0, pivot-1);
        if(res != -1){
            return res;
        }

        return binSearch(nums, target, pivot, nums.size()-1);
        
    }

    int binSearch(vector<int>& nums, int tar, int l, int r){
        while(l+1 < r){
            int mid = l + (r-l)/2;
            if(nums[mid] == tar){
                return mid;
            }
            else if(nums[mid] < tar){
                l = mid;
            }
            else{
                r = mid;
            }
        }
        if(nums[l] == tar) return l;
        if(nums[r] == tar) return r;
        return -1;
    }
};
