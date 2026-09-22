class Solution 
{
    public:
    int maximumSwap(int num) 
    {
        string numStr = to_string(num);
        int n = numStr.length();
        // store the idx of the number that is to the right of the queried idx
        // inclusive
        vector<int> maxRightIdx(n, 0); 
        maxRightIdx[n-1] = n-1; 
        // greedy right to left
        for (int i=n-2; i>=0; i--) {
            if (numStr[i] > numStr[maxRightIdx[i+1]]) {
                maxRightIdx[i] = i;
            } else {
                maxRightIdx[i] = maxRightIdx[i+1];
            }
        }

        // left to right
        // once find the 
        for (int i=0; i<n; i++) {
            if (numStr[i] < numStr[maxRightIdx[i]]) {
                swap(numStr[i], numStr[maxRightIdx[i]]);
                return stoi(numStr);
            }
        }
        return num;
    }
};