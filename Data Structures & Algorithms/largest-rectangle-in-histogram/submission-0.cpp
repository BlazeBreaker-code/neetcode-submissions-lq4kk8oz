class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<int> st;
        int maxArea = 0;
        for (int i = 0; i <= heights.size(); ++i) {              
            while (!st.empty() && (i == heights.size() || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = std::max(maxArea, height * width);
            }
            
            st.push(i);
        }

        return maxArea;
    }
};
