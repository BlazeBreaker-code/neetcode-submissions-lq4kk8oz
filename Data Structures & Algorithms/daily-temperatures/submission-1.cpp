class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // we want to find the number of days till we get a higher value
        // return a list of days till higher temp
        // We should keep track of indices and then pop once we reach a higher temp

        // as we iterate we want to check which indices have temps below us and we can store the diff
        int n = temperatures.size();
        vector<int> days(n, 0);

        std::stack<int> st;

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                days[st.top()] = i - st.top();
                st.pop();
            }

            st.push(i);
        }

        return days;
    }
};
