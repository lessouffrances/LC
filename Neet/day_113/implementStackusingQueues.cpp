class MyStack 
{
    public:
    MyStack() {}
    void push(int x) 
    {
        q.push(x);
        // rotate q
        int n = q.size();
        for (int i=0; i<n-1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() 
    {
        int top = q.front();
        q.pop();
        return top;
    }
    
    int top() 
    {
        return q.front();
    }
    
    bool empty() 
    {
        return q.size() == 0;
    }
    private:
    queue<int> q;
};
    
