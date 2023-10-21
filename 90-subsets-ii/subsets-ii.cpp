class Solution {
void solve(vector<int>& nums, set<vector<int>>& st, vector<int> ds, int ind) {
    if(ind < 0) {
        st.insert(ds);
        return;
    }

    if(ind < nums.size()-1 && nums[ind] == nums[ind+1]) {
        solve(nums, st, ds, ind-1);
    }
    ds.push_back(nums[ind]);
    solve(nums, st, ds, ind-1);
    ds.pop_back();

    solve(nums, st, ds, ind-1);
}

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        vector<int> ds;
        int ind = nums.size()-1;
        solve(nums, st, ds, ind);
        vector<vector<int>> ans;
        for(auto it : st) {
            ans.push_back(it);
        }
        return ans;
    }
};