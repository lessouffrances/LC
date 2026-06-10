class Solution 
{
    public:
    int compress(vector<char>& chars) 
    {
        int write = 0, read = 0;
        int n = chars.size();

        while (read < n) {
            char ch = chars[read];
            int count = 0;
            while (read < n && chars[read] == ch) {
                count++;
                read++;
            }

            chars[write] = ch;
            write++;

            if (count > 1) {
                string countStr = to_string(count);
                for (char ch : countStr) {
                    chars[write] = ch;
                    write++;
                }
            }
        }
        return write;
    }
};