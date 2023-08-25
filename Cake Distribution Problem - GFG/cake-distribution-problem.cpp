//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPossible(vector<int>& sweetness, int N, int K, int minSweetness) {
        int currentSum = 0;
        int students = 0;

        for (int i = 0; i < N; ++i) {
            currentSum += sweetness[i];
            if (currentSum >= minSweetness) {
                currentSum = 0;
                students++;
            }
        }

        return students >= K + 1;  // Adjusted to K + 1
    }

    int maxSweetness(vector<int>& sweetness, int N, int K) {
        int totalSum = 0;
        for (int sweet : sweetness) {
            totalSum += sweet;
        }

        int left = 1; // Minimum sweetness value
        int right = totalSum; // Maximum sweetness value
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(sweetness, N, K, mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends