class Solution {
public:
    string simplifyPath(string path) {
        vector<string> parts; 
        string part = ""; 

        for (char c : path) {
            if (c == '/') {
                if (part == "..") {
                    if (!parts.empty()) {
                        parts.pop_back();
                    }
                } else if (!part.empty() && part != ".") {
                    parts.push_back(part); 
                }
                part = ""; 
            } else {
                part += c; 
            }
        }

        if (part == "..") {
            if (!parts.empty()) {
                parts.pop_back(); 
            }
        } else if (!part.empty() && part != ".") {
            parts.push_back(part);
        }

        string simplifiedPath = "";
        for (string dir : parts) {
            simplifiedPath += "/" + dir; 
        }

        return (simplifiedPath.empty()) ? "/" : simplifiedPath;
    }
};
