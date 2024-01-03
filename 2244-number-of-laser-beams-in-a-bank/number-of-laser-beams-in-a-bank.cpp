class Solution {
private:
    int calculate(auto str) {
        int count = 0;
        for(char ch : str) {
            count += ch - '0';
        }
        return count;
    }

public:
    int numberOfBeams(vector<string>& bank) {
        int prevRowCount = 0;
        int total = 0;
        for(auto row : bank) {
            int curRowCount = calculate(row);
            if(curRowCount == 0) continue;
            total += curRowCount * prevRowCount;
            prevRowCount = curRowCount;
        }
        return total;
    }
};