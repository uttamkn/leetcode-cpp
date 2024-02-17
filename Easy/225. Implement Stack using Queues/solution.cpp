class MyStack {
public:
    queue<int> queue1;
    queue<int> queue2;
    MyStack() {
        
    }
    
    void push(int x) {
        queue1.push(x);
    }
    
    int pop() {
        while(queue1.size() > 1) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        int pop_val=queue1.front();
        queue1.pop();
        swap(queue1, queue2);
        return pop_val;
    }
    
    int top() {
        return queue1.back();
    }
    
    bool empty() {
        return queue1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */