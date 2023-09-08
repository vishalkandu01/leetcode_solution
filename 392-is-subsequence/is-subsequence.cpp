class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<int> hsh(26, 0);
        for(int i = 0; i < t.size(); i++) {
            hsh[t[i] - 'a']++;
        }

        for(int i = 0; i < s.size(); i++) {
            hsh[s[i] - 'a']--;
        }

        for(int i = 0; i < 26; i++) {
            if(hsh[i] < 0) {
                return false;
            }
        }

        int i = 0, j = 0;
        while(i < t.size() && j < s.size()) {
            if(t[i] == s[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }

        if(j == s.size()) return true;
        return false;
    }
};