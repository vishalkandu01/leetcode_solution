class Solution {
private:
    void solve(vector<int>& nums, set<vector<int>>& ans, int ind) {
        if(ind == nums.size()) {
            ans.insert(nums);
            return;
        }

        for(int i = 0; i <= ind; i++) {
            swap(nums[i], nums[ind]);
            solve(nums, ans, ind+1);
            swap(nums[i], nums[ind]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int ind = 0;
        set<vector<int>> st;
        solve(nums, st, ind);
        vector<vector<int>> ans;
        for(auto it : st) {
            ans.push_back(it);
        }
        return ans;
    }
};