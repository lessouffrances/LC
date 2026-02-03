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
         int peakIdx = findPeak(mountainArr);
         int n = mountainArr.length();
 
         // search in the first half sorted array
         int idx = binarySearch(0, peakIdx, target, mountainArr, true);
         if (idx != -1) return idx;
 
         return binarySearch(peakIdx+1, n-1, target, mountainArr, false);
     }
     private:
     int binarySearch(int left, int right, int target, MountainArray &mountainArr, bool isAscending) 
     {
         while (left <= right) {
             int mid = left + (right-left)/2;
             int midVal = mountainArr.get(mid);
             if (midVal == target) return mid;
 
             if (midVal > target) {
                 if (isAscending) {
                     right = mid-1;
                 } else {
                     left = mid+1;
                 }
                 
             } else {
                 if (isAscending) {
                     left = mid+1;
                 } else {
                     right = mid-1;
                 }
             }
         }
         return -1;
     }
     int findPeak(MountainArray &mountainArr) 
     {
         int n = mountainArr.length();
         int left = 0, right = n-1;
 
         while (left < right) {
             int mid = left + (right-left) / 2;
 
             if (mid+1 < n && mountainArr.get(mid) < mountainArr.get(mid+1)) {
                 left = mid+1;
             } else {
                 right = mid;
             }
         }
         return left;
     }
 };