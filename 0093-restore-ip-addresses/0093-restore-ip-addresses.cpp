class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string current; 
        
        generateIPAddresses(s, 0, 0, current, result);
        
        return result;
    }
    
private:
    void generateIPAddresses(const string& s, int startIndex, int segmentCount, string& current, vector<string>& result) {
        if (segmentCount == 4) {
            if (startIndex == s.length()) {
                result.push_back(current); 
            }
            return;
        }
        
        for (int i = 1; i <= 3; i++) {
            if (startIndex + i <= s.length()) {
                string segment = s.substr(startIndex, i);
                
               
                if ((segment[0] != '0' || segment.length() == 1) && stoi(segment) <= 255) {
                    string updatedCurrent = current + segment;
                    if (segmentCount < 3) {
                        updatedCurrent += '.';
                    }
                    generateIPAddresses(s, startIndex + i, segmentCount + 1, updatedCurrent, result);
                }
            }
        }
    }
};
