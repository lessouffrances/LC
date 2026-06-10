class Solution 
{
    public:
    void reverseString(vector<char>& s) 
    {
        if (s.size() == 1) return;
        int n = s.size();

        int left = 0, right = n-1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
        return;
    }
};