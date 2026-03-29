class MyQueue 
{
    public:
    MyQueue() {}
    
    void push(int x) {
        inbox.push(x);
    }
    
    int pop() {
        pour();
        int val = outbox.top();
        outbox.pop();
        return val;
    }
    
    int peek() {
        pour();
        int val = outbox.top();
        return val;
    }
    
    bool empty() {
        return outbox.empty() && inbox.empty();
    }

    private:
    stack<int> inbox;
    stack<int> outbox;

    void pour() 
    {
        if (outbox.empty()) {
            while (!inbox.empty()) {
                outbox.push( inbox.top() );
                inbox.pop();
            }
        }
    }
};
