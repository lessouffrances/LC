class MyCircularQueue 
{
    public:
    MyCircularQueue(int k) 
    {
        capacity = k;
        data.resize(k);
        head = 0;
        tail = 0;
        size = 0;
    }
    
    // data[tail] = value and then move tail
    // update size
    bool enQueue(int value) 
    {
        if (isFull()) return false;
        data[tail] = value;
        tail = (tail + 1) % capacity;
        size++;
        return true;
    }
    
    // move head 
    // update size
    bool deQueue() 
    {
        if (isEmpty()) return false;
        head = (head + 1) % capacity;
        size--;
        return true;
    }
    
    int Front() 
    {
        if (isEmpty()) return -1;
        return data[head];
    }
    
    int Rear() 
    {
        if (isEmpty()) return -1;
        // tail is the next fillable pos
        return data[(tail-1+capacity) % capacity];
    }
    
    bool isEmpty() 
    {
        return size == 0;
    }
    
    bool isFull() 
    {
        return size == capacity;
    }

    private:
    vector<int> data;
    int capacity, head, tail, size;
};
    
    