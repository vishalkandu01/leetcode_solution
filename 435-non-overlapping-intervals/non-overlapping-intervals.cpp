class Solution {
private:
    static bool comp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1]; // use this test case [[-52,31],[-73,-26],[82,97],[-65,-11],[-62,-49],[95,99],[58,95],[-31,49],[66,98],[-63,2],[30,47],[-40,-26]]
    }

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), comp);
        int overlap_cnt = 1;
        int prevInd = 0;
        for(int ind = 1; ind < n; ind++) {
            if(intervals[prevInd][1] <= intervals[ind][0]) {
                prevInd = ind;
                overlap_cnt += 1;
            }
        }
        return n - overlap_cnt;
    }
};