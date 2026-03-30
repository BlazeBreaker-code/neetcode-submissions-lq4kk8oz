class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // how do we solve this?
        // we can use a stack keeping track of the indices
        // 
        vector<int> res;
        res.resize(temperatures.size(), 0);
        std::stack<int> stack;
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!stack.empty() && temperatures[i] > temperatures[stack.top()]) {
                res[stack.top()] = i - stack.top();
                stack.pop();
            }

            stack.push(i);
        }

        return res;
    }
};
