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
        
        // method-1
        // int prevRowCount = 0;
        // int total = 0;
        // for(auto row : bank) {
        //     int curRowCount = calculate(row);
        //     if(curRowCount == 0) continue;
        //     total += curRowCount * prevRowCount;
        //     prevRowCount = curRowCount;
        // }
        // return total;
  
  
        // method-2
        int ans = 0;
        vector<int> v;
        for(auto it : bank) {
            string str = it;
            int cnt = 0;
            for(int i = 0; i < str.size(); i++) {
                if(str[i] == '1') {
                    cnt++;
                }
            }
            if(cnt != 0) {
                v.push_back(cnt);
            }
        }
        for(int i = 1; i < v.size(); i++) {
            int t = v[i] * v[i-1];
            ans += t;
        }
        return ans;
    }
};