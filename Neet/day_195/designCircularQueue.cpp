class MyCircularQueue 
{
    public:
    MyCircularQueue(int k) 
    { 
        capacity = k;
    }
    
    bool enQueue(int value) 
    {
        if (container.size() == capacity) return false;
        container.push_back(value);
        return true;
    }
    
    bool deQueue() 
    {
        if (container.empty()) return false;
        container.pop_front();
        return true;
    }
    
    int Front() 
    {
        if (container.empty()) return -1;
        return container.front();
    }
    
    int Rear() 
    {
        if (container.empty()) return -1;
        return container.back();
    }
    
    bool isEmpty() 
    {
        return container.empty();
    }
    
    bool isFull() 
    {
        return container.size() == capacity;
    }

    private:
    int capacity;
    deque<int> container;
};
    
    