class CustomStack {
public:
    vector<int> v;
    int maxSize;
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if(v.size() == maxSize) return;
        v.push_back(x);
    }
    
    int pop() {
        if(v.empty()) return -1;
        int curr = v[v.size()-1];
        v.pop_back();
        return curr;
    }
    
    void increment(int k, int val) {
        if(k > v.size()) k = v.size();
        for(int i = 0; i < k; i++){
            v[i] = v[i] + val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */