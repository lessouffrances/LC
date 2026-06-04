

// [1,2,3,4]
// st.push(1) 
// st.push(2)
// st.pop()   => 2
// st.push(3)
// st.push(4)
// st.pop()   => 4


class MyStack 
{
    public:
    MyStack() {}
    
    void push(int x) 
    {
        q.push(x);

        // reverse
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
