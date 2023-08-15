class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) {
            return INT_MAX; // Handle division by zero
        }

        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX; // Handle overflow case
        }

        bool isNegative = (dividend < 0) ^ (divisor < 0);
        long long absDividend = abs((long long)dividend);
        long long absDivisor = abs((long long)divisor);
        long long quotient = 0;

        while (absDividend >= absDivisor) {
            long long temp = absDivisor;
            long long multiple = 1;

            while (absDividend >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            absDividend -= temp;
            quotient += multiple;
        }

        if (isNegative) {
            quotient = -quotient;
        }

        if (quotient > INT_MAX) {
            return INT_MAX;
        }

        return static_cast<int>(quotient);
    }
};
