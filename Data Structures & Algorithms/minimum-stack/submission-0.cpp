class MinStack {
private:
    stack<int> fullStack;
    stack<int> minStack;
public:
    MinStack() {
    }
    
    void push(int val) {
        fullStack.push(val);
        if(minStack.size() == 0 || val <= minStack.top())
            minStack.push(val);
    }
    
    void pop() {
        if(fullStack.size() == 0) return;
        if(fullStack.top() == minStack.top()) minStack.pop();
        fullStack.pop();
    }
    
    int top() {
        return fullStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
