/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peakIndex = findPeakIndex(mountainArr);
        int result = binarySearchAscending(target, mountainArr, peakIndex);
        if (result != -1) {
            return result;
        }
        return binarySearchDescending(target, mountainArr, peakIndex);
    }

private:
    int findPeakIndex(MountainArray &mountainArr) {
        int left = 0;
        int right = mountainArr.length() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

    int binarySearchAscending(int target, MountainArray &mountainArr, int peakIndex) {
        int left = 0;
        int right = peakIndex;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midVal = mountainArr.get(mid);

            if (midVal == target) {
                return mid;
            } else if (midVal < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }

    int binarySearchDescending(int target, MountainArray &mountainArr, int peakIndex) {
        int left = peakIndex;
        int right = mountainArr.length() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midVal = mountainArr.get(mid);

            if (midVal == target) {
                return mid;
            } else if (midVal < target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
};
