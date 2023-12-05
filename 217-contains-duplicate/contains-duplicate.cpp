class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        int n = nums.size();

        // method-1
        // for(int i = 0; i < n; i++) {
        //     for(int j = i+1; j < n; j++) {
        //         if(nums[i] == nums[j]) {
        //             return true;
        //         }
        //     }
        // }
        // return false;


        // method-2
        // sort(nums.begin(), nums.end());
        // for(int i = 0; i < n-1; i++) {
        //     if(nums[i] == nums[i+1]) {
        //         return true;
        //     }
        // }
        // return false;


        // method-3
        // unordered_map<int, int> mpp;
        // for(int i = 0; i < n; i++) {
        //     mpp[nums[i]]++;
        //     if(mpp[nums[i]] > 1) return true;
        // }
        // return false;

        
        // method-4
        unordered_set<int> st;
        for(int i = 0; i < n; i++) {
            if(st.find(nums[i]) != st.end()) {
                return true;
            }
            st.insert(nums[i]);
        }
        return false;
    }
};