class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;

        while(left <= right){
            int mid = left + (right-left)/2;
            if(nums[mid] == target){
                return mid;
            }

            // Checking if leftSide is sorted
            if(nums[left] <= nums[mid]){
                //We got that leftSide is sorted, So check whether target falls in this range
                if(target >= nums[left] && target < nums[mid]){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            // As the above if not executed, So rightSide is sorted. 
            else{
                if(target <= nums[right] && target > nums[mid]){
                    left = mid + 1; 
                }
                else{
                    right = mid - 1;
                }
            }
        }
        return -1; 
    }
};
