class Solution {
public:

    int area(int i1, int i2, vector<int> &heights) {
        int width = (i2 - i1);
        int length = min(heights[i1], heights[i2]);
        return width * length;
    }

    int maxArea(vector<int>& heights) {
        int sz = heights.size();

        int l = 0;
        int r = sz - 1;

        int currentArea = 0;

        while (l < r) {
            currentArea = max (area(l,r, heights) , currentArea);

            // move right or left
            // we want more area

            if (heights[r] > heights[l]) l++;
            else r--;


        }

        return currentArea;
    }
};
