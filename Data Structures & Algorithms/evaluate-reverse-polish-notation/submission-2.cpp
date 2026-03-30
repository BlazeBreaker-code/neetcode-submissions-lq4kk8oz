class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // We have a list of strings.
        // We want to perform actions in order to the previous string
        std::stack<int> stack;
        auto isOp = [](const string& s) -> bool {
            return s.size() == 1 && (s[0] == '+' || s[0] == '-' || s[0] == '/' || s[0] == '*');
        };
        for (const string& token : tokens) {
            if (!isOp(token)) {
                stack.push(std::stoi(token));
            } else {
                int num2 = stack.top();
                stack.pop();
                int num1 = stack.top();
                stack.pop();
                stack.push(solve(token[0], num1, num2));
            }
        }

        return stack.top();
    }

private: 
    int solve(char operatorChar, int num1, int num2) {
        switch (operatorChar) {
            case '+' :  return num1 + num2;
            case '-' :  return num1 - num2;
            case '/' :  return num1 / num2;
            case '*' :  return num1 * num2;
        }

        return 0;
    }
};
