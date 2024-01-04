class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(auto it : nums) {
            mpp[it]++;
        }

        int ctr = 0;
        for(auto it : mpp) {
            int cnt = it.second;
            if(cnt == 1) return -1;
            ctr += cnt/3;
            // if(cnt % 3 == 1 || cnt % 3 == 2) ctr++;
            if(cnt % 3 != 0) ctr++;
        }
        return ctr;
    }
};
