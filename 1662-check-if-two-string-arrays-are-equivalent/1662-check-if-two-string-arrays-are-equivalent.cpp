class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1 = concatenateStrings(word1);
        string str2 = concatenateStrings(word2);

        return str1 == str2;
    }

private:
    string concatenateStrings(const vector<string>& words) {
        string result;

        for (const string& word : words) {
            result += word;
        }

        return result;
    }
};