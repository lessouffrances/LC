





class MyQueue 
{
    public:
    MyQueue() {}
    
    void push(int x) 
    {
        inbox.push(x);
    }
    
    int pop() 
    {
        pour();
        int val = outbox.top();
        outbox.pop();
        return val;
    }
    
    int peek() 
    {
        pour();
        return outbox.top();
    }
    
    bool empty() 
    {
        return inbox.empty() && outbox.empty();
    }

    private:
    stack<int> inbox;
    stack<int> outbox;

    void pour()
    {
        if (outbox.empty()) {
            while (!inbox.empty()) {
                outbox.push(inbox.top());
                inbox.pop();
            }
        }
    }
};
    
    