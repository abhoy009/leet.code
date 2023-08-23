//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    int minCandy(int N, vector<int> &ratings) {
        vector<int> leftToRight(N, 1); // Initialize candies from left to right
        vector<int> rightToLeft(N, 1); // Initialize candies from right to left
        
        // Traverse from left to right, ensure higher-rated children get more candies than left neighbors
        for (int i = 1; i < N; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                leftToRight[i] = leftToRight[i - 1] + 1;
            }
        }
        
        // Traverse from right to left, ensure higher-rated children get more candies than right neighbors
        for (int i = N - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                rightToLeft[i] = rightToLeft[i + 1] + 1;
            }
        }
        
        int totalCandies = 0;
        // Calculate the maximum value between leftToRight and rightToLeft at each index
        for (int i = 0; i < N; ++i) {
            totalCandies += max(leftToRight[i], rightToLeft[i]);
        }
        
        return totalCandies;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends