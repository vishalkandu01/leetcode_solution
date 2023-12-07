class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;
        unordered_map<int, int> mpp;
        for(int i = 0; i < n; i++) {
            mpp[nums[i]] += 1;
        }
        for(auto it : mpp) {
            if(it.second > 1) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};