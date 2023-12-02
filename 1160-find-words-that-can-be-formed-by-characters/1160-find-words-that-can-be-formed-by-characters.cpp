class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> charCount;
        int result = 0;

        for (char ch : chars) {
            charCount[ch]++;
        }

        for (const string& word : words) {
            if (canFormWord(word, charCount)) {
                result += word.length();
            }
        }

        return result;
    }

private:
    bool canFormWord(const string& word, unordered_map<char, int>& charCount) {
        unordered_map<char, int> wordCount;

        for (char ch : word) {
            wordCount[ch]++;
        }

        for (const auto& entry : wordCount) {
            char ch = entry.first;
            int count = entry.second;

            if (charCount.find(ch) == charCount.end() || charCount[ch] < count) {
                return false;
            }
        }

        return true;
    }
};