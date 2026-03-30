class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxLeft = height[left], maxRight = height[right];
        int area = 0;
        while (left < right) {
            if (maxLeft < maxRight) {
                maxLeft = std::max(maxLeft, height[++left]);
                area += maxLeft - height[left];
            } else {
                maxRight = std::max(maxRight, height[--right]);
                area += maxRight - height[right];
            }
        }

        return area;
    }
};
