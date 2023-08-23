//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n) {
        // Convert all 0s to -1s in the array
        for (int i = 0; i < n; ++i) {
            if (arr[i] == 0)
                arr[i] = -1;
        }
        
        unordered_map<int, int> prefixSumCount; // Map to store prefix sum frequencies
        int prefixSum = 0; // Running sum
        long long int count = 0; // Count of subarrays
        
        for (int i = 0; i < n; ++i) {
            prefixSum += arr[i];
            
            if (prefixSum == 0)
                count++; // Prefix sum from 0 to i forms a subarray with equal 0s and 1s
            
            if (prefixSumCount.find(prefixSum) != prefixSumCount.end())
                count += prefixSumCount[prefixSum]; // Add subarrays with equal prefix sums
            
            prefixSumCount[prefixSum]++;
        }
        
        return count;
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution obj;
	cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}

// } Driver Code Ends