class MinStack {
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
        if (val == minSt.top()) minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
