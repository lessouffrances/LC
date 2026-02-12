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
         if (mountainArr.length() == 0) return 0;
         int n = mountainArr.length();
         int peakIdx = findPeakIdx(mountainArr);
 
         int res = binarySearchWithToggle(0, peakIdx, target, mountainArr, true);
         if (res != -1) return res;
 
         return binarySearchWithToggle(peakIdx, n-1, target, mountainArr, false);
     }
     private:
     int binarySearchWithToggle(int left, int right, int target, MountainArray &mountainArr, bool isAscending)
     {
         while (left <= right) {
             int mid = left + (right - left) / 2;
             if (target == mountainArr.get(mid)) return mid;
 
             if (target > mountainArr.get(mid)) {
                 if (isAscending) {
                     left = mid+1;
                 } else {
                     right = mid-1;
                 }
             } else {
                 if (isAscending) {
                     right = mid-1;
                 } else {
                     left = mid+1;
                 }
             }
         }
         return -1;
     }
     int findPeakIdx(MountainArray &mountainArr) 
     {
         if (mountainArr.length() == 0) return 0;
         int n = mountainArr.length();
         int left = 0, right = n-1;
 
         while (left < right) {
             int mid = left + (right - left) / 2;
             if (mid+1 < n && mountainArr.get(mid) < mountainArr.get(mid+1)) {
                 left = mid+1;
             } else {
                 right = mid;
             }
         }
         return left;
     }
 };