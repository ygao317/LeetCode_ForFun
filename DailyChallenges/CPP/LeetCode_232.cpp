class MyQueue {
private:
    queue<int> q;
public:
    MyQueue() {
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int x = q.front(); q.pop();
        return x;
    }
    
    int peek() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
