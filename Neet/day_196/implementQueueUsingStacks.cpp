class MyQueue 
{
    public:
    MyQueue() 
    {}
    
    void push(int x) 
    {
        st1.push(x);
    }
    
    int pop() 
    {
        pour();
        int toPop = st2.top();
        st2.pop();
        return toPop;
    }
    
    int peek() 
    {
        pour();
        int toPop = st2.top();
        return toPop;
    }
    
    bool empty() 
    {
        return (st1.empty() && st2.empty());
    }

    private:
    stack<int> st1;
    stack<int> st2;

    void pour()
    {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
    }
};
    
   