class MyQueue {
public:
    stack<int> input, output;
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(!output.empty()){
            int ele=output.top();
            output.pop();
            return ele;
        }
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        int ele=output.top();
        output.pop();
        return ele;
    }
    
    int peek() {
         if(!output.empty()){
            int ele=output.top();
            return ele;
        }
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        int ele=output.top();
        return ele;
    }
    
    bool empty() {
        return (input.empty() && output.empty());
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