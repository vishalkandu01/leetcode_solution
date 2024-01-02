class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();

        // method-1
        // unordered_map<int, int> mpp;
        // int ctr = 0;
        // for(int i = 0; i < n; i++) {
        //     mpp[nums[i]]++;
        //     ctr = max(ctr, mpp[nums[i]]);
        // }
        // vector<vector<int>> ans(ctr);
        // for(auto it : mpp) {
        //     int ele = it.first;
        //     int freq = it.second;
        //     for(int i = 0; i < freq; i++) {
        //         ans[i].push_back(ele);
        //     }
        // }
        // return ans;


        // method-2
        vector<int> frequency(n+1);
        vector<vector<int>> ans;
        for(int it : nums) {
            if(frequency[it] >= ans.size()) {
                ans.push_back({});
            }
            ans[frequency[it]].push_back(it);
            frequency[it]++;
        }
        return ans;
    }
};