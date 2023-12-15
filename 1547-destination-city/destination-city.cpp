class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n = paths.size();

        // method-1
        // unordered_map<string, int> mpp;
        // for(int i = 0; i < n; i++) {
        //     mpp[paths[i][0]] = 1;
        // }
        // for(int i = 0; i < n; i++) {
        //     if(mpp.find(paths[i][1]) == mpp.end()) {
        //         return paths[i][1];
        //     }
        // }
        // return "";


        // method-2
        unordered_set<string> st;
        for(int i = 0; i < n; i++) {
            st.insert(paths[i][0]);
        }
        for(int i = 0; i < n; i++) {
            if(st.find(paths[i][1]) == st.end()) {
                return paths[i][1];
            }
        }
        return "";
    }
};