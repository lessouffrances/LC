




class Solution 
{
    public:
    int fib(int n) 
    {
        // base case
        if (n == 0 || n == 1) return n;
        return fib(n-2) + fib(n-1);
    }
};s