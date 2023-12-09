class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        // method-1
        // int area = 0;
        // for(int i = 0; i < n; i++) {
        //     for(int j = i+1; j < n; j++) {
        //         area = max(area, min(height[i], height[j]) * (j-i));
        //     }
        // }
        // return area;


        // method-2
        int area = 0;
        int start, end;
        start = 0, end = n-1;
        while(start < end) {
            area = max(area, min(height[start], height[end]) * (end-start));
            if(height[start] < height[end]) start++;
            else end--;
        }
        return area;
    }
};