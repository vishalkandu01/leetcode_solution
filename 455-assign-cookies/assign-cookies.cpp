class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int n = g.size();
        int m = s.size();
        int j = 0;

        int ctr = 0;
        for(int i = n-1; i >= 0; i--) {
            if(m-1-j < 0) return ctr;
            if(g[i] <= s[m-1-j]) {
                j++;
                ctr++;
            }
        }

        return ctr;
    }
};