class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // method-1
        // int n = nums.size();
        // int total_sum = 0;
        // int estimated_sum = 0;
        // for(int i = 0; i <= n; i++) {
        //     total_sum += i;
        // }
        // for(int i = 0; i < n; i++) {
        //     estimated_sum += nums[i];
        // }
        // return total_sum - estimated_sum;


        // method-2
        int x = 0;
        for(int i = 0; i < nums.size(); i++) {
                x = x ^ ( (i+1) ^ nums[i] );
        }
        return x;
    }
};