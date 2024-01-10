class Solution {
private:
    void solve(vector<int>& candidates, int target, int ind, vector<int> ds, vector<vector<int>>& ans) {
        if(ind < 0) {
            if(target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        // if(target - candidates[ind] >= 0) {
        if(candidates[ind] <= target) {
            ds.push_back(candidates[ind]);
            solve(candidates, target-candidates[ind], ind, ds, ans);
            ds.pop_back();
        }
        
        solve(candidates, target, ind-1, ds, ans); // humlog jab apne base condition pe hit kar jayenge uske baad hum chahenge ki ye wala function call run kare isliye humlog ne idher else nahi lagaya else nahi lagane ka karan ye bhi hai ki yaha candidates[ind] less than, equal to or greater than target kuch bhi ho sakta hai tab bhi bhi hum chahenge ki ye function run ho par agar else case lagate hai to ye function call sirf candidates greater than target wale ke liye hi run karega
    }


public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int ind = candidates.size()-1;
        solve(candidates, target, ind, ds, ans);
        return ans;
    }
};