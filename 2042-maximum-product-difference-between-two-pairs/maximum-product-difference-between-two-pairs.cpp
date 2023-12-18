class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        // method-1
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n-2]*nums[n-1] - nums[0]*nums[1];
    }
};