class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n == 0) {
            return 0;
        }

        int msb = 0;
        while ((1 << msb) <= n) {
            msb++;
        }
        msb--;  

        if (msb == 0) {
            return 1 + minimumOneBitOperations(n ^ 1);
        }

        return (1 << (msb + 1)) - 1 - minimumOneBitOperations(n ^ (1 << msb));
    }
};
