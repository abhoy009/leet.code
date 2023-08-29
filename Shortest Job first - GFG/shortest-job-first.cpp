//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// Back-end complete function Template for C++

class Solution {
public:
    long long solve(vector<int>& bt) {
        int n = bt.size();
        
        vector<int> completionTime(n);
        vector<int> waitingTime(n);
        
        // Sort processes based on burst time
        vector<int> processOrder(n);
        for (int i = 0; i < n; i++) {
            processOrder[i] = i;
        }
        sort(processOrder.begin(), processOrder.end(), [&](int a, int b) {
            return bt[a] < bt[b];
        });
        
        completionTime[processOrder[0]] = bt[processOrder[0]];
        for (int i = 1; i < n; i++) {
            completionTime[processOrder[i]] = completionTime[processOrder[i - 1]] + bt[processOrder[i]];
        }
        
        for (int i = 0; i < n; i++) {
            waitingTime[processOrder[i]] = completionTime[processOrder[i]] - bt[processOrder[i]];
        }
        
        long long totalWaitingTime = 0;
        for (int i = 0; i < n; i++) {
            totalWaitingTime += waitingTime[i];
        }
        
        return totalWaitingTime / n;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> bt(n), p(n);
        for (int i = 0; i < n; i++) {
            cin >> bt[i];
        }
        Solution obj;
        long long ans = obj.solve(bt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends