class Solution 
{
    public:
    int maximumSwap(int num) 
    {
        string numStr = to_string(num);
        int n = numStr.length();

        // right to left pass
        // stores the idx of the max number that are right to the curr number
        vector<int> maxRightIdx(n, -1);
        maxRightIdx[n-1] = n-1; // the last idx
        for (int i=n-2; i>=0; i--) {
            if (numStr[i] > numStr[maxRightIdx[i+1]]) {
                maxRightIdx[i] = i;
            } else {
                maxRightIdx[i] = maxRightIdx[i+1];
            }
        }

        for (int i=0; i<n; i++) {
            if (numStr[i] < numStr[maxRightIdx[i]]) {
                swap(numStr[i], numStr[maxRightIdx[i]]);
                return stoi(numStr);
            }
        }
        return num;
    }
};