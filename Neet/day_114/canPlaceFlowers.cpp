class Solution 
{
    public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        if (flowerbed.empty()) return n == 0;
        if (n == 0) return true;

        int size = flowerbed.size();
        for (int i=0; i<size; i++) {
            if (flowerbed[i] == 0) {
                bool leftOK = (i-1)>=0 ? flowerbed[i-1] == 0 : true;
                bool rightOK = (i+1)<size ? flowerbed[i+1] == 0 : true;

                if (leftOK && rightOK) {
                    flowerbed[i] = 1;
                    if (n > 0) n--;
                    if (n == 0) return true;
                }
            }
        }
        return n <= 0;
    }
};