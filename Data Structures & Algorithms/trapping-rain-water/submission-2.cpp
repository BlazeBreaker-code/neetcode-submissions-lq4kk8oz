class Solution {
public:
    int trap(vector<int>& height) {
        // so what we need to know is the maxheights at both the left and right

        int left = 0, right = height.size() - 1; 
        int maxLeft = height[left], maxRight = height[right];
        int maxArea = 0;

        while (left < right) {
            if (maxLeft < maxRight) {
                maxLeft = std::max(maxLeft, height[++left]);
                maxArea += maxLeft - height[left];
            } else {
                maxRight = std::max(maxRight, height[--right]); 
                maxArea += maxRight - height[right];
            }
        }

        return maxArea; 
    }
};
