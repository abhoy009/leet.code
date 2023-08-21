//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
public:
    int maxLen(vector<int>& A, int n) {
        unordered_map<int, int> sumMap; // Maps cumulative sum to index
        int maxLength = 0;
        int cumulativeSum = 0;

        for (int i = 0; i < n; ++i) {
            cumulativeSum += A[i];

            if (cumulativeSum == 0) {
                // If cumulative sum is 0, the subarray from the beginning has a 0 sum
                maxLength = max(maxLength, i + 1);
            } else if (sumMap.find(cumulativeSum) != sumMap.end()) {
                // If cumulative sum already exists in the map, a subarray with 0 sum is found
                maxLength = max(maxLength, i - sumMap[cumulativeSum]);
            } else {
                // Store the cumulative sum and its index in the map
                sumMap[cumulativeSum] = i;
            }
        }

        return maxLength;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends