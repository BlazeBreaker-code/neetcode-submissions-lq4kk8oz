class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else if (st.empty()) {
                return false;
            } else if (isPair(st.top(), c)) {
                st.pop();
            } else {
                return false;
            }
        }

        return st.empty();
    }

    bool isPair(char open, char close) {
        return (open == '[' && close == ']' ||
                open == '{' && close == '}' ||
                open == '(' && close == ')'); 
    }
};
