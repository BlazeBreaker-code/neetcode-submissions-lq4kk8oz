class MinStack { // Whole point is to keep a stack or min vals
private: 
    std::stack<int> st;
    std::stack<int> minSt;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if (minSt.empty() || val <= minSt.top()) minSt.push(val);
    }
    
    void pop() {
        int val = st.top(); st.pop();
        if (minSt.top() == val) minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
