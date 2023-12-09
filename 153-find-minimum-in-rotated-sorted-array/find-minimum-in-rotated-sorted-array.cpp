class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        // method-1
        // int minimum = INT_MAX;
        // for(int i = 0; i < n; i++) {
        //     if(nums[i] < minimum) {
        //         minimum = nums[i];
        //     }
        // }
        // return minimum;


        // method-2
        int start = 0;
        int end = n-1;
        int mid = start + (end-start)/2;
        if(nums[0] < nums[end]) return nums[0];
        while(start < end) {
            if(nums[mid] >= nums[0]) {
                start = mid+1;
            }
            else {
                end = mid;
            }
            mid = start + (end-start)/2;
        }
        return nums[start];
    }
};