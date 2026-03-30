class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size() - 1;
        int maxArea = 0;
        while (left < right) {
            int length = right - left; 
            int minHeight = std::min(heights[left], heights[right]);
            maxArea = std::max(maxArea, minHeight * length);
            if (heights[left] < heights[right]) ++left;
            else --right;
        }

        return maxArea;
    }
};
