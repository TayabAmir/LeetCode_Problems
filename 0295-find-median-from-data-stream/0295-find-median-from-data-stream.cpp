class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    double median;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty() && minHeap.empty()){
            minHeap.push(num), median = num;
            return;
        }
        if(num >= median)
            minHeap.push(num);
        else 
            maxHeap.push(num);
        
        balanceHeaps();
        median = findMedian();
    }
    void balanceHeaps(){
        if(abs((int)maxHeap.size() - (int)minHeap.size()) <= 1) return;
        if(maxHeap.size() > minHeap.size()){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    double findMedian() {
        if(minHeap.size() > maxHeap.size()){
            return minHeap.top();
        } else if(minHeap.size() < maxHeap.size()) {
            return maxHeap.top();
        } else {
            return (minHeap.top() + maxHeap.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */