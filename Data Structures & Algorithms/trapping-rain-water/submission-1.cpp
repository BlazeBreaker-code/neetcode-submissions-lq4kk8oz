class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return -1;
        int left = 0, right = height.size() - 1; 
        int leftMax = height[left], rightMax = height[right];
        int res =  0;

        while (left < right) {
            if (leftMax < rightMax) {
                ++left;
                leftMax = std::max(leftMax, height[left]);
                res += leftMax - height[left];
            } else {
                --right;
                rightMax = std::max(rightMax, height[right]);
                res += rightMax - height[right];
            }
        }

        return res;
    }
};
