class OrderedStream 
{
    public:
    OrderedStream(int n) : ptr(1), stream(n + 1) {}
    
    vector<string> insert(int idKey, string value) 
    {
        stream[idKey] = value;

        vector<string> res;
        while (ptr < stream.size() && !stream[ptr].empty()) {
            res.push_back(stream[ptr]);
            ptr++;
        }
        return res;
    }
    private:
    vector<string> stream;
    int ptr;
};