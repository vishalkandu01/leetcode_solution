class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        for(auto i : intervals) { 
            if(i[1] < newInterval[0]) ans.push_back(i); // the new interval is after the range of other interval
            else if(newInterval[1] < i[0]) { // the new interval's range is before the other
                ans.push_back(newInterval);
                newInterval = i; // updating the new interval
            }
            else { // the new interval is in the range of the other interval
                newInterval[0] = min(newInterval[0], i[0]);
                newInterval[1] = max(newInterval[1], i[1]);
            }
        }

        ans.push_back(newInterval); // at the end after the loop just add the updated newIntervals
        return ans;
    }
};