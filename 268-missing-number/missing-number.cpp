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
        int xor1 = 0;
        int xor2 = 0;
        // int x = 0;
        for(int i = 0; i < nums.size(); i++) {
                xor1 = xor1 ^ nums[i];
                xor2 = xor2 ^ (i+1);
                // x = x ^ ( nums[i] ^ (i+1) );
        }
        return xor1 ^ xor2;
    }
};