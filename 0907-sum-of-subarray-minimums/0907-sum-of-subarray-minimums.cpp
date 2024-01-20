class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        stack<int> s;  // Stack to store indices
        vector<int> left(n), right(n);

        // Calculate left boundary for each element
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            left[i] = (s.empty() ? i + 1 : i - s.top());
            s.push(i);
        }

        // Clear the stack for right boundary calculation
        while (!s.empty()) {
            s.pop();
        }

        // Calculate right boundary for each element
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            right[i] = (s.empty() ? n - i : s.top() - i);
            s.push(i);
        }

        // Calculate the sum of minimums for each subarray
        int result = 0;
        for (int i = 0; i < n; ++i) {
            result = (result + (long long)arr[i] * left[i] * right[i]) % MOD;
        }

        return result;
    }
};