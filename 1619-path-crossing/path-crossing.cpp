class Solution {
public:
    bool isPathCrossing(string path) {
        int n = path.size();

        vector<pair<int, int>> visited;
        int x = 0;
        int y = 0;
        visited.push_back({x, y});
        for(auto it : path) {
            if(it == 'E') x++;
            else if(it == 'W') x--;
            else if(it == 'N') y++;
            else if(it == 'S') y--;
            visited.push_back({x, y});
        }

        set<pair<int, int>> st;
        for(auto it : visited) {
            st.insert(it);
        }

        if(visited.size() == st.size()) return false;
        return true;
    }
};