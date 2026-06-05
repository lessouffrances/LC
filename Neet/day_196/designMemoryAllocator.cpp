class Allocator 
{
    public:
    Allocator(int n) 
    {
        ram = vector<int>(n, INT_MAX);  
        capacity = n;
    }
    //        l     r
    // [1,1,1,0,0,0,2,2,0,3,3,4,0,0,0,0,0]
    //  0,1,2,3,4,5,6
    int allocate(int size, int mID) 
    {

        int left = 0;
        while (left < capacity) {
            if (ram[left] == INT_MAX) {
                int currChunk = 0;
                int right = left;
                while (right < capacity && ram[right] == INT_MAX) {
                    right++;
                }
                currChunk = right-left;
            
                if (currChunk >= size) {
                    for (int i=left; i<left+size; i++) {
                        ram[i] = mID;
                    }
                    return left;
                } else {
                    left = right;
                    continue;
                }
            }
            left++;
        }
        return -1;
    }
    
    int freeMemory(int mID) 
    {
        int count = 0;
        for (int& num : ram) {
            if (num == mID) {
                count++;
                num = INT_MAX;
            }
        }
        return count;
    }
    private:
    vector<int> ram;
    int capacity = 0;
};
    
    