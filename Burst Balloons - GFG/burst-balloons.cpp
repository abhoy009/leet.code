//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    int maxCoins(int N, vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        vector<int> balloons(n + 2, 1); // Add padding balloons at the beginning and end
        
        for (int i = 1; i <= n; ++i) {
            balloons[i] = arr[i - 1];
        }
        
        for (int len = 1; len <= n; ++len) {
            for (int left = 1; left <= n - len + 1; ++left) {
                int right = left + len - 1;
                for (int k = left; k <= right; ++k) {
                    dp[left][right] = max(dp[left][right],
                                          dp[left][k - 1] + balloons[left - 1] * balloons[k] * balloons[right + 1] + dp[k + 1][right]);
                }
            }
        }
        
        return dp[1][n];
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends