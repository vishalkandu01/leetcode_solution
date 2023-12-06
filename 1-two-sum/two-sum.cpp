class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        // method-1
        // for(int i = 0; i < n; i++) {
        //     for(int j = i+1; j < n; j++) {
        //         if(nums[i] + nums[j] == target) {
        //             return {i, j};
        //         }
        //     }
        // }
        // return {-1, -1};


        // method-2
        // vector<pair<int, int>> v;
        // for(int i = 0; i < n; i++) {
        //     v.push_back({nums[i], i});
        // }
        // sort(v.begin(), v.end());
        // int low, high;
        // low = 0, high = n-1;
        // while(low < high) {
        //     if(v[low].first+v[high].first == target) {
        //         return {v[low].second, v[high].second};
        //     }
        //     else if(v[low].first+v[high].first < target) {
        //         low++;
        //     }
        //     else {
        //         high--;
        //     }
        // }
        // return {-1, -1};


        // method-3
        unordered_map<int, int> mpp;
        for(int i = 0; i < n; i++) {
            if(mpp.find(target-nums[i]) != mpp.end()) {
                return {i, mpp[target - nums[i]]};
            }
            
            // mpp[nums[i]] = i;
            mpp.insert({nums[i], i});
        }
        return {-1,-1};
    }
};