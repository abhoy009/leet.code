class Solution {
public:
    string countOfAtoms(string formula) {
        regex reg("([A-Z][a-z]*)(\\d*)|(\\()|(\\))(\\d*)");
        sregex_iterator it(formula.begin(), formula.end(), reg);
        sregex_iterator end;
        vector<tuple<string, string, string, string, string>> matcher;
        while (it != end) {
            matcher.push_back(
                {(*it)[1], (*it)[2], (*it)[3], (*it)[4], (*it)[5]});
            it++;
        }
        reverse(matcher.begin(), matcher.end());

        unordered_map<string, int> finalMap;

        stack<int> stack;
        stack.push(0);

        int runningMul = 1;
        for (auto& quintuple : matcher) {
            string atom = get<0>(quintuple);
            string count = get<1>(quintuple);
            string left = get<2>(quintuple);
            string right = get<3>(quintuple);
            string multiplier = get<4>(quintuple);

            if (!atom.empty()) {
                int cnt = count.empty() ? 1 : stoi(count);
                finalMap[atom] += cnt * runningMul;
            }
            else if (!right.empty()) {
                int currMultiplier = multiplier.empty() ? 1 : stoi(multiplier);
                runningMul *= currMultiplier;
                stack.push(currMultiplier);
            }
            else if (!left.empty()) {
                runningMul /= stack.top();
                stack.pop();
            }
        }
        map<string, int> sortedMap(finalMap.begin(), finalMap.end());
        string ans;
        for (auto& [atom, count] : sortedMap) {
            ans += atom;
            if (count > 1) {
                ans += to_string(count);
            }
        }

        return ans;
    }
};