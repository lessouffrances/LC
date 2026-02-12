class OrderedStream 
{
    public:
    OrderedStream(int n): ptr(1), stream(n+1) {}

    vector<string> insert(int idKey, string value)
    {
        // always assign the value
        stream[idKey] = value;

        vector<string> res;
        // only move forward if the slot is not empty
        while (ptr < stream.size() && !stream[ptr].empty()) {
            res.push_back(stream[ptr]);
            ptr++;
        }
        return res;
    }
    private:
    int ptr;
    vector<string> stream;
};