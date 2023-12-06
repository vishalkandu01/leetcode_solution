class Solution {
private:
    string getKey(string str) {
        vector<int> count(26);
        for(int i = 0; i < str.size(); i++) {
            count[str[i] - 'a']++;
        }
        string key = "";
        for(int i = 0; i < count.size(); i++) {
            key.append(to_string(count[i]) + '#');
        }
        return key;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // method-1
        // vector<vector<string>> ans;
        // int n = strs.size();
        // unordered_map<string, vector<string>> mpp;
        // for(int i = 0; i < n; i++) {
        //     string key = strs[i];
        //     sort(key.begin(), key.end());
        //     mpp[key].push_back(strs[i]);
        // }
        // for(auto it : mpp) {
        //     ans.push_back(it.second);
        // }
        // return ans;


        // method-2
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mpp;
        for(int i = 0; i < strs.size(); i++) {
            string key = getKey(strs[i]);
            mpp[key].push_back(strs[i]);
        }
        for(auto it = mpp.begin(); it != mpp.end(); it++) {
            ans.push_back(it->second);
        }
        return ans;
    }
};