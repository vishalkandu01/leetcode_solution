class Solution {
private:
    bool solve(int ind, vector<int>& arr, vector<int>& vis) {
        if(ind >= arr.size() || ind < 0) return false;
        if(arr[ind] == 0) return true;
        if(vis[ind] == 1) return false;

        vis[ind] = 1;
        return solve(ind + arr[ind], arr, vis) || solve(ind - arr[ind], arr, vis);
    }

public:
    bool canReach(vector<int>& arr, int start) {
        vector<int> vis(arr.size(), 0);
        return solve(start, arr, vis);
    }
};