class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0); // need to put a 0 at the end to get the last rect
        int maxArea = 0;

        std::stack<int> st;
        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()]; st.pop();
                int left = st.empty() ? -1 : st.top();
                int w = i - left - 1;
                maxArea = std::max(maxArea, h * w);
            }

            st.push(i);
        }

        return maxArea;
    }
};
