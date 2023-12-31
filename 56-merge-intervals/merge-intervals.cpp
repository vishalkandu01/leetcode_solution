class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        
        // method-1
        // if(intervals.empty()) {
        //     return vector<vector<int>> ();
        // }
        // sort(intervals.begin(), intervals.end());
        // for(int i = 0; i < n; i++) {
        //     for (int j = 0; j < intervals[i].size(); j++) {
        //         cout << intervals[i][j];
        //     }
        // }
        // stack<vector<int>> st;
        // st.push(intervals[0]);
        // for(int i = 1; i < n; i++) {
        //     vector<int> current = intervals[i];
        //     vector<int> top = st.top();
        //     if(top[1] >= current[0]) {
        //         top[1] = max(top[1], current[1]);
        //         st.pop();
        //         st.push(top);
        //     } 
        //     else {
        //         st.push(current);
        //     }
        // }
        // intervals.clear();
        // while(!st.empty()) {
        //     intervals.push_back(st.top());
        //     st.pop();
        // }
        // return intervals;


        // // method-2
        // sort(intervals.begin(), intervals.end());
        // int index = 0;
        // for(int i = 1; i < n; i++) {
        //     if(intervals[index][1] >= intervals[i][0]) {
        //         intervals[index][1] = max(intervals[index][1], intervals[i][1]);
        //         intervals.erase(intervals.begin()+i);
        //         n = intervals.size();
        //         i--; // use this as a testcase if you don't know why it is written [[1,4],[0,2],[3,5]]
        //     }
        //     else {
        //         index++;
        //     }
        // }
        // return intervals;


        // method-3
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) {
            if(ans.empty() || ans.back()[1] < intervals[i][0]) {
                ans.push_back(intervals[i]);
            }
            else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};