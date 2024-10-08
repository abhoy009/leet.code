class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> merged(m + n);
        
        int i = 0, j = 0, k = 0;
        
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                merged[k++] = nums1[i++];
            } else {
                merged[k++] = nums2[j++];
            }
        }
        
        while (i < m) {
            merged[k++] = nums1[i++];
        }
        
        while (j < n) {
            merged[k++] = nums2[j++];
        }
        
        int total = m + n;        
        if (total % 2 != 0) {
            return static_cast<double>(merged[total / 2]);
        }        
        int mid1 = merged[(total - 1) / 2];
        int mid2 = merged[total / 2];
        return (static_cast<double>(mid1) + static_cast<double>(mid2)) / 2.0;
    }
};