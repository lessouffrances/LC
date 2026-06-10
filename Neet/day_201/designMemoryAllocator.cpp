class Allocator 
{
    public:
    Allocator(int n) 
    {
        capacity = n;
        ram.resize(n, INT_MAX);
    }
    
    //        l     r
    // [1,1,1,0,0,0,2,2,0,3,3,4,0,0,0,0,0]
    //  0,1,2,3,4,5,6
    int allocate(int size, int mID) 
    {
        int left = 0, right = 0;
        while (left < capacity) {
            if (ram[left] == INT_MAX) {
                right = left;
                int currChunkSize = 0;
                while (right < capacity && ram[right] == INT_MAX) {
                    currChunkSize++;
                    right++;
                }

                if (currChunkSize >= size) {
                    // if currChunk can fit
                    // allocate:
                    for (int i=left; i<left+size; i++) {
                        ram[i] = mID;
                    }
                    return left;
                } else {
                    // if currChunk cannot fit
                    // continue
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
        for (auto& block : ram) {
            if (block == mID) {
                block = INT_MAX;
                count++;
            }
        }
        return count; 
    }

    private:
    int capacity = 0;
    vector<int> ram;
};
    
    