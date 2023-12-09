class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        
        // method-1
        // vector<vector<int>> ans;
        // for(int i = 0; i < n-2; i++) {
        //     for(int j = i+1; j < n-1; j++) {
        //         for(int k = j+1; k < n; k++) {
        //             if(nums[i] + nums[j] + nums[k] == 0) {
        //                 ans.push_back({nums[i], nums[j], nums[k]});
        //             }
        //         }
        //     }
        // }
        // return ans;


        // method-2
        // set<vector<int>> st;
        // sort(nums.begin(), nums.end());
        // for(int i = 0; i < n; i++) {
        //     int start = i+1;
        //     int end = n-1;
        //     while(start < end) {
        //         int targetValue = nums[i] + nums[start] + nums[end];
        //         if(targetValue == 0) {
        //             st.insert({nums[i], nums[start], nums[end]});
        //             start++;
        //             end--;
        //         }
        //         else if(targetValue < 0) {
        //             start++;
        //         }
        //         else {
        //             end--;
        //         }
        //     }
        // }
        // vector<vector<int>> ans;
        // for(auto it : st) {
        //     ans.push_back(it);
        // }
        // return ans;


        // method-3
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            int start = i+1;
            int end = n-1;
            while(start < end) {
                int targetValue = nums[i] + nums[start] + nums[end];
                if(targetValue == 0) {
                    ans.push_back({nums[i], nums[start], nums[end]});
                    while(start < end && nums[start] == nums[start+1])start++;
                    while(start < end && nums[end] == nums[end-1]) end--;
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
            while(i+1 <= n-1 && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};