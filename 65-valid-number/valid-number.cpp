class Solution {
public:
    bool isNumber(string s) {
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
        
        bool seenDigit = false;
        bool seenE = false;
        bool seenDot = false;
        bool seenSign = false;
        
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (isdigit(c)) {
                seenDigit = true;
            } else if (c == 'e' || c == 'E') {
                if (seenE || !seenDigit) return false;
                seenE = true;
                seenDigit = false; // Reset for digits after 'e' or 'E'
            } else if (c == '.') {
                if (seenDot || seenE) return false;
                seenDot = true;
            } else if (c == '+' || c == '-') {
                if (seenSign && s[i - 1] != 'e' && s[i - 1] != 'E') return false;
                if (!seenSign && i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') return false;
                seenSign = true;
            } else {
                return false; // Invalid character
            }
        }

        return seenDigit;
    }
};