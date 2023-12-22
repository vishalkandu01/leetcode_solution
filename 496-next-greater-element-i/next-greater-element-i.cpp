class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp;
        int ans = -1;
        for(int i = nums2.size()-1; i >= 0; i--) {
            for(int j = i+1; j < nums2.size(); j++) {
                if(nums2[j] > nums2[i]) {
                    ans = nums2[j];
                    break;
                }
            }
            mpp[nums2[i]] = ans;
            ans = -1;
        }
        vector<int> v;
        for(auto it : nums1) {
            if(mpp.find(it) != mpp.end()) {
                auto ele = mpp.find(it);
                v.push_back(ele -> second);
            }
            else {
                v.push_back(-1);
            }
        }    
        return v;
    }
};