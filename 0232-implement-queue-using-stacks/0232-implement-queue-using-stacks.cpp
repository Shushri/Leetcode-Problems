class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!st2.empty()){
            int lll=st2.top();
            st2.pop();
            st1.push(lll);
        }
        st1.push(x);
        while(!st1.empty()){
            int lll=st1.top();
            st1.pop();
            st2.push(lll);
        }
    }
    
    int pop() {
        
        if(st2.empty()){
            return -1;
        }
        int tp=st2.top();
        st2.pop();
        return tp;

    }
    
    int peek() {
        if(st2.empty()){
            return -1;
        }
        int tp=st2.top();
        
        return tp;
    }
    
    bool empty() {
        return st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */