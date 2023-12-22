class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        // method-1
        // vector<int> ans;
        // for(int i = 0; i < n; i++) {
        //     int maxi = -1;
        //     for(int j = 0; j < m; j++) {
        //         int index = j;
        //         if(nums1[i] == nums2[j]) {
        //             while(index != nums2.size()) {
        //                 if(nums2[index] > nums1[i]) {
        //                     max = nums2[index];
        //                     break;
        //                 }
        //                 index++;
        //             }
        //         }
        //     }
        //     ans.push_back(max);
        // }
        // return ans;


        // method-2
        unordered_map<int, int> mpp;
        stack<int> st;
        for(int it : nums2) {
            while(!st.empty() && st.top() < it) {
                mpp[st.top()] = it;
                st.pop();
            }
            st.push(it);
        }
        for(int i = 0; i < nums1.size(); i++) {
            nums1[i] = mpp.count(nums1[i]) ? mpp[nums1[i]] : -1;
        }
        return nums1;
    }
};