class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::stack<int> st;

        for (string& s : operations) {
            if (s == "+") {
                int n2 = st.top(); st.pop();
                int n1 = st.top();
                st.push(n2);
                st.push(n1 + n2);
            } else if (s == "C") {
                st.pop();
            } else if (s == "D") {
                int num = st.top();
                st.push(num * 2);
            } else {
                st.push(stoi(s));
            }
        }

        int total = 0; 
        while (!st.empty()) {
            total += st.top(); st.pop();
        }

        return total;
    }
};