class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<bool> arr;
    SmallestInfiniteSet() {
        arr = vector<bool>(1001, true);
        for(int i = 1; i <= 1000; ++i) 
            pq.push(i);
    }
    
    int popSmallest() {
        int smallest = pq.top();
        arr[smallest] = false;
        pq.pop();
        return smallest;
    }
    
    void addBack(int num) {
        if(!arr[num])
            pq.push(num), arr[num] = true;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */