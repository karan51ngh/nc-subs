class Solution {
public:

    int area(vector<int>& heights , int ptr1, int ptr2) {

        return (ptr2 - ptr1) * min(heights[ptr1], heights[ptr2]);

    }

    int maxArea(vector<int>& heights) {

       int ptr1 = 0;
       int ptr2 = heights.size() - 1;


       int maxarea = 0;

       while (ptr1 < ptr2) {
        int currArea = area(heights, ptr1, ptr2);
        maxarea = max( currArea , maxarea);

        if (heights[ptr1] < heights[ptr2]) {
                ptr1++;
            } else {
                ptr2--;
            }
       
       }

       return maxarea;

        
    }
};
