



class Solution 
{
    public:
    int maximumSwap(int num) 
    {
        string numStr = to_string(num);
        int n = numStr.size();

        // right to left pass
        vector<int> maxRightIdx(n, -1);
        maxRightIdx[n-1] = n-1; // inclusive
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
        // already the optimal form
        return num;
    }
};