//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
public:
    long long int countSubsets(vector<int>& arr, int n, int l, int r){
        int totalSubsets = 0;

        // Generating all possible subsets
        for (int mask = 0; mask < (1 << n); mask++) {
            int subsetSum = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    subsetSum += arr[i];
                }
            }

            if (subsetSum >= l && subsetSum <= r) {
                totalSubsets++;
            }
        }

        return totalSubsets;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    int l, r;
	    cin >> l >> r;
	    Solution ob;
	    long long int ans = ob.countSubsets(arr, n, l, r);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends