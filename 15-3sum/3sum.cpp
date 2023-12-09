class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            int start = i+1;
            int end = n-1;
            while(start < end) {
                int targetValue = nums[i] + nums[start] + nums[end];
                if(targetValue == 0) {
                    st.insert({nums[i], nums[start], nums[end]});
                    start++;
                    end--;
                }
                else if(targetValue < 0) {
                    start++;
                }
                else {
                    end--;
                }
            }
        }

        vector<vector<int>> ans;
        for(auto it : st) {
            ans.push_back(it);
        }
        return ans;
    }
};