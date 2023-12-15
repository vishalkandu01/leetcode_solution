class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n = paths.size();

        unordered_map<string, int> mpp;
        for(int i = 0; i < n; i++) {
            mpp[paths[i][0]] = 1;
        }

        for(int i = 0; i < n; i++) {
            if(mpp.find(paths[i][1]) == mpp.end()) {
                return paths[i][1];
            }
        }

        return "";
    }
};