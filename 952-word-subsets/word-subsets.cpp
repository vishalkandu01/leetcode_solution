class Solution {
private:
    bool isSame(vector<int> h1, vector<int> h2) {
        for(int i = 0; i < 26; i++) {
            if(h1[i] > h2[i]) return false;
        }
        return true;
    }

public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        vector<int> hash1(26, 0);

        for(int i = 0; i < words2.size(); i++) {
            vector<int> temp(26, 0);
            for(int j = 0; j < words2[i].size(); j++) {
                temp[words2[i][j] - 'a']++;
            }

            for(int j = 0; j < 26; j++) {
                hash1[j] = max(hash1[j], temp[j]);
            }
        }

        for(int i = 0; i < words1.size(); i++) {
            vector<int> hash2(26, 0);
            string temp = words1[i];
            for(int j = 0; j < temp.length(); j++) {
                hash2[temp[j] - 'a']++;
            }
            
            if(isSame(hash1, hash2) == true) {
                res.push_back(temp);
            }
        }

        return res;
    }
};