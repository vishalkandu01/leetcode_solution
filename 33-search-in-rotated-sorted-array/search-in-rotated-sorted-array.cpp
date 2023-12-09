class Solution {
private:
    int pivot(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        int mid = start + (end - start)/2;
        while(start < end) {
            if(nums[0] <= nums[mid]) {
                start = mid+1;
            }
            else {
                end = mid;
            }
            mid = start + (end-start)/2;
        }
        return start;
    }

    int binarySearch(vector<int>& nums, int start, int end, int target) {
        int mid = start + (end-start)/2;
        while(start <= end) {
            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] < target) {
                start = mid+1;
            }
            else {
                end = mid-1;
            }
            mid = start + (end-start)/2;
        }
        return -1;
    } 

public:
    int search(vector<int>& nums, int target) {
        // Method 1
        // int n = nums.size();
        // for(int i = 0; i < n; i++) {
        //     if(nums[i] == target) {
        //         return i;
        //     }
        // }
        // return -1;


        // Method 2
        // int low = 0;
        // int high = nums.size() - 1;
        // while(low <= high) {
        //     int mid = (low + high) / 2;
        //     if(nums[mid] == target) {
        //         return mid;
        //     }
        //     // if Left part is sorted:
        //     if(nums[low] <= nums[mid]) {
        //         if(nums[low] <= target && target <= nums[mid]) {
        //             high = mid - 1;
        //         }
        //         else {
        //             low = mid + 1;
        //         }
        //     }
        //     else {
        //         if(nums[mid] <= target && target <= nums[high]) {
        //             low = mid + 1;
        //         }
        //         else {
        //             high = mid - 1;
        //         }
        //     }
        // }
        // return -1;
    
    
        // method-3
        int pivotIndex = pivot(nums);
        int start = 0;
        int end = nums.size()-1;
        if(nums.size() == 1) {
            if(nums[0] == target) return 0;
            else return -1;
        }
        if(nums[start] <= target && target <= nums[pivotIndex-1]) {
            return binarySearch(nums, start, pivotIndex-1, target);
        }
        return binarySearch(nums, pivotIndex, end, target);
    }
};