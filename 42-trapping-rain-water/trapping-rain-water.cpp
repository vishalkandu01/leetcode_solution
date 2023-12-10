class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        // method-1 -> Time Limit Exceeded
        // int res = 0;
        // for(int i = 1; i < n-1; i++) {
        //     int leftMax = height[i];
        //     for(int j = 0; j < i; j++) {
        //         leftMax = max(leftMax, height[j]);
        //     }
        //     int rightMax = height[i];
        //     for(int j = i+1; j < n; j++) {
        //         rightMax = max(rightMax, height[j]);
        //     }
        //     res = res + min(leftMax, rightMax) - height[i];
        // }
        // return res;


        // method-2 -> Precalculation method -> it's a easy one
        // vector<int> leftMax(n, 0);
        // leftMax[0] = height[0];
        // for(int i = 1; i < n; i++) {
        //     leftMax[i] = max(leftMax[i-1], height[i]);
        // }
        // vector<int> rightMax(n, 0);
        // rightMax[n-1] = height[n-1];
        // for(int i = n-2; i >= 0; i--) {
        //     rightMax[i] = max(rightMax[i+1], height[i]);
        // }
        // int res = 0;
        // for(int i = 0; i < n; i++) {
        //     res = res + min(leftMax[i], rightMax[i]) - height[i];
        // }
        // return res;


        // method-3
        int left, right;
        left = 0, right = n-1;
        int leftMax, rightMax;
        leftMax = 0, rightMax = 0;
        int res = 0;
        while(left <= right) {
            if(rightMax <= leftMax) {
                res = res + max(0, rightMax - height[right]);
                rightMax = max(rightMax, height[right]);
                right = right - 1;
            }
            else {
                res = res + max(0, leftMax - height[left]);
                leftMax = max(leftMax, height[left]);
                left = left + 1;
            }
        }
        return res;
    }
};