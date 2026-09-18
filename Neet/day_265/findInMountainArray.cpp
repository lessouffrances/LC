/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

 class Solution 
 {
     public:
     int findInMountainArray(int target, MountainArray &mountainArr) 
     {
         int peak = findPeak(mountainArr);
         int idx = binarySearchWithToggle(0, peak, target, mountainArr, true);
         if (idx != -1) return idx;
         idx = binarySearchWithToggle(peak+1, mountainArr.length()-1, target, mountainArr, false);
         return idx;
     }
 
     private:
     int binarySearchWithToggle(int left, int right, int target, MountainArray& mountainArr, bool isAsc)
     {
         while (left <= right) {
             int mid = left + (right-left)/2;
             if (target == mountainArr.get(mid)) return mid;
             if (target > mountainArr.get(mid)) {
                 if (isAsc) {
                     left = mid+1;
                 } else {
                     right = mid-1;
                 }
             } else {
                 if (isAsc) {
                     right = mid-1;
                 } else {
                     left = mid+1;
                 }
             }
         }
         return -1;
     }
     
     int findPeak(MountainArray& mountainArr) 
     {
         int n = mountainArr.length();
         int left = 0, right = n-1;
 
         while (left < right) {
             int mid = left+(right-left) / 2;
             if (mid+1 < n && mountainArr.get(mid) < mountainArr.get(mid+1)) {
                 left = mid+1;
             } else {
                 right = mid;
             }
         }
         return left;
     }
 };