class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> st;

        for (const string& s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int num2 = st.top(); st.pop();
                int num1 = st.top(); st.pop();

                switch (s[0]) {
                    case '+':   st.push(num1 + num2);
                                break;
                    case '-':   st.push(num1 - num2);
                                break;
                    case '/':   st.push(num1 / num2);
                                break;
                    case '*':   st.push(num1 * num2);
                                break;
                }
            } else {
                st.push(stoi(s));
            }
        }

        return st.top();
    }
};
