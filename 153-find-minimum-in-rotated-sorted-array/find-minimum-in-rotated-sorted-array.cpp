class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        // method-1
        int minimum = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(nums[i] < minimum) {
                minimum = nums[i];
            }
        }
        return minimum;
    }
};