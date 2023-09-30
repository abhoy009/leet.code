class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> parent;
        unordered_map<string, string> owner;
        unordered_map<string, set<string>> unions;
        
        for (const vector<string>& account : accounts) {
            for (int i = 1; i < account.size(); i++) {
                parent[account[i]] = account[i]; 
                owner[account[i]] = account[0];  
            }
        }
        
        for (const vector<string>& account : accounts) {
            string p = find(account[1], parent); 
            for (int i = 2; i < account.size(); i++) {
                parent[find(account[i], parent)] = p; // Union all emails in the account.
            }
        }
        
        // Step 3: Group emails by their root parent.
        for (const vector<string>& account : accounts) {
            for (int i = 1; i < account.size(); i++) {
                unions[find(account[i], parent)].insert(account[i]);
            }
        }
        
        vector<vector<string>> result;
        for (const auto& kvp : unions) {
            vector<string> emails(kvp.second.begin(), kvp.second.end());
            emails.insert(emails.begin(), owner[kvp.first]); 
            result.push_back(emails);
        }
        
        return result;
    }
    
private:
    string find(string s, unordered_map<string, string>& parent) {
        if (parent[s] != s) {
            parent[s] = find(parent[s], parent);
        }
        return parent[s];
    }
};
