class Solution {
public:
    int trap(vector<int>& height) {
        // for this we need the maxHeight on the left and right 
        int left = 0, right = height.size() - 1;
        int maxLeft = height[left], maxRight = height[right];
        int water = 0; 

        while (left < right) {
            if (maxLeft < maxRight) {
                maxLeft = std::max(maxLeft, height[++left]);
                water += maxLeft - height[left];
            } else {
                maxRight = std::max(maxRight, height[--right]);
                water += maxRight - height[right];
            }
        }
        
        return water;
    }
};
