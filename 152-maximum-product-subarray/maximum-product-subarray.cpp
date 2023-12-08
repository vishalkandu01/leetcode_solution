class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        // method-1
        // int maximumProduct = nums[0];
        // for(int i = 0; i < n; i++) {
        //     int currentProduct = nums[i];
        //     for(int j = i+1; j < n; j++) {
        //         maximumProduct = max(maximumProduct, currentProduct);
        //         currentProduct *= nums[j];
        //     }
        //     maximumProduct = max(maximumProduct, currentProduct);
        // }
        // return maximumProduct;


        // method-2
        int ans = INT_MIN;
        int product = 1;
        for(int i = 0; i < n; i++) {
            product = product * nums[i];
            ans = max(ans, product);
            if(nums[i] == 0) {
                product = 1;
            }
        }
        product = 1;
        for(int i = n-1; i >= 0; i--) {
            product = product * nums[i];
            ans = max(ans, product);
            if(nums[i] == 0) {
                product = 1;
            }
        }
        return ans;
    }
};