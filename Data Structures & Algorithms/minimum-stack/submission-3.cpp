class MinStack {
public:
    std::stack<int> stack;
    std::stack<int> minStack;

    MinStack() {
        
    }
    
    void push(int val) {
        stack.push(val);
        if (minStack.empty() || val <= minStack.top()) minStack.push(val);
    }
    
    void pop() {
        int val = stack.top();
        stack.pop();
        if (val == minStack.top()) minStack.pop();
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
