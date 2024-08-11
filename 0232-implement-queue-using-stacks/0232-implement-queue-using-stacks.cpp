class MyQueue {
    stack<int> st;
    int front = -1;
public:
    MyQueue() {
        
    }
    void popHelper(){
        if(st.size()==2) front = st.top();
        if(st.size()==1) {
            st.pop();
            return;
        }
        int curr = st.top();
        st.pop();
        popHelper();
        st.push(curr);
    }
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        getPeek();
        int temp = front;
        popHelper();
        return temp;
    }
    
    int peek() {
        getPeek();
        return front;
    }
    void getPeek(){
        if(st.empty()) return;
        int curr = st.top();
        st.pop();
        getPeek();
        st.push(curr);
        if(st.size()==1) front = st.top();
    }
    bool empty() {
        return st.empty();
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