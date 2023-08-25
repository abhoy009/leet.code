class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1;  // Smallest possible number in the multiplication table
        int right = m * n;  // Largest possible number in the multiplication table
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // Count how many numbers in the multiplication table are less than or equal to 'mid'
            int count = 0;
            for (int i = 1; i <= m; ++i) {
                count += min(mid / i, n);
            }
            
            if (count < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
};
