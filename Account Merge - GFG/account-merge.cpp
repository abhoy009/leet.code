//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> emailToName;  // Map email to its owner's name
        unordered_map<string, vector<string>> graph;  // Graph to represent email connections
        
        // Build the graph and emailToName map
        for (const vector<string>& account : accounts) {
            string name = account[0];
            for (int i = 1; i < account.size(); i++) {
                emailToName[account[i]] = name;
                if (i == 1) continue;  // Skip the first email
                graph[account[i]].push_back(account[i - 1]);
                graph[account[i - 1]].push_back(account[i]);
            }
        }
        
        unordered_set<string> visited;
        vector<vector<string>> result;
        
        // Perform depth-first search to merge connected emails
        for (const auto& email : emailToName) {
            if (visited.find(email.first) == visited.end()) {
                vector<string> connectedEmails;
                dfs(email.first, graph, visited, connectedEmails);
                sort(connectedEmails.begin(), connectedEmails.end());  // Sort the emails
                connectedEmails.insert(connectedEmails.begin(), emailToName[email.first]);  // Insert name at the beginning
                result.push_back(connectedEmails);
            }
        }
        
        return result;
    }
    
private:
    void dfs(const string& email, unordered_map<string, vector<string>>& graph, unordered_set<string>& visited, vector<string>& connectedEmails) {
        visited.insert(email);
        connectedEmails.push_back(email);
        for (const string& neighbor : graph[email]) {
            if (visited.find(neighbor) == visited.end()) {
                dfs(neighbor, graph, visited, connectedEmails);
            }
        }
    }
};



//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends