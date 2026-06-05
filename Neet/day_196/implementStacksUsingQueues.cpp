class MyStack { 
    public:
    MyStack() {}
    
    void push(int x) 
    {
        q.push(x);
        for (int i=0; i<q.size()-1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() 
    {
        int toPop = q.front();
        q.pop();
        return toPop;
    }
    
    int top() 
    {
        int toPop = q.front();
        return toPop;
    }
    
    bool empty() 
    {
        return q.empty();
    }

    private:
    queue<int> q;
};
    
    