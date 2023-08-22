//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    string removeDups(string S) 
    {
        // Create a boolean array to track whether a character has been encountered before
        bool seen[256] = {false}; // Assuming ASCII characters
        
        int newSize = 0; // Index to track the current position in the modified string
        
        // Iterate through each character in the original string
        for (int i = 0; i < S.size(); ++i) {
            char currentChar = S[i];
            
            // If the character hasn't been encountered before, add it to the modified string
            if (!seen[currentChar]) {
                seen[currentChar] = true;
                S[newSize] = currentChar;
                newSize++;
            }
        }
        
        // Resize the string to the new size to remove any leftover characters
        S.resize(newSize);
        
        return S;
    }
};


//{ Driver Code Starts.


int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   		
   		Solution ob;
   		cout << ob.removeDups(s) << "\n";
   		
   	}

    return 0;
}
// } Driver Code Ends