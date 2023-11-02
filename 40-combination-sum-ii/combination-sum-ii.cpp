class Solution {
private:
    void solve(vector<int>& candidates, int target, int ind, set<vector<int>>& ds, vector<int> v, int sum) {
        if(sum == target) {
            ds.insert(v);
            return;
        }

        if(sum > target) return;

        for(int i = ind; i < candidates.size(); i++) {
            if(i > ind && candidates[i] == candidates[i-1]) continue;
            sum += candidates[i];
            v.push_back(candidates[i]);
            solve(candidates, target, i+1, ds, v, sum);
            v.pop_back();
            sum -= candidates[i];
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int ind = 0;
        set<vector<int>> ds;
        vector<int> v;
        int sum = 0;
        solve(candidates, target, ind, ds, v, sum);
        vector<vector<int>> ans;
        for(auto it : ds) {
            ans.push_back(it);
        }
        return ans;
    }
};