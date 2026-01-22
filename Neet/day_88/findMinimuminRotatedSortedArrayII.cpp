//  0 1 2 3
// [3,3,1,3]

//  0 1 2 3 4 5 6
// [4,5,6,7,0,1,4]

//  0 1 2 3 4 5 6
// [0,1,4,4,5,6,7]

class Solution 
{
    public:
    int findMin(vector<int>& nums) 
    {
        int left = 0, right = nums.size() - 1; //l=0, r=1

        while (left < right) {  //0<6  0<3  0<1
            int mid = left + (right - left) / 2; //m=3  m=1  m=0
            
            if (nums[mid] > nums[right]) { //
                left = mid + 1; //
            } else if (nums[mid] < nums[right]) { //
                right = mid; //r=3  r=1  r=0
            } else {
                right--; 
            }
        }
        return nums[left];
    }
};