class Solution {
public:
    int reverse(int x) {
        if(x == 0 || x <= INT_MIN || x >= INT_MAX) return 0;

        string s = to_string(x);
        int i = 0;
        int n = s.size();
        double ans = 0;

        if(s[i] == '-') {
            i++;
        }

        int start = i, end = n-1;
        while(start < end) {
            swap(s[start++], s[end--]);
        }

        while(s[i] == '0') {
            s.erase(s.begin() + i);
        }
        
        i = 0;
        int isNegative = 0;
        if(s[i] == '-') {
            isNegative++;
            i++;
        }

        while(i < s.size()) {
            int num = s[i] - '0';
            ans = ans*10 + num;
            i++;
        }

        if(isNegative) {
            ans = -ans;
        }
        if(ans >= INT_MAX || ans <= INT_MIN) return 0;

        return (int)ans;
    }
};