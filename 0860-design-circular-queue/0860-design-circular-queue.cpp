class MyCircularQueue {
public:
    queue<int> q;
    int size, maxSize;
    MyCircularQueue(int k) {
        size = 0;
        maxSize = k;
    }
    
    bool enQueue(int value) {
        if(size == maxSize) return false;
        q.push(value);
        size++;
        return true;
    }
    
    bool deQueue() {
        if(size == 0) return false;
        size--;
        q.pop();
        return true;
    }
    
    int Front() {
        if(size==0) return -1;
        return q.front();
    }
    
    int Rear() {
        if(size==0) return -1;
        return q.back();
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == maxSize;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */