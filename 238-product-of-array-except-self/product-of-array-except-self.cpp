class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        // method-1 -> Time Limit Exceeded
        // vector<int> ans;
        // for(int i = 0; i < n; i++) {
        //     int num = nums[i];
        //     int product = 1;
        //     for(int j = 0; j < n; j++) {
        //         if(i != j) {
        //             product *= nums[j];
        //         }
        //     }
        //     ans.push_back(product);
        // }
        // return ans;


        // method-2
        vector<int> prefix(n, 1);
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] * nums[i-1];
        }
        vector<int> suffix(n, 1);
        for(int i = n-2; i >= 0; i--) {
            suffix[i] = suffix[i+1] * nums[i+1];
        }
        vector<int> ans(n, 1);
        for(int i = 0; i < n; i++) {
            ans[i] = prefix[i] * suffix[i];
        }
        return ans;
    }
};