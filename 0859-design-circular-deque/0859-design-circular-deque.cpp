class Node {
public:
    int val;
    Node *next, *prev;

    Node(int val) {
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};

class MyCircularDeque {
public:
    Node *head, *tail;
    int size, maxSize;
    MyCircularDeque(int k) {
        size = 0, maxSize = k;
        head = NULL;
        tail = NULL;
    }

    bool insertFront(int val) {
        if (size == maxSize)
            return false;
        Node* node = new Node(val);
        node->prev = NULL;
        node->next = head;
        if (head)
            head->prev = node;
        head = node;
        if (!tail)
            tail = head;
        size++;
        return true;
    }

    bool insertLast(int val) {
        if (size == maxSize)
            return false;
        Node* node = new Node(val);
        node->next = NULL;
        node->prev = tail;
        if (tail)
            tail->next = node;
        tail = node;
        if (!head)
            head = tail;
        size++;
        return true;
    }

    bool deleteFront() {
        if (size == 0)
            return false;
        Node* temp = head;
        head = head->next;
        delete temp;
        head ? head->prev = NULL : tail = NULL;
        size--;
        return true;
    }

    bool deleteLast() {
        if (size == 0)
            return false;
        Node* temp = tail;
        tail = tail->prev;
        delete temp;
        tail ? tail->next = NULL : head = NULL;
        size--;
        return true;
    }

    int getFront() { 
        if (!head)
            return -1;
        return head->val;
    }

    int getRear() { 
        if (!tail)
            return -1;
        return tail->val; 
    }

    bool isEmpty() { return size == 0; }

    bool isFull() { return size == maxSize; }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */