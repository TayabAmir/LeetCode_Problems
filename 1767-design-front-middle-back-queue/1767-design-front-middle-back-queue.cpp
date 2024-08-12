class FrontMiddleBackQueue {
public:
    deque<int> deque;
    FrontMiddleBackQueue() {}

    void pushFront(int val) {
        deque.push_front(val);
    }

    void pushMiddle(int val) {
        int mid = deque.size() / 2;
        deque.insert(deque.begin() + mid, val);
    }

    void pushBack(int val) {
        deque.push_back(val);
    }

    int popFront() {
        if (deque.empty()) return -1;
        int val = deque.front();
        deque.pop_front();
        return val;
    }

    int popMiddle() {
        if (deque.empty()) return -1;
        int mid = (deque.size() - 1) / 2;
        int val = deque[mid];
        deque.erase(deque.begin() + mid);
        return val;
    }

    int popBack() {
        if (deque.empty()) return -1;
        int val = deque.back();
        deque.pop_back();
        return val;
    }
};
