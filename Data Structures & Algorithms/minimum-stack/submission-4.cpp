class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (minSt.empty() || val <= minSt.top()) minSt.push(val);
        st.push(val);
    }
    
    void pop() {
        int val = st.top();
        st.pop();
        if (val == minSt.top()) minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }

private: 
    std::stack<int> minSt;
    std::stack<int> st;
};
