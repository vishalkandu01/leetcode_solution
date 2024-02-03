class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        int sum = 0;

        for(auto &eachRow : nums) {
            sort(eachRow.begin(), eachRow.end());
        }
        
        for(int j = 0; j < m; j++) {
            int maxi = 0;
            for(int i = 0; i < n; i++) {
                maxi = max(maxi, nums[i][j]);
            }
            sum += maxi;
        }
        return sum;
    }
};