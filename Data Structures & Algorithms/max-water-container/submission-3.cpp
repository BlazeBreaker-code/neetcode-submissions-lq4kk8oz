class Solution {
public:
    int maxArea(vector<int>& heights) {
        // area = width * height

        int left = 0, right = heights.size() - 1;
        int maxArea = 0;
        while (left < right) {
            int width = right - left;
            int height = std::min(heights[left], heights[right]); 
            maxArea = std::max(maxArea, width * height); 
            if (heights[left] > heights[right]) --right;
            else ++left;
        }

        return maxArea;
    }
};
