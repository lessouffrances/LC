class Solution 
{
    public:
    int search(const ArrayReader& reader, int target)
    {
        int left = 0, right = 1;

        while (reader.get(right) < target) {
            left = right;
            right = 2 * right;
        }

        while (left <= right) {
            int mid = left + (right - left)/2;
            int val = reader.get(mid);

            if (val == target) {
                return mid;
            } else if (val > target) {
                right = mid-1;
            } else if (val < target) {
                left = mid+1;
            }
        }
        return -1;
    }
};