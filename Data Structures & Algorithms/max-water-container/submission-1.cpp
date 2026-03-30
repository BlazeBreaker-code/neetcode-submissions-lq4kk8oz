class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size() - 1;
        int maxArea = 0; 

        while (left < right) {
            int width = right - left; 
            int minHeight = std::min(heights[left], heights[right]);
            int area = width * minHeight;

            maxArea = std::max(maxArea, area); 
            if (heights[left] < heights[right]) {
                ++left;
            } else {
                --right;
            }
        }

        return maxArea;
    }
};
