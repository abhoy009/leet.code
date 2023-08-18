class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m + n - 1;
        int i = m - 1; // Index for nums1
        int j = n - 1; // Index for nums2
        
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[index] = nums1[i];
                i--;
            } else {
                nums1[index] = nums2[j];
                j--;
            }
            index--;
        }
        
        // If there are remaining elements in nums2
        while (j >= 0) {
            nums1[index] = nums2[j];
            j--;
            index--;
        }
    }
};
