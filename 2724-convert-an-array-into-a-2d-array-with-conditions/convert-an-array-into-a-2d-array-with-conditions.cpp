class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int ctr = 0;
        for(int i = 0; i < n; i++) {
            mpp[nums[i]]++;
            ctr = max(ctr, mpp[nums[i]]);
        }

        vector<vector<int>> ans(ctr);
        for(auto it : mpp) {
            int ele = it.first;
            int freq = it.second;
            for(int i = 0; i < freq; i++) {
                ans[i].push_back(ele);
            }
        }
        return ans;
    }
};