class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        int countForAlternate_0 = 0;
        int countForAlternate_1 = 0;
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                if(s[i] == '0') {
                    countForAlternate_1 += 1;
                }
                else {
                    countForAlternate_0 += 1;
                }
            }
            else {
                if(s[i] == '1') {
                    countForAlternate_1 += 1;
                }
                else {
                    countForAlternate_0 += 1;
                }
            }
        }
        return min(countForAlternate_0, countForAlternate_1);
    }
};