class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) return {{1}};
        if(numRows == 2) return {{1}, {1, 1}};
        vector<vector<int>> ans;
        int size = 1;
        int cnt = 0;
        while(cnt < numRows) {
            vector<int> v(size);
            v[0] = 1;
            v[size-1] = 1;
            for(int i = 1; i < v.size()-1; i++) {
                v[i] = ans[cnt-1][i-1] + ans[cnt-1][i];
            }
            ans.push_back(v);
            size++;
            cnt++;
        }
        return ans;
    }
};